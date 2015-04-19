//210503824
//Nhlakanipho Calvin Nsindane

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class TicTacToe {
public:
	TicTacToe();
	int PlayerStart();		// first player
	int Move(int row, int column);	// Moves
	void ResetGame();		// Reset
	int GetState();
	void DisplayBoard();	//board display
private:
	string board[3][3];		// a 2D board presentation
	int playerTurn;			// 1 for player 1 ,2 for player 2
	int gameState;			// active mode or disabled
	void UpdateGameState(int row, int column); //new game state 
	int CheckWin(int row, int column); //checking which player won
	int CheckDraw();
};

TicTacToe::TicTacToe() {
	this->ResetGame(); //game reset
}

int TicTacToe::PlayerStart() {
	srand(time(NULL));
	this->gameState = 1;
	this->playerTurn = rand() % 2 + 1;
	return playerTurn;
}

int TicTacToe::Move(int row, int column) {
	row--;
	column--;
	if (board[row][column] != "") {
		return -1;
	}
	else {
		board[row][column] = this->playerTurn == 1 ? "X" : "O";
		this->UpdateGameState(row, column);
	}
}

void TicTacToe::UpdateGameState(int r, int c) {
	TicTacToe::DisplayBoard();
	int won = TicTacToe::CheckWin(r, c);
	if (won) {
		this->gameState = 0;
	}
	else {
		int drew = TicTacToe::CheckDraw();
		if (drew) {
			this->gameState = 0;
			cout << "\nThe game was drawn!";
		}
		else {
			this->playerTurn = this->playerTurn == 1 ? 2 : 1;
			cout << "\nPlayer " << this->playerTurn << "'s turn!" << endl;
		}
	}

}

void TicTacToe::DisplayBoard() {
	for (int r = 0; r<3; r++) {
		for (int c = 0; c<3; c++) {
			if (board[r][c] == "") {
				cout << "   |";
			}
			else {
				cout << " " << board[r][c] << " |";
			}
		}
		cout << endl << "____________" << endl;
	}
}

int TicTacToe::CheckWin(int r, int c) {
	string ch = this->playerTurn == 1 ? "X" : "O";
	if (r == 0 && c == 0) {
		if ((board[0][0] == ch) && (board[0][1] == ch) && (board[0][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[0][0] == ch) && (board[1][0] == ch) && (board[2][0] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 0 && c == 1) {
		if ((board[0][1] == ch) && (board[1][1] == ch) && (board[2][1] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 0 && c == 2) {
		if ((board[0][0] == ch) && (board[0][1] == ch) && (board[0][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[2][0] == ch) && (board[1][1] == ch) && (board[0][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[0][2] == ch) && (board[1][2] == ch) && (board[2][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 1 && c == 0) {
		if ((board[0][0] == ch) && (board[1][0] == ch) && (board[2][0] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[1][0] == ch) && (board[1][1] == ch) && (board[1][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 1 && c == 1) {
		if ((board[0][0] == ch) && (board[1][1] == ch) && (board[2][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[2][0] == ch) && (board[1][1] == ch) && (board[0][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[1][0] == ch) && (board[1][1] == ch) && (board[1][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[0][1] == ch) && (board[1][1] == ch) && (board[2][1] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 1 && c == 2) {
		if ((board[1][0] == ch) && (board[1][1] == ch) && (board[1][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[0][2] == ch) && (board[1][2] == ch) && (board[2][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 2 && c == 0) {
		if ((board[0][0] == ch) && (board[1][0] == ch) && (board[2][0] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[2][0] == ch) && (board[1][1] == ch) && (board[0][2]) == ch) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[2][0] == ch) && (board[2][1] == ch) && (board[2][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 2 && c == 1) {
		if ((board[0][1] == ch) && (board[1][1] == ch) && (board[2][1] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[2][0] == ch) && (board[2][1] == ch) && (board[2][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	else if (r == 2 && c == 2) {
		if ((board[0][2] == ch) && (board[1][2] == ch) && (board[2][2] == ch)) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[2][0] == ch) && (board[2][1] == ch) && (board[2][2]) == ch) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
		else if ((board[0][0] == ch) && (board[1][1] == ch) && (board[2][2]) == ch) {
			cout << "Player " << this->playerTurn << " wins!";
			return 1;
		}
	}
	return 0;
}

int TicTacToe::CheckDraw() {
	int drew = 1;
	for (int r = 0; r<3; r++) {
		for (int c = 0; c<3; c++) {
			if (board[r][c] == "") {
				drew = 0;
			}
		}
	}
	return drew;
}

void TicTacToe::ResetGame() {
	for (int r = 0; r<3; r++) {
		for (int c = 0; c<3; c++) {
			board[r][c] = "";
		}
	}
	this->gameState = 0;
}

int TicTacToe::GetState() {
	return this->gameState;
}

int main() {
	TicTacToe game = TicTacToe();
	int playerStart = game.PlayerStart();
	cout << "Player " << playerStart << " Starts" << endl;
	game.DisplayBoard();
	while (game.GetState() != 0) {
		int r, c;
		cout << "Enter row:";
		cin >> r;
		cout << "Enter column";
		cin >> c;
		int v = game.Move(r, c);
		if (v == -1) {
			cout << "Invalid Move!\n";
		}
	}
	cout << "\nGame over\n";
	system("pause");
	return 0;
}
