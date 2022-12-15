//Francisco Banda CSCI241 Queens
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void printBoard(int board[8][8]) {

	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){

			cout << board[i][j] << " ";

		}
		cout << endl;
	}
}

bool possible(int board[8][8], int row, int col, int n) {
    int i, j;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i = row, j = col; j < n && i < n; i++, j++)
        if (board[i][j])
            return false;

    for (j = 0; j < col; j++)
        if (board[row][j])
            return false;

    for (j = col; j < n; j++)
        if (board[row][j])
            return false;

    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row; i < n; i++)
        if (board[i][col])
            return false;

    return true;
}

int main(){
	
    int board[8][8];

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {

            board[i][j] = possible(board, i, j, 8);


        }



    }

    printBoard(board);
    return 0;

}