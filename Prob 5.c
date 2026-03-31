#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int Sudoku[9][9];

bool unassigned(int i, int j) {
    if (Sudoku[i][j] == 0)
    {
         return true;
    } else
        return false;
}

bool is_safe(int i, int j, int n) {
            int index = (i / 3) * 3 + j / 3;
                for (int i2 = 0; i2 < 9; i2++)
                {
                    if (Sudoku[i2][j] == n)
                        return false;
                }
                    
                for (int j2 = 0; j2 < 9; j2++)
                {
                    if(Sudoku[i][j2] == n)
                        return false;
                }
                for(int i2 = 0; i2 < 3; i2++)
                {
                    for(int j2 = 0; j2 < 3; j2++)
                    {
                        if(Sudoku[i2 + i - (i % 3)][j2 +  j - (j % 3)] == n)
                        {
                            return false;
                        }
                         
                    }
                        
                }
                    
                return true;                 
}

bool solve ()
{
    for(int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (unassigned(i, j) == true)
            {
                for(int n = 1; n <= 9; n++)
                {
                     if(is_safe(i, j, n))
                      {
                        Sudoku[i][j] = n;
                        if (solve() == true)
                        {
                            return true;
                        }
                        Sudoku[i][j] = 0;
                      }  
                }
                return false;
                }
            }
    }  
    return true;
}

int main() {
    printf("Sudoku:\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &Sudoku[i][j]);
        }
    }
    printf("\nSolutie:\n");
    if (solve() == true)
    {
        for (int i = 0; i < 9; i++) 
        {
            for (int j = 0; j < 9; j++) 
                printf("%d ", Sudoku[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("Nu exista solutie");
    }

    return 0;
}
