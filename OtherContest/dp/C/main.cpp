#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

template <typename T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<vector<int>> happy(n, vector<int>(3));
  REP(i, n){
    cin >> happy[i][0] >> happy[i][1] >> happy[i][2];
  }

  vector<vector<ll>> dp(n+1, vector<ll>(3,0));

  REP(i, n+1){
    if(i == 0){
      REP(j, 3) dp[i][j] = 0;
    } else {
      REP(j, 3){
        REP(k, 3){
          if(j != k){
            chmax(dp[i][j], dp[i-1][k] + happy[i-1][j]);
          }
        }
      }
    }
  }

  ll ans = 0;

  REP(j, 3){
    chmax(ans, dp[n][j]);
  }

  cout << ans << endl;

  // ここまで
  return 0;
}
