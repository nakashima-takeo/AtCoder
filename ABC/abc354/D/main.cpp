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

struct Rectangle {
  ll a, b, c, d;
  ll area = 0;
};

int cellInt(int n, int m){
  int n_mod = n % 4;
  int m_mod = m % 2;
  if(n_mod == 0){
    if(m_mod == 0) return 2;
    if(m_mod == 1) return 1;
  } else if (n_mod == 1){
    if(m_mod == 0) return 1;
    if(m_mod == 1) return 2;
  } else if (n_mod == 2){
    if(m_mod == 0) return 0;
    if(m_mod == 1) return 1;
  } else if (n_mod == 3){
    if(m_mod == 0) return 1;
    if(m_mod == 1) return 0;
  }
  return 0;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  Rectangle rec;
  cin >> rec.a >> rec.b >> rec.c >> rec.d;

  Rectangle inner_rec;
  if (rec.a < 0) inner_rec.a = rec.a - (rec.a % 4 - 4);
  else inner_rec.a = rec.a - rec.a % 4;
  if (rec.b < 0) inner_rec.b = rec.b - (rec.b % 2 - 2);
  else inner_rec.b = rec.b - rec.b % 2;
  if (rec.c < 0) inner_rec.c = rec.c - (rec.c % 4 - 4);
  else inner_rec.c = rec.c - rec.c % 4;
  if (rec.d < 0) inner_rec.d = rec.d - (rec.d % 2 - 2);
  else inner_rec.d = rec.d - rec.d % 2;
  inner_rec.area = (inner_rec.c - inner_rec.d / 4) * (inner_rec.d - inner_rec.b / 2) * 8;
  rec.area += inner_rec.area;

  Rectangle edge;
  if (rec.a < 0) edge.a = (rec.a % 4 - 4);
  else edge.a = rec.a % 4;
  if (rec.b < 0) edge.b = (rec.b % 2 - 2);
  else edge.b = rec.b % 2;
  if (rec.c < 0) edge.c = (rec.c % 4 - 4);
  else edge.c = rec.c % 4;
  if (rec.d < 0) edge.d = (rec.d % 2 - 2);
  else edge.d = rec.d % 2;
  
  for(int i = 0; edge.a + i < edge.c; i++){
    for (int j = 0;edge.b + j < edge.d; j++){
      edge.area += cellInt(edge.a + i, edge.b + j);
    }
  }

  rec.area += (inner_rec.c - inner_rec.c) * (edge.d - edge.b) * 4;
  rec.area += 0;

  rec.area += edge.area;

  cout << rec.area << endl;
  // ここまで
  return 0;
}
