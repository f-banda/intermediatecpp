//insertion_sort
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

vector<int> arr;

//Implementing/Swapping insertion_sort

void insertion_sort(int n) {
	int min, j;
	for (int i = 1; i < n; i++) {
		min = arr[i];
		j = i;
		while (j > 0 && arr[j - 1] > min) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = min;
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

	insertion_sort(size);

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