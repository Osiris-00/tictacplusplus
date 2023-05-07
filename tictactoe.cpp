#include<iostream>  
using namespace std;

char square[10] = { 'o','1','2','3','4','5','6','7','8','9' }; // this holds the square slots

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3]) // first row win

        return 1;
    else if (square[4] == square[5] && square[5] == square[6]) //second row win

        return 1;
    else if (square[7] == square[8] && square[8] == square[9]) //bottom row win

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])//first column win

        return 1;
    else if (square[2] == square[5] && square[5] == square[8]) //second column win

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])// third column win

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])// diagonal win

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])// diagonal win

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
        && square[4] != '4' && square[5] != '5' && square[6] != '6'
        && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0; //no winners
    else
        return -1; // game is still being played
}
void board() //game board matrix
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}


int main(){
	int player{ 1 }, i{}, choice{};
	char mark;
    do {
        board(); // draws the playing board
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << " , enter a number: ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O'; // goes through X and O
        if (choice == 1 && square[1] == '1')

            square[1] = mark;
        else if (choice == 2 && square[2] == '2')

            square[2] = mark;
        else if (choice == 3 && square[3] == '3')

            square[3] = mark;
        else if (choice == 4 && square[4] == '4')

            square[4] = mark;
        else if (choice == 5 && square[5] == '5')

            square[5] = mark;
        else if (choice == 6 && square[6] == '6')

            square[6] = mark;
        else if (choice == 7 && square[7] == '7')

            square[7] = mark;
        else if (choice == 8 && square[8] == '8')

            square[8] = mark;
        else if (choice == 9 && square[9] == '9')

            square[9] = mark;
        else
        {
            cout << "Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();

        player++;
    } while (i == -1);
    board();
    if (i == 1)

        cout << "==>\aPlayer " << --player << " wins ";
    else
        cout << "==>\aIt's a draw!";

    cin.ignore();
    cin.get();
    return 0;
}