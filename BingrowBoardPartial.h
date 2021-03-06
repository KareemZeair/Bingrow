#ifndef BINGROWBOARDPARTIAL_H
#define BINGROWBOARDPARTIAL_H

#include "BingrowSquare.h"
#include <deque>
#include <algorithm>


using namespace std;

class BingrowBoard
{
   private:
      int size;
      
   public:
      deque <deque <BingrowSquare>> BingoX {};
      BingrowBoard(int n); // Constructor for board with side length n
      ~BingrowBoard(); // Destructor

      void addUpperRow ();
      void addLowerRow ();
      void addRightCol ();
      void addLeftCol ();

      void GrowBoard(ArrowType direction); // Grow board in the specified direction
      bool UpdateBoard(Symbol symbol); // Cover all occurences of symbol on board 
   				    // and possibly grow the board if symbol is arrow
      bool WinningBoard(void); // True if winning condition is satisfied, false otherwise
      int GetSize(void); // Returns the side length of the board
      void SetSquare(int row, int col, BingrowSquare square);  // Sets a square on the board
};

#endif
