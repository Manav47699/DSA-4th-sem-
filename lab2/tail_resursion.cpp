#include <iostream>
using namespace std;
int tailfact(int n, int a)

{
    if (n==0 || n==1)
        return a;
        else
            return tailfact(n - 1, a * n);    //(4, 5*1 = 5) -> (3, 4*5=20) -> (2, 60) -> (1, 120) -> base case
}

int main()
{
    cout << tailfact(5, 1);
}
