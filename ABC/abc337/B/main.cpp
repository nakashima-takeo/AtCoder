#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  string s;
  cin >> s;

  char state = 'A';

  for(int i = 0; i < s.length(); i++){
    if(s[i] == 'A'){
      if(state != 'A') break;
      if(i == s.length() - 1){
        cout << "Yes" << endl;
        return 0;
      }
    } else if(s[i] == 'B'){
      if(state == 'A'){
        state = 'B';
        if(i == s.length() - 1){
          cout << "Yes" << endl;
          return 0;
        }
      } else if (state != 'B'){
        break;
      } else if (i == s.length() - 1){
        cout << "Yes" << endl;
        return 0;
      }
    } else if(s[i] == 'C'){
      if(state == 'B' || 'C'){
        state = 'C';
        if(i == s.length() - 1){
          cout << "Yes" << endl;
          return 0;
        }
      } else if (state != 'C'){
        break;
      } else if (i = s.length() - 1){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
