#include <iostre
int fibo(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else{
        int result;
        result = fibo(n - 1) + fibo(n - 2);
        return result;
    }
}

void main()
{
    print
}