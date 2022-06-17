#include <iostream>
#include <vector>
#include <algorithm> // std::copy, std::shuffle
#include <random>

void Merge(std::vector<int>& vec, size_t left, size_t mid, size_t right)
{
    // “两个”vec一共有多少个数
    size_t n = right - left;
    // need a tmp vec for sorting
    std::vector<int> c(n);

    // mid:第二个vec开始的地方
    for (size_t i=left, j=mid, k=0; k<n; k++)
    {
        if (i == mid)
            c[k] = vec[j++];
        else if(j == right)
            c[k] = vec[i++];
        else
            c[k] = (vec[i] <= vec[j]) ? vec[i++] : vec[j++];
    }
    // 注意拷贝的位置：第一个vec开始的地方
    //（vec[left]第一个vector）（&vec[left]第一个vector的地址）
    std::copy(c.begin(), c.end(), &vec[left]);
}

void MergeSort(std::vector<int>& vec, size_t left, size_t right)
{
    // base case 0 or 1 item(s)
    if (right < left+2)
        return ;
    size_t mid = left + (right-left)/2;

    // 不是真的分成两个vector然后合并，而是告诉你，哪里是第一个vec，哪里是第二个vec
    MergeSort(vec, left, mid); // [left, mid)
    MergeSort(vec, mid, right); //[mid, right)
    Merge(vec, left, mid, right);
}

std::ostream& operator<<(std::ostream& out, std::vector<int>& vec)
{
    for (size_t i=0; i<vec.size(); i++)
        out << vec[i] << " ";
    return out;
}

int main(){
    std::vector<int> vec{2,9,3,4,7,5,8,6};
    MergeSort(vec, 0, vec.size());
    std::cout << vec << std::endl;
}