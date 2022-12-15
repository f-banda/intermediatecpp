//Francisco Banda CSCI241 - merge_sort

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

//Swapping array/elements

void swap(int* i, int* j) {

	int copy = *i;
	*i = *j;
	*j = copy;

}

//Implement merge_sort
void merge_in(int arr[], int l, int m, int r) {
	int i, j, k, lh, rh;
	//Sizing of both directions
	lh = m - l + 1; rh = r - m;
	int lhs[lh], rhs[rh];

	//Insertion Sort
	for (i = 0; i < lh; i++)
		lhs[i] = arr[l + i];
	for (j = 0; j < rh; j++)
		rhs[j] = arr[m + 1 + j];
	i = 0; j = 0; k = l;

	//Merging previous array with valid array
	while (i < lh && j < rh) {
		if (lhs[i] <= rhs[j]) {
			arr[k] = lhs[i];
			i++;
		}
		else {
			arr[k] = rhs[j];
			j++;
		}
		k++;
	}
	while (i < lh) {
		arr[k] = lhs[i];
		i++; k++;
	}
	while (j < rh) {
		arr[k] = rhs[j];
		j++;
		k++;
	}
}
void merge_sort(int arr[], int l, int r) {
	int m;
	if (l < r) {
		m = l + (r - l) / 2;
		// Sort first and second arrs
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge_in(arr, l, m, r);
	}
}

//Algorithm Implementation Above
//************************
//Visual Display Below

int main()
{
	// Input .txt file into vector, while also alligning it into rows/colums

	int size = 0;

	string num;

	vector<int> vec;

	while (cin >> num) {
		vec.push_back(stoi(num));

		size++;

	}

	int* arr = new int[size];
	arr = vec.data();

	merge_sort(arr, 0, size - 1);

	int width = 0;
	int index = 0;

	while (width < 8 && index < size) {

		cout << setw(8);

		if (width < 7) {

			width++;
			cout << arr[index];
		}
		else {
			cout << arr[index] << endl;
			width = 0;
		}

		index++;

		if (index == size) {
			cout << "\n";
		}


	}

	return 0;
}