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
            cout << "Goodbye!" << endl;
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
