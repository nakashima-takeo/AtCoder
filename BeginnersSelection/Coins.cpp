#include<iostream>
using namespace std;
// C++では、整数を整数で割ったときの商が切り捨てられる

int MaxDevideCount(int amount, int coinValue, int maxCoinNumber);

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int ans = 0;
    for (int i = MaxDevideCount(x, 500, a); i >= 0; i--)
    {
        for (int j = MaxDevideCount(x - i * 500, 100, b); j >= 0; j--)
        {
            if ((x - i * 500 - j * 100) % 50 != 0) continue;
            if ((x - i * 500 - j * 100) / 50 <= c) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

int MaxDevideCount(int amount, int coinValue, int maxCoinNumber)
{
    int b = amount / coinValue;
    return min(b,maxCoinNumber);
}