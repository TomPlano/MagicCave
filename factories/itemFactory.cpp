#include "itemFactory.h"


ItemFactory::ItemFactory()
{
  rng.seed(std::random_device()());

  FILE* fp = fopen("data/test_data.json", "r"); // non-Windows use "r"
  // can we catch an error here?
  fclose(fp);
}
ItemFactory::~ItemFactory(){}
DungeonItem ItemFactory::create_item(int player_lvl, int value)
{
  int rarity = default_dstro(rng);
  DungeonItem iprod;
  iprod.set_value(value);
  return iprod;
}
