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

  char state = 'f';

  REP(i, s.length()){
    if(s[i] =='<'){
      if(state == 'f') state = '<';
      if(state != '<') break;
    } else if (s[i] == '='){
      if(state == '<') state = '=';
      if(state != '=') break;
    } else if (s[i] == '>'){
      if(state != '=') break;
      if(i == s.length() - 1){
        cout << "Yes" << endl;
        return 0;
      } else {
        break;
      }
    }
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
