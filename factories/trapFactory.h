#include "../products/trapProduct.h"

#ifndef TRAP_FACTORY
#define TRAP_FACTORY
class TrapFactory
{
  public:
    TrapFactory();
    ~TrapFactory();
    DungeonTrap create_trap();
  private:
    void init();

};

#endif
