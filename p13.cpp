/*
Problem#13
Given two arrays A and B, we can determine the array C = A B using the standard definition of matrix
multiplication:
The number of columns in the A array must be the same as the number of rows in the B array.
Notationally, let's say that rows(A) and columns(A) are the number of rows and columns, respectively, in
the A array. The number of individual multiplications required to compute the entire C array (which will
have the same number of rows as A and the same number of columns as B) is then rows(A) columns(B)
columns(A). For example, if Ais a array, and B is a array, it will take , or 3000 multiplications to compute
the C array.
To perform multiplication of more than two arrays we have a choice of how to proceed. For example, if
X, Y, and Z are arrays, then to compute X Y Z we could either compute (X Y) Z or X (Y Z). Suppose X is a
array, Y is a array, and Z is a array. Let's look at the number of multiplications required to compute the
product using the two different sequences:
(X Y) Z
● multiplications to determine the product (X Y), a array.
● Then multiplications to determine the final result.
● Total multiplications: 4500.
X (Y Z)
● multiplications to determine the product (Y Z), a array.
● Then multiplications to determine the final result.
● Total multiplications: 8750.
Clearly we'll be able to compute (X Y) Z using fewer individual multiplications.
Given the size of each array in a sequence of arrays to be multiplied, you are to determine an optimal
computational sequence. Optimality, for this problem, is relative to the number of individual
multiplications required.

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

// Function for printing the optimal
// parenthesization of a matrix chain product
void print_brackets(int i, int j, int n, int* bracket,
                      char& name)
{
    // If only one matrix left in current segment
    if (i == j) {
        cout << name<<i<<" ";
        return;
    }

    cout << "(";

    // Recursively put brackets around subexpression
    // from i to bracket[i][j].
    // Note that "*((bracket+i*n)+j)" is similar to
    // bracket[i][j]
    print_brackets(i, *((bracket + i * n) + j), n,
                     bracket, name);

    // Recursively put brackets around subexpression
    // from bracket[i][j] + 1 to j.
    print_brackets(*((bracket + i * n) + j) + 1, j, n,
                     bracket, name);
    cout << ")";
}


int main()
{
    int nMatrix ;
    cout << "how many matrix you will enter \n" << endl;
    cin>>nMatrix; //n
    int m [nMatrix+1][nMatrix+1] = {0}; //for minimum value of multiplications (A1*A2)*A3 or A1*(A2*A3)
    int s [nMatrix+1][nMatrix+1]= {0}; // for the number of k that gives the menimum
    int dimeinsional [nMatrix+1] = {0};
    int f ,l;
    for (int i = 0 ;i<nMatrix;i++) //n-1
    {
        cout<<"enter the dimensions of the matrix \n";
            cin>>f>>l;
                dimeinsional[i]=f;  //store the dimesional of the matrices
    }
    dimeinsional[nMatrix]=l; //the value of last column
    int j ,q,Min;
    for (int d=1;d<nMatrix;d++){

        for (int i = 1 ;i<(nMatrix+1)-d;i++){
            j= i+d; //to access the columns
            Min = 375498;
            for (int k =i;k<=j-1;k++) //to find the minimum
                {
                q= m[i][k]+m[k+1][j]+dimeinsional[i-1]*dimeinsional[k]*dimeinsional[j]; //dynamic programming formula
                if (q<Min){
                    Min = q;
                    s[i][j]=k;
                }
             m[i][j]=Min;
            }
        }
       // cout<<m[1][nMatrix]<<" ";
    }
    char name = 'A';

    cout << "Optimal Parenthesization is : "<<endl<<endl;
    print_brackets(1, nMatrix, nMatrix+1, (int*)s, name);
    cout << "nOptimal Cost is : " << m[1][nMatrix];

    return 0;
}
