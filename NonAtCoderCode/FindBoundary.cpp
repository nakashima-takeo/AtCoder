#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_boundary(std::vector<bool> arr) {
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == true)
        {
            if(mid == 0)
            {
                return 0;
            }
            else if(arr[mid - 1] == false)
            {
                return mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        else if (arr[mid] == false)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<bool> arr;
    bool b;
    while (ss >> std::boolalpha >> b) {
        arr.push_back(b);
    }
    int res = find_boundary(arr);
    std::cout << res << '\n';
}
