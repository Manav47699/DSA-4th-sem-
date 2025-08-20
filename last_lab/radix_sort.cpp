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
// make a array for each digit [0, 1, ...., 9] and initialize it to zero
    int count[10] = {0};

    // this loop give the count/frequency of each digit . eg: [2,3,..] -> this means that there are 2 o's and 3 1's and so on
    for (int i = 0; i < size; i++)
        count[(arr[i] / div) % 10]++;

    // this loop calculates the cumulative sum. meaning it gives us any idea of kun element lai kun position samma rakhne
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // This loop sorts the current elments form right to left. eg: it starts with 66 i.e. arry[7] = 66. Now it extracts 1's digit i.e. 6 from it
    // so count[6] i.e 8  - 1 = 7. so 66 is stored in output[7]


    //(arr[i] / div) % 10 → extracts the current digit we are sorting by:
    //count[] gives the cumulative sum
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / div) % 10] - 1] = arr[i];
        count[(arr[i] / div) % 10]--;
    }

    // copy output to arr
    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int size)
{
    int m = get_max(arr, size);   //max number in arr[]

// here "div" decides which digit we are sorting. initallly it is 1's, then 10's ... and so on
    for (int div = 1; m / div > 0; div *= 10)
        counting_sort(arr, size, div);
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
//   total bytes ÷ bytes per element = number of elements.
    int size = sizeof(arr) / sizeof(arr[0]);


    radixsort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
