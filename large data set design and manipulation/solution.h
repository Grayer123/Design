#ifndef SOLUTION_H
#define SOLUTION_H

#include<vector>
#include<cstdlib>
#include<algorithm>
#include<cassert>

//compare function
template<typename T>
int compare(const void *a, const void* b)
{
    if (*(T*)a  == *(T*)b) {
        return 0;
    }
    if (*(T*)a  < *(T*)b) {
        return -1;
    } else {
        return 1;
    }
}

//Solution class defines all data and apis 
template<typename T>
class Solution
{
public:
    Solution() : m_size(0), m_data(NULL) {

    }

    void initialize(T *data, size_t size) {//, int(*cmp)(const void*, const void*)) {
        m_data = data;
        m_size = size;
        std::qsort(m_data, m_size, sizeof(T), compare<T>);
    }

    size_t query(T min, T max) {
        assert(min < max || min == max);
        T *min_p =  std::lower_bound(m_data, m_data + m_size, min);
        T *max_p = std::upper_bound(min_p, m_data + m_size, max);
        return (max_p - min_p);
    }

    size_t query(T val) {
        T *val_p =  std::lower_bound(m_data, m_data + m_size, val);
        return (m_data + m_size - val_p);
    }

private:
    Solution(const Solution&);

private:
    size_t m_size;
    T *m_data;
};

#endif // SOLUTION_H
