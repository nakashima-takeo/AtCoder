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

const int INF = 107374182;

struct BingoNumbers{
  int number;
  int index;

  bool operator<(const BingoNumbers& other) const {
    return number < other.number;
  }
};

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n, t;
  cin >> n >> t;

  set<BingoNumbers> a;
  rep(i, t){
    BingoNumbers bingo;
    bingo.index = i;
    cin >> bingo.number;
    a.insert(bingo);
  }

  vector<vector<int>> bingoBoard(n, vector<int>(n, -1));
  rep(i, n){
    rep(j, n){
      BingoNumbers for_search = {n*i+j+1, 0};
      auto search = a.find(for_search);
      if(search != a.end()){
        bingoBoard[i][j] = search->index;
      }
    }
  }

  int min_bingo = INF;
  rep(i, n){
    bool bingo = true;
    int bingo_index = 0;
    rep(j, n){
      if(bingoBoard[i][j] == -1){
        bingo = false;
        break;
      }
      bingo_index = max(bingo_index, bingoBoard[i][j]);
    }
    if(bingo){
      min_bingo = min(min_bingo, bingo_index+1);
    }
  }
  rep(i, n){
    bool bingo = true;
    int bingo_index = 0;
    rep(j, n){
      if(bingoBoard[j][i] == -1){
        bingo = false;
        break;
      }
      bingo_index = max(bingo_index, bingoBoard[j][i]);
    }
    if(bingo){
      min_bingo = min(min_bingo, bingo_index+1);
    }
  }
  rep(i, 1){
    bool bingo = true;
    int bingo_index = 0;
    rep(j, n){
      if(bingoBoard[j][j] == -1){
        bingo = false;
        break;
      }
      bingo_index = max(bingo_index, bingoBoard[j][j]);
    }
    if(bingo){
      min_bingo = min(min_bingo, bingo_index+1);
    }
  }
  rep(i, 1){
    bool bingo = true;
    int bingo_index = 0;
    rep(j, n){
      if(bingoBoard[j][n-j-1] == -1){
        bingo = false;
        break;
      }
      bingo_index = max(bingo_index, bingoBoard[j][n-j-1]);
    }
    if(bingo){
      min_bingo = min(min_bingo, bingo_index+1);
    }
  }

  if(min_bingo == INF){
    cout << -1 << endl;
  }else{
    cout << min_bingo << endl;
  }

  // ここまで
  return 0;
}
