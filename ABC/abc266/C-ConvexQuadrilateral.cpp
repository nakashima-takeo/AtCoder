#include<iostream>
using namespace std;
typedef pair<int,int> point;

bool CounterClockWise(point A, point B, point C){
    point X = point(B.first - A.first, B.second - A.second);
    point Y = point(C.first - A.first, C.second - A.second);
    int det = X.first * Y.second - X.second * Y.first;
    if (det > 0) return true;
    else return false;
}

int main(){
    int a, b;
    cin >> a >> b;
    point A = point(a, b);
    cin >> a >> b;
    point B = point(a, b);
    cin >> a >> b;
    point C = point(a, b);
    cin >> a >> b;
    point D = point(a, b);
    if (CounterClockWise(A, B, C) == true &&
        CounterClockWise(B, C, D) == true &&
        CounterClockWise(C, D, A) == true &&
        CounterClockWise(D, A, B) == true){
            cout << "Yes" << endl;
            return 0;
        }
    cout << "No" << endl;
    return 0;
}

