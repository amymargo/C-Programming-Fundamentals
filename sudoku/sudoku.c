#include <stdio.h>
#include <stdbool.h>

bool isValid(int board[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (board[row][x] == num || board[x][col] == num || board[3 * (row / 3) + x / 3][3 * (col / 3) + x % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku(int board[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true; 
}

int main(int argc, char *argv[]) {

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("error\n");
        return 1;
    }

    int board[9][9];

    // Read Sudoku puzzle from the file
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c;
            fscanf(file, " %c", &c);
            if (c == '_') {
                board[i][j] = 0; // Unspecified element represented by 0
            } else {
                board[i][j] = c - '0'; // Convert character to integer
            }
        }
    }

    bool isfull= true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j]==0){
                    isfull=false;
                    break;}}}
bool iscorrect = true;
//runs through rows
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k=j+1;k<9;k++){
            if (board[i][j]==board[i][k]){
                iscorrect = false;
                break;
            }
        }}}
//run through columns
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k=j+1;k<9;k++){
                if (board[j][i]==board[k][i]){
                    iscorrect=false;
                    break;
                }
            }}}
int box[9][9];
for (int i = 0; i < 9; i++) {
    int boxRow = (i / 3) * 3; // Starting row index of the 3x3 subgrid
    int boxCol = (i % 3) * 3; // Starting column index of the 3x3 subgrid
    
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            box[i][j * 3 + k] = board[boxRow + j][boxCol + k];
        }
    }
}
for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
        for (int k = j + 1; k < 9; k++) {
            if (box[i][j] == box[i][k]) {
                iscorrect = false;
                break;
            }
        }
    }
}

  if (isfull){
        if (iscorrect){
            printf("correct\n");
        }
        else{printf("incorrect\n");}
    }
     else {
        if (solveSudoku(board)) {
            printf("solvable\n");
        } else {
            printf("unsolvable\n");
        }
    }

    fclose(file);
    return 0;
}
