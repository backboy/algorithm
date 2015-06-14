#include "maximum_subarray_dividenconquer.h"
#include "stdio.h"
#include "conio.h"
#define MAX_SIZE 20
#define FFOR(i,a,b) for(i=a;i<b;i++)

static int N;
static int A[MAX_SIZE];
int maximum_subarray_dividenconquer_main(){

    FILE* fin=fopen("maximum_subarray_dividenconquer.in","r");
    fscanf(fin,"%d",&N);
    int i;
    FFOR(i,0,N)fscanf(fin,"%d",&A[i]);
    getch();
    return 0;

}
