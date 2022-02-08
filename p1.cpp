/*
Insertion Sort is a classical sorting technique.
As you probably already know, the algorithm can be really slow. To study this more, you want to find out
the number of times the swap operation is performed when sorting an array.
*/
//////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;
int InsertionSort (int arr [],int size_)
{
    int key , j ,comp=0;
    for (int i =1 ;i<size_;i++)
    {
        key = arr[i]; //second element in the array
        j = i -1; // first element
        while(j>=0 && arr[j]>key)
            {
                comp++; //to calculate the number of comparisons
                arr[j+1]= arr[j]; //shifting to the left
                j =j-1;
            }
            arr [j+1]= key; // putting the element in the proper place


    }
    return comp;
}
int main()
{
    int n;
    cout<<"enter the number of elements \n";
    cin>>n;
    int A [n] ; //{2,1,3,1,2}
    int c = 0;
    cout<<"Enter the elements \n";
    for (int i = 0;i<n;i++){
        cin>>A[i];
    }
    c = InsertionSort(A,n);
    cout<<"the number of comparisons:  "<<c<<endl;
    cout<<"the array after sorting : ";
    for (int i =0;i<5;i++)
    {
        cout<<A[i] <<" ";
    }


    return 0;
}
