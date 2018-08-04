#include "characterFactory.h"

CharacterFactory::CharacterFactory()
{
  rng.seed(std::random_device()());

  std::ifstream rstream("data/races.json");
  rstream >> race_root;

  std::ifstream cstream("data/classes.json");
  cstream >> class_root;

}
CharacterFactory::~CharacterFactory()
{
}

Character CharacterFactory::create_character(bool is_npc)
{
  int num_races = race_root["race"].size()-1;
  std::uniform_int_distribution<int> race_select(0,num_races);

  int num_classes = class_root["class"].size()-1;
  std::uniform_int_distribution<int> class_select(0,num_classes);

  Json::Value char_race = race_root["race"][race_select(rng)];
  Json::Value char_class = class_root["class"][class_select(rng)];


  Character ch (is_npc);
  ch.level=1;
  ch.prof_bonus = 2;
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
  ch.proficiency=list_reformat(char_class["proficiency"]);
  ch.armor_profs = list_reformat(char_class["startingProficiencies"]["armor"]);
  ch.weapon_profs = list_reformat(char_class["startingProficiencies"]["weapons"]);
  ch.gold = char_class["startingEquipment"]["goldAlternative"].asString();

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


std::list<std::string> CharacterFactory::list_reformat(Json::Value profs){
    std::vector<std::string> local_skills;
    std::list<std::string> skill_gen_result;
    for (auto itr : profs) {
        local_skills.push_back(itr.asString());
    }
    for (std::vector<std::string>::iterator it=local_skills.begin(); it!=local_skills.end(); ++it)
    {
        skill_gen_result.push_front(*it);
    }
    return skill_gen_result;
}

std::list<std::string> CharacterFactory::skill_gen(Json::Value classs)
{
  int choose = classs["startingProficiencies"]["skills"]["choose"].asInt();

  std::vector<std::string> local_skills;
  std::list<std::string> skill_gen_result;


  for (auto itr : classs["startingProficiencies"]["skills"]["from"]) {
      local_skills.push_back(itr.asString());
  }
  std::random_shuffle(local_skills.begin(), local_skills.end());
  int count=0;
  for (std::vector<std::string>::iterator it=local_skills.begin(); it!=local_skills.end(); ++it)
  {
    if (count>=choose)
    {
      break;
    }
    skill_gen_result.push_front(*it);
    count++;
  }

  return skill_gen_result;
}
