#include "ford_fulkerson.h"
#include <bits/stdc++.h>
#include <conio.h>
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define MAX_SIZE 10
static int N;
static int graph[MAX_SIZE][MAX_SIZE];
static int rgraph[MAX_SIZE][MAX_SIZE];
using namespace std;
static bool bfs(int s,int t,int parent[]){

    bool visited[MAX_SIZE];
    memset(visited,0,sizeof(visited));
    queue<int> bfs_queue;
    visited[s]=true;
    parent[s]=-1;
    bfs_queue.push(s);
    while(!bfs_queue.empty()){
        int u=bfs_queue.front();
        bfs_queue.pop();
        int v;
        FFOR(v,0,N){if(visited[v]==false && rgraph[u][v]>0){bfs_queue.push(v);parent[v]=u;visited[v]=true;}}
    }
    return (visited[t]==true);

}
int ford_fulkerson(int s,int t){

    int i,j;
    FFOR(i,0,N)FFOR(j,0,N)rgraph[i][j]=graph[i][j];
    int parent[N];
    memset(parent,-1,sizeof(parent));
    int max_flow=0;
    while(bfs(s,t,parent)){

        int path_flow = INT_MAX;
        int v;
        for(v=t;v!=s;v=parent[v]){
            int u=parent[v];
            path_flow=min(path_flow,rgraph[u][v]);
        }
        for(v=t;v!=s;v=parent[v]){
            int u=parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;

        }
        max_flow+=path_flow;

    }
    return max_flow;

}
int ford_fulkerson_main(){

    //printf("FORD FULKERSON");
    freopen("ford_fulkerson.in","r",stdin);
    scanf("%d",&N);
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)scanf("%d",&graph[i][j]);
    printf("The maximum possible flow is %d\n",ford_fulkerson(0,5));
    //for(i=0; i<N; i++){for(j=0; j<N; j++){printf("%d ",graph[i][j]);}printf("\n");}
    getch();
    return 0;

}
