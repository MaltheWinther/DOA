#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include "quick_sort.h"

using namespace std;
using namespace std::chrono;

vector<int> generateRandom(int size) { //Generates a random number to fill our vector with.
    vector<int> v(size);
    auto f = []() -> int { return rand() % 1000000; };
    generate(v.begin(), v.end(), f);
    return v;
}

int main() {
    vector<int> sizes = {100, 1000, 10000, 100000};

    cout << "Testing our IntroSort (useInsertion = " << useInsertion << ")" << endl;

    for (int size : sizes) {
        vector<int> v = generateRandom(size);

        auto start = high_resolution_clock::now();
        quickSort(v);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "N = " << size << " \t Time: " << duration.count() << " microseconds" << endl;
    }

    cout << endl;
    cout << "Testing std::sort " << endl;

    for (int size : sizes) {
        vector<int> v = generateRandom(size);

        auto start = high_resolution_clock::now();
        sort(v.begin(), v.end());
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);
        cout << "N = " << size << " \t Time: " << duration.count() << " microseconds" << endl;
    }

    return 0;
}
