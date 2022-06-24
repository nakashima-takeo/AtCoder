#include<iostream>
#include<string>
// stoiを使うためには<string>をインクルードする必要がある。
// 更にusing namespace stdを書くことでstdを省略できる。
using namespace std;
int main()
{
    string str;
    cin >> str;
    int a;
    a = stoi(str.substr(0,1));
    a += stoi(str.substr(1,1));
    a += stoi(str.substr(2,1));
    cout << a << endl;
    return 0;
}