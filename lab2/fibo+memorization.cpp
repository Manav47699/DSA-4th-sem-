// fibonacci series with memorization
//fibonacci series = 1,1,2,3,5,8,13...



#include <iostream>
using namespace std;


#define MAX 10


int table[MAX] = {0};

int fiboM(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        if (table[n] != 0)                                        //check if table[n] is non zero. 
        {
            return table[n];
        }
        else{
            table[n] = fiboM(n - 1) + fiboM(n - 2);
            return table[n];

        }
     
    }
}


int main()
{

    cout << fiboM(5);
}