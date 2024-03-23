#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)

int culculateScore(vector<vector<int>> groups){
  int result = 0;
  for(auto& group: groups){
    sort(ALL(group));
    if (group[0] == group[1] && group[1] == group[2]) result += 2;
    if (group[0] + 1 == group[1] && group[1] + 1 == group[2]) result += 1;
  }
  return result;
}

int main(void)
{
  const int NUMBER_OF_CARDS = 12;
  vector<int> cards(NUMBER_OF_CARDS);
  REP(i, NUMBER_OF_CARDS) cin >> cards[i];

  int maxScore = 0;
  vector<vector<int>> groups(4);
  REP(a, 4){
    REP(b, 4){
      REP(c, 4){
        REP(d, 4){
          REP(e, 4){
            REP(f, 4){
              REP(g, 4){
                REP(h, 4){
                  REP(i, 4){
                    REP(j, 4){
                      REP(k, 4){
                        REP(l, 4){
                          groups[a].push_back(cards[0]);
                          groups[b].push_back(cards[1]);
                          groups[c].push_back(cards[2]);
                          groups[d].push_back(cards[3]);
                          groups[e].push_back(cards[4]);
                          groups[f].push_back(cards[5]);
                          groups[g].push_back(cards[6]);
                          groups[h].push_back(cards[7]);
                          groups[i].push_back(cards[8]);
                          groups[j].push_back(cards[9]);
                          groups[k].push_back(cards[10]);
                          groups[l].push_back(cards[11]);
                          if(groups[0].size() == 3 && groups[1].size() == 3 && groups[2].size() == 3 && groups[3].size() == 3){
                            maxScore = max(maxScore, culculateScore(groups));
                          }
                          for (auto& group : groups) {
                            group.clear();
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  cout << maxScore << endl;

  return 0;
}
