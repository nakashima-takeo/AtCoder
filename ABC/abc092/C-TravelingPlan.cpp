#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int ans = 0;
    int n;
    cin >> n;
    vector<int> d(n + 2);
    d[0] = 0;
    d[n+1] = 0;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 0; i <= n; i++) ans += abs(d[i] - d[i + 1]);
    for (int i = 1; i <= n; i++) cout << ans - abs(d[i - 1] - d[i]) - abs(d[i] - d[i + 1]) + abs(d[i - 1] - d[i + 1]) << endl;
    return 0;
}