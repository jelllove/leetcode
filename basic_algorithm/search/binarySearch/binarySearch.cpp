#include "../../../include/public.h"

using namespace std;



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




int main(int argc, char *argv[])
{


    int data[] = {4, 2, 5, 6, 1, 9, 8, 7};

    sort(data, data + sizeof(data) / sizeof(data[0]));

    if (binaryFind(data, 0, sizeof(data)/sizeof(data[0]) - 1, 8))
        cout<<"Found"<<endl;
    else
        cout<<"Not found"<<endl;

    return EXIT_SUCCESS;

}