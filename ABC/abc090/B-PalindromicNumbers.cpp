#include<iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    ans = (int)(b / 1000) - (int)(a / 1000) * 10;
    cout << ans << endl;
}