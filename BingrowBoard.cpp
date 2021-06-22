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
            square.setCovered(false);

            }

        // if SymbolType is an arrow, sets the square to a random arrow
        else if (randomSymbolType==3){
            symbol.setSymbolType(SymbolType::Arrow);
            square.setCovered(false);

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


// returns the side length of the original board
int BingrowBoard::GetSize(void){
    return size;
}


// function to add a row to the beginning of the board
void BingrowBoard::addUpperRow(){

    deque <BingrowSquare> row{};
    int size = BingrowBoard::GetSize()+1;

    srand(time(0));
    int randomSymbolType = (rand() % 3) + 1; 
    int finalArrow = (rand() % 4) + 1; 
    int finalNumber = (1) + (rand() % (3*size)); 
    Symbol symbol;

    for (int i = 0; i < row.size(); i++) {
        for (int j = 1; j <= size; j++ ){
            BingrowSquare square;
            row.push_back(square);
            if (randomSymbolType==1){
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
        BingoX.push_front(row);
    }
}

// function to add a row to the end of the board
void BingrowBoard::addLowerRow(){
deque <BingrowSquare> row{};
    int size = BingrowBoard::GetSize()+1;

    srand(time(0));
    int randomSymbolType = (rand() % 3) + 1; 
    int finalArrow = (rand() % 4) + 1; 
    int finalNumber = (1) + (rand() % (3*size)); 
    Symbol symbol;

    for (int i = 0; i < row.size(); i++) {
        for (int j = 1; j <= size; j++ ){
            BingrowSquare square;
            row.push_back(square);
            if (randomSymbolType==1){
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
    BingoX.push_back(row);
}

// function to add a column to the end of the board
void BingrowBoard::addRightCol(){
    for (int i = 0; i < BingoX.size(); i++) {
        BingrowSquare square;
        int size = BingrowBoard::GetSize()+1;
        srand(time(0));
        int randomSymbolType = (rand() % 3) + 1; 
        int finalArrow = (rand() % 4) + 1; 
        int finalNumber = (1) + (rand() % (3*size)); 
        Symbol symbol;
        if (randomSymbolType==1){
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

        BingoX[i].push_back(square);
    }
}

// function to add a column to the beginning of the board
void BingrowBoard::addLeftCol(){
    for (int i = 0; i < BingoX.size(); i++) {
        BingrowSquare square;
        int size = BingrowBoard::GetSize()+1;
        srand(time(0));
        int randomSymbolType = (rand() % 3) + 1; 
        int finalArrow = (rand() % 4) + 1; 
        int finalNumber = (1) + (rand() % (3*size)); 
        Symbol symbol;
        if (randomSymbolType==1){
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

        BingoX[i].push_front(square);
    }
}


void BingrowBoard::GrowBoard(ArrowType direction){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++){
            deque <BingrowSquare> currentRow = BingoX[i];
            BingrowSquare currentSquare = currentRow[j];
            Symbol symbol = currentSquare.getSymbol();
            if (symbol.getSymbolType() == SymbolType::Arrow && symbol.getArrowType() == direction){
                if (direction == ArrowType::UpperRight){
                    addUpperRow();
                    addRightCol();
                }
                if (direction == ArrowType::UpperLeft){
                    addUpperRow();
                    addLeftCol();
                }
                if (direction == ArrowType::LowerRight){
                    addLowerRow();
                    addRightCol();
                }
                if (direction == ArrowType::LowerLeft){
                    addLowerRow();
                    addLeftCol();
                }
            }
        }
    }
}

bool BingrowBoard::UpdateBoard(Symbol symbol){

    bool ischanged = false;
    int countMatch = 0;
    // constructs an arrow of an empty type to check if an arrow exists
    ArrowType direction;
    bool isArrow = false;
    // loops over every square
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++){
            deque <BingrowSquare> currentRow = BingoX[i];
            BingrowSquare currentSquare = currentRow[j];
            Symbol currentSymbol = currentSquare.getSymbol();                
        {
            // if the symbol exists and is already covered, the board will change
            if(currentSymbol == symbol && !currentSquare.getCovered() ){
                ischanged = true;
                currentSquare.setCovered(true);
                countMatch++;
                // sets the direction to an appropriate ArrowType 
                if (currentSymbol.getSymbolType() == SymbolType::Arrow){
                    isArrow = true;
                    direction = currentSquare.getSymbol().getArrowType();
                }
            }

        }
    }
    if(isArrow){
        //for arrows the GrowBoard function will be called a maximum 2 times
        countMatch = (countMatch > 2) ? 2 : countMatch;

        for(int i = 0; i < countMatch; i++)
            GrowBoard(direction);
        }
    }
return ischanged;   
}


bool BingrowBoard::WinningBoard(void){

    // checks the board row by row for the winning condition
    bool iswinning = false;
    int size = BingrowBoard::GetSize();

    int countCoveredRow = 0;
    int countCoveredCol = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size ; j++){
            deque <BingrowSquare> currentRow = BingoX[i];
            BingrowSquare currentSquare = currentRow[j];
            Symbol currentSymbol = currentSquare.getSymbol();  
            if (currentSquare.getCovered()==true){
                countCoveredRow++;    
            } 

        }
    }
    if(countCoveredRow >= 5){return true;}
    else{return false;}
}

