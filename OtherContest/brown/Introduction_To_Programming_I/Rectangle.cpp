#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  int a, b;
  cin >> a >> b;

  int area = a * b;
  int circumference = 2 * (a + b);
  cout << area << " " << circumference << endl;
  return 0;
}
