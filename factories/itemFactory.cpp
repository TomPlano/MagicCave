#include "itemFactory.h"

using namespace rapidjson;

ItemFactory::ItemFactory()
{
  FILE* fp = fopen("data/item_data.json", "r"); // non-Windows use "r"
  // can we catch an error here

  char readBuffer[65536];
  FileReadStream is(fp, readBuffer, sizeof(readBuffer));
  itemset.ParseStream(is);

  assert(itemset.IsObject());
  assert(itemset.HasMember("Apparatus of Kwalish"));
  printf("hello = %s\n", itemset[1]["page"].GetString());
  fclose(fp);
}
ItemFactory::~ItemFactory(){}
DungeonItem ItemFactory::create_item(int player_lvl, int value)
{

  DungeonItem iprod;
  iprod.set_value(value);
  return iprod;
}
