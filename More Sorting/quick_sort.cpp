//Francisco Banda CSCI241 - quick_sort

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

int half (int arr[], int low, int high) {

	int piv = arr[high];
	int i = (low - 1);

	//If less than, add then swap
	for (int b = low; b <= high - 1; b++) {

		if (arr[b] <= piv) {
			i++;
			swap(&arr[i], &arr[b]);

		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

//Implementing quick_sort, where low is the starting index, and high is the ending index
void quick_sort(int arr[], int low, int high) {

	if (low < high) {

		//Half the array 2
		int piv = half(arr, low, high);

		//Sort separately
		quick_sort(arr, low, piv - 1);
		quick_sort(arr, piv + 1, high);

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

		quick_sort(arr, 0, size - 1);

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