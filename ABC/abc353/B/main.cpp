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

  int n, k;
  cin >> n >> k;
  queue<int> a;
  rep(i, n){
    int tmp = 0;
    cin >> tmp;
    a.push(tmp);
  }

  int result = 0;
  int empty_seat = 0;
  while (!a.empty())
  {
    int group = a.front(); a.pop();
    if(empty_seat + group > k){
      result++;
      empty_seat = 0;
    }
    empty_seat += group;
  }
  result++;
  cout << result << endl;

  // ここまで
  return 0;
}
