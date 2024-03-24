#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

const ll INF = 1LL << 60;

template <typename T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

ll dp[200005][2][2];

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> c(n);
  REP(i, n) cin >> c[i];

  REP(i, n+1)REP(j, 2)REP(k, 2) dp[i][j][k] = INF;
  // 初期化
  // jが末尾の文字
  // kが何か所隣り合った文字があったか
  REP(j, 2){
    int cost = 0;
    if(s[0] != '0' + j) cost = c[0];
    dp[1][j][0] = cost;
  }
  for(int i = 1; i < n; i++){
    // i-1文字目が0か1か
    REP(j, 2){
      // i-1文字目までで隣接する文字が同じである箇所が0個か1個か
      REP(k, 2){
        // 現在のi文字目を0にするか1にするか
        REP(next_j, 2){
          int next_k = k;
          if (j == next_j) next_k++;
          if (next_k >= 2) continue;
          int cost = 0;
          if(s[i] != '0' + next_j) cost = c[i];
          chmin(dp[i+1][next_j][next_k], dp[i][j][k] + cost);
        }
      }
    }
  }

  ll ans = INF;
  REP(j, 2) chmin(ans, dp[n][j][1]);
  cout << ans << endl;

  // ここまで
  return 0;
}
