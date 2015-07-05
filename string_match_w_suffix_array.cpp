#include "string_match_w_suffix_array.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 20
#define FFOR(i,a,b) for(i=a;i<b;i++)
using namespace std;
char str[MAX_SIZE];
char pat[MAX_SIZE];
int N,M;
typedef struct _suffix suffix;
typedef struct _suffix{
    int indx;
    char* suffix_str;
};
suffix suffixs[MAX_SIZE];
static int comparator(suffix a, suffix b){

    return strcmp(a.suffix_str,b.suffix_str)<0?1:0;

}
void naive_suffix_array(){

    int i;
    FFOR(i,0,N){
        suffixs[i].indx=i;
        suffixs[i].suffix_str=str+i;
    }
    sort(suffixs,suffixs+N,comparator);
    FFOR(i,0,N)cout<<suffixs[i].indx<<" "<<suffixs[i].suffix_str<<endl;
    cout<<endl;
}
static int my_binary_search(){
    int l=0;
    int r=N-1;
    int m;
    while(l<=r){
        m=l+(r-l)/2;
        int res=strncmp(pat,suffixs[m].suffix_str,M);
        if(res==0)return m;
        if(res>0)l=m+1;
        else r=m-1;
    }
    return -1;
}
int string_match_w_suffix_array_main(){

    //printf("Hello Suffix Array");
    freopen("string_match_w_suffix_array.in","r",stdin);
    cin>>str;
    cin>>pat;
    for(N=0;str[N];N++);
    for(M=0;pat[M];M++);
    //cout<<N<<" "<<M<<endl;
    naive_suffix_array();
    int res=my_binary_search();
    if(res>=0)cout<<suffixs[res].suffix_str<<" "<<suffixs[res].indx<<endl;
    getch();
    return 0;

}
