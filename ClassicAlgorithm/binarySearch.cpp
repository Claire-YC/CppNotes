#include <iostream>
#include <vector>
#include <numeric>  // std::iota
#include <random>
#include <algorithm> // std::shuffle, sort

template <typename T>
int BSearch(std::vector<T>& vec, T val, int left, int right)
{
    while (right > left)
    {
        // 注意mid的求法：Avoid summation overflow
        int mid = left + (right-left) / 2;

        // left = mid+1
        // right = mid -> 这样让mid在left和right之间

        // 若right = mid-1 -> left == right时表示找到，否则没找到
        if (vec[mid] < val)
            left = mid + 1;
        else if (vec[mid] > val)
            right = mid;
        else
            return mid;
    }
    return -1;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec)
{
    for (int i = 0; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

int main(){
    std::vector<double> vec(10, 0);
    std::iota(vec.begin(), vec.end(), 1.2);
    std::cout << vec << std::endl;

    std::random_device rd;
    std::mt19937_64 mt(rd());
    std::shuffle(vec.begin(), vec.end(), mt);
    std::sort(vec.begin(), vec.end());

    int ans = BSearch(vec, 7.2, 0, (int)vec.size()-1);

    std::cout << ans << std::endl;

}