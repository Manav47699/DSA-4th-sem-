#include <iostream>
using namespace std;


void shell_sort(int array[], int n) {
  int gap = n / 2;
  while (gap > 0) {
    for (int i = gap; i < n; i++) {

// 'i' is the current elment and j is the target elments (i.e i+gap and i-gap)
// loops runs if j (i.e the current element) is found to be greated than the target elment ahead of it.
//as gap is divied by 2 every iteration, 'i' also decrease. so 'j' is also done j - gap after each iteration

//this loops runs when j is inside the current array(i.e 0 to 4) and j is bigger than j+gap (i.e swapping need to be done to bring the samller elment at front)
      for (int j = i - gap; j >= 0 && array[j] > array[j + gap]; j = j - gap) 


      {
        // Swap elements instead of shift
        int temp = array[j];
        array[j] = array[j + gap];
        array[j + gap] = temp;
      }
    }
    gap /= 2;
  }
}


// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int data[] = {100, 90, 4, 5, 21};
  
  shell_sort(data, 5);
  cout << "Sorted array: \n";
  printArray(data, 5);
}