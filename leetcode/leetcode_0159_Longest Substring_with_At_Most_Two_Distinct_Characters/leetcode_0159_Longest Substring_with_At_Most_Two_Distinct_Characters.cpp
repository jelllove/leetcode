
class Solution {
public:
    int maxLen(string str)
    {
        unordered_map<char, int> hashTable;

        int len = std::numeric_limits<int>::min();
        int l = 0;
        for (int r = 0; r < str.size(); ++r)
        {
            hashTable[str[r]]++;
            if (hashTable.size() == 2)
            {
                len = max(len, r - l + 1);
            }
            else if (hashTable.size() > 2)
            {
                while (hashTable.size() > 2)
                {
                    hashTable[str[l]]--;
                    if (hashTable[str[l]] == 0)
                    {
                        hashTable.erase(str[l]);
                    }
                    ++l;
                }
            }
        }

        return len;
    }
};
