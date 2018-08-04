#include "../products/trapProduct.h"

#ifndef TRAP_FACTORY
#define TRAP_FACTORY

/*
This class generates traps for the map
*/

class TrapFactory
{
  public:
    TrapFactory();
    ~TrapFactory();
    //Picks a trap from the list of enums and populates a TrapProduct object with needed information for the trap to work
    DungeonTrap create_trap();
  private:
    void init();

};

#endif
