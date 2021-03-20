#include "../../../include/public.h"

using namespace std;



//快速排序
template<class T>
void quickSort(T *data, int l, int r)
{
    if (l >= r)
        return;
    int i = l;
    int j = r;

    int ref = data[i];
    while (i < j)
    {
        while (data[j] > ref && j > i)
            --j;
        data[i] = data[j];
        while (data[i] < ref && j > i)
            ++i;
        data[j] = data[i];
    }
    data[i] = ref;
    quickSort(data, l, i - 1);
    quickSort(data, i + 1, r);
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
    quickSort(data, 0, sizeof(data) / sizeof(data[0]) - 1);
    printArray(data, sizeof(data) / sizeof(data[0]));

    return EXIT_SUCCESS;

}