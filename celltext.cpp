#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

class MapBuilder
{
  public:
  MapBuilder(int x, int y)
  {
    x_size = x;
    y_size = y;
    map = (int**)malloc(x_size*sizeof(int*));
    for(int i = 0; i < x; i++)
    {
        map[i] = (int*)malloc(x_size*sizeof(int));
    }
  }
  ~MapBuilder()
  {
    for(int i = 0; i < x_size; i++)
    {
        free(map[i]);
    }
    free(map);
  }
  void init_map()
  {
    srand(time(NULL));
    for(int i = 0; i < x_size; i++)
    {
      for(int j = 0; j < y_size; j++)
      {
          map[i][j] = rand()%2;
      }
    }

  }
  void itterate_map()
  {
    for(int i = 1; i < x_size-1; i++)
    {
      for(int j = 1; j < y_size-1; j++)
      {
          if(map[i-1][j-1]+map[i-1][j]+map[i-1][j+1]+map[i][j-1]+map[i][j]+map[i][j+1]+map[i+1][j-1]+map[i+1][j]+map[i+1][j+1]>4)
          {
              map[i][j] = 1;
          }
          else
          {
              map[i][j] = 0;
          }
      }
    }
  }
  void print_map()
  {
    for(int i = 0; i < x_size; i++)
    {
      for(int j = 0; j < y_size; j++)
      {
        printf("%i",map[i][j]);
      }
      printf("\n");
    }
  }
  private:
    int** map;
    int x_size, y_size;
};

int main (int argc, char* argv[])
{
  MapBuilder builder (atoi(argv[1]),atoi(argv[2]));
  builder.init_map();
  for (int i=0; i<atoi(argv[3]); i++)
  {
    builder.itterate_map();
  }
  builder.print_map();
  return 0;
}
