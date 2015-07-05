#include "maximum_bipartite_matching.h"
#include <stdio.h>
#include <conio.h>
#include <string.h>
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define MAX_SIZE 10
// N= applicants
//M jobs
static int N,M;
static int graph[MAX_SIZE][MAX_SIZE];
static int _match[MAX_SIZE];
static bool visited[MAX_SIZE];
static int max_bpm_count;
bool bpm(int u){

    int v;
    FFOR(v,0,N){
        if(graph[u][v] && !visited[v]){
            visited[v]=true;
            if(_match[v]<0||bpm(_match[v])){
                _match[v]=u;
                return true;

            }

        }
    }
    return false;

}
int max_bpm(){

    memset(_match,-1,sizeof(_match));
    max_bpm_count=0;
    int i,j;
    FFOR(i,0,M){
        FFOR(j,0,N)visited[N]=false;
        if(bpm(i))max_bpm_count++;

    }
    return max_bpm_count;
}
int maximum_bipartite_matching_main(){
    freopen("maximum_bipartite_matching.in","r",stdin);
    N=M=6;
    int i,j;
    FFOR(i,0,M){int m=N;scanf("{%d,%d,%d,%d,%d,%d}\n",&graph[i][--m],&graph[i][--m],&graph[i][--m],&graph[i][--m],&graph[i][--m],&graph[i][--m]);}
    //FFOR(i,0,N){FFOR(j,0,N){printf("%d",graph[i][j]);}printf("\n");}
    printf("MAX BPM=%d\n",max_bpm());
    FFOR(i,0,M)printf("%d %d\n",_match[i],i);
    getch();
    return 0;

}
