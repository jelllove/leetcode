#include "public.h"

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


//二分查找法(递归法), return the index
template<class T>
int binaryFind(T *data, int l, int r, T target)
{
    if (l == r)
    {
        return data[l] == target ? l : -1;
    }
    int mid = (r - l) / 2 + l;
    if (data[mid] == target)
        return mid;
    else if (data[mid] > target)
        return binaryFind(data, l, mid - 1, target);
    else
        return binaryFind(data, mid + 1, r, target);
}



//二分查找法(非递归法), return the index
template<class T>
int binaryFind2(T *data, int l, int r, T target)
{
    while (l < r)
    {
        int mid = (r - l) / 2 + l;
        if (data[mid] == target)
            return mid;
        else if (data[mid] > target)
            return binaryFind2(data, l, mid - 1, target);
        else
            return binaryFind2(data, mid + 1, r, target);
    }

    if (data[l] == target)
        return l;
    else
        return -1;
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
    int data[] = {1, 2, 4, 5, 6, 7, 9};

    cout << binaryFind2(data, 0, sizeof(data) / sizeof(data[0]) - 1, atoi(argv[1])) << endl;

    return EXIT_SUCCESS;

}