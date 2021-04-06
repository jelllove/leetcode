#include "../../include/public.h"


class myException : public exception
{
public:
    myException(int id):errID(id)
    {}

    const char * what() throw()
    {
        str = "Error ID:";
        char buf[256] = {0};
        itoa(errID, buf, 10);
        str += buf;
        return str.c_str();
    }

private:
    int errID;
    string str;

};

int main()
{

    //---------throw an integer
    try
    {
        throw 789;
    }
    catch (int exp)/*no dedicated exception*/
    {
        cout<<"I got an exception value:"<<exp<<endl;
    }


    //---------throw a string
    try
    {
        throw "hello world";
    }
    catch (const char* str)
    {
        cout<<"I got an exception value:"<<str<<endl;
    }


    //---------throw a string
    try
    {
        throw string("hello world");
    }
    catch (string str)
    {
        cout<<"I got an exception value:"<<str<<endl;
    }


    //---------throw std exception 
    try
    {
        string str = "abc";
        string newStr = str.substr(100);
    }
    catch (std::exception e)
    {
        cout<<"I got an stl exception:"<<e.what()<<endl;
    }


    //specified a STD exception,
    try
    {
        throw runtime_error("it is wrong");
    }
    catch (runtime_error re)/*no dedicated exception*/
    {
        cout<<"runtime_error:"<<re.what()<<endl;
    }

    /*
      exception	description
    bad_alloc	thrown by new on allocation failure
    bad_cast	thrown by dynamic_cast when it fails in a dynamic cast
    bad_exception	thrown by certain dynamic exception specifiers
    bad_typeid	thrown by typeid
    bad_function_call	thrown by empty function objects
    bad_weak_ptr	thrown by shared_ptr when passed a bad weak_ptr
    */

    try
    {
        throw runtime_error("wrong");
    }
    catch (...)/*no dedicated exception*/
    {
        cout<<"There are some exception occurred"<<endl;
    }


    //Using custom exception class
    try
    {
        throw myException(5);
    }
    catch (myException me)
    {
        cout<<me.what()<<endl;
    }


    cout<<"I am not die yet"<<endl;


    return 0;
}