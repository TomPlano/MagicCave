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

  std::cout<<"xp: "<<desired_xp<<std::endl;

  DungeonMonster dm (1,desired_xp,"","","","","");
  return dm;
}
