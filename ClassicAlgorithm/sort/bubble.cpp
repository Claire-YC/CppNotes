#include <iostream>
#include <vector>
#include <utility> // std::swap

using std::cout;
using std::endl;

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec)
{
    for (int i = 0; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

// Non-adaptive: 走完所有的循环
// 这样写更加general一点
template <typename T>
void Bubble(std::vector<T>& vec, size_t left, size_t right)
{
    // left, right = 表示排序的范围 s[left:right) "[)"
    for (size_t i = left; i<right-1; ++i)
        for (size_t j=right-1; j>i; --j)
            if (vec[j] < vec[j-1])
                std::swap(vec[j-1], vec[j]);
}

int main(){
    std::vector<int> vec{14,2,6,4,2};
    Bubble(vec, 1, vec.size()-1); // [14] [2,6,4] [2]只排中间的部分
    std::cout << vec << std::endl;
}