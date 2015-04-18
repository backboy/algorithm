#include "topological_sort.h"
#include "stdio.h"
#include "conio.h"

static int N;
static int graph[10][10];
static int color[10];
static int parent[10];
static int time_stamp[10][2];
static int white=0,gray=1,black=2;
static int time;
static void dfs_visit(int);
static void dfs(){
    int i;
    for(i=0;i<N;i++){color[i]=white;parent[i]=-1;time_stamp[i][0]=time_stamp[i][1]=0;}
    time=0;
    for(i=0;i<N;i++){
            if(color[i]==white)
                dfs_visit(i);
    }

}
static void dfs_visit(int u){

    time_stamp[u][0]=++time;
    color[u]=gray;
    int i;
    for(i=0;i<N;i++){if(graph[u][i]==1 && color[i]==white){parent[i]=u;dfs_visit(i);}}
    printf("%d ",u);
    time_stamp[u][1]=++time;
    color[u]=black;

}
int topological_sort_main()
{
    FILE* fin=fopen("topological_sort.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)fscanf(fin,"%d",&graph[i][j]);
    dfs();
    /*for(i=0; i<N; i++){
            printf("%d->",i);
            for(j=0; j<2; j++){
                    printf("%d ",time_stamp[i][j]);
                    }
            printf("%\n");
    }*/
    getch();
    return 0;
}

