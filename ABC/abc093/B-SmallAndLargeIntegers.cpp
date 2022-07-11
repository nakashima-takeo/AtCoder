#include<iostream>
using namespace std;

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int i;
    for (i = a; i <= min(b, a + k - 1); i++) cout << i << endl;
    if (i == b + 1) return 0;
    else if (i < b - k + 1) for (i = b - k + 1; i <= b; i++) cout << i << endl;
    else for (i; i <= b; i++) cout << i << endl;
    return 0;
}