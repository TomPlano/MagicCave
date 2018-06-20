#include "itemFactory.h"


ItemFactory::ItemFactory()
{
  rng.seed(std::random_device()());

  std::ifstream file("data/test_data.json");
  file >> root;
  // can we catch an error here?
}
ItemFactory::~ItemFactory(){}
DungeonItem ItemFactory::create_item(int player_lvl, int value)
{
  std::string rarity = std::to_string(default_dstro(rng));
  std::cout<<root[rarity]["0"]["name"].asString()<<std::endl;
  DungeonItem iprod;
  iprod.set_value(value);
  return iprod;
}
