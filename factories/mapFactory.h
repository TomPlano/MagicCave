#include "../products/mapProduct.h"

#ifndef MAP_FACTORY
#define MAP_FACTORY

/*
This class generates the cave like map using celular automata. 1
*/
class MapFactory
{
  public:
    MapFactory(int x, int y);
    ~MapFactory();
    //Iterates through each point in the map matrix and assigns a value to it, either 0 or 1.
    DungeonMap create_map(int = 0);
    void print_map();
    //Prints the map for the user to view
  private:
    //initial population of the map following the 45% rule for walls
    void init_map();
    //Applies the celular automata rules for cave like structure generation
    void itterate_map(bool extra_rule);
    //Allocates space for the map matrix
    bool** alloc_map();
    //Checks if a wall exists before altering its value
    int wall_check(int radius,int x, int y);
    //Sets values of the map matrix to 0
    void clear(bool** grid);
    bool** cellFill;
    bool** buffer;
    int xSize, ySize;
    //unused
    void walls_up();
    void prevent_dc_rooms();
};

#endif
