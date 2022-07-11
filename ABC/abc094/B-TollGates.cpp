#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int CulculateCost(int n, int m, int x, vector<int>& v)
{
    sort(v.begin(), v.end());
    int cost = 0;
    for (int i = x; i < n; i++)
    {
        auto itr = find(v.begin(), v.end(), i);
        if (itr != v.end())
        {
            int cost1 = distance(v.begin(), itr);
            int cost2 = distance(itr, v.end());
            cost = cost1 > cost2 ? cost2 : cost1;
            break;
        }
    }
    return cost;
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> v(m);
    for (int i = 0; i < m; i++) cin >> v[i];
    cout << CulculateCost(n, m, x, v) << endl;
}