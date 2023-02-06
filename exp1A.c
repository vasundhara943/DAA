#include <stdio.h>
#include <math.h>

float f2(int n)
{
    return pow(n,3);
}

float f3(int n)
{
    return log2(n);
}

float f4(int n)
{
    return log(n);
}

float f5(int n)
{

    return log2(log2(n));
}

float f6(int n)
{
    return log(log(n));
}

float f7(int n)
{
    return log2(n)*log2(n);
}

float f8(int n)
{
    return pow(2, log2(n));
}

float f9(int n)
{
    return sqrt(log2(n));
}

float f10(int n)
{
    return pow(log2(n), log2(n));
}

long long fact(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}

void main()
{
    int i=0;

    printf("\nn\t|n^3\t\t|log2(n)\t|ln(n)\t|log2(log2(n))\t|ln(ln(n))\t|(log2(n))^2\t|2^(log2(n))\t|sqrt(log2(n))\t|(log2(n))^(log2(n))\n");
    //printf("\t|\t\t|\t\t|\t|\t\t|\t\t|\t\t|\t\t|\t\t|\t|\n");

    printf("---------------------------------------------------------------------------------------------------------------------------------------------------");

    for(i=0; i<=100; i+=10)
    {
        printf("\n%d\t",i);

        printf("|%7.0f\t", f2(i)); 

        printf("|%0.2f\t\t", f3(i));

        printf("|%0.2f\t", f4(i));

        printf("|%0.2f\t\t", f5(i));

        printf("|%0.2f\t\t", f6(i));

        printf("|%0.2f\t\t", f7(i));

        printf("|%0.0f\t\t", f8(i));

        printf("|%0.2f\t\t", f9(i));

        printf("|%0.2f", f10(i));
    }

    printf("\n\nn\t|n!");
    printf("\n----------------------------");
    for(i=0; i<=20; i+=2)
    {
        printf("\n%d\t",i);

        printf("|%lld", fact(i)); 
    }
}