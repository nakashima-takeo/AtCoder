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

  int q;
  cin >> q;

  vector<int> a;
  rep(i, q){
    int j;
    cin >> j;
    if(j == 1){
      int x;
      cin >> x;
      a.push_back(x);
    } else {
      int k;
      cin >> k;
      cout << a.at(a.size() - k) << endl;
    }
  }

  // ここまで
  return 0;
}
