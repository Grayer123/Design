#include<cstdio>
#include<cstdlib>
#include<sys/time.h>
#include"solution.h"

const int min_size = 10000;
const int max_size = 100000000;

//function to calculate time difference
double time_diff(struct timeval x, struct timeval y)
{
	double x_ms, y_ms, diff;

	x_ms = (double)x.tv_sec * 1000000 + (double)x.tv_usec;
	y_ms = (double)y.tv_sec * 1000000 + (double)y.tv_usec;

	diff = (double)y_ms - (double)x_ms;

	return diff;
}

//to test int type
void test_case1()
{
    printf("testcase1(int test)\n");
    Solution<int> sol;
    for (int size = min_size; size <= max_size; size *= 10) {
        int *array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = rand() % size;
        }
        int min_val = rand() % size;
        int max_val = rand() % size;
        if (min_val > max_val) {
            int temp = min_val;
            min_val = max_val;
            max_val = temp;
        }
        sol.initialize(array, size);
        printf("\tsize %d, [%d - %d] query result:", size, min_val, max_val);
		    struct timeval before, after;
		    gettimeofday(&before, NULL);
        int num = sol.query(min_val, max_val);
        printf("\t%d,\n", num);
		    gettimeofday(&after, NULL);
		    printf("\ttotal time elapsed : %.0lf us;\n", time_diff(before, after));
        delete []array;
    }
    {
        int size = 1000;
        int *array = new int[size];
        for (int i = 0; i < size; ++i) {
            array[i] = rand()% size;
        }
        int min_val = array[rand()% size];
        int max_val = min_val;
        sol.initialize(array, size);
        printf("\tsize %d, [%d ] query result:", size, min_val);
        int num = sol.query(min_val, max_val);
        printf("\t%d\n", num);

        printf("\tsize %d, [%d - max ] query result:", size, min_val);
        num = sol.query(min_val);
        printf("\t%d\n", num);
        delete []array;
    }
}


//to test float type
void test_case2()
{
    printf("testcase2(float test)\n");
    Solution<float> sol;
    for (int size = min_size; size <= max_size; size *= 10) {
        float *array = new float[size];
        for (int i = 0; i < size; ++i) {
            array[i] = rand()/ (float)RAND_MAX;
        }
        float min_val = rand()/ (float)RAND_MAX;
        float max_val = rand()/ (float)RAND_MAX;
        if (min_val > max_val) {
            float temp = min_val;
            min_val = max_val;
            max_val = temp;
        }
        sol.initialize(array, size);
        printf("\tsize %d, [%f - %f] query result:", size, min_val, max_val);
        struct timeval before, after;
        gettimeofday(&before, NULL);
        int num = sol.query(min_val, max_val);
        printf("\t%d,\n", num);
        gettimeofday(&after, NULL);
        printf("\ttotal time elapsed : %.0lf us;\n", time_diff(before, after));
        delete []array;
    }
    {
        int size = 1000;
        float *array = new float[size];
        for (int i = 0; i < size; ++i) {
            array[i] = rand()/ (float)RAND_MAX;
        }
        float min_val = array[rand() % size];
        sol.initialize(array, size);
        printf("\tsize %d, [%f ] query result:", size, min_val);
        int num = sol.query(min_val, min_val);
        printf("\t%d\n", num);
        delete []array;
    }
}


//to define an int object class
class IntObj {
public:
    IntObj(int val = 0) : m_val(val) { }
    void setVal(int val) {
        m_val = val;
    }
    int getVal() {
        return m_val;
    }
    friend bool operator < (const IntObj& obj1, const IntObj& obj2) {
        return obj1.m_val < obj2.m_val;
    }
    friend bool operator == (const IntObj& obj1, const IntObj& obj2) {
        return obj1.m_val == obj2.m_val;
    }
private:
    int m_val;
};

//to test object type
void test_case3()
{
    printf("testcase3(IntObj test)\n");
    Solution<IntObj> sol;
    for (int size = min_size; size <= max_size; size *= 10) {
        IntObj *array = new IntObj[size];
        for (int i = 0; i < size; ++i) {
            array[i].setVal( rand() % size);
        }
        IntObj min_val(rand() % size);
        IntObj max_val(rand() % size);
        if (max_val < min_val ) {
            IntObj temp = min_val;
            min_val = max_val;
            max_val = temp;
        }
        sol.initialize(array, size);
        printf("\tsize: %d, [%d - %d] query result:", size,
               min_val.getVal(), max_val.getVal());
        struct timeval before, after;
        gettimeofday(&before, NULL);
        int num = sol.query(min_val, max_val);
        printf("\t%d,\n", num);
        gettimeofday(&after, NULL);
        printf("\ttotal time elapsed : %.0lf us;\n", time_diff(before, after));
        delete []array;
    }
}

int main()
{
    srand(0);
    test_case1();
    test_case2();
    test_case3();
    return 0;
}
