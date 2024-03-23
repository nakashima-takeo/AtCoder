#include <iostream>
using namespace std;
int main(void){
    int n,x,y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        string displayChar = "N";
        if (i % x == 0) displayChar = "A";
        if (i % y == 0) displayChar = "B";
        if (i % x == 0 && i % y == 0) displayChar = "AB";
        cout << displayChar << endl;
    }
    return 0;
}