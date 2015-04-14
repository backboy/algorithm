#include "bfs.h"
#include "stdio.h"
#include "conio.h"

static int N;
static int graph[10][10];
static int bfs_queue[10];
static int color[10];
static int distance[10];
static int parent[10];
static int white=0,gray=1,black=2;
static int infinite_distance=9999;
static int qhead,qtail;

void enqueue(int x)
{
    bfs_queue[qtail]=x;
    if(qtail==N-1)qtail=0;
    else qtail+=1;
}
int dequeue()
{

    int x=bfs_queue[qhead];
    if(qhead==N-1)qhead=0;
    else qhead+=1;
    return x;


}
void bfs(int s)
{

    int i;
    for(i=0; i<N; i++)if(i!=s){color[i]=white;distance[i]=infinite_distance;parent[i]=-1;}
    color[s]=gray;
    distance[s]=0;
    parent[s]=-1;
    enqueue(s);
    printf("%d ",s);
    while(qhead!=qtail)
    {
        int x=dequeue();
        for(i=0; i<N; i++)if(graph[x][i]==1 && color[i]==white){printf("%d ",i);color[i]=gray;enqueue(i);parent[i]=x;distance[i]=distance[x]+1;}
        color[x]=black;

    }

}
int bfs_main()
{
    FILE* fin=fopen("bfs.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)fscanf(fin,"%d",&graph[i][j]);
    qhead=qtail=0;
    bfs(0);
    getch();
    return 0;
}
