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
