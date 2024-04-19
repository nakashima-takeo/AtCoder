#include <bits/stdc++.h>
using namespace std;
using long long ll;
using unsigned long long ull;
using long double ld;
const int INF = 107374182;

#define OVERLOAD_REP(_1, _2, _3, name, ...) name
#define REP1(i, n) for (auto i = std::decay_t<decltype(n)>{}; (i) != (n); ++(i))
#define REP2(i, l, r) for (auto i = (l); (i) != (r); ++(i))
#define rep(...) OVERLOAD_REP(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define all(...) std::begin(__VA_ARGS__), std::end(__VA_ARGS__)
#define rall(...) std::rbegin(__VA_ARGS__), std::rend(__VA_ARGS__)

struct ShipInfo
{
  int from, to, fee;
  void read()
  {
    cin >> from >> to >> fee;
    from--;
    to--;
  }
};

struct Customer
{
  int from, to;
  void read()
  {
    cin >> from >> to;
    from--;
    to--;
  }
};

struct Edge
{
  int to;
  ll cost;
  Edge(int to, ll cost) : to(to), cost(cost) {}
};
using Graph = vector<vector<Edge>>;

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, k;
  cin >> n >> k;

  vector<int> result;
  Graph graph(n);

  rep(i, k)
  {
    int flag = 0;
    cin >> flag;

    ShipInfo ship;
    Customer customer;

    if (flag == 0)
    {
      customer.read();
      // ここからダイクストラ法
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      vector<int> minCost(n, INF);
      pq.push(make_pair(0, customer.from)); // コストを先に入れないとpriority_queueが正しく動作しない
      minCost[customer.from] = 0;
      while (not(pq.empty()))
      {
        auto [cost, from] = pq.top();
        pq.pop();
        if (from == customer.to)
          break;
        auto tos = graph[from];
        for (auto &&to : tos)
        {
          if (minCost[to.to] > to.cost + cost)
          {
            pq.push(make_pair(to.cost + cost, to.to));
            minCost[to.to] = to.cost + cost;
          }
        }
      }
      if (minCost[customer.to] == INF)
      {
        result.push_back(-1);
      }
      else
      {
        result.push_back(minCost[customer.to]);
      }
      // ここまで
    }
    else
    {
      // 双方向にしないといけない
      ship.read();
      graph[ship.from].push_back(Edge(ship.to, ship.fee));
      graph[ship.to].push_back(Edge(ship.from, ship.fee));
    }
  }

  rep(i, result.size())
  {
    cout << result[i] << endl;
  }

  // ここまで
  return 0;
}
