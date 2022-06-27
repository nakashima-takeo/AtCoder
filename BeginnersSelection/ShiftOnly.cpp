#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int a;
    cin >> a;
    vector<int> v(a);
    for (int i = 0; i < a ; i++)
    {
        cin >> v[i];
    }
    int howManyDevide = 0;
    while (v[0] % (int)pow(2, howManyDevide + 1) == 0)
    {
        howManyDevide++;
    }
    for (int element : v)
    {
        while (element % (int)pow(2,howManyDevide) != 0)
        {
            howManyDevide--;
        }
    }
    cout << howManyDevide << endl;
    return 0;
}