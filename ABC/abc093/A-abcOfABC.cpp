#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.find("a") != string::npos && s.find("b") != string::npos && s.find("c") != string::npos)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}