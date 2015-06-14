#include "minimum_cut.h"
#include <bits/stdc++.h>
#include <conio.h>
#define MAX_SIZE 10
#define FFOR(i,a,b) for(i=a;i<b;i++)
static int graph[MAX_SIZE][MAX_SIZE];
static int rgraph[MAX_SIZE][MAX_SIZE];
static int N;

using namespace std;
bool bfs_visit(int s,int t,int parent[]){
    bool visited[N];
    memset(visited,false,sizeof(visited));
    queue<int>bfs_q;
    visited[s]=true;
    parent[s]=-1;
    bfs_q.push(s);
    while(!bfs_q.empty()){
        int u=bfs_q.front();
        bfs_q.pop();
        int v;
        FFOR(v,0,N){if(visited[v]==false && rgraph[u][v]>0){visited[v]=true;parent[v]=u;bfs_q.push(v);}}
    }
    return (visited[t]==true);

}
void dfs_visit(int s,int visited[]){
    visited[s]=true;
    int v;
    FFOR(v,0,N) {if(visited[v]==false && rgraph[s][v]>0)dfs_visit(v,visited);}
}
void min_cut(int s,int t){

    int i,j;
    FFOR(i,0,N)FFOR(j,0,N)rgraph[i][j]=graph[i][j];
    int parent[N];
    memset(parent,-1,sizeof(parent));
    int min_cut_val=0;
    while(bfs_visit(s,t,parent)){
        int path_flow=INT_MAX;
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
        min_cut_val+=path_flow;

    }
    int visited[N];
    memset(visited,false,sizeof(visited));
    dfs_visit(s,visited);
    FFOR(i,0,N)FFOR(j,0,N)if(visited[i] && !visited[j] && graph[i][j]>0)printf("%d-%d\n",i,j);
    //printf("minimum cut=%d",min_cut_val);

}
int minimum_cut_main(){

    freopen("ford_fulkerson.in","r",stdin);
    scanf("%d",&N);
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)scanf("%d",&graph[i][j]);
    min_cut(0,5);
    //for(i=0; i<N; i++){for(j=0; j<N; j++){printf("%d ",graph[i][j]);}printf("\n");}
    getch();
    return 0;
}
