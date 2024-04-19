#include <bits/stdc++.h>
using namespace std;
using long long ll;
using unsigned long long ull;
using long double ld;

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

  int n, m, k;
  cin >> n >> m >> k;

  vector<pair<int,int>> badPair(m);
  rep(i, m) cin >> badPair[i].first >> badPair[i].second;

  // ランダムの準備
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dist(0, n-1);

  double result = 0.0;
  int failure_count = 0;
  vector<int> mans(n);
  int loopCount = 3001001;
  rep(i, loopCount){
    iota(all(mans), 0);
    rep(j, k){
      while(true){
        int a = dist(gen);
        int b = dist(gen);
        if(a != b){
          swap(mans[a], mans[b]);
          break;
        }
      }
    }
    vector<int> inv(n);
    rep(j, n){
      inv[mans[j]] = j;
    }
    rep(l, m){
      if(inv[badPair[l].first] == (inv[badPair[l].second]+1) % n || inv[badPair[l].first] == (inv[badPair[l].second]-1+n) % n){
        failure_count++;
        break;
      }
    }
  }

  result = 1 - (static_cast<double>(failure_count)/ loopCount);
  cout << result << endl;

  // ここまで
  return 0;
}
