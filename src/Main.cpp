#include <iostream>
#include <stdlib.h>
using namespace std;

/*
Title: Tic-Tac-Toe game with unbeatable AI
Author: Nathan Singiri
Resources: https://gsurma.medium.com/tic-tac-toe-creating-unbeatable-ai-with-minimax-algorithm-8af9e52c1e7d,
https://www.stechies.com/tic-tac-toe-cpp/
*/

/*
Possible extensions as of now:
- Implement minimax algorithm
- Convert from 2 player game to 1 player vs AI
- Better UI
- Modularize and place into different classes
- Utilize polymporphism/inheritance and h file integration
*/

// Global Variables
char user_answer;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int choice;
int row, column;
bool draw = false;
bool endGame = false;
int numMoves = 0;


//forward declarations
void displayBoard();
void playerTurn();
bool gameOver();
void validateInput();


void displayBoard()
{
    // current game board and info about who is who
    cout << " ----------------------------------------------------------------------------" << endl;
    cout << "   YOU: [X]\t COMPUTER: [O]\n\n";
    cout << "\t     |    |     \n";
    cout << "\t  " << board[0][0] << "  | " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t_____|____|_____\n";
    cout << "\t     |    |     \n";
    cout << "\t  " << board[1][0] <<"  | "<< board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t_____|____|_____\n";
    cout << "\t     |    |     \n";
    cout << "\t  " << board[2][0] <<"  | "<< board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t     |    |     \n";
    cout << "------------------------------------------------------------------------------" << endl;
}


void playerTurn()
{

    if (turn == 'X') {
        cout << "Your [X] turn: " << endl;
        cout << "Input a number ('1' - '9') to indicate the square you want to mark" << endl;
    } else if (turn == 'O') {
        cout << "Computer's [O] turn: " << endl;
        cout << "Input a number ('1' - '9') to indicate the square you want to mark" << endl;
    }

    cin >> choice;
    // marking a square on board based off user input
    switch (choice) {
        case 1:
            row = 0, column = 0;
            break;
        case 2:
            row = 0, column = 1;
            break;
        case 3:
            row = 0, column = 2;
            break;
        case 4:
            row = 1, column = 0;
            break;
        case 5:
            row = 1, column = 1;
            break;
        case 6:
            row = 1, column = 2;
            break;
        case 7:
            row = 2, column = 0;
            break;
        case 8:
            row = 2, column = 1;
            break;
        case 9:
            row = 2, column = 2;
            break;
        default:
            cout << "Invalid input, try again." << endl;
    }
    // mark board and then switch turns
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    } else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    } else {
        cout << endl;
        cout << "Position is already occupied. Please try again." << endl;
        cout << endl;
        playerTurn();
    }
    ++numMoves;
    displayBoard();
}


bool gameOver()
{
    // simple column or row win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }
    // diagonal or anti-diagonal win
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }
    // at least on square unoccupied so game can continue
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'Y') {
                return true;
            }
        }
    }
    // else the game is at a draw, since all squares occupied but no win
    draw = true;
    return false;
}

//
void validateInput()
{
    try {
        cout << "---------------------------" << endl;
        cout << "Welcome to Tic-Tac-Toe!" << endl;
        cout << "Today, you will be facing an unbeatable AI. Are you up for the challenge? (y/n): " << endl;
        cin >> user_answer;

        if (user_answer == 'y' || user_answer == 'Y') {
            cout << "***Commence Game***" << endl;
            cout << endl;
        } else if (user_answer == 'n' || user_answer == 'N') {
            endGame = true;
        } else {
            cout << "Invalid input. Try again." << endl;
        }
    }
    catch (invalid_argument const &e) {
        cout << "Bad input: invalid_argument thrown" << endl;
    }
    catch (out_of_range const &e) {
        cout << "Out of range" << endl;
    }
    return;
}

// main execution of game implementation
int main()
{
    validateInput();

    while (gameOver() && !endGame) {
        displayBoard();
        playerTurn();
        system("cls");
        gameOver();
        if (numMoves == 9) {
            cout << "It's a draw!" << endl;
            break;
        }
    }

    if (!endGame && turn == 'O' && draw == false) {
        cout << "Congratulations, you have won!" << endl;
    } else if (!endGame && turn == 'X' && draw == false) {
        cout << "Unfortunately, the Computer has won (as expected)." << endl;
    }
    cout << endl;
    if (!endGame) {
        cout << "Thanks for playing!" << endl;
        cout << "Would you like to play again (y/n)?" << endl;
        char s;
        cin >> s;
        if (s == 'y') {
            main();
        } else {
            cout << endl;
            cout << "Goodbye now!" << endl;
        }
    } else {
        cout << "Lol why did you even run this program then?? Anyway, cya!" << endl;
    }

    return 0;
}


// Minimax algorithm -> apply to decision problems -> uses recursion?
// draw a tree of all possible board states
// algorithm is performing simulations at every move -> makes it unbeatable
// the smaller the state space, the better (can optimally run algo)
// explore entire game tree assigning values based off result
// fully deterministic environment
// 3^9 possible board combinations, no need to limit the depth of our search
// you can draw at most against this AI, and only with a perfect game
// can compute terminal states at the bottom of the game tree and then propogate these values upward in a min-max-min-max-... fashion
// maximize gains, minimize losses, alternating
