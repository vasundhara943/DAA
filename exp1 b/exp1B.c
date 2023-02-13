#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rand_int()
{
    int num1, num2;
    long num;
    FILE *ptr;
    ptr = fopen("int.txt", "w");

    srand( time(0));

    for (long i = 0; i < 100000; i++)
    {
        num1 = rand();
        num2 = rand();

        num = num1 * 10 + num2;

        fprintf(ptr,"%ld\n",num);
    }
    fclose(ptr);
}

void in_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void sel_sort(long * A, long n)
{
    for(int i = 0; i<n; i++)
    {
        int min = A[i];
        int pos = i;
        int temp;
        for(int j = i; j<n; j++)
        {
            if(A[j]<min)
            {
                min = A[j];
                pos = j;
            }
        }
        temp = A[i];
        A[i] = min;
        A[pos] = temp;
    }
}

int main()
{
    rand_int();
    FILE * ptr_int, * ptr_time;
    ptr_time = fopen("times.csv", "w");
    if(!ptr_time)
        return 0;
    fprintf(ptr_time, "Cases, Selection, Insertion\n");
    
    for(long int i = 100; i<=100000; i+=100)
    {
        ptr_int = fopen("int.txt", "r");
        long int A[i], B[i];
        clock_t start1, end1, start2, end2;
        if(i % 1000 == 0)
        {
            printf("i = %ld.\n", i);
        }

        for(long int j = 0; j<i; j++)
        {
            fscanf(ptr_int, "%d\n", &A[j]);
            B[j] = A[j];
        }

        start1 = clock();
        sel_sort(A, i);
        end1 = clock();

        start2 = clock();
        in_sort(B, i);
        end2 = clock();

        double t1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
        double t2 = (double) (end2 - start2) / CLOCKS_PER_SEC;

        fprintf(ptr_time, "%ld, %f, %f\n", i, t1, t2);

        fclose(ptr_int);
    }
    fclose(ptr_time);
    return 0;
}