#include "../../include/public.h"


int main()
{

    cout<<"integer maximum value:" << INT_MAX <<endl;
    cout<<"integer minmum value:" << INT_MIN <<endl;

    //integer max = 2147483647
    //integer min = -2147483648

    //防止int溢出，方法1：
    //-------------------------------------------------------------
    //如果是两数相加后要取中间值的话，
    //相加的过程，可能会溢出
    int a = 2147483640;
    int b = 10;

    //想去a与b的中间值，直接相加的话，会溢出
    int c = (a + b) / 2;
    cout << "c = (a + b) / 2: "<< c <<endl;

    //可以利用先减，再除，再加
    c = (a - b) / 2 + b;
    cout << "c = (a - b) / 2 + b: "<< c <<endl;


    //可以利用位移，效率更高
    c = ((a - b) >> 1) + b;
    cout << "c = ((a - b) >> 1) + b: "<< c <<endl;


    //防止int溢出，方法2：
    //-------------------------------------------------------------
    //两数相加可能会溢出的话，要怎么判断
    //比如a + b = 2147483640, 大于int的最大值2147483647

    //直接相加一定会溢出
    c = (a + b);
    cout << "c = (a + b):"<<c <<endl;


    //如果先判断一下 INT_MAX - a，或INT_MAX - b后的值，就可以了

    if ((INT_MAX - a) >= b)
    {
        cout <<"No overflow"<<endl;
    }
    else
    {
        cout <<"Yes, it is overflow"<<endl;
    }


    //防止int溢出，方法3:
    //当你实现一个strtoint()的时候，比如转化一个 “2147483649”, 它明显是大于 int的最大值2147483648的。
    //那当你已经把前面的几位转成了  214748364的时候，最后一个如果加上9，就直接溢出了。
    //那要怎么在没有加上去之前先判断是否会超过
    int ans = 214748364;//当前已经转化好的值
    int n = 9; //准备加上去的


    //一般错误的做法
    ans *= 10;
    ans += n;
    cout << "ans with any adjustment: " <<ans<<endl;


    //正确的做法
    ans = 214748364;
    n = 8;
    //因为 ans要准备乘上10,所以要先保证ans乘10比INT_MAX要小
    if ((INT_MAX / 10) < ans)
    {
        cout <<"Ans is overflow"<<endl;
    }
    else
    {
        if ((INT_MAX / 10) == ans && (INT_MAX % 10) < n)
        {
            cout <<"Ans is overflow"<<endl;
        }
        else
        {
            cout <<"Ans is NOT overflow"<<endl;
        }
    }

    //也可以写成这样：
    if ((INT_MAX / 10) > ans || ((INT_MAX / 10) == ans && (INT_MAX % 10) < n))
    {
        cout <<"Ans is overflow"<<endl;
    }
    else
    {
        cout <<"Ans is NOT overflow"<<endl;
    }


    //如果是负数相加的话，那也可能会溢出
    //比如  -214748364，加  -9，就会溢出
    ans = -214748364;
    n = -9;
    ans *= 10;
    ans += n;
    cout<<"Negative overflow, ans:" << ans <<endl;


    ans = -214748364;
    n = -8;
    ans *= 10;
    ans += n;
    cout<<"Negative NOT overflow, ans:" << ans <<endl;
    

    ans = -214748364;
    n = -9;
    if (((unsigned)INT_MIN / 10) > -ans || (((unsigned)INT_MIN / 10) == -ans && ((unsigned)INT_MIN % 10) < -n))
    {
        cout <<"N-Ans is overflow"<<endl;
    }
    else
    {
        cout <<"N-Ans is NOT overflow"<<endl;
    }


    return 0;
}