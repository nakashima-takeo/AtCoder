#include<iostream>
using namespace std;

int Count(int amount);

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        int m = Count(i);
        if(a <= m && m <= b) sum += i;
    }
    cout << sum << endl;
    return 0;
}

int Count(int amount)
{
    int d10000, d1000, d100, d10;
    d10000 = amount / 10000;
    amount = amount - d10000 * 10000;
    d1000 = amount / 1000;
    amount = amount - d1000 * 1000;
    d100 = amount / 100;
    amount = amount - d100 * 100;
    d10 = amount / 10;
    amount = amount - d10 * 10;
    return d10000 + d1000 + d100 + d10 + amount;
}