#include <iostream>
#include <time.h>
#define max 200000

using namespace std;

//Bubble sort works by repatedly comparing the next element with the current elemnet and if the current element is bigger than the next element, swap.

void bubble_sort(int a[], int n)
{
    int j, k, temp;
    for (int i = 0; i < n-1; i++)           // all the elements are sorted after 'n-1' passes in bubblesort
    {
        for (int j = 0; j < n-1-i; j++)     // total elements - the sorted elements
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
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
    srand(time(NULL));      //this ensures random number everytime
    time_t t1, t2;
    double d;

    cout << "enter n:" << endl;
    cin >> n;
    for ( i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }
    display(a, n);
    t1 = time(NULL);       //captures start and end time
    bubble_sort(a, n);
    t2 = time(NULL);

    display(a, n);
    d = difftime(t2, t1);          //measures duration of sort
    cout << "The time is :" << d;  
    return 0;
}