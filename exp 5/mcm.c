#include <limits.h>
#include <stdio.h>

void brac(int i, int j, int n, int* bracket, char * name)
{
    // If only one matrix left in current segment
    if (i == j) {
        printf("%c",(*name));
        (*name)++;
        return;
    }
 
    printf("(");
 
    // Recursively put brackets around subexpression from i to bracket[i][j].
    // "*((bracket+i*n)+j)" is similar to bracket[i][j]
    
    brac(i, *((bracket + i * n) + j), n, bracket, name);
 
    // Recursively put brackets around subexpression from bracket[i][j] + 1 to j.
    brac(*((bracket + i * n) + j) + 1, j, n, bracket, name);
    printf(")");
}

void MCM(int ord[], int size)
{
    int m[size][size], s[size][size];
    int k, l;
	int count;

    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for(int i = 2; i<size; i++)
    {
        for(int j = 1; j<size-i+1; j++)
        {
            l = i+j-1;
            m[j][l]= INT_MAX;
            for(int k = j;  k<=l-1; k++)
            {
                count = m[j][k] + m[k+1][l] + ord[j-1]*ord[k]*ord[l];

                if(count < m[j][l])
                {
                    m[j][l] = count;
                    s[j][l] = k;
                }
            }
        }
    }

    for(int i=1; i<size; i++)
    {
        for(int j = 1; j<size; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(int i=1; i<size; i++)
    {
        for(int j = 1; j<size; j++)
        {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOrder of multiplication: ");   
    char name = 'A';
    brac(1, size - 1, size, (int*)s, &name);
    printf("\n\n");
    printf("Min no. of multiplications: %d ", m[1][size-1]);
}

int main()
{
    int n, temo;
    printf("Enter no. of matrices: ");
    scanf("%d", &n);

    int ord[n+1];
    
    printf("Enter order (m n) of matrix 1: ");
    scanf("%d%d", &ord[0], &ord[1]);

    for(int i = 1; i<n; i++)
    {
        printf("Enter order (m n) of matrix %d: ", i+1);
        scanf("%d%d", &temo, &ord[i+1]);
        if(temo != ord[i])
        {
            printf("Order does not match. Matrices cannot be multiplied. Re-enter.\n");
            i--;
        }
    }

    for(int i=0; i<=n; i++)
    {
        printf("%d  ", ord[i]);
    }
    printf("\n\n");

    MCM(ord, n+1);

}
