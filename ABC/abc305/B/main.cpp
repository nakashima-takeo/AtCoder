#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)


int alphabet_number(char a){
  switch(a){
    case 'A': return 0;
    case 'B': return 1;
    case 'C': return 2;
    case 'D': return 3;
    case 'E': return 4;
    case 'F': return 5;
    case 'G': return 6;
  }

  return 0;
}

int main(void)
{
  cin.tie(0)->sync_with_stdio(0);
  // ここから本番コード

  char p, q;
  cin >> p >> q;

  vector<int> distance = {3, 1, 4, 1, 5, 9};
  int p_number = alphabet_number(p);
  int q_number = alphabet_number(q);

  if (p_number > q_number){
    int tem_number = p_number;
    p_number = q_number;
    q_number = tem_number;
  }

  int result = 0;

  REP(i, 6){
    if( i >= p_number && i < q_number){
      result += distance[i];
    }
  }

  cout << result << endl;

  // ここまで
  return 0;
}
