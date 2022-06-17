#include <iostream>
#include <vector>
#include <utility> // std::swap

enum ClassStanding : unsigned int
{
    Freshman, Sophomore, Junior, Senior
};

struct Student
{
public:
    ClassStanding classStand;

    Student(ClassStanding stand=Freshman)
            : classStand(stand) {}
};

// 最多有多少类，这里是4类
static size_t MAX = 4;

template <typename T>
void CountingSort(std::vector<Student>& students)
{
    // 先准备一个和待排序vector一样大的vector
    std::vector<T> tmp_vec(students.size());
    std::vector<size_t> counts(MAX);

    // 统计类一个类型的数量
    for (auto &s : students)
        ++counts[s.classStand];

    // calculate the offset from counts
    for (size_t i=1; i<MAX; i++)
        counts[i] += counts[i-1];

    // place the students into the right place
    for (auto &s: students)
    {
        // s的classstand == 0
        // (counts[0] - 1) vec的index从0开始
        // 假设大一有3个人：(counts[0] - 1) = (3-1) = 2 [从后面的位置开始填充]
        tmp_vec[counts[s.classStand] - 1] = s;
        // counts[0]=2,减少一个位置
        --counts[s.classStand];
    } // for

    // 把排好序的学生跟原来的swap一下
    // 这里也是为什么counting sort没有那么快的原因。因为不是inplace的
    std::swap(students, tmp_vec);
}

std::ostream& operator<<(std::ostream& out, const std::vector<Student>& vec)
{
    for (int i=0; i<vec.size(); i++)
        out << vec[i].classStand << " ";
    return out;
}

int main(){

    std::vector<Student> s(10, Freshman);
    s[3].classStand = Junior;
    s[6].classStand = Sophomore;
    s[9].classStand = Senior;
    std::cout << s << std::endl;

    CountingSort<Student>(s);
    std::cout << s << std::endl;
}