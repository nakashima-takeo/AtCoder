#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanInt;
        romanInt['I'] = 1;
        romanInt['V'] = 5;
        romanInt['X'] = 10;
        romanInt['L'] = 50;
        romanInt['C'] = 100;
        romanInt['D'] = 500;
        romanInt['M'] = 1000;
        int result = 0;
        for (int i = 0; i < s.size(); i++)
        {
          int romanValue = romanInt[s[i]];
          if (i != s.size()-1){
            int nextRomanValue = romanInt[s[i+1]];
            if(romanValue < nextRomanValue){
              result -= romanValue;
            } else {
              result += romanValue;
            }
          } else {
            result += romanValue;
          }
        }
        return result;
    }
};
