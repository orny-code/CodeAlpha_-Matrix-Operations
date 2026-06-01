#include <stdio.h>


void inputMatrix(int row, int col, int matrix[row][col])
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            while(1)
            {
                printf("Enter element [%d][%d]: ", i, j);

                if(scanf("%d", &matrix[i][j]) == 1)
                {
                    break;
                }

                printf("Sorry! Numbers only.\n");

                while(getchar() != '\n');
            }
        }
    }
}

void displayMatrix(int row, int col, int matrix[row][col])
{
    int i, j;

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int row, int col,
               int A[row][col],
               int B[row][col])
{
    int i, j, sum[row][col];

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("\nAddition Matrix:\n");
    displayMatrix(row, col, sum);
}

void multiplyMatrix(int r1, int c1, int c2,
                    int A[r1][c1],
                    int B[c1][c2])
{
    int i, j, k;
    int mul[r1][c2];

    for(i = 0; i < r1; i++)
    {
        for(j = 0; j < c2; j++)
        {
            mul[i][j] = 0;

            for(k = 0; k < c1; k++)
            {
                mul[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMultiplication Matrix:\n");
    displayMatrix(r1, c2, mul);
}


void transposeMatrix(int row, int col,
                     int matrix[row][col])
{
    int i, j;
    int transpose[col][row];

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }

    for(i = 0; i < col; i++)
    {
        for(j = 0; j < row; j++)
        {
            printf("%d\t", transpose[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int r1, c1, r2, c2;


    while(1)
    {
        printf("Enter rows and columns of First Matrix: ");

        if(scanf("%d %d", &r1, &c1) == 2)
        {
            if(r1 > 0 && c1 > 0)
                break;

            printf("Sorry! Rows and columns must be greater than 0.\n");
        }
        else
        {
            printf("Sorry! Enter numbers only.\n");
        }

        while(getchar() != '\n');
    }

    int A[r1][c1];

    printf("\nEnter elements of First Matrix:\n");
    inputMatrix(r1, c1, A);


    while(1)
    {
        printf("\nEnter rows and columns of Second Matrix: ");

        if(scanf("%d %d", &r2, &c2) == 2)
        {
            if(r2 > 0 && c2 > 0)
                break;

            printf("Sorry! Rows and columns must be greater than 0.\n");
        }
        else
        {
            printf("Sorry! Enter numbers only.\n");
        }

        while(getchar() != '\n');
    }

    int B[r2][c2];

    printf("\nEnter elements of Second Matrix:\n");
    inputMatrix(r2, c2, B);


    printf("\nFirst Matrix:\n");
    displayMatrix(r1, c1, A);

    printf("\nSecond Matrix:\n");
    displayMatrix(r2, c2, B);

    if(r1 == r2 && c1 == c2)
    {
        addMatrix(r1, c1, A, B);
    }
    else
    {
        printf("\nMatrix Addition not possible!\n");
    }

    if(c1 == r2)
    {
        multiplyMatrix(r1, c1, c2, A, B);
    }
    else
    {
        printf("\nMatrix Multiplication not possible!\n");
    }


    printf("\nTranspose of First Matrix:\n");
    transposeMatrix(r1, c1, A);

    printf("\nTranspose of Second Matrix:\n");
    transposeMatrix(r2, c2, B);

    return 0;
}
