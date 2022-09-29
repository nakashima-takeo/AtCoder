#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector

int find_min_rotated(std::vector<int> arr) {
    int left = 0;
    int right = arr.size() - 1;
    int mid = 0;
    while (arr[left] > arr[right])
    {
        mid = (left + right) / 2;
        if (arr[mid] <= arr[right])
        {
            if (arr[mid] < arr[mid - 1])
            {
                return mid;
            }
            right = mid - 1;
        }
        else if(arr[mid] >= arr[left])
        {
            mid += 1;
            left = mid;
        }
    }
    return mid;
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
    int res = find_min_rotated(arr);
    std::cout << res << '\n';
}
