#include "bellman_ford.h"
#include <stdio.h>
#include <conio.h>
#define MAX_SIZE 10
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define INFINITE 10e5

static int N;
static int graph[MAX_SIZE][MAX_SIZE];
static int distance[MAX_SIZE];
static int parent[MAX_SIZE];
bool bellman_ford(int s){
    int i;
    FFOR(i,0,N){parent[i]=-1;distance[i]=INFINITE;}
    distance[s]=0;
    int j,k;
    for(i=1;i<=N-1;i++){
        FFOR(j,0,N){
            FFOR(k,0,N){
                if(graph[j][k]!=0)
                    if(distance[k]>(distance[j]+graph[j][k])){
                            distance[k]=distance[j]+graph[j][k];
                            parent[k]=j;

                    }

            }
        }
    }
    FFOR(j,0,N){
            FFOR(k,0,N){
                if(graph[j][k]!=0)
                    if(distance[k]>(distance[j]+graph[j][k])){
                            return false;

                    }

            }
    }
    return true;


}
int bellman_ford_main(){

    FILE * fin=fopen("bellman_ford.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    FFOR(i,0,N)FFOR(j,0,N)fscanf(fin,"%d",&graph[i][j]);
    bool is_defined=bellman_ford(0);
    getch();
    return 0;

}
/*
#include <stdio.h>
//#include <conio.h>
#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <iostream>
#define MAX_SIZE 1010
#define INFT 99999
#define IS_DEBUG 1
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define RFOR(i,a,b) for(i=a;i>=b;i--)
using namespace std;
int N,E;
//int graph[MAX_SIZE][MAX_SIZE];
int parent[MAX_SIZE];
int dist[MAX_SIZE];
typedef struct edge edge;
struct edge{
    int u;
    int v;
    int w;

}edges[2010];
bool bellman_ford(int s){

    int i,j;
    FFOR(i,0,N){parent[i]=-1;dist[i]=INFT;}
    dist[s]=0;
    FFOR(i,0,N-1){
        FFOR(j,0,E){
            if((dist[edges[j].u]+edges[j].w)<dist[edges[j].v]){
                dist[edges[j].v]=dist[edges[j].u]+edges[j].w;
                parent[edges[j].v]=edges[j].u;
            }

        }
    }
    FFOR(j,0,E){
            if((dist[edges[j].u]+edges[j].w)<dist[edges[j].v]){
                return false;
        }

    }
    return true;

}
int main()
{
    //if(IS_DEBUG)freopen("input.in","r",stdin);
    int T=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&N,&E);
        int i,j;
        //FFOR(i,0,N)FFOR(j,0,N)graph[i][j]=0;
        FFOR(i,0,E){scanf("%d %d %d",&edges[i].u,&edges[i].v,&edges[i].w);}
        //FFOR(i,0,N){FFOR(j,0,N){printf("%d ",graph[i][j]);}printf("\n");}
        //printf("\n");
        if(bellman_ford(0))printf("not possible\n");
        else printf("possible\n");


    }
    //getch();
    return 0;
}

*/
