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
