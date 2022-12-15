//bubble_sort
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

vector<int> arr;

//Swapping array

void swap(int i, int j) {

	int copy = arr[i];
	arr[i] = arr[j];
	arr[j] = copy;

}

//Implementing bubble_sort
void bubble_sort(int n) {

	int i, j;

	bool swapped = false;
	bool sorted = false;

	while (!sorted) {

		swapped = false;

		for (i = 0; i < n - 1; i++) {

			j = i + 1;

			if (arr[j] < arr[i]) {

				swapped = true;

				swap(i, j);

			}

		}

		sorted = !swapped;

	}

}

int main()
{
	// Input .txt file into vector

	int size = 0;

	string num;

	while (cin >> num) {
		arr.push_back(stoi(num));

		size++;

	}

	bubble_sort(size);

	int width = 0;
	size_t index = 0;

	while (width < 8 && index < arr.size()) {

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

		if (index == arr.size()) {
			cout << "\n";
		}


	}

	return 0;
}