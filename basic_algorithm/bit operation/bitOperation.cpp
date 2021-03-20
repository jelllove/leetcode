#include "../../include/public.h"

using namespace std;



//Bit operation位的操作
void bitOperation()
{
    //不使用第三个变量的情况下，交换两个值
    int a = 4;
    int b = 3;

    cout << "Before exchange, a:"<<a<<", b: "<<b<<endl;
    a ^= b;
    b ^= a;
    a ^= b;

    cout << "after exchange, a:"<<a<<", b: "<<b<<endl;
    

    //计算一下这个数中有多少个1
    //利用这个 x &= (x-1)可以消除，最后一个1的原理
    int data = 897;
    while (data != 0)
    {
        bitset<32> bt(data);
        cout << bt.to_string() <<endl;
        data &= (data - 1);
    }


    ///将一个数的高位与地位进行互换
    unsigned char num = 231;
    cout<<"Before high/low exchange:" <<bitset<8>(num).to_string()<<endl;
    num = (num >> 4) | (num << 4);
    cout<<"After high/low exchange:" <<bitset<8>(num).to_string()<<endl;


    //将一个右边的N个位都设置成0
    num = 231;
    cout<<"Before set n zero:" <<bitset<8>(num).to_string()<<endl;
    num &= (~0 << 3);//右边的三位
    cout<<"After set n zero:" <<bitset<8>(num).to_string()<<endl;

    //将右边的第N位设置成0
    num = 231;
    cout<<"Before set the n zero:" <<bitset<8>(num).to_string()<<endl;
    num &= ~(1 << 2);//右边的二位
    cout<<"After set the n zero:" <<bitset<8>(num).to_string()<<endl;

    //将右边的第N位设置成1
    num = 231;
    cout<<"Before set the n one:" <<bitset<8>(num).to_string()<<endl;
    num |= (1 << 3);//右边的二位
    cout<<"After set the n one:" <<bitset<8>(num).to_string()<<endl;




}




int main(int argc, char *argv[])
{

    bitOperation();
    return EXIT_SUCCESS;

}