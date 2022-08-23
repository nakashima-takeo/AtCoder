#include<iostream>
using namespace std;

int main()
{
    int x,y,n;
    cin >> x >> y >> n;
    int price1 = n/3 * y + (n % 3) * x;
    int price2 = n * x;
    cout << min(price1,price2) << endl;
    return 0;
}