#include <iostream>
using namespace std;

int rGCD(int a, int n)
{
    if (n == 0)
    {
        return a;
    }
    else
    {
        return rGCD(n, a % n);         //: (7, 20%7) -> (7, 6), (6, 7%6) -> (6, 1 ) -> (1, 6%1)-> (1,0),Base
    }

}


int main()
{
    cout << rGCD(20, 7);
}

