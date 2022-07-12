#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int minGram = 100000;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x -= a;
        if (a < minGram)
        {
            minGram = a;
        }
    }
    n += x / minGram;
    cout << n << endl;
}