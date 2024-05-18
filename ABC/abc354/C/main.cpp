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

struct Card{
  int power;
  int cost;
  int number;

  bool operator<(const Card &other) const {
    return power > other.power;
  }
};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<Card> cards(n);
  rep(i, n) {
    cin >> cards[i].power >> cards[i].cost;
    cards[i].number = i+1;
  }

  sort(all(cards));

  int min_cost = cards[0].cost;
  vector<int> result;
  rep(i, n){
    if(min_cost >= cards[i].cost){
      result.push_back(cards[i].number);
      min_cost = cards[i].cost;
    }
  }

  sort(all(result));

  cout << result.size() << endl;
  rep(i, result.size()){
    if(i != result.size()-1){
      cout << result[i] << " ";
    } else{
      cout << result[i] << endl;
    }
  }

  // ここまで
  return 0;
}
