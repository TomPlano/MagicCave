#include "characterFactory.h"

CharacterFactory::CharacterFactory()
{
  rng.seed(std::random_device()());

  std::ifstream rstream("data/races.json");
  rstream >> race_root;

  std::ifstream cstream("data/classes.json");
  cstream >> class_root;

}

Character CharacterFactory::create_character()
{
  int num_races = race_root["race"].size()-1;
  std::uniform_int_distribution<int> race_select(0,num_races);

  int num_classes = class_root["class"].size()-1;
  std::uniform_int_distribution<int> class_select(0,num_classes);

  Json::Value char_race = race_root["race"][race_select(rng)];
  Json::Value char_class = class_root["class"][class_select(rng)];


  Character ch;
  ch.level=1;
  ch.prof_bonus = std::ceil(ch.level/4)+1;
  ch.char_race = char_race["name"].asString();
  ch.char_class = char_class["name"].asString();
  ch.hp = char_class["hd"]["faces"].asInt();
  ch.hit_die = char_class["hd"]["number"].asString()+"d"+char_class["hd"]["faces"].asString()+"per class level";
  ch.str=stat_gen();
  ch.dex=stat_gen();
  ch.con=stat_gen();
  ch.intel=stat_gen();
  ch.wis=stat_gen();
  ch.cha=stat_gen();

  ch.str_mod = std::floor((ch.str-10)/2);
  ch.dex_mod = std::floor((ch.dex-10)/2);
  ch.con_mod= std::floor((ch.con-10)/2);
  ch.intel_mod= std::floor((ch.intel-10)/2);
  ch.wis_mod= std::floor((ch.wis-10)/2);
  ch.cha_mod= std::floor((ch.cha-10)/2);

  ch.skills = skill_gen(char_class);

  std::cout<<ch.skills[0]<<std::endl;


  return ch;
}


int CharacterFactory::stat_gen()
{
    std::uniform_int_distribution<int> d6(1,6);
    int rolls [4];
    for(int i = 0; i<4; i ++)
    {
      rolls[i] =d6(rng);
    }
    std::sort(rolls, rolls+4);
    int result = 0;
    for(int i = 1; i<4; i ++)
    {
      result+=rolls[i];
    }
    return result;
}
std::string* CharacterFactory::skill_gen(Json::Value classs)
{
  int size = classs["startingProficiencies"]["skills"]["from"].size();
  int choose = classs["startingProficiencies"]["skills"]["choose"].asInt();

  std::string lskills[size];

  for (int i=0;i<size;i++)
  {
    lskills[i]=classs["startingProficiencies"]["skills"]["from"][i].asString();
  }
  std::random_shuffle(&lskills[0], &lskills[size+1]);

  std::string* result = (std::string*)malloc(sizeof(std::string)*size);

  for (int i=0;i<choose;i++)
  {
    result[i] = lskills[i];
  }

  return result;
}
