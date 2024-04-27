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

  int n;
  cin >> n;
  auto gridA = vector<vector<char>>(n, vector<char>(n, 'a'));
  auto gridB = vector<vector<char>>(n, vector<char>(n, 'a'));
  rep(i, n)rep(j, n) cin >> gridA[i][j];
  rep(i, n)rep(j, n) cin >> gridB[i][j];

  rep(i, n)rep(j, n){
    if(gridA[i][j] != gridB[i][j]){
      cout << i+1 << " " << j+1 << endl;
      return 0;
    }
  }
  // ここまで
  return 0;
}

// Union-Find
struct UnionFind {
  vector<int> par, rank, siz;

  // 構造体の初期化
  UnionFind(int n) : par(n,-1), rank(n,0), siz(n,1) { }

  // 根を求める
  int root(int x) {
      if (par[x]==-1) return x; // x が根の場合は x を返す
      else return par[x] = root(par[x]); // 経路圧縮
  }

  // x と y が同じグループに属するか (= 根が一致するか)
  bool issame(int x, int y) {
      return root(x)==root(y);
  }

  // x を含むグループと y を含むグループを併合する
  bool unite(int x, int y) {
      int rx = root(x), ry = root(y); // x 側と y 側の根を取得する
      if (rx==ry) return false; // すでに同じグループのときは何もしない
      // union by rank
      if (rank[rx]<rank[ry]) swap(rx, ry); // ry 側の rank が小さくなるようにする
      par[ry] = rx; // ry を rx の子とする
      if (rank[rx]==rank[ry]) rank[rx]++; // rx 側の rank を調整する
      siz[rx] += siz[ry]; // rx 側の siz を調整する
      return true;
  }

  // x を含む根付き木のサイズを求める
  int size(int x) {
      return siz[root(x)];
  }
};
