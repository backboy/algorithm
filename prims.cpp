#include "prims.h"
#include <stdio.h>
#include <conio.h>
#define INFINITE 10e5
#define MAX_SIZE 10
#define FFOR(i,a,b) for(i=a;i<b;i++)

static int N;
static int graph[MAX_SIZE][MAX_SIZE];
static int parent[MAX_SIZE];
static bool mst_status[MAX_SIZE];
static int key_value[MAX_SIZE];

int find_min_key(){

    int i,min_key=INFINITE,min_index=0;
    FFOR(i,0,N){if(mst_status[i]==false && key_value[i]<min_key){min_key=key_value[i];min_index=i;}}
    return min_index;
}
void print_mst(){
     printf("Edge   Weight\n");
     for (int i = 1; i < N; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);

}
void prims(int s){
    int i,j;
    FFOR(i,0,N){mst_status[i]=false;parent[i]=-1;key_value[i]=INFINITE;}
    parent[s]=-1;
    key_value[s]=0;
    FFOR(i,0,N-1){
        int u=find_min_key();
        mst_status[u]=true;
        FFOR(j,0,N){
            if(mst_status[j]==false&&graph[u][j]!=0&&graph[u][j]<key_value[j]){
                key_value[j]=graph[u][j];parent[j]=u;
            }
        }

    }
    print_mst();

}

int prims_main(){

    FILE * fin=fopen("prims.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    FFOR(i,0,N)FFOR(j,0,N)fscanf(fin,"%d",&graph[i][j]);
    prims(0);
    /*printf("Hello Prims%d\n",N);
    FFOR(i,0,N){FFOR(j,0,N){printf("%d ",graph[i][j]);}printf("\n");}*/
    getch();
    return 0;

}
