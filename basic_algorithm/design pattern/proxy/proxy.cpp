#include <iostream>

using namespace std;

//接口类
class IBoy
{
public:
    virtual void Proposal() = 0;
};

//害羞男孩
class CShyBoy : public IBoy
{
public:
    void Proposal()
    {
        cout<<"Would you marry me?"<<endl;
    }
};

//粗鲁男孩
class CToughBoy : public IBoy
{
public:
    void Proposal()
    {
        cout<<"Would you marry me?"<<endl;
    }
};

//代理类，为什么代理类也要继承呢，因为它也要实现那个Proposal的函数
//这样的话，从最后的结果来看，就是一个IBOY进行一个proposal的操作，但是你看不到到底是谁来做的proposal
class CProxy : public IBoy
{
public:
    CProxy(IBoy *pBoy) : m_boy(pBoy)
    {

    }

    void Proposal()
    {
        //Pre-action
        //.....


        if (m_boy != nullptr)
            m_boy->Proposal();

        //Post-action
        //.......
    }
private:
    IBoy *m_boy = nullptr;
};


int main(int argc, char *argv[])
{
    CShyBoy shyBoy;

    CProxy proxy(&shyBoy);
    proxy.Proposal();


    return EXIT_SUCCESS;
}