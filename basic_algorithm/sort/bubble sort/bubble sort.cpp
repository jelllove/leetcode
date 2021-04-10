#include "../../../include/public.h"

using namespace std;


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

int main(int argc, char *argv[])
{


    int data[] = {4, 2, 5, 6, 1, 9, 8, 7};

    printArray(data, sizeof(data) / sizeof(data[0]));
    bubbleSort(data, sizeof(data) / sizeof(data[0]));
    printArray(data, sizeof(data) / sizeof(data[0]));

    return EXIT_SUCCESS;

}