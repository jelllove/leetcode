#include "include/public.h"
#include <stdlib.h>
#include <string.h>

vector<int> getNext(string needle)
    {
        if (needle.size() == 0)
            return vector<int>();
        
        vector<int> next(needle.size(), 0);
        
        next[0] = 0;
        
        for (int q = 1, k = 0; q < needle.size(); ++q)
        {
            while (k > 0 && needle[q] != needle[k])
            {
                k = next[k - 1];
            }
            
            if (needle[q] == needle[k])
                ++k;
            
            next[q] = k;
        }
        
        return next;
    }

int main(int argc, char *argv[])
{
    
    char p[] = "abcac";
    int next[5] = {0};
    getNext("abdcabd");
    
    return EXIT_SUCCESS;
}