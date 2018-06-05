#include <stdlib.h>
#include "factories/mapFactory.h"

int main (int argc, char* argv[])
{
  MapFactory mfact (atoi(argv[1]),atoi(argv[2]));
  mfact.init_map();
  for (int i=0; i<atoi(argv[3]); i++)
  {
    mfact.itterate_map();
  }
  mfact.print_map();
  return 0;
}
