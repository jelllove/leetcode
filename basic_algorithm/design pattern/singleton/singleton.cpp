#include <iostream>
#include <mutex>

using namespace std;


class CAutoLock
{
public:
    CAutoLock(mutex *pLock) : m_lock(pLock)
    {
        m_lock->lock();
    }

    ~CAutoLock()
    {
        m_lock->unlock();
    }

    void Lock()
    {
        if (m_lock != nullptr)
            m_lock->lock();
    }
    void unlock()
    {
        if (m_lock != nullptr)
            m_lock->unlock();
    }

private:
    mutex *m_lock = nullptr;
};

class CSingleton
{
public:
    void WhoAmI()
    {
        printf("I am: %x\n", (void *)this);
    }

    static CSingleton *getInstance()
    {
        if (p == nullptr)
        {
            CAutoLock al(&lockA);
            if (p == nullptr)
            {
                p = new CSingleton();
            }
        }
        
        return p;
    }
private:
    static mutex lockA; 
private:
    static CSingleton *p;
    CSingleton() //放在private下面，是为了不让它进行一个初始化，这样就只能使用getInstance来得到返回值了
    {
    }


    CSingleton(const CSingleton &other)
    {
    }

};

//初始化这个静态指针
CSingleton* CSingleton::p = nullptr;
mutex CSingleton::lockA;





int main(int argc, char *argv[])
{
    
    CSingleton *g = CSingleton::getInstance();

    g->WhoAmI();
    
    g = CSingleton::getInstance();

    g->WhoAmI();

    
    

    return EXIT_SUCCESS;
}