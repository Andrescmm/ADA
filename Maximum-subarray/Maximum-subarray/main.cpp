#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <vector>
using namespace std;
 
vector<int> FindMaxCrossingSubarray(int A[], int low, int mid, int high) {
    int left_sum = INT_MIN;
    int max_left;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = INT_MIN;
    int max_right;
    sum = 0;
    for (int j = mid + 1; j <= high; j++) {
        sum = sum + A[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }
    vector<int> res(3);
    res[0] = max_left;
    res[1] = max_right;
    res[2] = left_sum + right_sum;
    return res;
}
 
vector<int> FindMaximunSubarray(int A[], int low, int high) {
    vector<int> res(3);
    res[0] = low;
    res[1] = high;
    res[2] = A[low];
    if (high == low) {
        return res;
    }
    else {
        vector<int> left(3);
        vector<int> right(3);
        vector<int> cross(3);
        int mid = (low + high) / 2;
        left = FindMaximunSubarray(A, low, mid);
        right = FindMaximunSubarray(A, mid + 1, high);
        cross = FindMaxCrossingSubarray(A, low, mid, high);
        if (left[2] >= right[2] && left[2] >= cross[2]) {
            return left;
        }
        else if (right[2] >= left[2] && right[2] >= cross[2]) {
            return right;
        }
        else {
            return cross;
        }
    }
}
int main() {
  int tam = 1000000;
vector<int> max_sum;
  int* arr = new int[tam];
  srand(time(NULL));
  int aleatorio;
  for (int* i = arr; i < arr + tam; i++) {
      aleatorio = (-30) + (rand() % ((30)-(-30)+1));
      *i = aleatorio;
  }
  unsigned t0, t1;
  t0 = clock();
  max_sum = FindMaximunSubarray(arr, 0, tam - 1);
  t1 = clock();
  cout<< "Maximum contiguous sum is: " << endl;
  for (std::vector<int>::iterator it = max_sum.begin() ; it != max_sum.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
 
  double time = (double(t1 - t0) / CLOCKS_PER_SEC);
  cout << "Execution Time: " << time << endl;
}


//

