#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 5

   char board[MAX_SIZE][MAX_SIZE];
   int size;
   void initializeBoard() {
       for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
              board[i][j] = ' ';
          }
      }
  }
  void printBoard() {
      printf("\n");
      printf("  ");
      for (int j = 1; j <= size; j++) {
          printf(" %d ", j);
      }
      printf("\n");

      for (int i = 0; i < size; i++) {
          printf("%d ", i + 1);
          for (int j = 0; j < size; j++) {
              printf(" %c ", board[i][j]);
              if (j < size - 1) printf("|");
          }
          printf("\n");
          if (i < size - 1) {
              for (int k = 0; k < size; k++) {
                  printf("----");
              }
              printf("\n");
          }
      }
      printf("\n");
  }
  bool isGameOver() {
      for (int i = 0; i < size; i++) {
          if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) return true;
          if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) return true;
      }
      if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return true;
      if (board[0][size - 1] != ' ' && board[0][size - 1] == board[1][size - 2] && board[0][size - 1] == board[2][0]) return true;
      for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
              if (board[i][j] == ' ') return false;
          }
      }
      return true;
  }
  char getWinner() {
      for (int i = 0; i < size; i++) {
          if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) return board[i][0];
          if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) return board[0][i];
      }
      if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) return board[0][0];
      if (board[0][size - 1] != ' ' && board[0][size - 1] == board[1][size - 2] && board[0][size - 1] == board[2][0]) return board[0][size - 1];
      return ' ';
  }
  void botMove() {
      for (int i = 0; i < size; i++) {
          for (int j = 0; j < size; j++) {
              if (board[i][j] == ' ') {
                  board[i][j] = 'O';
                  return;
              }
          }
      }
  }

  int main() {
      printf("Pilih papan dulu yaw\n1. 3x3\n2. 4x4\n3. 5x5\n");
      int choice;
      scanf("%d", &choice);

      switch (choice) {
           case 1:
              size = 3;
              break;
          case 2:
              size = 4;
              break;
          case 3:
              size = 5;
              break;
          default:
              printf("Input tidak valid, menggunakan ukuran default 3x3.\n");
              size = 3;
      }

      initializeBoard();

      int mode;
     printf("Mau lawan siapa nih?\n1. Pemain vs Pemain\n2. Pemain vs Bot\n");
      scanf("%d", &mode);

      int currentPlayer = 1;
     while (true) {
         printBoard();
         int row, col;
         if (mode == 1 || currentPlayer == 1) {
             printf("Pemain %d, mau di mana? (baris-kolom) (1-%d): ", currentPlayer, size);
             scanf("%d %d", &row, &col);
             row--; col--;
             if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ') {
                 printf("Yang bener dong, coba lagi\n");
                 continue;
            }
             board[row][col] = (currentPlayer == 1) ? 'X' : 'O';
         } else {
             botMove();
         }
         if (isGameOver()) {
             printBoard();
             char winner = getWinner();
             if (winner != ' ') {
                 printf("Pemain %d menang!\n", (winner == 'X') ? 1 : 2);
            } else {
                 printf("yah seri, main lagi dong!\n");
             }
             break;
         }
         currentPlayer = (currentPlayer == 1) ? 2 : 1;
     }
    return 0;
}
