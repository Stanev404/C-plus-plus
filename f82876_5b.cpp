#include <iostream>
#include <vector>

using namespace std;

const int diffX[8] = { 1, 1, -1, -1, 2, -2, 2, -2 };
const int diffY[8] = { 2, -2, 2, -2, 1, 1, -1, -1 };


class Board
{
public:
	Board(int s, int x, int y) : x(x), y(y) {
		i = 1;
		n = s;
		board = new int *[n];
		for (int i = 0; i < n; i++) {
			board[i] = new int[n];
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				board[i][j] = 0;
			}
		}
	}

	void print() {
		for (int j = n; j > 0; j--) {
			for (int i = 0; i < n; i++) {
				cout << board[j - 1][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	bool flag = false;
	void nextMove(int x, int y, int i) {
		if (flag) return;
		board[x][y] = i;
		if (i == n*n) { this->print(); flag = true; return; }
		for (int k = 0; k < 8; k++) {
			if (flag) return;
			int newX = x + diffX[k]; int newY = y + diffY[k];
			if ((newX >= 0 && newX < n && newY >= 0 && newY < n) && (0 == board[newX][newY]))
				nextMove(newX, newY, i + 1);
			if (flag) return;
		}
		if (flag) return;
		board[x][y] = 0;
	}

	~Board() {

		for (int i = 0; i < n; i++) {
			delete[] board[i];
		}
		delete[] board;


	}

private:
	int ** board;
	int n;
	int i, x, y;
};






int main() {

	int n, x, y;
	while (cin >> n >> x >> y){
		Board ivan(n, x, y);
		if (n <= 4) ivan.print();

		else ivan.nextMove(x - 1, y - 1, 1);
	}
	return 0;
}
a