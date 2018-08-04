#ifndef TRAP_PRODUCT
#define TRAP_PRODUCT
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

/*
This class holds all information relating to traps found throughout the map
*/


/*
The action the trap takes when activated
*/
enum effect{
  Falling_Rocks,
  Log_Swing,
  Sleep_Powder,
  Arrows,
  Darts,
  Pit,
  Teleport,
  Magic,
  effect_END
};
/*
How the trap is triggered
*/
enum trigger{
  Preasure_Plate,
  Trip_Wire,
  trigger_END
};
/*
Typical saving throw for the trap
*/
enum counters{
  Perception,
  counters_END
};
/*
Effects the trap might have after contact
*/
enum trap_mods{
  Poison,
  Spiked,
  Flaming,
  One_Way,
  trap_mods_END
};
/*
If the trap is magical this will be the effect
*/
enum magic_eff{
  Missle,
  magic_eff_END
};

class DungeonTrap{
public:
  DungeonTrap();
  std::string print_trap();
  int x_coord,y_coord,radius,x_drop,y_drop;
  static int trap_count;
  int PLACEMENT_ID;
private:
  int level;
  effect get_trap_effect(std::mt19937 rng);
  effect trap_effect;
  magic_eff get_magic_effect(std::mt19937 rng);
  magic_eff magic_trap;
  trigger get_trigger(std::mt19937 rng);
  trigger trap_trigger;
  counters get_countermeasure(std::mt19937 rng);
  counters countermeasures;
  trap_mods get_modifiers(std::mt19937 rng);
  trap_mods mods;
  std::string blocktext;
};

#endif
