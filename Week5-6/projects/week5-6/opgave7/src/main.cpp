#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(const vector<int>& input, int k) {
    vector<int> count(k + 1, 0);
    vector<int> output(input.size());

   
    for (int i = 0; i < input.size(); i++) {
        count[input[i]] = count[input[i]] + 1;
    }

   
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];
    }

    
    for (int i = input.size() - 1; i >= 0; i--) {
        int j = input[i];
        count[j] = count[j] - 1;
        output[count[j]] = input[i];
    }

    return output;
}

int main() {
    vector<int> A {8,2,1,6};

    vector<int> sorted = countingSort(A, 8); // Output [1,2,6,8]

    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    cout << endl; 

    return 0;
}