#include "itemFactory.h"

using namespace rapidjson;

ItemFactory::ItemFactory()
{
  rng.seed(std::random_device()());

  FILE* fp = fopen("data/test_data.json", "r"); // non-Windows use "r"
  // can we catch an error here

  char readBuffer[65536];
  FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  itemset.ParseStream(is);
  assert(itemset.IsObject());
  fclose(fp);
}
ItemFactory::~ItemFactory(){}
DungeonItem ItemFactory::create_item(int player_lvl, int value)
{
  int result[1]= {default_dstro(rng)};
  printf("%s\n",itemset[result[0]]["1"]["name"].GetString());
  DungeonItem iprod;
  iprod.set_value(value);
  return iprod;
}
