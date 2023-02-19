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

void q_sort(long int n[],int first,long int last){
	int i, j, pivot, temp;
	if(first<last){
		pivot=first;
		i=first;
		j=last;
		while(i<j){
			while(n[i]<=n[pivot]&&i<last)
			i++;
			while(n[j]>n[pivot])
			j--;
			if(i<j){
			    temp=n[i];
			    n[i]=n[j];
			    n[j]=temp;
			 }
		}
		temp=n[pivot];
		n[pivot]=n[j];
		n[j]=temp;
		q_sort(n,first,j-1);
		q_sort(n,j+1,last);
	}
}

void merge(long int arr[], int l, int m, long int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void m_sort(long int arr[], int l, long int r)
{
    if (l < r) {

        int m = l + (r - l) / 2;
 
        m_sort(arr, l, m);
        m_sort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }
}


int main()
{
    rand_int();
    FILE * ptr_int, * ptr_time;
    ptr_time = fopen("times.csv", "w");
    if(!ptr_time)
        return 0;
    fprintf(ptr_time, "Cases, Quick, Merge\n");
    
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
        q_sort(A, 0, i-1);
        end1 = clock();

        start2 = clock();
        m_sort(B, 0, i-1);
        end2 = clock();

        double t1 = (double) (end1 - start1) / CLOCKS_PER_SEC;
        double t2 = (double) (end2 - start2) / CLOCKS_PER_SEC;

        fprintf(ptr_time, "%ld, %f, %f\n", i, t1, t2);

        fclose(ptr_int);
    }
    fclose(ptr_time);
    return 0;
}