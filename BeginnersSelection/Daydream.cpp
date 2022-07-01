#include<iostream>
using namespace std;

int AnalyzeString(string& s, int place);

int main()
{
    string s;
    cin >> s;
    if (AnalyzeString(s, 0))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}

int AnalyzeString(string& s, int place)
{
    if (place == s.size()) return true;
    if (s.substr(place, 5) == "dream" || s.substr(place, 5) == "erase")
    {
        if(AnalyzeString(s, place + 5) == true) return true;
        if (s.substr(place, 6) == "eraser") if(AnalyzeString(s, place + 6) == true) return true;
        if (s.substr(place, 7) == "dreamer") if(AnalyzeString(s, place + 7) == true) return true;
    }
    return false;
}