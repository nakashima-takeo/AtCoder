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

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<int> h(n);
  REP(i, n) cin >> h[i];

  vector<ll> dp(n, INF);

  REP(i, n){
    if(i == 0) dp[i] = 0;
    else if(i == 1) dp[i] = abs(h[i] - h[i-1]);
    else {
      // dp[i] = min(dp[i-1] + abs(h[i] - h[i-1]), dp[i-2] + abs(h[i] - h[i-2]));
      chmin(dp[i], dp[i-1] + abs(h[i-1] - h[i]));
      chmin(dp[i], dp[i-2] + abs(h[i-2] - h[i]));
    }
  }

  cout << dp[n-1] << endl;

  // ここまで
  return 0;
}
