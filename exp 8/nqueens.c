#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Display(int N, int A[N][N])
{
    printf("\n");
    for(int i = 0; i<N; i++)
    {
        printf("-----");
    }
    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("|");
        for (int j = 0; j < N; j++)
        {
            printf(" %d | ", A[i][j]);

        }
        printf("\n");
       for(int k = 0; k<N; k++)
        {
            printf("-----");
        }
        printf("\n");
    }
}

bool isSafe(int N, int board[N][N], int row, int col)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool DFS(int N, int board[N][N], int depth)
{
	if (depth >= N)
	{   
        char ch;
        printf("\nSolution: \n");
        Display(N, board);
        return true;
    }

	for (int i = 0; i < N; i++) {
		if (isSafe(N, board, i, depth)) {
			{
                char ch;
                board[i][depth] = 1;
            }
            if(DFS(N, board, depth + 1))
                return true;
			board[i][depth] = 0;
		}
	}
	return false;
}

bool solveNQ(int N)
{
	int board[N][N];

    for(int i = 0 ; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            board[i][j] = 0;
        }
    }

	if (N == 2 || N == 3) {
		printf("Solution does not exist");
		return false;
	}
    DFS(N,board, 0);
	return true;
}

int main()
{
    int N = 0;
    printf("For chessboard of dimensions n x n\nEnter value of 'n': ");
    scanf("%d", &N);
	solveNQ(N);
	return 0;
}
