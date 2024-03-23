#include <iostream>
#include<vector>
#include<utility>
using namespace std;
int main(){
    int n;
    cin << n;
    vector<int> A(n);
    vector<int> B(n);
    typedef pair<int,int> pairs
    for (int i = 0; i < n; i++)
    {
        cin << A[i] << B[i];
    }
    vector<pairs> C;
    for (int i = 0; i < n; i++){
        while(element)
        for (auto element : C){
            if (element.first <= A[i] && element.second => A[i]){
                if (element.second < B[i]{
                    element.second = B[i];
                    break;
                }
            }
            else if(element.first <= B[i] && element.second => B[i]){
                if (element.first > A[i]{
                    element.first = A[i];
                    break;
                }
            }
            else if(element.first >= A[i] && element.second <= B[i]){
                element.first = A[i];
                element.second = B[i];
                break;
            }
        }
        C.push_back(pair(A[i], B[i]));
    }
}
