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

struct Point {
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {}
  void move(int dx, int dy) {
    x += dx;
    y += dy;
  }
};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int h, w, n;
  cin >> h >> w >> n;
  string t;
  cin >> t;
  auto grid = vector<vector<char>>(h, vector<char>(w, '#'));
  rep(i, h){
    string s;
    cin >> s;
    rep(j, w){
      grid[i][j] = s[j];
    }
  }

  int result = 0;
  rep(ih, h){
    rep(iw, w){
      Point current_place(ih, iw);
      if(grid[current_place.x][current_place.y] == '#') continue;
      rep(j, n){
        switch (t[j])
        {
        case 'U':
          current_place.x--;
          break;
        case 'D':
          current_place.x++;
          break;
        case 'R':
          current_place.y++;
          break;
        case 'L':
          current_place.y--;
          break;
        }
        if(grid[current_place.x][current_place.y] == '#') break;
        if(j == n-1){
          result++;
        }
      }
    }
  }

  cout << result << endl;

  // ここまで
  return 0;
}
