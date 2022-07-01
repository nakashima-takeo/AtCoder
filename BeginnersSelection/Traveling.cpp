#include<iostream>
#include <cstdlib>
using namespace std;

// 入力は一行ごとに行われ、結果を分かった時点で出力しても問題ないことが分かった。

class AtCoDeer
{
public:
    AtCoDeer()
    {
        currentTime = 0;
        xPos = 0;
        yPos = 0;
    }
    ~AtCoDeer()
    {
    }
    bool Move(int time, int x, int y)
    {
        int Distance = abs(x - xPos) + abs(y - yPos);
        if (Distance <= time - currentTime && (currentTime - time - Distance) % 2 == 0)
        {
            currentTime = time;
            xPos = x;
            yPos = y;
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    int currentTime;
    int xPos;
    int yPos;
};

int main()
{
    int n;
    cin >> n;
    AtCoDeer deer;
    int time, x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> time >> x >> y;
        if(!deer.Move(time, x, y))
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}