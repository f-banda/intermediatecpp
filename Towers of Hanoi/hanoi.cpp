//Francisco Banda CSCI241 Towers of Hanoi
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void move (int, int, int, int);

int main(int argc, char *argv[])
{
	int n = atoi(argv[1]);

	move(n, 1, 3, 2);

	return 0;
}

void move(int n, int src, int temp, int dest) {

	if (n == 1) {

		cout << "1 " << src << "->" << dest << endl;

		return;
	}
	move(n - 1, src, dest, temp);

	cout << "" << n << " " << src << "->" << dest << endl;

	move(n - 1, temp, src, dest);

}