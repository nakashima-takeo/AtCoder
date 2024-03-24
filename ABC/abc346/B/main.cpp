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

  int w, b;
  cin >> w >> b;

  while (w >= 14)
  {
    w -= 7;
    b -= 5;
  }

  string s = "wbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbwwbwbwwbwbwbw";

  REP(i, s.length()){
    int cw = w;
    int cb = b;
    REP(j, s.length() - i){
      if(s[i+j] == 'w') cw--;
      if(s[i+j] == 'b') cb--;
      if(cw < 0 || cb < 0) break;
      if(cw == 0 && cb == 0){
        cout << "Yes" << endl;
        return 0;
      }
    };
  };

  cout << "No" << endl;

  // ここまで
  return 0;
}
