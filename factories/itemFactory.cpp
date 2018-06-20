#include "itemFactory.h"


ItemFactory::ItemFactory()
{
  rng.seed(std::random_device()());

  std::ifstream file("data/item_data.json");
  file >> root;
}
ItemFactory::~ItemFactory(){}
DungeonItem ItemFactory::create_item(int player_lvl, int value)
{


  std::uniform_int_distribution<int> c_distro(0,root["count"]["c"].asInt());
  std::uniform_int_distribution<int> u_distro(0,root["count"]["u"].asInt());
  std::uniform_int_distribution<int> r_distro(0,root["count"]["r"].asInt());
  std::uniform_int_distribution<int> v_distro(0,root["count"]["v"].asInt());
  std::uniform_int_distribution<int> l_distro(0,root["count"]["l"].asInt());


  int int_rarity = default_dstro(rng);
  int item_idx;
  switch (int_rarity) {
    case 0:
      item_idx = c_distro(rng);
      break;
    case 1:
      item_idx = u_distro(rng);
      break;
    case 2:
      item_idx = r_distro(rng);
      break;
    case 3:
      item_idx = v_distro(rng);
      break;
    case 4:
      item_idx = l_distro(rng);
      break;


  }


  std::string str_rarity = std::to_string(int_rarity);
  std::string str_item = std::to_string(item_idx);

  DungeonItem iprod (root[str_rarity][str_item]["attunement"].asString(),
                      root[str_rarity][str_item]["type"].asString(),
                      root[str_rarity][str_item]["page"].asString(),
                      root[str_rarity][str_item]["name"].asString(),
                      root[str_rarity][str_item]["rarity"].asString());
  iprod.set_value(value);
  return iprod;
}
