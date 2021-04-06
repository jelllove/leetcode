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
vector<int> sortArrayByParityII(vector<int>& nums) {
        
        
        if (nums.size() <= 1)
            return nums;
        int oddIndex = 1;
        int evenIndex = 0;
        
        while (oddIndex < nums.size() &&
              evenIndex < nums.size())
        {
            while (evenIndex < nums.size() && (nums[evenIndex] & 0x1 == 0))
            {
                evenIndex += 2;
            }
            
            
            while (oddIndex < nums.size() && (nums[oddIndex] & 0x1 == 0x1))
            {
                oddIndex += 2;
            }
            
            if (oddIndex < nums.size() &&
              evenIndex < nums.size())
            {
                swap(nums[oddIndex], nums[evenIndex]);
            }
            else
            {
                break;
            }
        }
        
        return nums;
    }
int maxProduct(vector<int>& nums) {
        int maxEnd = nums[0];
        int minEnd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int end1 = maxEnd * nums[0];
            int end2 = minEnd * nums[0];
            
            maxEnd = max(max(end1, end2), nums[i]);
            minEnd = min(min(end1, end2), nums[i]);
            
            ans = max(ans, maxEnd);
        }
        return ans;
    }

int main(int argc, char *argv[])
{
    vector<int> vec = {2, 3, -2, 4};

    maxProduct(vec);

   // sortArrayByParityII(vec);

    
    return EXIT_SUCCESS;
}