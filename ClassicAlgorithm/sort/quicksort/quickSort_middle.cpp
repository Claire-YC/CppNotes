size_t Partition(std::vector<int>& vec, size_t left, size_t right)
{
    // 1. pick the middle one as pivot
    size_t pivot = left + (right-left)/2;
    // 2. swap it with the right most
    std::swap(vec[pivot], vec[--right]);
    pivot = right;

    /* Below is the same */

    while (true)
    {
        while (vec[left] < vec[pivot])
            ++left;
        // 'vec[right-1]?'因为进入最外层while的初始，right指向pivot，需要往前走一个
        while (left < right && vec[right-1] >= vec[pivot])
            --right;

        // 2 5 3 6 6 9 8 [6,pivot]
        // left指向第一个大于pivot的元素 -> 9
        // right指向第一个小于等于pivot的元素 -> (第一个6)
        // 所以可能出现left > right的情况
        if (left >= right)
            break;

        // 交换pivot左右两边的元素
        std::swap(vec[left], vec[right-1]);
    } // while

    // 把pivot放到中间
    std::swap(vec[left], vec[pivot]);

    // 此时left的位置就是pivot的位置
    return left;
} // Partition