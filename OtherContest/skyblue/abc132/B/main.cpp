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
  vector<int> p(n);
  REP(i, n) cin >> p[i];

  set<int> s;

  for (int i = 0; i < n-2; i++)
  {
    if(p[i] < p[i+1] && p[i+1] < p[i+2]) s.insert(i+1);
    if(p[i] > p[i+1] && p[i+1] > p[i+2]) s.insert(i+1);
  }

  cout << s.size() << endl;


  // ここまで
  return 0;
}
