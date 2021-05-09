#include <iostream>

using namespace std;


class A
{
public:
    virtual void dummy()
    {
        cout<<"A -> dummy"<<endl;
    }
};

class B
{
public:
    virtual void dummy()
    {
        cout<<"B -> dummy"<<endl;
    }
};

//C同时从A和B中继承下来，这样的话，在C中同时存在了A和B的实现
class C: public A, public B
{
public:
    int m_c;

    void dummy()
    {
        cout<<"C-> dummy"<<endl;
    }
};


int main(int argc, char *argv[])
{
    C c;
    c.A::dummy();
    c.B::dummy();
    c.dummy();

    return EXIT_SUCCESS;
}