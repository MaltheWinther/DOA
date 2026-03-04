#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
void selectionSort(vector<Comparable>& a) {
  for (int i = 0; i < a.size(); i++) {
    int minIndex = i;

    for (int j = i + 1; j < a.size(); j++) {
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }

    // Swap a[i] with the smallest element
    Comparable temp = std::move(a[i]);
    a[i] = std::move(a[minIndex]);
    a[minIndex] = std::move(temp);
  }
}

int main() {
  vector<int> A {1, 4, 2, 3, 6, 5,24,25};

  vector<int> B {6, 5, 4, 3, 2, 1,14,23,46};

  

  selectionSort(A);
  selectionSort(B);

  std::cout << "Test A:" << std::endl;

  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << endl;
  }

  std::cout << "Test B:" << std::endl;

  for (int i = 0; i < B.size(); i++) {
    cout << B[i] << endl;
  }

  return 0;
}