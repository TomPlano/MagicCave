#include "monsterFactory.h"

MonsterFactory::MonsterFactory()
{
  rng.seed(std::random_device()());

  std::ifstream file("data/monster_data.json");
  file >> root;
}

DungeonMonster MonsterFactory::create_monster(int player_lvl, int player_count)
{
  int desired_xp=(player_count*83.1983)*exp(0.1799999*player_lvl);
  Json::Value::Members all_members = root["count"].getMemberNames();
  Json::Value::Members usable_members;
  for (uint i=0; i < all_members.size(); i++) {
      if(desired_xp>=std::stoi(all_members[i]))
      {
        usable_members.push_back(all_members[i]);
      }
  }
  Json::Value mon; 

  do {
    std::uniform_int_distribution<int> exp_distro(0,usable_members.size()-1);
    std::string exp_level_choice = usable_members[exp_distro(rng)]; //all monsters of a specific xp value
    std::uniform_int_distribution<int> mon_distro(0,root["count"][exp_level_choice].asInt());
    mon = root[exp_level_choice][std::to_string(mon_distro(rng))];
  } while(mon["name"].asString().empty());

    
  DungeonMonster dm (mon["challenge"].asString(),
                      mon["xp"].asString(),
                      mon["alignment"].asString(),
                      mon["type"].asString(),
                      mon["page"].asString(),
                      mon["name"].asString(),
                      mon["size"].asString());
  return dm;
}
