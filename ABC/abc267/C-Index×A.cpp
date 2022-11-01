#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> A(n);
    vector<int> S(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
        S[i] = sum;
    }
    
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        max += A[i];
    }

    for (int i = 0; i < n; i++)
    {
        /* code */
    }
    
}