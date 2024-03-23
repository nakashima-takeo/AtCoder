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

  int h, w, k;
  cin >> h >> w >> k;

  vector<vector<int>> cumulativeSum_batu()

  vector<string> s(h);
  REP(i, h) cin >> s[i];

  int result = 100100100;
  REP(i, h){
    REP(j, w){
      int tmp_result = 0;
      REP(a, k){
        if(i+k > h) break;
        if(s[i+a][j] == 'x') break;
        if(s[i+a][j] == '.') tmp_result++;
        if(s[i+a][j] == 'o') ;
        if(a == k-1) result = min(result, tmp_result);
      }
      tmp_result = 0;
      REP(a, k){
        if(j+k > w) break;
        if(s[i][j+a] == 'x') break;
        if(s[i][j+a] == '.') tmp_result++;
        if(s[i][j+a] == 'o') ;
        if(a == k-1) result = min(result, tmp_result);
      }
    }
  }

  if(result == 100100100){
    cout << "-1" << endl;
  } else{
    cout << result << endl;
  }

  // ここまで
  return 0;
}
