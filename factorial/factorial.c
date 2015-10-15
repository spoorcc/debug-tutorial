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

    printf("Provide a number:\n");
    scanf("%d", &n);

    long val=factorial(n);
    
    printf("factorial: %ld\n", val);

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
