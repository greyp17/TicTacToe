#include <iostream>
#include <string>
using namespace std;

class TicTacToe {
    private:
        char board[3][3];// makes the Tic Tac Toe board
        char player;
        int* movesremainingptr;
        int movesremainingvalue;
    public:
    // Initialize the board and make the first player X
    TicTacToe() {
        player = 'X';
        movesremainingvalue = 9;//initializes value
        movesremainingptr = &movesremainingvalue;//pointer to the value
        int count = 1;
        //show slots 1-9 to show avalable spots
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                board[row][col] = '1' + count - 1;
                count++;
            }
        }
    }

    //Display board state
    void display() {
        cout << "board:\n";
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                cout << board[row][col] << " ";
            }
            cout << endl;
        }
    }

    //check if anyone has won
    bool checkWin() {
        //checks rows and columns
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }
        //checks diagonals
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

        return false;
    }

    //checks for a draw
    bool checkTie() {
        return *movesremainingptr == 0;
    }

    //swap between players
    void switchplayer() {
        player = (player == 'X') ? 'O' : 'X';
    }

    //players move
    bool move(int position) {
        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (position < 1 || position > 9 || board[row][col] == 'X'|| board[row][col] == 'O') {
            cout << "Illegal position.\n" << endl;
            return false;
        }
        board[row][col] = player;
        (*movesremainingptr)--;
        return true;
    }

    //Main loop
    void start() {
        int position;
        bool validMove = false;

        while (true) {
            // takes position and checks if its a legal move
            display();
            cout << "Player " << player << ", enter a position 1-9 Left to Right: ";
            cin >> position;

            validMove = move(position);
            // checks if the player wins
            if (validMove) {
                if (checkWin()) {
                    display();
                    cout << "Player " << player << ", won\n" << endl;
                    break;
                } else if (checkTie()) {
                    display();
                    cout << "Its a tie\n" << endl;
                    break;
                }

                switchplayer();
            }
        }
    }
};

int main() {
    TicTacToe game;
    game.start();
    return 0;
}