#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int peak_of_mountain_array(std::vector<int> arr) {
    int left = 0;
    int right = arr.size() - 1;
    int mid = 0;
    if (arr.size() == 1) return arr[0];
    while(arr[right - 1] > arr[right])
    {
        mid = (left + right) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            if (arr[mid - 1] < arr[mid]) return mid;
            right = mid - 1;
        }
    }
    return right;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> arr = get_words<int>();
    int res = peak_of_mountain_array(arr);
    std::cout << res << '\n';
}
