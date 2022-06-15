#include <iostream>
#include <vector>
#include <utility> // std::swap

/*
 Fix-up, from bottom to top
 1. `k > 1`: 'k' is not the root, so 'k' node has parent.
 2. `heap[k/2] < heap[k]`: the parent has lower priority
 3. 'swap': swap the number between parent and child
 4. `k/=2` move to the upper level
*/
std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
    // the first item is the dummy node.
    for (int i=1; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

void Fixup(std::vector<int>& heap, int k)
{
    while (k > 1 && heap[k/2] < heap[k])
    {
        std::swap(heap[k], heap[k/2]);
        k /= 2;
    }
}

int main()
{
    // heap index starts with 1, add a dummy node, 0就是dummy head
    std::vector<int> vec = {0, 81, 18, 14, 9, 7, 1, 5, 35, 4};
    Fixup(vec, 8); // 8 新插入破坏heap order的node 【从1开始】
    std::cout << vec << std::endl;
}