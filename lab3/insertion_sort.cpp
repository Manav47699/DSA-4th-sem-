#include <iostream>
#include <time.h>
#define max 200000
using namespace std;



// inseration sort: There is like a curtain, that is increase by 1 at each pass. the LHS of the curtain is sorted and the RHS is unsorted. At the end , the curtain reaches the end and all the elements are kept at the LHS meaning they are all sorted.
void insertion_sort(int a[], int n){
    for(int i = 1; i < n; i++){           //we start with 1 as we consider 1st elment to be sorted
        int j = i - 1;
        int temp = a[i];

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