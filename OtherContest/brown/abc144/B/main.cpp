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

  for(int i = 1; i < 10; i++){
    if(n % i == 0){
      if(n / i < 10){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;

  // ここまで
  return 0;
}
