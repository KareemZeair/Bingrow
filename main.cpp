#include <iostream>
#include <deque>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Symbol.h"
#include "BingrowSquare.h"
#include "BingrowBoardPartial.h"
using namespace std;




int main() {
    srand(time(0));
    BingrowBoard myBoard(5);
    cout << "Hello World!\n";
    int size = myBoard.GetSize();
    cout << size << endl;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++){
            deque <BingrowSquare> currentRow = myBoard.BingoX[i];
            BingrowSquare currentSquare = currentRow[j];
            Symbol symbol = currentSquare.getSymbol();

            if (symbol.getSymbolType() == SymbolType::Number){
            cout << symbol.getNumber() << "   ";
            }

            else if (symbol.getSymbolType() == SymbolType::Arrow){
                if (symbol.getArrowType() == ArrowType::LowerRight){
                    cout << "LR   ";
                }
                if (symbol.getArrowType() == ArrowType::LowerLeft){
                    cout << "LL   ";
                }
                if (symbol.getArrowType() == ArrowType::UpperRight){
                    cout << "UR   ";
                }
                if (symbol.getArrowType() == ArrowType::UpperLeft){
                    cout << "UL   ";
                }
            }
            else{
                cout << "free   ";
            }
        }
        cout << "\n done";
    }
}

