/*
Problem#16
Given an unsorted integer array containing many duplicate elements, rearrange it such that the same
element appears together and the relative order of the first occurrence of each element remains
unchanged. For example,
Input: { 1, 2, 3, 1, 2, 1 }
Output: { 1, 1, 1, 2, 2, 3 }
Input: { 5, 4, 5, 5, 3, 1, 2, 2, 4 }
Output: { 5, 5, 5, 4, 4, 3, 1, 2, 2 }

*/


#include <iostream>

using namespace std;

void Getduplicate_groups (int arr [],int n )
{

    bool *visited = new bool [n];
    int i = 0;
        // Initialize all elements as not visited
    while (i <n)
      {
          visited[i] = false;
          i++;
      }
    for (int i=0; i<n; i++)
    {
        // Check if this is first occurrence
        if (!visited[i])
        {
            // If yes, print it and all subsequent occurrences
            cout << arr[i] << " ";
            for (int j=i+1; j<n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cout << arr[i] << " ";
                    visited[j] = true;
                }
            }
        }
    }
    delete [] visited;

}

int main()
{
    int n;
    cout<<"enter the number of integers you will enter\n"<<endl;
    cin>>n;
    int arr [n];
    cout<<"Enter the integers"<<endl;
    for (int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    Getduplicate_groups(arr,n);



    return 0;
}
