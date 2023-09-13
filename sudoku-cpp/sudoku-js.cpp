#include "Board.hpp"

#include <emscripten/bind.h>

using namespace emscripten;

// Binding code
EMSCRIPTEN_BINDINGS(Board)
{
  class_<Board>("Board")
      .constructor()
      .function("read", select_overload<void(string)>(&Board::read))
      .function("write", &Board::write)
      .function("algorithm", &Board::algorithm);
}
