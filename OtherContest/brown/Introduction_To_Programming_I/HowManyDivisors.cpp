#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  int a, b, c;
  cin >> a >> b >> c;

  int result = 0;
  for (int i = a; i < b+1; i++)
  {
    if(c % i == 0) result++;
  }

  cout << result << endl;

  return 0;
}

