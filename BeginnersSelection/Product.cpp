#include<iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int sum;
    sum = a * b;
    if (sum % 2 == 0) cout << "Even" << endl;
    else cout << "Odd" << endl;
    return 0;
}