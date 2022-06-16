#include <iostream>
#include <vector>
#include <utility> // std::swap
#include <random>

std::ostream& operator<<(std::ostream& out, std::vector<int>& vec)
{
    for (size_t i=0; i<vec.size(); i++){
        if (i == 0 and vec[i] == 0)
            continue;
        out << vec[i] << " ";
    }
    return out;
}

void FixDown(std::vector<int>& heap, unsigned long size, unsigned long idx)
{
    // 不是叶子节点2*idx <= size （千万别忘了=）
    while (2*idx <= size)
    {
        unsigned long node = 2*idx;
        if (node < size && heap[node] < heap[node+1])
            node++;
        if (heap[idx] > heap[node])
            break;
        std::swap(heap[idx], heap[node]);
        idx = node;
    }
}

void Heapify(std::vector<int>& heap)
{
    unsigned long start_idx = heap.size() / 2;
    // add a dummy node
    heap.insert(heap.begin(), 0);

    // 从第一个非叶子节点开始，一直往前fix-down
    for (unsigned long i=start_idx; i>0; i--)
    {
        FixDown(heap, heap.size(), i);
    }
}

void Heapsort(std::vector<int>& vec)
{
    Heapify(vec);
    std::cout << vec << std::endl;

    for (unsigned long i=vec.size()-1; i>0; i--)
    {
        std::swap(vec[i], vec[1]);
        // 通过fixDown不断的找到下一个最大值
        FixDown(vec, i-1, 1);
    }
}

int main(){
    setbuf(stdout, 0);
    std::random_device rd;
    std::mt19937_64 mt(rd());

    std::vector<int> vec = {4,2,5,1,7,9,14,18,81};
    std::shuffle(vec.begin(), vec.end(), mt);
    std::cout << vec << std::endl;

    Heapsort(vec);
    std::cout << vec << std::endl;
}