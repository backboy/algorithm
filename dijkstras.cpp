#include "dijkstras.h"
#include <bits/stdc++.h>
#include "conio.h"
#define INFINITE 10e5
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define MAX_SIZE 10
static int N;
static int graph[MAX_SIZE][MAX_SIZE];
static int distance[MAX_SIZE];
static int spt_status[MAX_SIZE];

int find_min_distance(){
    int i;
    int min_distance=INFINITE,min_distance_vertex=0;
    FFOR(i,0,N){if(spt_status[i]==false && distance[i]<min_distance){min_distance=distance[i];min_distance_vertex=i;}}
    return min_distance_vertex;

}
int print_solution(){
   printf("Vertex   Distance from Source\n");
   int i;
   FFOR(i,0,N)printf("%d \t\t %d\n", i, distance[i]);
}
void dijkstras(int s){

    int i,j;
    FFOR(i,0,N){distance[i]=INFINITE;spt_status[i]=false;}
    distance[s]=0;
    FFOR(i,0,N-1){
        int u=find_min_distance();
        spt_status[u]=true;
        FFOR(j,0,N){

            if(spt_status[j]==false && graph[u][j]!=0 &&distance[j]>(distance[u]+graph[u][j])){
                distance[j]=distance[u]+graph[u][j];
            }

        }

    }
    print_solution();

}
int dijkstras_main(){

    FILE * fin=fopen("dijkstras.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    FFOR(i,0,N)FFOR(j,0,N)fscanf(fin,"%d",&graph[i][j]);
    dijkstras(0);
    /*printf("DIJK%d\n",N);
    FFOR(i,0,N){FFOR(j,0,N){printf("%d ",graph[i][j]);}printf("\n");}*/
    getch();
    return 0;

}
