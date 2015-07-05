#include "bfs.h"
#include <stdio.h>
#include <queue>
#include "conio.h"
#define MAX_SIZE 10
#define infinite_distance 9999
using namespace std;
static int N;
static int graph[MAX_SIZE][MAX_SIZE];
static queue<int> bfs_queue;
static int color[MAX_SIZE];
static int bfs_distance[MAX_SIZE];
static int parent[MAX_SIZE];
static int white=0,gray=1,black=2;
static int qhead,qtail;




void bfs(int s)
{

    int i;
    for(i=0; i<N; i++)if(i!=s){color[i]=white;bfs_distance[i]=infinite_distance;parent[i]=-1;}
    color[s]=gray;
    bfs_distance[s]=0;
    parent[s]=-1;
    bfs_queue.push(s);
    //enqueue(s);
    //printf("%d ",s);
    while(!bfs_queue.empty())
    {
        int x=bfs_queue.front();
        bfs_queue.pop();
        for(i=0; i<N; i++)if(graph[x][i]==1 && color[i]==white){color[i]=gray;bfs_queue.push(i);parent[i]=x;bfs_distance[i]=bfs_distance[x]+1;}
        color[x]=black;

    }

}
void print_path(int s,int v){
    if(s==v){printf("%d ",s);return;}
    else if(parent[v]==-1){printf("no path from %d to %d",s,v);return;}
    else print_path(s,parent[v]);
    printf("%d ",v);
}
int bfs_main()
{
    FILE* fin=fopen("bfs.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)fscanf(fin,"%d",&graph[i][j]);
    //qhead=qtail=0;
    int s=0;
    bfs(s);
    for(i=0;i<N;i++){printf("%d->",i);print_path(s,i);printf("\n");}
    getch();
    return 0;
}
