#include <iostream>

using namespace std;

class IFruit
{
public:
    virtual void makeJuice() = 0;
};

class CApple : public IFruit
{
public:
    void makeJuice()
    {
        cout<<"Apple juice done"<<endl;
    }
};


class COrange : public IFruit
{
public:
    void makeJuice()
    {
        cout<<"Orange juice done"<<endl;
    }
};

class CFruitFactory
{
public:
    static IFruit* getFruit(int fruitID)
    {
        IFruit *ret = nullptr;
        switch (fruitID)
        {
        case 0:
            ret = new CApple();
            break;

        case 1:
            ret = new COrange();
            break;
        
        default:
            break;
        }
        return ret;
    }
};


int main(int argc, char *argv[])
{
    IFruit *pFruit = CFruitFactory::getFruit(0);

    if (pFruit != nullptr)
    {
        pFruit->makeJuice();
        delete pFruit;
        pFruit = nullptr;
    }


    pFruit = CFruitFactory::getFruit(1);

    if (pFruit != nullptr)
    {
        pFruit->makeJuice();
        delete pFruit;
        pFruit = nullptr;
    }
        




    return EXIT_SUCCESS;
}