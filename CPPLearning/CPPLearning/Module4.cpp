#include <iostream>
#include <cassert>
#include <vector>;
using namespace std;

constexpr int kNotFound = -1;

// Linear Search
int Search(int element, const int* v, int size) {
	for (int i = 0; i < size; i++) {
		if (v[i] == element) {
			return i;
		}
	}
	return kNotFound;
}

// Binary Search When Array is Sorted
int BinarySearch(int element, const int* v, int size) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int middle = (left + right) / 2;

		if (v[middle] == element) {
			return middle;
		}
		else if (v[middle] < element) {
			left = middle + 1;
		}
		else if(v[middle] > element) {
			right = middle - 1;
		}
	}
	return kNotFound;
}

void Print(const vector<int>& v) {
	cout << "[";
	for (int x : v) {
		cout << x << ' ';
	}
	cout << "]\n";
}

int main() {
	vector<int> v{ 11, 22, 33, 44, 55, 66 };
	Print(v);

	cout << "Element to search? ";
	int x;
	cin >> x;

	cout << '\n';

	int pos = BinarySearch(x, v.data(), v.size());
	if (pos == kNotFound) {
		cout << "Element not found.\n";
	}
	else {
		cout << "Element found at index " << pos << ".\n";
	}
}