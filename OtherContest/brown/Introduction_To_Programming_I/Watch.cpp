#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  int total_seconds;
  cin >> total_seconds;

  int hours = total_seconds / (60 * 60);
  int minutes = (total_seconds - hours * 60 * 60) / 60;
  int seconds = total_seconds - hours * 60 * 60 - minutes * 60;

  cout << hours << ":" << minutes << ":" << seconds << endl;

  return 0;
}
