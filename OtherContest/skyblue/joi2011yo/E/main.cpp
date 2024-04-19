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

using P = pair<int, int>;
const int INF = 107374182;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int H, W, N;
  cin >> H >> W >> N;
  auto grid = vector<vector<char>>(H, vector<char>(W));
  rep(i, H) rep(j, W) cin >> grid[i][j];

  queue<pair<P, int>> search_point;
  int current_hp = 1;
  int elasped_time = 0;

  rep(i, H) rep(j, W)
  {
    if (grid[i][j] == 'S')
    {
      search_point.emplace(make_pair(i, j), 0);
    }
  }

  while (true)
  {
    if (current_hp == N + 1)
    {
      cout << search_point.front().second << endl;
      return 0;
    }
    auto cost_grid = vector<vector<int>>(H, vector<int>(W, INF));
    bool goal_flag = false;
    while (!goal_flag)
    {
      auto p = search_point.front().first;
      auto time = search_point.front().second;
      int next_time = time + 1;
      search_point.pop();

      rep(i, 4)
      {
        P next_p = make_pair(p.first + dx[i], p.second + dy[i]);
        if (next_p.first < 0 || next_p.first > H - 1 || next_p.second < 0 || next_p.second > W - 1)
          continue;

        char mark = grid[next_p.first][next_p.second];
        bool unreached = cost_grid[next_p.first][next_p.second] == INF;

        if (mark == 'X')
          continue;
        if (mark == '0' + current_hp)
        {
          goal_flag = true;
          current_hp++;
          while (!search_point.empty())
            search_point.pop();
          search_point.emplace(next_p, next_time);
          break;
        }
        else if (unreached)
        {
          cost_grid[next_p.first][next_p.second] = next_time;
          search_point.emplace(next_p, next_time);
        }
      }
    }
  }

  // ここまで
  return 0;
}
