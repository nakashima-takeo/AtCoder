#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// uniqueは前のほうに集められた値の最後のインデックスの次のインデックスを返す。

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n ; i++) cin >> v[i];
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << endl;
    return 0;
}