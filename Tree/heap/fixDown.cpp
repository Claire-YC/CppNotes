#include <iostream>
#include <vector>
#include <utility> // std::swap

/*
 Fix-Down, top down
 1. '2*k < heapsize': 'k' node is not a leaf node
 2. 'node = 2*k': (if k is not a leaf node, it must have left child)
    Find the left child
 3. Find the highest priority child
    'node < heapsize': whether the right child exist?
    'heap[node] < heap[node+1]': whether the right child's priority is higher than the left child
 4. '(heap[k] >= heap[node])' If the parent's priority is higher than the highest child, current node is ok.
*/
std::ostream& operator<<(std::ostream& out, const std::vector<int>& vec)
{
    // the first item is the dummy node.
    for (int i=1; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

void FixDown(std::vector<int>& heap, int heapsize, int k)
{
    while (2*k <= heapsize)
    {
        int node = 2*k;

        // 要跟最大的那个Leaf node换
        if (node < heapsize && heap[node] < heap[node+1])
            node++;

        if (heap[k] >= heap[node])
            break;

        // swap the parent and child
        std::swap(heap[k], heap[node]);
        // move down to the next layer
        k = node;
    }
}


int main()
{
    // heap index starts with 1, add a dummy node
    std::vector<int> vec = {0, 81, 3, 14, 9, 7, 1, 5, 2, 4};
    FixDown(vec, 9, 2);
// (vec, heapsize(without dummy node), the position of 'bad' node)
    std::cout << vec << std::endl;
}