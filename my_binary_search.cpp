#include "my_binary_search.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
int my_binary_search(int a[],int l,int r,int key){
    int m;
    while(l<=r){
        m=l+(r-l)/2;
        if(a[m]==key)return m;
        if(a[m]<key)l=m+1;
        if(a[m]>key)r=m-1;
    }
    return -1;
}
int my_binary_search_main(){

    //printf("BINARY SEARCH");
    int n=7;
    int arr[]={1,2,3,4,5,6,7};
    cout<<my_binary_search(arr,0,n-1,7);
    getch();
    return 0;


}
