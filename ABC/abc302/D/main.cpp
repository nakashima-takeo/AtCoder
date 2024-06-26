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

  int n, m; ll d;
  cin >> n >> m >> d;

  vector<ll> a(n);
  vector<ll> b(m);
  REP(i, n){
    cin >> a[i];
  }
  REP(i, m){
    cin >> b[i];
  }

  sort(ALL(a));
  sort(ALL(b));

  ll ans = -1;

  REP(i, n){
    int it = upper_bound(ALL(b), a[i]+ d) - b.begin();
    if(it > 0 ){
      ll x = b[it - 1];
      if (a[i] - d <= x){
        ans = max(ans, a[i] + x);
      }
    }
  }

  cout << ans << endl;

  // ここまで
  return 0;
}
