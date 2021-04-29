#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;


class IObserver
{
public:
    virtual void handleMsg(char *msg) = 0;
};

class CAObserver: public IObserver
{
public:
    void handleMsg(char *msg)
    {
        if (strcmp(msg, "Hello") == 0)
            cout<<"A: Hello"<<endl;
    }
};


class CBObserver: public IObserver
{
public:
    void handleMsg(char *msg)
    {
        if (strcmp(msg, "你好") == 0)
            cout<<"B: 你好啊"<<endl;
    }
};


class CMsgCenter
{
public:
    void addObserver(IObserver *pObserver)
    {
        observerList.push_back(pObserver);
    }

    void HandleMsg(char *msg)
    {
        for (auto &item : observerList)
        {
            item->handleMsg(msg);
        }
    }

private:
    vector<IObserver *> observerList;
};



int main(int argc, char *argv[])
{
    CMsgCenter msgCenter;

    CAObserver a;
    CBObserver b;

    msgCenter.addObserver(&a);
    msgCenter.addObserver(&b);

    msgCenter.HandleMsg((char *)"Hello");
    msgCenter.HandleMsg((char *)"你好");

    return EXIT_SUCCESS;
}