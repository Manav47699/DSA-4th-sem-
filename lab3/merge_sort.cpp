#include<iostream>
#include<cmath>

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


void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main(){
    int a[ARR_SIZE] = {12, 17, 2, -1, 0, 1, 15, 100, 8, 19};

    printArray(a, ARR_SIZE);
    MergeSort(a, 0, ARR_SIZE-1);
    printArray(a, ARR_SIZE);
    
};