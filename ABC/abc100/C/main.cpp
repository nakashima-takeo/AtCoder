#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)

int main()
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  int N;
  cin >> N;
  int a[N];
  REP(i, N){
    cin >> a[i];
  }

  int max_devide = 0;
  REP(i, N){
    REP(j, 30){
      if (a[i] % 2 == 1){
        max_devide = max_devide + j;
        break;
      } else {
        a[i] = a[i] / 2;
      }
    }
  }

  cout << max_devide << endl;

  // ここまで
  return 0;
}
