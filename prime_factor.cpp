#include "prime_factor.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>
void primeFactors(long long n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }

    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2)
        printf ("%d ", n);
}
int prime_factor_main(){

    //printf("PRIME FACTOR");
    primeFactors(5000000);
    getch();
    return 0;

}
/*
We begin by writing the number as a product of prime factors: n = paqbrc...
then the number of divisors, d(n) = (a+1)(b+1)(c+1)...
*/
