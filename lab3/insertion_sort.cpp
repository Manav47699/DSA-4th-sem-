#include <iostream>
#include <time.h>
#define max 200000
using namespace std;



// inseration sort: There is like a curtain, that is increase by 1 at each pass. the LHS of the curtain is sorted and the RHS is unsorted. At the end , the curtain reaches the end and all the elements are kept at the LHS meaning they are all sorted.
void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){           //we start with 1 as we consider 1st elment to be sorted
        int j = i - 1;
        int temp = a[i];         // stores current element

        //'temp' is the element ahead of 'a[j]'
        //we dont swap directly as insertion sort uses shifting and not swapping
        while(j >= 0 && temp < a[j]){
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
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








/*
Example for : 5 4 2 3 1
temp = a[1] = 4

j = 0 → compare 4 with a[0] = 5

4 < 5 → shift 5 to the right
Array becomes: 5 5 2 3 1

j = -1 → stop while loop

Place temp in a[0]:
4 5 2 3 1

✅ End of iteration 1 → Sorted part: 4 5

_____________________________________________
temp = a[2] = 2

j = 1 → compare 2 with a[1] = 5 → shift right
4 5 5 3 1

j = 0 → compare 2 with a[0] = 4 → shift right
4 4 5 3 1

j = -1 → stop

Place temp in a[0]:
2 4 5 3 1

✅ End of iteration 2 → Sorted part: 2 4 5

*/