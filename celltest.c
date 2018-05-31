#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_map(int** map, int x, int y);
void itterate_map(int** map, int x, int y);
int main (int argc, char* argv[])
{
int x = atoi(argv[1]);
int y = atoi(argv[2]);
int** map = (int**)malloc(x*sizeof(int*));

for(int i = 0; i < x; i++)
{
    map[i] = (int*)malloc(y*sizeof(int));
}

init_map(map,x,y);
printf("---------------\n");
for (int i=0; i<atoi(argv[3]); i++)
{
printf("---------------\n");
itterate_map(map,x,y);
}
for(int i = 0; i < x; i++)
{
    free(map[i]);
}
free(map);



return 0;
}
void itterate_map(int** map,int x, int y)
{
for(int i = 1; i < x-1; i++)
{
for(int j = 1; j < y-1; j++)
{
    if(map[i-1][j-1]+map[i-1][j]+map[i-1][j+1]+map[i][j-1]+map[i][j]+map[i][j+1]+map[i+1][j-1]+map[i+1][j]+map[i+1][j+1]>4){
        map[i][j] = 1;

    }
    else
    {
        map[i][j] = 0;
    }

    printf("%i",map[i][j]);
}
    printf("\n");
}
}

void init_map(int** map, int x, int y)
{
srand(time(NULL));
for(int i = 0; i < x; i++)
{
for(int j = 0; j < y; j++)
{
    map[i][j] = rand()%2;
    printf("%i",map[i][j]);
}
    printf("\n");
}

}
