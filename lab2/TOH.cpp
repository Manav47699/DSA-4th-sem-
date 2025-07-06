//implementation of tower of hanoi
#include <iostream>
using namespace std;

int moves = 0;

void TOH(int n,char src,char dst,char temp)
{
    if (n==1)
    {
        cout << " Move disc " << n << " from " << src << " to " << dst << endl;
        moves++;
    }
    else
    {
        TOH(n - 1, src, temp, dst);
        cout << "Move disc " << n << " from " << src << " to " << dst << endl;
        TOH(n - 1, temp, dst, src);
        moves++;
    }
    
}

int main()
{
    
    int n;
    char src, dst, temp;
    TOH(3, 'A', 'C', 'B');
    cout << "The total number of moves = " << moves << endl;
    return 0;
}