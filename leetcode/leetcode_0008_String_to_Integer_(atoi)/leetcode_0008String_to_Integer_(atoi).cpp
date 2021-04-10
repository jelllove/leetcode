class Solution {
public:
    int myAtoi(string s) {
        char symbol = '\0';
        
        int ans = 0;
        
        int index = 0;
        
        //按题目要求去掉前面的空格
        //但是真正的atoi中，一开始的字符，只要不是数字的，都要过滤掉的
        while (index < s.size())
        {
            ////可以判断是不是数字或+-符号
            //if (isdigit(s[index]) || s[index] == '+' || s[index] == '-')
            //    break;
            
            if (!isspace(s[index]))
                break;
            ++index;
        }
        
        //依次向下找数字或+-符号
        while (index < s.size())
        {
            if (s[index] == '-' ||
                s[index] == '+')
            {
                if (symbol == '\0')
                {
                    //如果第一次遇上符号，然后之前有过数字或符号的，就结束
                    //因为可能是这样的"987-98"
                    if (index > 0 && !isspace(s[index - 1]))
                    {
                        break;
                    }
                    //否则就定一下符号
                    symbol = s[index];
                }
                else
                {
                    //如果不是第一次遇上符号的话，那就结束
                    //比如这样的  "-5-"
                    break;
                }
            }
            else if (isdigit(s[index]))
            {
                //得到数字
                int n = s[index] - '0';
                
                //如果是正数的话，用INT_MAX来判断
                if (symbol != '-')
                {
                    //简单来说，就是当前的ans准备 *１０
                    //乘上10之前，要看一下，是不是乘上10之后会超过INT_MAX
                    if ((ans > (INT_MAX / 10)) || //就是看一下当前的ANS是不是已经大于INT_MAX除10的结果了
                        (ans == (INT_MAX / 10)  && n >= (INT_MAX % 10))) //如果当前的ANS与INT_MAX除10后相等，那就要比一下最后一位加上去之后，是不是超过INT_MAX的最后一位
                    {
                        return INT_MAX;
                    }
                }
                else
                {
                    //如果是负数的话，用INT_MIN来判断，相同的理论
                    if ((ans > ((unsigned int)INT_MIN / 10)) || 
                        (ans == ((unsigned int)INT_MIN / 10)  && n >= ((unsigned int)INT_MIN % 10)))
                    {
                        return INT_MIN;
                    }
                }
                
                ans *= 10;
                ans += n;
            }
            else
            {
                //如果在前面已经过滤空格后，又一次遇上非数字的东西，那直接结束
                break;
            }
            ++index;
        }
        
        
        return (symbol == '-') ? -ans : ans;
        
        
    }
};