#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int d,x;
    cin >> d >> x;
    int ans = x;
    for(int i=0;i<n;i++)
    {
        int t;
        cin >> t;
        if (d / t == 0)
            ans += 1;
        else if (d % t == 0)
            ans += d / t;
        else
            ans += 1 + (d / t);
    }
    cout << ans << endl;
}