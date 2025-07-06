#include <iostream>
#include <time.h>
#define max 200000
using namespace std;


void insertion_sort(int a[], int n)
{
    int i, j, min, pos, temp;
    for (i = 0; i < n - 1; i++)
    {
        min = a[i];
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                pos = j;
            }
        }
        if (i != pos)
        {
            temp = a[i];
            a[i] = a[pos];
            a[pos] = temp;
        }
    }
}

void display(int a[], int n)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int i, a[max], n;
    srand(time(NULL));
    time_t t1, t2;
    double d;
    cout << "enter n:" << endl;
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }
    display(a, n);
    t1 = time(NULL);
    insertion_sort(a, n);
    t2 = time(NULL);

    display(a, n);
    d = difftime(t2, t1);
    cout << "The time is :" << d;
    return 0;
}