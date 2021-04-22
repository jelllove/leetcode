#include "../../include/public.h"

////Method 1，用文字的方式来的方式
void Hanota(int n, char A, char B, char C)
{
    if (n <= 0)
    {
        return;
    }
        

    Hanota(n - 1, A, C, B);
    cout<<"Move " << A << " -> " << C <<endl;
    Hanota(n - 1, B, A, C);
}


    vector<int> gA = {4, 3, 2, 1};
    vector<int> gB;
    vector<int> gC;


void printTower()
{
    int ia = gA.size() - 1;
    int ib = gB.size() - 1;
    int ic = gC.size() - 1;
    while (ia >= 0 || ib >= 0  || ic >= 0)
    {
        if (ia >= 0)
            printf("%8d", gA[ia--]);
        else
            printf("%8s", "");


        if (ib >= 0)
            printf("%8d", gB[ib--]);
        else
            printf("%8s", "");


        if (ic >= 0)
            printf("%8d", gC[ic--]);
        else
            printf("%8s", "");
        printf("\n");
    }

    printf("     ____    ____    ____  \n");
    printf("      A        B       C   \n\n");
}

//Method 2: 利用Vector，可以更形象的表示出来
void Hanota(int n, vector<int> &A, vector<int> &B, vector<int> &C)
{
    if (n <= 0)
    {
        return;
    }

    Hanota(n - 1, A, C, B);
    C.push_back(A.back());
    A.pop_back();
    printTower();
    Hanota(n - 1, B, A, C);
}

int main()
{
    //Hanota(20, 'A', 'B', 'C');
    printTower();
    Hanota(gA.size(), gA, gB, gC);

    return 0;
}