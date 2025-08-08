#include<iostream>
#include<cmath>
#include <time.h>
#define max 200000
using namespace std;

#define ARR_SIZE 10

using namespace std;

void Merge(int a[], int l, int m, int r){
    int i = l, j = m, k = l;
    int b[r-l+1];
    while(i<m && j<=r){
        if(a[i]<a[j]){
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    for(; i<m; i++, k++){
        b[k] = a[i];
    }
    for(; j<=r; j++, k++){
        b[k] = a[j];
    }

    for(k=l; k<=r; k++){
        a[k] = b[k];
    }
}

void MergeSort(int a[], int l, int r){
    if(l<r){
        int mid = floor((float)(l+r)/2);
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        Merge(a, l, mid+1, r);
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
    MergeSort(a, n);
    t2 = time(NULL);

    display(a, n);
    d = difftime(t2, t1);
    cout << "The time is :" << d;
    return 0;
}