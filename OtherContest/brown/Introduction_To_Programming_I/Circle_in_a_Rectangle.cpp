#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  int w,h,x,y,r;
  cin >> w >> h >> x >> y >> r;

  if(x >= r && x <= w-r && y >= r && y <= h-r) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
