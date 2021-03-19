#include "public.h"

//冒泡排序
template<class T>
void bubbleSort(T *data, size_t size)
{
    if (size <= 0)
    {
        return;
    }

    for (int i = size - 1; i >= 0; --i)
    {
        for (int j = 0; j <= i - 1; ++j)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j+1]);
            }
        }
    }
}


template<class T>
void printArray(T *data, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << ", ";
    }
    cout<<endl;
}

 
class classA
{
public:

    classA()
    {

    }
    classA(int ia, int ib, int ic): a(ia), b(ib), c(ic)
    {
        str = "hello";
        d[0] = ia;
        d[1] = ib;
        d[2] = ic;
    }
    
public:
    int a;
    int b;
    string str;
    int d[3]; 
private:
    int c;
};




int main(int argc, char *argv[])
{

    classA a(1, 2, 3);

    classA b;

    b = a;

    int d = 0;

    return EXIT_SUCCESS;

}