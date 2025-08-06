#include <iostream>
#include <time.h>
#define max 200000
using namespace std;

// void selection_sort(int a[], int n)
// {
//     int j, temp, min, pos, i;
//     for (i = 0; i < n; i++)
//     {
//         min = a[i];
//         pos = 1;
//         for (int j = i+1; j < n; j++)
//         {
//             if(a[j]<min)
//             {
//                 min = a[j];
//                 pos = j;
//             }
//         } 
//     }
//     if (i != pos)
//     {
//         temp = a[i];
//         a[i] = a[pos];
//         a[pos] = temp;
//     }
// }


// selection sort: The first element is compared witht the rest of the array. If any smaller element is found, it is swapped. When we do this in 1st pass, the first elemnet is now sorted. so in 2nd pass we start with 2nd element
void selection_sort(int a[], int n)
{
    
    int i, j, min, pos, temp; 
    for (i = 0; i < n - 1; i++)   //selection sort requires 'n-1' passses
    {
        // assume the 1st element is the smallest one
        min = a[i];
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            //the the next element is found to be larger, swap it with the minimum one
            if (a[j] < min)
            {
                min = a[j];
                pos = j;
            }
        }
        // if the position i is not at the smallest position, swap it
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
    selection_sort(a, n);
    t2 = time(NULL);

    display(a, n);
    d = difftime(t2, t1);
    cout << "The time is :" << d;
    return 0;
}