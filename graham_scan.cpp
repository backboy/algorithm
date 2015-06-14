#include "graham_scan.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <algorithm>
#include <stack>
#define MAX_SIZE 100
#define FFOR(i,a,b) for(i=a;i<b;i++)

static int N;
struct Point{
    int x;
    int y;
};
typedef struct Point Point;
Point points[MAX_SIZE];
Point P0;
using namespace std;

Point next_to_top(stack<Point>S){

    Point p=S.top();
    S.pop();
    Point temp=S.top();
    S.push(p);
    return temp;
}
int dist(Point p1,Point p2){

    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int orientation(Point p,Point q,Point r){
    int val=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);//positive mean counter clockwise
    if(val==0)return val;
    return val<0?1:2;//1--clockwise
}

int comparator(const void* vp1,const void* vp2){
    Point *p1=(Point*)vp1;
    Point *p2=(Point*)vp2;
    int o=orientation(P0,*p1,*p2);
    if(o==0)return (dist(P0,*p1)<=dist(P0,*p2)?-1:1);
    return (o==2)?-1:1;
}
int swap_points(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
void graham_scan(){

    int y_min=points[0].y,min_index=0;
    int i;
    FFOR(i,1,N){
        if(points[i].y<y_min){y_min=points[i].y;min_index=i;}
        else if(points[i].y==y_min && points[i].x<points[min_index].x){y_min=points[i].y;min_index=i;}
    }
    swap_points(points[0],points[min_index]);
    P0=points[0];
    qsort(&points[1],N-1,sizeof(Point),comparator);
    stack<Point>S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    FFOR(i,3,N){
        while(orientation(next_to_top(S),S.top(),points[i])!=2)S.pop();
        S.push(points[i]);
    }
    while(!S.empty()){
        Point t=S.top();
        printf("(%d,%d)\n",t.x,t.y);
        S.pop();
    }

}
int graham_scan_main(){

    freopen("graham_scan.in","r",stdin);
    string s;getline(cin,s);
    sscanf(s.c_str(),"%d\n",&N);
    //printf("%d\n",N);
    int i;
    FFOR(i,0,N){
        getline(cin,s);
        sscanf(s.c_str(),"{%d,%d}",&points[i].x,&points[i].y);
    }
    //FFOR(i,0,N){printf("{%d,%d}\n",points[i].x,points[i].y);}
    //printf("\n");
    graham_scan();
    //FFOR(i,0,N){printf("{%d,%d}\n",points[i].x,points[i].y);}
    getch();
    return 0;

}
