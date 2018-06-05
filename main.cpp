#include <stdlib.h>
#include "factories/mapFactory.h"
#include "products/mapProduct.h"

int main (int argc, char* argv[])
{
  MapFactory mfact (atoi(argv[1]),atoi(argv[2]));
  DungeonMap thingy = mfact.create_map(atoi(argv[3]));
  thingy.print_map();
  return 0;
}
