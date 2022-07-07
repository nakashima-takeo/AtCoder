#include<iostream>
#include<string>
using namespace std;

int main()
{
    long long m,n;
    cin >> m >> n;
    long long ans = 0;
    if (m >= 2 && n >= 2)
    {
        ans = (m - 2) * (n - 2);
    }
    else if (m == 1 && n == 1)
    {
        ans = 1;
    }
    else
    {
        ans = n * m - 2;
    }
    cout << ans << endl;
}