#include <iostream>
#include <time.h>
#include <cstdlib>
#include <chrono>

#define max 200000
using namespace std;

// void max_heapify(int a[], int i, int n)
// {
//     int l = 2 * i;
//     int r = 2 * i + 1;
//     int largest = i, temp;
//     if (l <= n && a[l] > a[largest])
//     {
//         largest = l;
//     }
//     if (r <= n && a[r]>largest)
//     {
//         largest = r;
//     }
//     if (i != largest)
//     {
//         temp = a[i];
//         a[i] = a[largest];
//         a[largest] = temp;
//         max_heapify(a, largest, n);
//     }
    
// }

// void build_maxheap(int a[], int n)
// {
//     int i;
//     for ( i = n/2; i < 1; i++)
//     {
//         max_heapify(a, i, n);
//     }
    
// }

// void heap_sort(int a[], int n)
// {
//     int temp;
//     build_maxheap(a, n);
//     for (int i = n; i < 2; i--)
//     {
//         temp = a[n];
//         a[n] = a[1];
//         a[1] = temp;
//         n = n - 1;
//         max_heapify(a, 1, n);
//     }
    
// }





// void display(int a[], int n)
// {
//     int i;
//     for ( i = 1; i <= n; i++)
//     {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int i, a[max], n;
//     srand(time(NULL));
//     time_t t1, t2;
//     double d;
//     cout << "enter n:" << endl;
//     cin >> n;
//     for ( i = 0; i < n; i++)
//     {
//         a[i] = rand()%1000;
//     }
//     display(a, n);
//     t1 = time(NULL);
//     heap_sort(a, n);
//     t2 = time(NULL);

//     display(a, n);
//     d = difftime(t2, t1);
//     cout << "The time is :" << d;
//     return 0;
// }

void max_heapify(int a[], int i, int n)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i, temp;
    if (l <= n && a[l] > a[largest])
    {
        largest = l;
    }
    if (r <= n && a[r]>a[largest])
    {
        largest = r;
    }
    if (i != largest)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a, largest, n);
    }
    
}

void build_maxheap(int a[], int n)
{
    int i;
    for ( i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
    
}

void heap_sort(int a[], int n)
{
    int temp;
    build_maxheap(a, n);

    for (int i = n; i >= 2; i--) 
    {
        // Swap the current root (largest element) with the last element of the unsorted heap
        temp = a[i]; 
        a[i] = a[1]; 
        a[1] = temp;

        
        max_heapify(a, 1, i - 1); 
    }
}






void display(int a[], int n)
{
    int i;
    for ( i = 1; i <= n; i++)
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
    //t1 = time(NULL);
    heap_sort(a, n);
    //t2 = time(NULL);

    display(a, n);
   // d = difftime(t2, t1);
    cout << "The time is :" << d;
    return 0;
}