#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;

    vector<vector<char>> data(h, vector<char>(w));
    vector<vector<bool>> boolData(h, vector<bool>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> data.at(i).at(j);
        }
    }

    int i = 0;
    int j = 0;
    while(true)
    {
        if (boolData.at(i).at(j) == true){
            cout << -1;
            return 0;
        }
        boolData.at(i).at(j) = true;
        if (data.at(i).at(j) == 'U'){
            if(i == 0){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
            i -= 1;
        }
        else if (data.at(i).at(j) == 'D'){
            if(i == h - 1){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
            i += 1;
        }
        else if (data.at(i).at(j) == 'L'){
            if(j == 0){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
            j -= 1;
        }
        else if (data.at(i).at(j) == 'R'){
            if(j == w - 1){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
            j += 1;
        }
    }
}