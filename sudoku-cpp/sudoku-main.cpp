#include "Board.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  Board sudoku;
  bool toCout = bool(argv[1]);
  string in = sudoku.read();
  // cout << "in: " << in << endl;
  sudoku.read(in);
  sudoku.write();
  // cout << "c" << endl;
  bool c = false;
  if (argc > 2) {
    c = string(argv[2]) == "count";
  }
  // cout << "Not from c" << endl;
  if (c) {
    sudoku.countM = true;
  };
  sudoku.algorithm();
  if (c) {
    if (toCout) {
      cout << "Sudoku solutions : " << sudoku.count << endl;
    }
  } else {
    sudoku.out += "\n";
    sudoku.write();
    if (toCout) {
      sudoku.writeToCout();
    };
  };

  return 0;
}