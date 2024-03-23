#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)



int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int h, w;
  cin >> h >> w;
  vector<string> s(h);

  REP(i, h) cin >> s[i];

  REP(i, h){
    REP(j, w){
      if(s[i][j] == '#') continue;
      int around_cookie_count = 0;
      if(i != 0 && s[i-1][j] == '#') around_cookie_count++;
      if(i != h-1 && s[i+1][j] == '#') around_cookie_count++;
      if(j != 0 && s[i][j-1] == '#') around_cookie_count++;
      if(j != w-1 && s[i][j+1] == '#') around_cookie_count++;
      if(around_cookie_count >= 2){
        cout << i+1 << ' ' << j+1 << endl;
        return 0;
      }
    }
  }

  // ここまで
  return 0;
}
