#include "strongly_connected_component.h"

#include "stdio.h"
#include "conio.h"

static int N;
static int graph[10][10];
static int color[10];
static int parent[10];
static int time_stamp[10][2];
static int white=0,gray=1,black=2;
static int time;
static int dfs_stack[10];
static int stack_ptr=0;
static char char_arry[8]={'A','B','C','D','E','F','G','H'};
static void stack_push(int u)
{
    dfs_stack[stack_ptr++]=u;
}
static void dfs_visit(int);
static void dfs()
{
    int i;
    for(i=0; i<N; i++)
    {
        color[i]=white;
        parent[i]=-1;
        time_stamp[i][0]=time_stamp[i][1]=0;
    }
    time=0;
    for(i=0; i<N; i++)
    {
        if(color[i]==white){
             dfs_visit(i);
             //printf("\n");
        }

    }

}
static void dfs_visit(int u)
{

    time_stamp[u][0]=++time;
    color[u]=gray;
    int i;
    for(i=0; i<N; i++)
    {
        if(graph[u][i]==1 && color[i]==white)
        {
            parent[i]=u;
            dfs_visit(i);
        }
    }
    //printf("%c ",char_arry[u]);
    stack_push(u);
    time_stamp[u][1]=++time;
    color[u]=black;

}
static void graph_transpose()
{

    int temp_graph[10][10];
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)temp_graph[i][j]=0;
    for(i=0; i<N; i++)for(j=0; j<N; j++){if(graph[i][j]==1)temp_graph[j][i]=1;}
    for(i=0; i<N; i++)for(j=0; j<N; j++)graph[i][j]=temp_graph[i][j];
    //for(i=0; i<N; i++){for(j=0; j<N; j++){printf("%d ",graph[i][j]);}printf("\n");}


}
static void dfs_t_visit(int u)
{

    time_stamp[u][0]=++time;
    color[u]=gray;
    int i;
    for(i=0; i<N; i++)
    {
        if(graph[u][i]==1 && color[i]==white)
        {
            parent[i]=u;
            dfs_t_visit(i);
        }
    }
    printf("%c ",char_arry[u]);
    time_stamp[u][1]=++time;
    color[u]=black;

}

static void dfs_t()
{
    int i;
    for(i=0; i<N; i++)
    {
        color[i]=white;
        parent[i]=-1;
        time_stamp[i][0]=time_stamp[i][1]=0;
    }
    time=0;

    for(i=stack_ptr-1; i>=0; i--)
    {
        int vtx=dfs_stack[i];

        if(color[vtx]==white){

                dfs_t_visit(vtx);
                 printf("\n");


        }

    }

}
int strongly_connected_component()
{
    FILE* fin=fopen("strongly_connected_component.in","r");
    fscanf(fin,"%d",&N);
    int i,j;
    for(i=0; i<N; i++)for(j=0; j<N; j++)fscanf(fin,"%d",&graph[i][j]);
    dfs();
    graph_transpose();
    dfs_t();
    getch();
    return 0;
}
