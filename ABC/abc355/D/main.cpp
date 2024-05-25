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

struct Interval{
  ll l, r;
  bool operator<(const Interval& other) const {
    return l < other.l || (l == other.l && r < other.r);
  }
};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  ll n;
  cin >> n;

  multiset<Interval> intervals;
  rep(i, n){
    ll l, r;
    cin >> l >> r;
    intervals.insert({l, r});
  }

  ll count = 0;
  multiset<ll> right_limit;
  auto it = intervals.begin();
  rep(i, n){
    auto end_it = right_limit.lower_bound(it->l);
    right_limit.erase(right_limit.begin(), end_it);
    count += right_limit.size();
    right_limit.insert(it->r);
    it++;
  }


  cout << count << endl;
  // ここまで
  return 0;
}
