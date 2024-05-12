#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;

  vector<ll> a(n);
  map<int, pair<ll,ll>> m;
  rep(i, n) {
    cin >> a[i];
  }

  rep(i, n-1){
    ll s, t;
    cin >> s >> t;
    m[i] = make_pair(s, t);
  }

  rep(i, n-1){
    if(a[i] >= m[i].first){
      ll devide_count = a[i] / m[i].first;
      a[i+1] += devide_count * m[i].second;
    }
  }

  cout << a[n-1] << endl;

  // ここまで
  return 0;
}
