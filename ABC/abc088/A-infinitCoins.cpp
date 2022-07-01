#include<iostream>
using namespace std;

int main()
{
    int n,a;
    cin >> n >> a;
    for (int i = n - a; i <= n; i++)
    {
        if (i % 500 == 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}