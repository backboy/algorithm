#include "euclid.h"
#include <stdio.h>
#include <conio.h>
typedef struct extended_euclid_triple{
    int d;
    int x;
    int y;
}extended_euclid_triple;

int euclid(int a,int b){
    if(b==0)return a;
    else return euclid(b,a%b);
}
extended_euclid_triple extended_euclid(int a,int b){

    if(b==0){extended_euclid_triple t;t.d=a;t.x=1;t.y=0; return t;}
    else {
        extended_euclid_triple _t=extended_euclid(b,a%b);
        extended_euclid_triple t;
        t.d=_t.d;
        t.x=_t.y;
        t.y=_t.x-(a/b)*_t.y;
        return t;
    }

}
int euclid_main(){

    euclid(2,8);
    extended_euclid_triple t=extended_euclid(2,8);
    printf("%d %d %d\n",t.d,t.x,t.y);
    getch();
    return 0;
}
