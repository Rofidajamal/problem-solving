/*
Problem#4
You have a multiset containing several integers. Initially, it contains a1 elements equal to
1, a2 elements equal to 2, ..., an elements equal to 𝑛.
You may apply two types of operations:
● choose two integers 𝑙 and 𝑟 (𝑙≤𝑟), then remove one occurrence of 𝑙, one occurrence of 𝑙+1, ...,
one occurrence of 𝑟 from the multiset. This operation can be applied only if each number from 𝑙
to 𝑟 occurs at least once in the multiset
● choose two integers 𝑖 and 𝑥 (𝑥≥1), then remove 𝑥 occurrences of 𝑖 from the multiset. This
operation can be applied only if the multiset contains at least 𝑥 occurrences of 𝑖
What is the minimum number of operations required to delete all elements from the multiset?
*/
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////


#include <bits/stdc++.h>

using namespace std;

const int N = int(5e3) + 9;

int n;
int a[N];
int dp[N][N];

int calc (int pos, int x) {
    int &res = dp[pos][x];
    if (res != -1) return res;

    if (pos == n) return res = 0;
    res = 1 + calc(pos + 1, n);
    res = min(res, calc(pos + 1, pos) + a[pos]);
    if (x != n) {
        if (a[x] >= a[pos])
            res = min(res, calc(pos + 1, pos));
        else {
            res = min(res, calc(pos + 1, pos) + a[pos] - a[x]);
            res = min(res, 1 + calc(pos + 1, x));
        }
    }

    return res;
}

int main(){
    cout<<"enter the number of elements \n";
    cin>>n;
    int x;
    cout<<"Enter you elements \n";
    for (int i = 0; i < n; ++i)
       {cin>>x;
        a[i]=x;
       }

    memset(dp, -1, sizeof(dp));
    cout<<"the output: "<< calc(0, n)<<endl;

    return 0;
}
