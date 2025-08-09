#include <iostream>
#include <time.h>
#define max 200000

using namespace std;
int partiation(int a[], int l, int r)  // first call (a, 0, 4)    for  5 4 2 3 1
{
    int x = l, y = r;
    int pivot = a[l], temp;              //at first a[0]
    while (x < y)
    {
        while (a[x] <= pivot && x <= r)
        {
            x++;
        }
        while (a[y] > pivot && y >= l)
        {
            y--;
        }
        // at the end if x crosses y, swap a[y] with pivot i.e a[x]
        if (x<y)
        {
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
    
        }  
        
    }
    
    a[l] = a[y];
    a[y] = pivot;
    return y;      // return the pivot's new index
    
}


void quick_sort(int a[], int l, int r)
{
    if (l<r)
    {
        int p = partiation(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
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
    quick_sort(a, 0, n-1);
    t2 = time(NULL);

    display(a, n);
    d = difftime(t2, t1);
    cout << "The time is :" << d;
    return 0;
}