//这个是一个是例子去解释override, overload, overwrite

#include <iostream>
using namespace std;


//overload
//--------------------------------------------------------------------------------------------
/*
			（1）相同的范围（在同一个类中）；
			（2）函数名字相同；
			（3）参数不同；
            （4）virtual 关键字可有可无。
*/
int getResult(int a);
int getResult(int a, int b);

class COverLoadExample
{
public:
    void setNum(int a);
    bool setNum(int a, int b);
};



//override
//--------------------------------------------------------------------------------------------
/*
			（1）不同的范围（分别位于派生类与基类）；
			（2）函数名字相同；
			（3）参数列表完全相同；
            （4）基类函数必须有virtual 关键字。
*/
class A
{
public:
    virtual void MyABC(int a)
    {
        cout<<"Here is the A"<<endl;
    }
};

class B : public A
{
public:
    void MyABC(int a)
    {
        cout<<"I am B"<<endl;
    }
};



//overwrite
//--------------------------------------------------------------------------------------------
/*
			（1）如果派生类的函数与基类的函数同名，但是参数不同。那么此时，不论有无virtual关键字，基类的函数将被隐藏（注意别与重载混淆）。
            （2）如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。那么此时，基类的函数被隐藏（注意别与覆盖混淆）。
*/
class C
{
public:
    bool getR(int a)
    {
        cout<<"C getR"<<endl;
        return true;
    }
    void myPrint(int a);
};

class D: public C
{
public:
    bool getR(int a)
    {
        cout<<"D getR"<<endl;
        return false;
    }

    bool myPrint()
    {
        cout<<"D print"<<endl;
        return true;
    }

};

int main(int argc, char *argv[])
{

    D d;
    d.getR(2);
    d.myPrint();

    return EXIT_SUCCESS;
}