#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  REP(i, n) cin >> c[i];

  sort(ALL(a));
  sort(ALL(b));
  sort(ALL(c));
  int result = 0;
  REP(i, n){
    auto it_b = upper_bound(ALL(b), a[i]);
    if(it_b == b.end()){
      continue;
    }
    for (auto i = it_b; i < b.end(); i++)
    {
      auto it_c = upper_bound(ALL(c), *i);
      result += c.end() - it_c;
    }
  }

  cout << result << endl;

  // ここまで
  return 0;
}
