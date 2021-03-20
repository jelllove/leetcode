#include "include/public.h"

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


//Bit operation位的操作
void bitOperation()
{
    //不使用第三个变量的情况下，交换两个值
    int a = 4;
    int b = 3;

    cout << "Before exchange, a:"<<a<<", b: "<<b<<endl;
    a ^= b;
    b ^= a;
    a ^= b;

    cout << "after exchange, a:"<<a<<", b: "<<b<<endl;
    

    //计算一下这个数中有多少个1
    //利用这个 x &= (x-1)可以消除，最后一个1的原理
    int data = 897;
    while (data != 0)
    {
        bitset<32> bt(data);
        cout << bt.to_string() <<endl;
        data &= (data - 1);
    }


    ///将一个数的高位与地位进行互换
    unsigned char num = 231;
    cout<<"Before high/low exchange:" <<bitset<8>(num).to_string()<<endl;
    num = (num >> 4) | (num << 4);
    cout<<"After high/low exchange:" <<bitset<8>(num).to_string()<<endl;


    //将一个右边的N个位都设置成0
    num = 231;
    cout<<"Before set n zero:" <<bitset<8>(num).to_string()<<endl;
    num &= (~0 << 3);//右边的三位
    cout<<"After set n zero:" <<bitset<8>(num).to_string()<<endl;

    //将右边的第N位设置成0
    num = 231;
    cout<<"Before set the n zero:" <<bitset<8>(num).to_string()<<endl;
    num &= ~(1 << 2);//右边的二位
    cout<<"After set the n zero:" <<bitset<8>(num).to_string()<<endl;

    //将右边的第N位设置成1
    num = 231;
    cout<<"Before set the n one:" <<bitset<8>(num).to_string()<<endl;
    num |= (1 << 3);//右边的二位
    cout<<"After set the n one:" <<bitset<8>(num).to_string()<<endl;




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