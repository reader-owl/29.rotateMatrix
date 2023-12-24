#include <iostream>

/*
                        Q. rotate Matrix by 90 degrees / rotate image

                    explanation - we will be given a n*n matrix and we have to rotate it by 90 degrees in clockwise direction

                                    1   2   3   4           13   9   5   1
                                    5   6   7   8    ->     14  10   6   2
                                    9  10  11  12           15  11   7   3
                                   13  14  15  16           16  12   8   4

                                first row goes to the last column, second row goes to the second last column
                                third row goes to the third last column, last row goes to the forth last column(first column)

                                by above we can observe that 
                                        goes to                 goes to
                                    [0][0] -> [0][3]        [1][0] -> [0][2]
                                    [0][1] -> [1][3]        [1][1] -> [1][2]
                                    [0][2] -> [2][3]        [1][2] -> [2][2]
                                    [0][3] -> [3][3]        [1][3] -> [3][0]
                                    [i][j]    [j][(n-1)-i]  [i][j]    [j][(n-1)-i]

                                by above transverse we can say that the original [j] is equals to mapped [j]

                                                                    and original [i] is equals to mapped column
                                                            which is,  if n = 4
                                                                        0 -> 3                  1 -> 2
                                                                        i -> (n - 1) - i        i -> (n - 1) - i
                                                            we can say that  i -> (n - 1) - i

        pseudo code
ans[n][n]
for(i=0->n)
{
    for(j=0->n)
    {
        ans[j][(n-1) - i] = matrix[i][j]
    }
}

                TC - O(N^2)
                SC - O(N^2)


                Optimal sol -  by above both matrix we can observe that the first colmn [1  5  9  13] is in the first row but in 
                                the reversed order [13  9  5  1]
                            in other words we have to transpose the matrix, means column becomes row and row becomes column

                            1   2   3   4                   1   5   9  13
                            5   6   7   8   -transpose->    2   6  10  14
                            9  10  11  12                   3   7  11  15
                           13  14  15  16                   4   8  12  16

                           we can see that 1st row is 1st column, and 1st column is 1st row
                           now we have to reverse every row in transposed matrix

                           by comparing original and transposed we can observe that the diagonal elements remains same [1  6  11  16]
                           we can also see that '2 & 5' exchange places, same goes for '3 & 9', '7 & 10', '4 & 13', '8 & 14', '12 & 15'
                            we an write their position - 
                                                            [0][1]  ->  [1][0]
                                                            [0][2]  ->  [2][0]
                                                            [0][3]  ->  [3][0]
                                                            [1][2]  ->  [2][1]
                                                            [1][3]  ->  [3][1]
                                                            [2][3]  ->  [3][2]

                                for '0' we goes '1' to '3', for '1' we goes '2' to '3', for '2' we goes till '3'
                                in other words,  0 -> (1 to 3)
                                                      'i+1' to 'n-1'
                                            for(i=0->n-2)
                                            
        pseudo code
// transposing matrix
for(i=0->n-2)
{
    for(j=i+1->n-1)
    {
        swap(a[i][j], a[j][i]);
    }
}


        Actual code
void rotateMatrix(vector<vector<int>> &mat)
{
    int n = mat.size();
    // transpose                                // O(n/2 + n/2)
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // reverse                                  // O(n + n/2)
    for(int i = 0; i < n; i++)
    {
        // row is mat[i]
        reverse(mat[i].begin(), mat[i].end());
    }
}

*/

int main()
{
    std::cout << "Hello World!\n";
}