#include "bellman_ford.h"
#include <bits/stdc++.h>
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
