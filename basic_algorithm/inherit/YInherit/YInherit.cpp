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