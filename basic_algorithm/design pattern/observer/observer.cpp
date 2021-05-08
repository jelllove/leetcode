#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>

using namespace std;

//观察者模式

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




class ISubject
{
public:
    virtual void attachObserver(IObserver *pObserver) = 0;
    virtual void detachObserver(IObserver *pObserver) = 0;
    virtual void HandleMsg(char *msg) = 0;
};


class CMsgCenter : public ISubject
{
public:
    void attachObserver(IObserver *pObserver)
    {
        observerList.push_back(pObserver);
    }

    void detachObserver(IObserver *pObserver)
    {
        for (int i = 0; i < observerList.size(); ++i)
        {
            if (observerList[i] == pObserver)
            {
                observerList.erase(observerList.begin() + i);
                return;
            }
        }
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
    ISubject *subject = new CMsgCenter;

    IObserver *a = new CAObserver;
    IObserver *b = new CBObserver;

    subject->attachObserver(a);
    subject->attachObserver(b);

    subject->HandleMsg((char *)"Hello");
    subject->HandleMsg((char *)"你好");

    subject->detachObserver(b);

    subject->HandleMsg((char *)"Hello");
    subject->HandleMsg((char *)"你好");

    return EXIT_SUCCESS;
}