#include <iostream>
#include "BingrowBoardPartial.h"
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

// overloads ++ operator for enum SymbolType
SymbolType& operator ++ (SymbolType& x)
{
    if (x == SymbolType::Arrow) {
        throw std::out_of_range("for SymbolType& operator ++ (SymbolType&)");
    }
    x = SymbolType(static_cast<std::underlying_type<SymbolType>::type>(x) + 1);
    return x;
}
// overloads ++ operator for enum ArrowType
ArrowType& operator ++ (ArrowType& x)
{
    if (x == ArrowType::UpperLeft) {
        throw std::out_of_range("for ArrowType& operator ++ (ArrowType&)");
    }
    x = ArrowType(static_cast<std::underlying_type<ArrowType>::type>(x) + 1);
    return x;
}

//definition of constructor
BingrowBoard::BingrowBoard(int n){
deque <BingrowSquare> row{};

int center = (n+1)/2; 
int size = n;

// adds rows of deques = n
for (int i = 1; i <= n; i++ ){
    BingoX.push_back(row);

// adds squares in each deque
    for (int j = 1; j <= n; j++ ){
        BingrowSquare square;
        row.push_back(square);

        srand(time(0));
        int randomSymbolType = (rand() % 3) + 1; 
        int finalArrow = (rand() % 4) + 1; 
        int finalNumber = (3*n*(i-1)+1) + (rand() % ((3*n*i)-((3*n*(i-1))+1)+1)); 
        Symbol symbol;
                
        // sets middle square as free and covers it
        if(i == center && j == i ){
        symbol.setSymbolType(SymbolType::Free);
        BingrowSquare middleSquare = BingoX[center][center];
        middleSquare.setSymbol(symbol);
        middleSquare.setCovered(true);
        }

        // if SymbolType is a Number, sets the square to a random number
        else if (randomSymbolType==1){
            symbol.setSymbolType(SymbolType::Number);
            symbol.setNumber(finalNumber);
            square.setSymbol(symbol);
            }

        // if SymbolType is an arrow, sets the square to a random arrow
        else if (randomSymbolType==3){
            symbol.setSymbolType(SymbolType::Arrow);
            // sets arrow direction according to random int
            if (finalArrow == 1){symbol.setArrowType(UpperLeft);}
            if (finalArrow == 2){symbol.setArrowType(UpperRight);}
            if (finalArrow == 3){symbol.setArrowType(LowerLeft);}
            if (finalArrow == 4){symbol.setArrowType(LowerRight);}
            }
        }
    } 
}

// destructor
BingrowBoard::~BingrowBoard(){}



// if (j == randomSymbolType) l51
// iterate over SymbolType to choose one randomly
// for (SymbolType x = SymbolType::Number; x != SymbolType::Arrow; ++x)
// enum SymbolType {Number, Free, Arrow};
// enum ArrowType {UpperLeft, UpperRight, LowerLeft, LowerRight};
// for (ArrowType x = ArrowType::UpperLeft; x != ArrowType::LowerRight; ++x)

// returns the side length of the original board
int BingrowBoard::GetSize(void){
    return size;
}

void BingrowBoard::GrowBoard(ArrowType direction){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++){
            deque <BingrowSquare> currentRow = BingoX[i];
            BingrowSquare currentSquare = currentRow[j];
            Symbol symbol = currentSquare.getSymbol();
            if (symbol.getSymbolType() == SymbolType::Arrow){

        }
}
}


// void BingrowBoard::SetSquare(int row, int col, BingrowSquare square)


int main() {
  std::cout << "Hello World!\n";

   BingrowBoard myBoard(5);

}