/// Copyright © 2021.
#include <iomanip>
#include <iostream>

static const int ROWS = 8;
static const int COLS = 8;
static const int POSITIONS = ROWS * COLS;

void printChessboard(int chessboard[][COLS]);

void knightTour(int chessboard[][COLS]);

int main() {
  int chessboard[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0}};

  knightTour(chessboard);
  printChessboard(chessboard);
  return 0;
}
void printChessboard(int chessboard[][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      std::cout << std::setw(2) << chessboard[r][c] << " ";
    }
    std::cout << "\n";
  }
  std::cout << std::endl;
}
void knightTour(int chessboard[][COLS]) {
  int accessibility[ROWS][COLS] = {
      {2, 3, 4, 4, 4, 4, 3, 2}, {3, 4, 6, 6, 6, 6, 4, 3},
      {4, 6, 8, 8, 8, 8, 6, 4}, {4, 6, 8, 8, 8, 8, 6, 4},
      {4, 6, 8, 8, 8, 8, 6, 4}, {4, 6, 8, 8, 8, 8, 6, 4},
      {3, 4, 6, 6, 6, 6, 4, 3}, {2, 3, 4, 4, 4, 4, 3, 2},
  };
  const int horizontal[ROWS] = {2, 1, -1, -2, -2, -1, 1, 2};
  const int vertical[COLS] = {-1, -2, -2, -1, 1, 2, 2, 1};
  int currRow = 3;
  int currCol = 4;
  int hits = 1;
  int mov = 0;
  chessboard[currRow][currCol] = hits;
  while (mov < 8) {  // while there are valid movements to be tried.
    const int futRow = currRow + vertical[mov];
    const int futCol = currCol + horizontal[mov];
    if ((futRow >= 0 && futRow < ROWS) && (futCol >= 0 && futCol < COLS) &&
        (chessboard[futRow][futCol] == 0)) {
      mov = 0;  // resets movement.
      chessboard[futRow][futCol] = ++hits;
      currRow = futRow;
      currCol = futCol;
    } else {  // try next movement.
      ++mov;
    }
  }
  std::cout << "hits: " << hits << "\n";
}
