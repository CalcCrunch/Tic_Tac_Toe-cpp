// main execution of game implementation
int main()
{
    validateInput();

    while (gameOver()) {
        displayBoard();
        playerTurn();
        gameOver();
    }

    if (turn == 'O' && draw == false) {
        cout << "Congratulations, you have won!" << endl;
    } else if (turn == 'X' && draw == false) {
        cout << "Unfortunately, the Computer has won (as expected)." << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
    cout << endl;
    cout << "Thanks for playing!" << endl;
    return 0;
}

