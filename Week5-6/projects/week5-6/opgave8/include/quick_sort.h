#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#include <vector>
#include <cassert>
#include "insertion_sort.h"
using namespace std;


const int useInsertion = 64; 

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	// Place pivot at position right - 1
	std::swap(a[center], a[right - 1]);

	// Now the partitioning
	Comparable& pivot = a[right - 1];
	int i = left, j = right - 1;
	do {
		while (a[++i] < pivot);
		while (pivot < a[--j]);
		if (i < j) {
			std::swap(a[i], a[j]);
		}
	} while (i < j);

	std::swap(a[i], a[right - 1]);	// Restore pivot
	return i;
}


template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right) {


	assert(left >= 0 && right < (int)a.size());

	if (right-left+1 > useInsertion) {
		int i = partition(a, left, right);
		quickSort(a, left, i - 1);
		quickSort(a, i + 1, right);
	} else {
		insertionSort(a.begin() + left, a.begin()+right+1);
	}
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable>
void quickSort(vector<Comparable>& a) {
	quickSort(a, 0, a.size() - 1);
}

#endif
