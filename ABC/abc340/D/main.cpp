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

struct Stage
{
  ll a;
  ll b;
  int x;
};

const ll INF = 1LL << 60;

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<Stage> s(n-1);
  rep(i, n-1){
    cin >> s[i].a;
    cin >> s[i].b;
    cin >> s[i].x;
  }

  vector<ll> minTime(n, INF);
  minTime[0] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;

  q.emplace(0, 0);
  while(!q.empty()){
    int i = q.top().second; q.pop();
    if(i == n-1) break;
    if(minTime[i] + s[i].a < minTime[i+1]){
      minTime[i+1] = minTime[i] + s[i].a;
      q.emplace(minTime[i+1], i+1);
    }
    if(minTime[i] + s[i].b < minTime[s[i].x - 1]){
      minTime[s[i].x - 1] = minTime[i] + s[i].b;
      q.emplace(minTime[s[i].x - 1], s[i].x - 1);
    }
  }

  cout << minTime[n-1] << endl;

  // ここまで
  return 0;
}
