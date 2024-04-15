#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define ALL(n) begin(n),end(n)

int main(void)
{
  vector<int> numbers;
  while(true){
    int a;
    cin >> a;
    if(a == 0) break;
    numbers.push_back(a);
  }

  REP(i, numbers.size()){
    cout << "Case " << i+1 << ": " << numbers[i] << endl;
  }

  return 0;
}
