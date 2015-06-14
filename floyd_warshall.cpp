#include "floyd_warshall.h"
#include "stdio.h"
#include "conio.h"
#define INFINITE 10e5
#define MAX_SIZE 10
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define MAX( a, b ) ( ( a > b) ? a : b )
#define MIN( a, b ) ( ( a < b) ? a : b )

static int N;
static int graph[MAX_SIZE][MAX_SIZE];
static int distance[MAX_SIZE][MAX_SIZE];
void floyd_warshall(){

    int i,j,k;
    FFOR(i,0,N)FFOR(j,0,N){distance[i][j]=graph[i][j];}
    FFOR(k,0,N)FFOR(i,0,N)FFOR(j,0,N)if(distance[i][j]>distance[i][k]+distance[k][j]){distance[i][j]=distance[i][k]+distance[k][j];}
    FFOR(i,0,N){FFOR(j,0,N){printf("%7d",distance[i][j]);}printf("\n");}
}
int floyd_warshall_main()
{
    FILE * fin=fopen("floyd_warshall.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    FFOR(i,0,N)FFOR(j,0,N)fscanf(fin,"%d",&graph[i][j]);
    //FFOR(i,0,N){FFOR(j,0,N){printf("%d\t",graph[i][j]);}printf("\n");}
    floyd_warshall();
    getch();
    return 0;

}
