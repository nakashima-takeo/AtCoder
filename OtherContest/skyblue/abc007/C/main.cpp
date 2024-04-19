#include <bits/stdc++.h>
using namespace std;
using long long ll;
using unsigned long long ull;
using long double ld;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n), end(n)

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int r, c;
  cin >> r >> c;
  P start;
  cin >> start.first >> start.second;
  start.first--;
  start.second--;
  P goal;
  cin >> goal.first >> goal.second;
  goal.first--;
  goal.second--;
  vector<vector<char>> grid(r, vector<char>(c));
  REP(i, r)
      REP(j, c) cin >> grid[i][j];

  queue<pair<P, int>> next_search;
  set<P> already_searched;
  next_search.emplace(start, 0);

  while (!next_search.empty())
  {
    auto p = next_search.front().first;
    auto cost = next_search.front().second;
    next_search.pop();

    REP(i, 4)
    {
      P next_p = make_pair(p.first + dx[i], p.second + dy[i]);
      char mark = grid[next_p.first][next_p.second];
      if (mark == '#')
        continue;
      if (mark == '.')
      {
        if (next_p == goal)
        {
          cout << cost + 1 << endl;
          return 0;
        }
        else
        {
          auto it = already_searched.find(next_p);
          if (it == already_searched.end())
          {
            already_searched.insert(next_p);
            next_search.emplace(next_p, cost + 1);
          }
        }
      }
    }
  }

  // ここまで
  return 0;
}
