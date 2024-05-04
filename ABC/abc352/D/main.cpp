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

const int INF = 107374182;

template <typename T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

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

  int n, k;
  cin >> n >> k;

  map<int,int> p;
  rep(i, n){
    int number;
    cin >> number;
    p[number-1] = i;
  }


  set<int> ranking;

  int max_index = 0;
  int min_index = INF;

  rep(i, k){
    ranking.insert(p[i]);
    chmax(max_index, p[i]);
    chmin(min_index, p[i]);
  }
  int result = max_index - min_index;

  for(int i = k; i < n; i++){
    int j = i-k;
    ranking.erase(p[j]);
    ranking.insert(p[i]);
    chmin(result, *ranking.rbegin() - *ranking.begin());
  }

  cout << result << endl;

  // ここまで
  return 0;
}
