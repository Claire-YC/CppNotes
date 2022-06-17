#include <iostream>
#include <vector>
#include <utility> // std::swap
#include <random>
#include <algorithm> // std::shuffle

size_t Partition(std::vector<int>& vec, size_t left, size_t right)
{
    // 1. pick the right most element
    // 因为--在前，right会先减一，再赋值给pivot。此时pivot指向最右边的元素
    size_t pivot = --right;

    while (true)
    {
        while (vec[left] < vec[pivot])
            ++left;
        // 'vec[right-1]?'因为进入最外层while的初始，right指向pivot，需要往前走一个
        while (left < right && vec[right-1] >= vec[pivot])
            --right;

        // 2 5 3 6 6 9 8 [8,pivot]
        // left指向第一个大于pivot的元素 -> 9
        // right指向第一个小于等于pivot的元素 -> (第一个6)
        // 所以可能出现left > right的情况
        // 这种情况表示，在当前pivot下，左右的排序不需要动
        if (left >= right)
            break;

        // 交换pivot左右两边的元素
        std::swap(vec[left], vec[right-1]);
    } // while

    // 把pivot放到中间
    // 为什么和left换？因为left的位置指向的是第一个大于pivot的元素。
    std::swap(vec[left], vec[pivot]);

    // 此时left的位置就是pivot的位置
    return left;
} // Partition


void QuickSort(std::vector<int>& vec, size_t left, size_t right)
{
    if (left+1 >= right)
        return ; // arrays of length 0 or 1 are trivially sorted

    // 1. Find a pivot
    size_t pivot = Partition(vec, left, right);

    // 2. sort the left section
    QuickSort(vec, left, pivot);

    // 3. sort the right section
    QuickSort(vec, pivot+1, right);
}
std::ostream& operator<<(std::ostream& out, std::vector<int>& vec)
{
    for (size_t i=0; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

int main(){
    std::vector<int> vec{2,9,3,4,7,5,8,6};
    QuickSort(vec, 0, vec.size());
    std::cout << vec << std::endl;
}