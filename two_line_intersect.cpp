#include "two_line_intersect.h"
#include <stdio.h>
#include <conio.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct Point
{
    double x;
    double y;
};
typedef struct Point Point;
bool on_segment(Point Pi,Point Pj,Point Pk){

    if(Pk.x>=min(Pi.x,Pj.x) && Pk.x<=max(Pi.x,Pj.x) && Pk.y>=min(Pi.y,Pj.y) && Pk.y>=min(Pi.y,Pj.y))return true;
    return false;

}
int directions(Point Pi,Point Pj,Point Pk){

    double x=(Pj.x-Pi.x)*(Pk.y-Pi.y)-(Pk.x-Pi.x)*(Pj.y-Pi.y);
    if(x==0.0)return 0;
    return x>0.0?1:2;
}
bool do_intersect(Point p1,Point p2,Point p3,Point p4){

    int d1=directions(p1,p2,p3);
    int d2=directions(p1,p2,p4);
    int d3=directions(p3,p4,p1);
    int d4=directions(p3,p4,p2);
    if (d1 != d2 && d3 != d4)return true;
    else if(d1==0 && on_segment(p1,p2,p3))return true;
    else if(d2==0 && on_segment(p1,p2,p4))return true;
    else if(d3==0 && on_segment(p3,p4,p1))return true;
    else if(d3==0 && on_segment(p3,p4,p2))return true;

    return false;
}
int two_line_intersect_main(){

    Point p1 = {1, 1}, p2 = {10, 1};
    Point p3 = {2, 2}, p4 = {10, 0};
    do_intersect(p1, p2, p3, p4)? cout << "Yes\n": cout << "No\n";
    p1 = {1, 1}, p2 = {10, 1};
    p3 = {1, 2}, p4 = {10, 2};
    do_intersect(p1, p2, p3, p4)? cout << "Yes\n": cout << "No\n";
    p1 = {-5, -5}, p2 = {0, 0};
    p3 = {1, 1}, p4 = {10, 10};
    do_intersect(p1, p2, p3, p4)? cout << "Yes\n": cout << "No\n";
    getch();
    return 0;
}
