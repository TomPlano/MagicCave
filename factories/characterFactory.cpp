#include "characterFactory.h"

CharacterFactory::CharacterFactory()
{
  rng.seed(std::random_device()());

  std::cout<<"Here\n";
  std::ifstream file1("data/races.json");
  file1 >> race_root;
  std::cout<<"Here1.5\n";

  std::ifstream file2("data/classes.json");
  file2 >> class_root;
  std::cout<<"Here2\n";

}

Character CharacterFactory::create_character()
{
  int num_races = race_root["race"].size()-1;
  std::uniform_int_distribution<int> race_select(0,num_races);

  int num_classes = class_root["class"].size()-1;
  std::uniform_int_distribution<int> class_select(0,num_classes);

  Json::Value char_race = race_root["race"][race_select(rng)];
  Json::Value char_class = class_root["class"][class_select(rng)];

  std::cout<< char_race["name"].asString()<< " "<< char_class["name"].asString()<<std::endl;

    Character ch;
    return ch;
}
