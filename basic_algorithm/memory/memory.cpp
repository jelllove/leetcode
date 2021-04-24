#include <iostream>

int main(int argc, char *argv[])
{
    //这样的定义会导致栈溢出的，因为不同的OS给不同的APP定义的STACK的大小是固定的
    long m[8111110] = {0};
}