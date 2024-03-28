#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

template <typename T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1LL << 60;

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  REP(i, n) cin >> h[i];

  vector<ll> dp(n, INF);

  REP(location, n){
    if(location == 0){
      dp[0] = 0;
    }
    REP(jump, k+1){
      if(location - jump < 0) break;
      chmin(dp[location], dp[location - jump] + abs(h[location] - h[location - jump]));
    }
  }

  cout << dp[n-1] << endl;

  // ここまで
  return 0;
}
