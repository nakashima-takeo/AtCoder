#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  vector<int> numbers(3);
  cin >> numbers[0] >> numbers[1] >> numbers[2];

  sort(ALL(numbers));
  cout << numbers[0] << " " << numbers[1] << " " << numbers[2] << endl;

  return 0;
}
