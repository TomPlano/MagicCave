#include "itemFactory.h"

using namespace rapidjson;

ItemFactory::ItemFactory()
{
  rng.seed(std::random_device()());

  FILE* fp = fopen("data/item_data.json", "r"); // non-Windows use "r"
  // can we catch an error here

  char readBuffer[65536];
  FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  itemset.ParseStream(is);

  assert(itemset.IsObject());
  printf("%s\n",itemset["data"][42]["rarity"].GetString());
  fclose(fp);
}
ItemFactory::~ItemFactory(){}
DungeonItem ItemFactory::create_item(int player_lvl, int value)
{
  printf("%i\n",default_dstro(rng));
  DungeonItem iprod;
  iprod.set_value(value);
  return iprod;
}
