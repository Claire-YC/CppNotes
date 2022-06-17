#include <iostream>
#include <vector>
#include <utility> // std::swap

template <typename T>
void InsertionSort(std::vector<T>& vec, size_t left, size_t right)
{
    // Suppose the first item is at the right place
    // start with the seconde item and compare backwards
    for (size_t i=left+1; i<right; i++)
        for (size_t j=i; j > left; j--)
            if (vec[j] < vec[j-1])
                std::swap(vec[j-1], vec[j]);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
    for (int i=0; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}
int main(){
    std::vector<int> vec{1,2,3,0};
    InsertionSort(vec, 0, vec.size());
    std::cout << vec << std::endl;
}