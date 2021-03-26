//
// Created by panda on 26-03-2021.
//

#include <iostream>

using namespace std;

int fact(int N);
int main()
{
    cout << fact(5);
}

int fact(int N)
{
    if (N==1)
        return 1;
    cout << N;
    return fact(N-1);
}