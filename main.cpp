#include <stdlib.h>
#include "factories/mapFactory.h"

int main (int argc, char* argv[])
{
  MapFactory mfact (atoi(argv[1]),atoi(argv[2]));
  mfact.create_map(atoi(argv[3]));
  mfact.print_map();
  return 0;
}
