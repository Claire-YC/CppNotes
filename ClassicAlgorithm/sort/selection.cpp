#include <iostream>
#include <vector>
#include <utility> // std::swap

template <typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T>& vec)
{
    for (int i = 0; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

template <typename T>
void SelectionSort(std::vector<T>& vec, size_t left, size_t right)
{
    // right：vec[left:right)
    // 'right-1'如果前面的元素都排好了，最后一个元素不需要排序
    for (size_t i=left; i<right-1; i++)
    {
        size_t minIdx = i;
        for (size_t j=i+1; j < right; j++)
            if (vec[j] < vec[minIdx])
                minIdx = j;
        std::swap(vec[i], vec[minIdx]);
    }
}

int main(){
    std::vector<float> vec{0.0, 9.8, 4, 5.2, 9.9, 8.0};
    SelectionSort(vec, 0, vec.size());
    std::cout << vec << std::endl;
}