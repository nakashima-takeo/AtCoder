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

  vector<int> takahashiPoint(n);
  vector<int> aokiPoint(n);
  REP(i, n) cin >> takahashiPoint[i] >> aokiPoint[i];

  int takahashi = accumulate(ALL(takahashiPoint), 0);
  int aoki = accumulate(ALL(aokiPoint), 0);

  if(takahashi == aoki){
    cout << "Draw" << endl;
  } else if (takahashi > aoki) {
    cout << "Takahashi" << endl;
  } else {
    cout << "Aoki" << endl;
  }

  // ここまで
  return 0;
}
