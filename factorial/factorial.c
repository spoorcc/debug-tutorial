#include <stdio.h>

/* Module forward declaration */ 
long factorial(int n);
 
/* 
Program factorial

Takes integer as commandline input and prints factorial 
*/
int main()
{
    int n = 0;

    scanf("%d", &n);
    long val=factorial(n);
    
    printf("factorial: %ld", val);

    return 0;
}
 
long factorial(int n)
{
    long result = 1;

    while(n--)
    {
        result*=n;
    }
    return result;
}
