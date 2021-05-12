#include "public.h"


string reverseWords(string str)
{
    vector<string> vecWords;
    
    int l = 0;
    int i = 1;
    for (; i < str.size(); ++i)
    {
        if (!isalpha(str[i]))
        {
            if (isalpha(str[l]))
            {
                vecWords.push_back(str.substr(l, i - l));
                l = i;
            }
        }
        else
        {
            if (!isalpha(str[l]))
            {
                vecWords.push_back(str.substr(l, i - l));
                l = i;
            }
        }
    }

    vecWords.push_back(str.substr(l, i - l));

    //------------------------------------------------------------
    int s = 0, e = vecWords.size() - 1;

    while (s < e)
    {
        while (s < e && !isalpha(vecWords[s][0]))
        {
            ++s;
        }

        while (s < e && !isalpha(vecWords[e][0]))
        {
            --e;
        }

        if (s < e)
        {
            swap(vecWords[s], vecWords[e]);
            --e;
            ++s;
        }
            
    }

    //-------------------------------------------------------
    string ret = "";
    for (auto &it : vecWords)
    {
        ret += it;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    string str = reverseWords("hello world");

    str = reverseWords("hello world  _");
    str = reverseWords("hello----world++this is new   world!!");
    
    return EXIT_SUCCESS;
}