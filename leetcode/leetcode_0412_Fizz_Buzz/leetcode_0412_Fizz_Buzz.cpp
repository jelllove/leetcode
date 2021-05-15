class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        //Method 1: using the multiple if condition.
        /*
        vector<string> ans;
        
        for (int i = 1; i <= n; ++i)
        {
            if (i % 3 == 0)
            {
                if (i % 5 == 0)
                {
                    ans.push_back("FizzBuzz");
                }
                else
                {
                    ans.push_back("Fizz");
                }
            }
            else if (i % 5 == 0)
            {
                ans.push_back("Buzz");
            }
            else
            {
                ans.push_back(to_string(i));
            }
        }
        
        return ans;
        */
        
        //Method 2: using less if condition
        vector<string> ans;
        string str = "";
        for (int i = 1; i <= n; ++i)
        {
            str = "";
            if (i % 3 == 0)
            {
                str = "Fizz";
            }
            
            if (i % 5 == 0)
            {
               str += "Buzz";
            }
            
            if (str == "")
            {
                ans.push_back(to_string(i));
            }
            else
            {
                ans.push_back(str);
            }
        }
        
        return ans;
    }
    
};