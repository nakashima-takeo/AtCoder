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

  int n, m;
  cin >> n >> m;

  vector<set<int>> relation(n);

  rep(i, n) relation[i].insert(i);

  rep(i, m){
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    relation[x].insert(y);
    relation[y].insert(x);
  }

  int result = 1;

  rep(bit, 1<<n){
    set<int> intersection;
    set<int> member;
    bool firstFlag = true;
    rep(i, n){
      if(bit & (1 << i)){
        member.insert(i);
        if(firstFlag){
          intersection = relation[i];
          firstFlag = false;
        } else {
          set<int> result_set;
          set_intersection(all(intersection), all(relation[i]), inserter(result_set, result_set.begin()));
          intersection = result_set;
        }
      }
    }

    if(member.size() == 0) continue;

    auto last = --member.end();
    for (auto &&m : member)
    {
      if(!intersection.contains(m)) break;
      if(m == *last){
        int size = member.size();
        result = max(result, size);
      }
    }
  }
  cout << result << endl;

  // ここまで
  return 0;
}
