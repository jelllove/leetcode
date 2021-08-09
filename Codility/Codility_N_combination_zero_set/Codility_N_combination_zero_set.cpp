
#include <algorithm>
#include <vector>

using namespace std;


vector<int> solution(int N) 
{
    vector<int> ans;
    if (N == 1)
        return {0};
    else 
    {
        for (int i = 1; i <= N/2; ++i)
        {
            ans.push_back(i);
            ans.push_back(-i);
        }

        if (N % 2 != 0)
            ans.push_back(0);
    }

    return ans;
}

int main(int argc, char *argv[])
{
    vector<int> res = solution(90);
    return EXIT_SUCCESS;
}