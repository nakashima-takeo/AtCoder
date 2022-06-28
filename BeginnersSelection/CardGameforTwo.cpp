#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n ; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    bool switchA = true;
    int amount = 0;
    for (auto i : v)
    {
        if (switchA)
        {
            amount += i;
            switchA = false;
        }
        else
        {
            amount -= i;
            switchA = true;
        }
    }
    cout << amount << endl;
    return 0;
}