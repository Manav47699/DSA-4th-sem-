#include <iostream>
using namespace std;

int get_max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void counting_sort(int arr[], int size, int div)
{
    int output[size];
    
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;

    // Cumulative sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (stable, right-to-left)
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    // Copy back
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int size)
{
    int m = get_max(arr, size);

// here "div" decides which digit we are sorting. initallly it is 1's, then 10's ... and so on
    for (int div = 1; m / div > 0; div *= 10)
        counting_sort(arr, size, div);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);

    radixsort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
