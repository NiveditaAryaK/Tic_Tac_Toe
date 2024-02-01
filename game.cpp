#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void drawBoard() {
        cout << "\t" << board[0] << " | " << board[1] << " | " << board[2] << "\n";
        cout << "\t---|---|---\n";
        cout << "\t" << board[3] << " | " << board[4] << " | " << board[5] << "\n";
        cout << "\t---|---|---\n";
        cout << "\t" << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

int humanMove() {
    int move;
    do {
            cout << "Enter your move: ";
            cin >> move;
    } while (move < 1 || move > 9 || board[move - 1] == 'X' || board[move - 1] == 'O');
    board[move - 1] = 'X';
    return move;
}

int computerMove() {
    int move;
    srand(time(0));
    do {
        move = rand() % 9;
    } while (board[move] == 'X' || board[move] == 'O');
    board[move] = 'O';
    return move;
}

int checkWin() {
    for (int i = 0; i < 9; i += 3)
        if (board[i] != '1' + i && board[i] == board[i + 1] && board[i] == board[i + 2])
            return board[i];
    for (int i = 0; i < 3; i++)
        if (board[i] != '1' + i && board[i] == board[i + 3] && board[i] == board[i + 6])
            return board[i];
    if (board[0] != '1' && board[0] == board[4] && board[0] == board[8])
        return board[0];
    if (board[2] != '3' && board[2] == board[4] && board[2] == board[6])
        return board[2];
       
    return 0;
}
int checkLose(){
          for (int i = 0; i < 9; i += 3)
        if (board[i] != '1' + i && board[i] == board[i + 1] && board[i] == board[i + 2])
            return -1;
    for (int i = 0; i < 3; i++)
        if (board[i] != '1' + i && board[i] == board[i + 3] && board[i] == board[i + 6])
            return -1;
    if (board[0] != '1' && board[0] == board[4] && board[0] == board[8])
        return -1;
    if (board[2] != '3' && board[2] == board[4] && board[2] == board[6])
        return -1;
   
    return 0;
}

int main() {
    int player = 1;
    int moves = 0;
    while (true) {
        drawBoard();
        if (player == 1) {
            humanMove();
            player = 2;
        } else {
            computerMove();
            player = 1;
        }
        moves++;
        if (checkWin() != 0) {
            drawBoard();
                cout << (player == 1 ? "Computer" : "You") << " wins!\n";
            break;
        }
        if(checkLose() != 0){
            drawBoard();
            cout<<(player == 1? "You":"Computer") << "wins!\n";
            break;
        }
        if (moves == 9) {
            drawBoard();
                cout << "Draw!\n";
            break;
        }
    }
         cout << "Do you want to play again? (y/n) ";
    char response;
         cin >> response;
    if (response == 'y') {
        main();
    }
    return 0;
}
