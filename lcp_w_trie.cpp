#include "lcp_w_trie.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define ALPH_SIZE 26
#define MAX_WORD_SIZE 8
#define FFOR(i,a,b) for(i=a;i<b;i++)
#define CHAR_TO_INDEX(c) ((int)c-(int)'a')
#define INDEX_TO_CHAR(c) ('a'+c)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
using namespace std;
typedef struct trie_node_structure trie_node_s;
typedef struct trie_structure trie_s;
struct trie_node_structure{
    int val;
    int child_cnt;
    bool is_visited;
    trie_node_s* child[ALPH_SIZE];

};
struct trie_structure{
    int cnt;
    trie_node_s* root;

};
trie_s trie;
int current_lcp;
int current_index;
int max_lcp;
int max_lcp_index;
char lcp_array[ALPH_SIZE][MAX_WORD_SIZE];
trie_node_s* create_new_node(){
    trie_node_s* p_crawl=NULL;
    p_crawl=(trie_node_s*)malloc(sizeof(trie_node_s));
    if(p_crawl){
        p_crawl->val=0;
        p_crawl->child_cnt=0;
        p_crawl->is_visited=false;
        int i;
        FFOR(i,0,ALPH_SIZE)p_crawl->child[i]=NULL;
        return p_crawl;
    }
    return NULL;
}
void insert_key(char key[]){

    trie_node_s* p_crawl=trie.root;
    trie.cnt++;
    int len;
    for(len=0;key[len];len++);
    int i;
    FFOR(i,0,len){
        int indx=CHAR_TO_INDEX(key[i]);
        if(!p_crawl->child[indx]){p_crawl->child[indx]=create_new_node();p_crawl->child_cnt++;}
        p_crawl=p_crawl->child[indx];
    }
    p_crawl->val=trie.cnt;

}
void bfs_visit(trie_node_s* p_crawl){
    p_crawl->is_visited=true;
    current_lcp++;
    if(p_crawl->child_cnt==0){current_lcp=0;return;}
    if(p_crawl->child_cnt>1)return;
    int i;
    FFOR(i,0,ALPH_SIZE){
        if(p_crawl->child[i] && p_crawl->child[i]->is_visited==false){
                //printf("%c->",INDEX_TO_CHAR(i));
                lcp_array[current_index][current_lcp]=INDEX_TO_CHAR(i);
                bfs_visit(p_crawl->child[i]);
        }
    }

}
void bfs(){
    max_lcp=-1;
    max_lcp_index=-1;
    int i,j;
    FFOR(i,0,ALPH_SIZE)FFOR(j,0,MAX_WORD_SIZE)lcp_array[i][j]='\0';
    trie_node_s* p_crawl=trie.root;
    FFOR(i,0,ALPH_SIZE)if(p_crawl->child[i])p_crawl->child[i]->is_visited=false;
    FFOR(i,0,ALPH_SIZE){
        if(p_crawl->child[i] && p_crawl->child[i]->is_visited==false){
                current_lcp=0;
                current_index=i;
                //printf("%c->",INDEX_TO_CHAR(i));
                lcp_array[current_index][current_lcp]=INDEX_TO_CHAR(i);
                bfs_visit(p_crawl->child[i]);
                //cout<<endl;
                if(max_lcp<current_lcp){max_lcp=current_lcp;max_lcp_index=i;}
        }

    }
}
void print_lcp(){

    int i;
    for(i=0;lcp_array[max_lcp_index][i];i++)cout<<lcp_array[max_lcp_index][i];

}
int lcp_w_trie_main(){

    trie.root=create_new_node();
    trie.cnt=0;
    char keys[][MAX_WORD_SIZE]={"ther", "a", "there", "answer", "any", "by", "bye", "therir"};
    int i;
    FFOR(i,0,ARRAY_SIZE(keys))insert_key(keys[i]);
    bfs();
    print_lcp();
    getch();
    return 0;

}
