#include <iostream>
#include <vector>
#include <utility> // std::swap

void FixDown(std::vector<int>& heap, unsigned long idx)
{
    while (2*idx <= heap.size())
    {
        unsigned long node = 2*idx;
        if (node < heap.size() && heap[node] < heap[node+1])
            node++;
        if (heap[idx] > heap[node])
            break;
        std::swap(heap[idx], heap[node]);
        idx = node;
    }
}

void Heapify(std::vector<int>& heap)
{
    // 从第一个非leaf node开始。（就leaf node本身来看，它是满足heap order的）
    // 2*i > heapsize -> heapsize/2==第一个非leaf node
    unsigned long start_idx = heap.size() / 2;
    // add a dummy node
    heap.insert(heap.begin(), 0);

    for (unsigned long i=start_idx; i>0; i--)
    {
        FixDown(heap, i);
    }
}

int main(){
    std::vector<int> vec = {4,2,5,1,7,9,14,18,81};
    Heapify(vec);

    for (int i=1; i<vec.size(); i++)
        std::cout << vec[i] << " ";
}