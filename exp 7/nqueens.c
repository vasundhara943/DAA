#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void Display(int N, char A[N][N])
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
            printf(" %c | ", A[i][j]);

        }
        printf("\n");
       for(int k = 0; k<N; k++)
        {
            printf("-----");
        }
        printf("\n");
    }
}

bool isSafe(int N, char board[N][N], int row, int col)
{
	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i] == 'Q')
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j] == 'Q')
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j] == 'Q')
			return false;

	return true;
}

bool DFS(int N, char board[N][N], int depth)
{
	if (depth >= N)
	{   
        printf("\nSolution: \n");
        Display(N, board);
        return true;
    }

	for (int i = 0; i < N; i++) {
		if (isSafe(N, board, i, depth)) {
			{
                char ch;
                board[i][depth] = 'Q';
            }
            if(DFS(N, board, depth + 1))
                return true;
			board[i][depth] = ' ';
		}
	}
	return false;
}

bool solveNQ(int N)
{
	char board[N][N];

    for(int i = 0 ; i<N; i++)
    {
        for(int j = 0; j<N; j++)
        {
            board[i][j] = ' ';
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
