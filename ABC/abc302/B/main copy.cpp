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

  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  REP(i, h) cin >> s[i];

  int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int dj[] = {1, 0, -1, 1, -1, 1, 0, -1};
  string T = "snuke";
  REP(i, h){
    REP(j, w){
      if(s[i][j] == 's'){
        REP(v, 8){
          REP(k, 5){
            int ik = i + di[k];
            int jk = j + dj[k];
            if(ik < 0 || jk < 0 || ik >= h || jk >= w) break;
            if(s[i][j] != T[k]) break;
            if(k == 4){
              REP(l, 5){
                printf("%d %d\n", i+di[l]+1, j+di[l]+1);
              }
              return 0;
            }
          }
        }
      }
    }
  }

  // ここまで
  return 0;
}
