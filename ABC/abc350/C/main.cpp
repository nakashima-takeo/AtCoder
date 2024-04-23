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

  int N;
  cin >> N;

  vector<int> a(N);
  rep(i, N) cin >> a[i];

  rep(i, N) a[i] -= 1;

  int result = 0;
  vector<pair<int, int>> result_vec;
  rep(i, N-1){
    int next = i;
    bool flag = true;
    while (flag){
      if(next != a[next]){
        if(next > a[next]) result_vec.push_back(make_pair(a[next], next));
        else result_vec.push_back(make_pair(next, a[next]));
        swap(a[next], a[a[next]]);
        result++;
      } else {
        flag = false;
      }
    }
  }

  cout << result << endl;
  rep(i, result_vec.size()) cout << result_vec[i].first+1 << " " << result_vec[i].second+1 << endl;

  // ここまで
  return 0;
}
