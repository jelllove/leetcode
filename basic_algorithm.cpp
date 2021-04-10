#include "include/public.h"

using namespace std;



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
    vector<int> vec = {2, 3, -2, 4};

    maxProduct(vec);

   // sortArrayByParityII(vec);

    
    return EXIT_SUCCESS;
}