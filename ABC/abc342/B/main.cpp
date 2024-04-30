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

  map<int,int> p_map;
  rep(i, n){
    int p;
    cin >> p;

    p_map[p] = i+1;
  }

  int q;
  cin >> q;
  rep(i, q){
    int a, b;
    cin >> a >> b;
    int a_index = p_map[a];
    int b_index = p_map[b];
    if(a_index > b_index) swap(a, b);
    cout << a << endl;
  }

  // ここまで
  return 0;
}
