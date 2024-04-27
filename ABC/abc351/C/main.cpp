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

void operation(vector<int> &vec, int next){
  vec.push_back(next);
  if(vec.size() <= 1) return;
  if(vec[vec.size()-2] != vec[vec.size()-1]) return;
  if(vec[vec.size()-2] == vec[vec.size()-1]){
    vec.pop_back();
    vec.pop_back();
    operation(vec, next+1);
  }
  return;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<ll> balls(n);
  rep(i, n) cin >> balls[i];

  vector<int> vec;
  rep(i, n){
    operation(vec, balls[i]);
  }
  cout << vec.size() << endl;

  // ここまで
  return 0;
}
