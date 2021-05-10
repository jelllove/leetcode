//C++ 11 lamda的用法
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
    //Define a lamda function
    auto lamdaA = []()->bool{return false;};

    if (lamdaA())
    {
        cout<<"Lamada true"<<endl;
    }
    else
    {
        cout<<"Lamada false"<<endl;
    }

    //Define a lamda function without return value
    auto lamdaB = [](){return true;};

    if (lamdaB())
    {
        cout<<"Lamada without return true"<<endl;
    }
    else
    {
        cout<<"Lamada without return false"<<endl;
    }


    //using the argument into the lamda
    auto lamdaC = [](int a, int b){return a + b + a*b;};
    cout<<"Lamda C:"<< lamdaC(4, 5)<<endl;


    //using the capacity list(Reference method) into the lamda
    int out_val = 9;
    auto lamdaD = [&out_val](){return ++out_val;};
    cout<<"Lamda D:"<< lamdaD()<<endl;


    //using the capacity list(Value method) into the lamda
    auto lamdaE = [out_val](){return out_val;};
    cout<<"Lamda E:"<< lamdaE()<<endl;


    //using the all Reference method into the lamda
    int val_a = 0;
    int val_b = 1;
    auto lamdaF = [&](){val_a++; val_b++;};
    lamdaF();
    cout<<"Lamda F:"<< val_a<<","<<val_b<<endl;


    //using the all Reference method into the lamda
    auto lamdaG = [this](){return this->val_a;};
    
    cout<<"Lamda G:"<< lamdaG()<<endl;




    return EXIT_SUCCESS;
}