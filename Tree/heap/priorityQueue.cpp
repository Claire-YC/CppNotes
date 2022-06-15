#include <iostream>
#include <stack>
#include <vector>
#include <utility> // std::swap


class PQ
{
private:
    // 一般size的返回都是unsigned long == size_t (aka: as known as)
    // m_Heapsize (including dummy node at the begining)
    unsigned long m_Heapsize;

    // Actual heap: m_Heap[1:m_Heapsize]
    std::vector<int> m_Heap;

    // index: from which position to fix up
    void FixUp(unsigned long index)
    {
        while (index > 1 && m_Heap[index/2] < m_Heap[index])
        {
            std::swap(m_Heap[index], m_Heap[index/2]);
            index /= 2;
        }
    }


    void FixDown(unsigned long index)
    {
        while (2*index <= m_Heapsize)
        {
            unsigned long node = 2*index;
            if (node < (m_Heapsize-1) && m_Heap[node] < m_Heap[node+1])
                node++;
            if (m_Heap[index] >= m_Heap[node])
                break;

            std::swap(m_Heap[index], m_Heap[node]);
            index = node;
        }
    }

public:
    // Constructor_1:empty PQ
    PQ()
            : m_Heapsize(1), m_Heap(m_Heapsize, 0) {}

    // Constructor_2: copy from a vector to create a PQ
    explicit PQ(const std::vector<int>& vec)
            : m_Heapsize(vec.size()+1){
        m_Heap = vec;
        // 在最前面加上一个dummy head 0，感觉这样做效率有点第
        m_Heap.insert(m_Heap.begin(), 0);
    }


    // 1. Insert the new item at the last position in heap.
    // 2. Fix-up: maintain the order of priority.
    void push(int value)
    {
        m_Heapsize++;
        m_Heap.push_back(value);
        FixUp(m_Heapsize-1);
    }

    void pop()
    {
        std::cout << m_Heap[1] << std::endl;

        // vector.back() return a reference
        // This reference can be used to assign another variable just like the normal variable. The assigned number will not change when the original variable are chaning.
        m_Heap[1] = m_Heap.back();
        m_Heap.pop_back();
        m_Heapsize--;
        FixDown(1);

    }

    void top() const
    {
        std::cout << m_Heap[1] << std::endl;
    }

    void print() const
    {
        // [0123] -> [123] m_Heapsize=3
        std::cout << "No dummy node at front: ";
        for (int i=1; i< m_Heapsize; i++)
            std::cout << m_Heap[i] << " ";
        std::cout << std::endl;
    }
};

int main()
{
    std::vector<int> o_vec = {81, 18, 14, 9, 7, 1, 5, 2, 4};
    PQ vec(o_vec);
    vec.push(9);
    vec.print();

    vec.pop();
    vec.print();

    vec.top();
    vec.print();
}