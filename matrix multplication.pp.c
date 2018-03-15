#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define N 8


void multiply(dd mat1[][N], dd mat2[][N], dd res[][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < N; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
}

void getCofactor(dd A[N][N],dd temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
dd determinant(dd A[N][N], int n)
{
    dd D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];

    dd temp[N][N]; // To store cofactors

    int sign = 1;  // To store sign multiplier

     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    return D;
}

// Function to get adjoint of A[N][N] in adj[N][N].
void adjoint(dd A[N][N],dd adj[N][N])
{
    if (N == 1)
    {
        adj[0][0] = 1;
        return;
    }

    // temp is used to store cofactors of A[][]
    dd sign = 1, temp[N][N];

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            // Get cofactor of A[i][j]
            getCofactor(A, temp, i, j, N);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i+j)%2==0)? 1: -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j][i] = (sign)*(determinant(temp, N-1));
        }
    }
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool inverse(dd A[N][N], dd inverse[N][N])
{
    // Find determinant of A[][]
    dd det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return false;
    }

    // Find adjoint
    dd adj[N][N];
    adjoint(A, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/float(det);

    return true;
}

// Generic function to display the matrix.  We use it to display
// both adjoin and inverse. adjoin is integer matrix and inverse
// is a float.
template<class T>
void display(T A[N][N])
{
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    dd A[N][N] ;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>A[i][j];
        }
    }

    dd adj[N][N];  // To store adjoint of A[][]
    dd inv[N][N];

    inverse(A, inv);
    display(inv);
//    dd res[N][N]; // To store result
//    int i, j;
//    multiply(mat1, mat2, res);
//
//    printf("Result matrix is \n");
//    for (i = 0; i < N; i++)
//    {
//        for (j = 0; j < N; j++)
//           printf("%0.4f ", res[i][j]);
//        printf("\n");
//    }

    return 0;
}
/*
0.353553390593 0.353553390593 0.353553390593 0.353553390593 0.353553390593 0.353553390593 0.353553390593 0.353553390593
0.490392640202 0.415734806151 0.27778511651 0.0975451610081 -0.0975451610081 -0.27778511651 -0.415734806151 -0.490392640202
0.461939766256 0.191341716183 -0.191341716183 -0.461939766256 -0.461939766256 -0.191341716183 0.191341716183 0.461939766256
0.415734806151 -0.0975451610081 -0.490392640202 -0.27778511651 0.27778511651 0.490392640202 0.0975451610081 -0.415734806151
0.353553390593 -0.353553390593 -0.353553390593 0.353553390593 0.353553390593 -0.353553390593 -0.353553390593 0.353553390593
0.27778511651 -0.490392640202 0.0975451610081 0.415734806151 -0.415734806151 -0.0975451610081 0.490392640202 -0.27778511651
0.191341716183 -0.461939766256 0.461939766256 -0.191341716183 -0.191341716183 0.461939766256 -0.461939766256 0.191341716183
0.0975451610081 -0.27778511651 0.415734806151 -0.490392640202 0.490392640202 -0.415734806151 0.27778511651 -0.0975451610081
*/
