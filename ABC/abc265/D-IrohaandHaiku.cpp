#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// setを用いると高速に取ってこれる
// 二分探索木でもよい
int main(){
    int n;
    long long p, q, r;
    cin >> n >> p >> q >> r;
    vector<int> A(n);
    set<long long> Sum;
    long long sum = 0;
    Sum.insert(sum);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        sum += A[i];
        Sum.insert(sum);
    }
    for (auto i : Sum)
    {
        auto yindex = Sum.find(p + i);
        if (yindex == Sum.end()) continue;
        auto zindex = Sum.find(q + *yindex);
        if (zindex == Sum.end()) continue;
        auto windex = Sum.find(r + *zindex);
        if (windex == Sum.end()) continue;
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}