#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n);
    b = a;
    sort(a.begin(), a.end());
    int center1 = a[n / 2 - 1];
    int center2 = a[n / 2];
    for (int i = 0; i < n; i++)
    {
        if (b[i] <= center1)
        {
            cout << center2 << endl;
        }
        else
        {
            cout << center1 << endl;
        }
    }
}