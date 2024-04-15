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

  if (a > b){
    cout << "a > b" << endl;
  } else if(a < b){
    cout << "a < b" << endl;
  } else {
    cout << "a == b" << endl;
  }

  return 0;
}
