#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char a;
        cin >> a;
        if (a == 'Y')
        {
            cout << "Four" << endl;
            return 0;
        }
    }
    cout << "Three" << endl;
    return 0;
}