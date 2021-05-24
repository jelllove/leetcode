#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
    //share_ptr usage


    shared_ptr<int> sh(new int[10], std::default_delete<int[]>());
    shared_ptr<int> sh1 = std::make_shared<int>(20);

    return 0;
}

