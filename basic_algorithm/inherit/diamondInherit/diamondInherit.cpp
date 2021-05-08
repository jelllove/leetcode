//菱形继承的问题

#include <iostream>

using namespace std;

class IBase
{
public:
    void dummy()
    {
        cout<<"IBase output"<<endl;
    }
};

class A : virtual public IBase
{
public:
    int m_a;
};

class B : virtual public IBase
{
public:
    int m_b;
};


class C : public A, public B
{
public:
    int m_c;
};


int main(int argc, char *argv[])
{
    C c;
    //c.dummy();   //这样会直接编译失败，因为编译器不知道使用哪一个
    //Method 1: 使用命名空间
    /*
    c.B::dummy();
    c.A::dummy();
    */
    //Method 2: using the virtual public
    c.dummy();

    return 0;
}