#include<stdio.h>

// Define the game board (3x3 grid)
char board[3][3] = {
    {' ', ' ', ' '}, // Row 0
    {' ', ' ', ' '}, // Row 1
    {' ', ' ', ' '}  // Row 2
};

// Variable to keep track of the current player ('X' or 'O')
char currentPlayer = 'X';

// Function to print the game board
void printBoard() {
    printf("-------------\n");
    for (int i = 0; i < 3; i++) {
        printf("| ");
        for (int j = 0; j < 3; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n-------------\n");
    }
}

// Function to check if there is a winner or if the game is a draw
int checkWin() {
    // Check rows for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return 1; // Win
        }
    }

    // Check columns for a win
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return 1; // Win
        }
    }

    // Check diagonals for a win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return 1; // Win
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return 1; // Win
    }

    // Check for a draw (if all cells are filled)
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Game not over
            }
        }
    }

    return -1; // Draw
}

// Function to switch the current player
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}

int main() {
    int row, col;
    int gameStatus;

    printf("Tic-Tac-Toe Game\n");

    do {
        // Print the current state of the board
        printBoard();

        // Get input from the current player
        printf("Player %c, enter row (0-2) and column (0-2) separated by space: ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Try again.\n");
            continue; // Go back to the beginning of the loop
        }

        // Place the player's mark on the board
        board[row][col] = currentPlayer;

        // Check if the game is over
        gameStatus = checkWin();

        // If the game is not over, switch to the next player
        if (gameStatus == 0) {
            switchPlayer();
        }

    } while (gameStatus == 0); // Continue the loop until the game is over

    // Print the final board
    printBoard();

    // Print the result of the game
    if (gameStatus == 1) {
        printf("Player %c wins!\n", currentPlayer == 'X' ? 'O' : 'X'); // switch back because of last switch
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}