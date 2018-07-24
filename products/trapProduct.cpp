#include "trapProduct.h"
int DungeonTrap::trap_count=0;

//public
DungeonTrap::DungeonTrap()
{
  std::mt19937 rng;
  rng.seed(std::random_device()());

  trap_effect = get_trap_effect(rng);
  trap_trigger = get_trigger(rng);
  countermeasures = get_countermeasure(rng);
  mods = get_modifiers(rng);

  switch (trap_effect) {
/*    case  Falling_Rocks:
      break;
    case  Log_Swing:
      break;
    case  Sleep_Powder:
     break;
    case  Arrows:
     break;
    case  Darts:
     break;
    case  Pit:
     break;
    case  Teleport:
     break;*/
    case  Magic:
     magic_trap = get_magic_effect(rng);
     break;
     default:
      break;
  }

  trap_count++;
}
std::string DungeonTrap::print_trap()
{
    std::string result = "";
    char id = PLACEMENT_ID;
    std::string monsterInfo = "";
    monsterInfo += "["+std::string(1,id)+"] ";

    switch (trap_effect) {
        case  Falling_Rocks:
            monsterInfo += "Falling_Rocks\n";
            break;
        case Log_Swing:
            monsterInfo += "Log_Swing\n";
            break;
        case Sleep_Powder:
            monsterInfo += "Sleep_Powder\n";
            break;
        case Arrows:
            monsterInfo += "Arrows\n";
            break;
        case Darts:
            monsterInfo += "Darts\n";
            break;
        case Pit:
            monsterInfo += "Pit\n";
            break;
        case Teleport:
            monsterInfo += "Teleport\n";
            break;
        case Magic:
            monsterInfo += "Magic\n";
            switch (magic_trap) {
                case Missle:
                    monsterInfo += "Missle\n";
                    break;
                }
            break;
    }

    switch (trap_trigger) {
        case Preasure_Plate:
            monsterInfo += "Preasure plate\n";
            break;
        case Trip_Wire:
            monsterInfo += "Trip wire\n";
            break;
    }

    switch (countermeasures) {
        case Perception:
            monsterInfo += "Perception\n"; 
            break;
    }

    switch (mods) {
        case Poison:
            monsterInfo += "Poison\n"; 
            break;
        case Spiked:
            monsterInfo += "Spikes\n"; 
            break;
        case Flaming:
            monsterInfo += "Flames\n"; 
            break;
        case One_Way:
            monsterInfo += "One way\n"; 
            break;
    }

    return monsterInfo;

}

//private
effect DungeonTrap::get_trap_effect(std::mt19937 rng)
{
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,effect_END-1);
  return (effect)uni_dist(rng);
}
magic_eff DungeonTrap::get_magic_effect(std::mt19937 rng)
{
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,magic_eff_END-1);
  return (magic_eff)uni_dist(rng);
}
trigger DungeonTrap::get_trigger(std::mt19937 rng)
{
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,trigger_END-1);
  return (trigger)uni_dist(rng);
}
counters DungeonTrap::get_countermeasure(std::mt19937 rng)
{
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,counters_END-1);
  return (counters)uni_dist(rng);
}
trap_mods DungeonTrap::get_modifiers(std::mt19937 rng)
{
  std::uniform_int_distribution<std::mt19937::result_type> uni_dist(0,trap_mods_END-1);
  return (trap_mods)uni_dist(rng);
}
