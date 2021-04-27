#include <iostream>

using namespace std;


//Product A: Keyboard
class IKeyBoard
{
public:
    virtual void typing() = 0;
};


class CLogicKeyboard : public IKeyBoard
{
public:
    void typing()
    {
        cout << "I am Logic brand keyboard, and typing now...." << endl;
    }
};

class CMicrosoftKeyboard : public IKeyBoard
{
public:
    void typing()
    {
        cout << "I am Microsoft brand keyboard, and typing now...." << endl;
    }
};


//Product B: Mouse
class IMouse
{
public:
    virtual void move() = 0;
};

class CLogicMouse: public IMouse
{
public:
    void move()
    {
        cout << "I am Logic brand mouse, and moving now...." << endl;
    }
};

class CMicrosoftMouse: public IMouse
{
public:
    void move()
    {
        cout << "I am Microsoft brand mouse, and moving now...." << endl;
    }
};


// Factory interface class;
class IFactory
{
public:
    virtual IKeyBoard* createKeyboard() = 0;
    virtual IMouse* createMouse() = 0;
};

class CLogicFactory: public IFactory
{
public:
    IKeyBoard* createKeyboard()
    {
        return new CLogicKeyboard();
    }


    IMouse* createMouse()
    {
        return new CLogicMouse();
    }
};


class CMicrosoftFactory: public IFactory
{
public:
    IKeyBoard* createKeyboard()
    {
        return new CMicrosoftKeyboard();
    }


    IMouse* createMouse()
    {
        return new CMicrosoftMouse();
    }
};

int main(int argc, char *argv[])
{

    //Microsoft factory
    IFactory *pFactory = new CMicrosoftFactory();
    IKeyBoard *pKeyboard = pFactory->createKeyboard();
    IMouse *pMouse = pFactory->createMouse();

    pKeyboard->typing();
    pMouse->move();

    //Release resource
    delete pFactory;
    delete pKeyboard;
    delete pMouse;
    pFactory = nullptr;
    pKeyboard = nullptr;
    pMouse = nullptr;

    //Logic factory
    pFactory = new CLogicFactory();
    pKeyboard = pFactory->createKeyboard();
    pMouse = pFactory->createMouse();

    pKeyboard->typing();
    pMouse->move();

    //Release resource
    delete pFactory;
    delete pKeyboard;
    delete pMouse;
    pFactory = nullptr;
    pKeyboard = nullptr;
    pMouse = nullptr;


    return 0;
}