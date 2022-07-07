#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s,t;
    for (int i = 0; i < 3; i++)
    {
        cin >> s;
        t.append(s.substr(i,1));
    }
    cout << t << endl;
}