#ifndef MAP_FACTORY
#define MAP_FACOTRY

class MapFactory
{
  public:
  MapFactory(int x, int y);
  ~MapFactory();
  void init_map();
  void itterate_map();
  void print_map();
  private:
    int** map;
    int x_size, y_size;
};

#endif
