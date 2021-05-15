
//Method 1: using the random value
/*
class Solution {
public:
    Solution(vector<int>& nums) {
        m_numsOrg = nums;
        m_numsCur = nums;
    }
    
    // Resets the array to its original configuration and return it. 
    vector<int> reset() {
        m_numsCur = m_numsOrg;
        return m_numsCur;
    }
    
    // Returns a random shuffling of the array.
    vector<int> shuffle() {
        vector<int> result(m_numsCur);
        
        for (int i = 1; i < result.size(); ++i)
        {
            swap(result[i], result[rand() % (i + 1)]);
        }
        
        return result;
    }
private:
    vector<int> m_numsOrg;
    vector<int> m_numsCur;
};
*/


//Method 2: using the random_shuffle

class Solution {
public:
    Solution(vector<int>& nums) {
        m_numsOrg = nums;
        m_numsCur = nums;
    }
    
    // Resets the array to its original configuration and return it. 
    vector<int> reset() {
        m_numsCur = m_numsOrg;
        return m_numsCur;
    }
    
    // Returns a random shuffling of the array.
    vector<int> shuffle() {
        
        random_shuffle(m_numsCur.begin(), m_numsCur.end());
        
        return m_numsCur;
    }
private:
    vector<int> m_numsOrg;
    vector<int> m_numsCur;
};

    