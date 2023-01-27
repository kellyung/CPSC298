/// @file tictactoe.cpp
/// @brief Implementation file for TicTacToeGame class
/// @author kelung@chapman.edu
/// CPSC 298-6 Colloquium: Programming in C++

#include <iostream>
#include <tuple>

class TicTacToeGame
{
    
public:
    TicTacToeGame();
    virtual ~TicTacToeGame();
    
    void play();
    
private:
    void initializeGrid();
    void displayGrid();
    std::tuple<int, int> findFirstUnoccupiedGridSquare(); // comp move
    std::tuple<int, int> promptForGridCoord(); // user move
    bool checkForDraw();
    bool checkForWin();
    
private:
    char** pp_cGrid = nullptr; // Pointer to character
};

TicTacToeGame::TicTacToeGame()
{
    this->pp_cGrid = new char* [3]; // array of three pointers to char
    
    for (int iRow = 0; iRow < 3; ++iRow)
        pp_cGrid[iRow] = new char[3];
        
    initializeGrid();
}

TicTacToeGame::~TicTacToeGame()
{
    for (int iRow = 0; iRow < 3; ++iRow)
    {
        delete[] pp_cGrid[iRow]; // Delete arrays of 3 characters
    }
    
    delete[] pp_cGrid; // Delete array of three pointers to character
    pp_cGrid = nullptr;
}

void TicTacToeGame::initializeGrid()
{
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            this->pp_cGrid[iRow][iColumn] = '~';
        }
    }
}

void TicTacToeGame::displayGrid()
{
    
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            std::cout << this->pp_cGrid[iRow][iColumn] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void TicTacToeGame::play()
{
    bool bWin = false;
    bool bDraw = false;
    int iRow = 0;
    int iColumn = 0;
    
    std::cout << "Tic Tac Toe" << std::endl;
    std::cout << std::endl;
    
    displayGrid();
    
    while (!bWin && !bDraw)
    {
        // Human Player Turn
        std::tie(iRow, iColumn) = promptForGridCoord();
        this->pp_cGrid[iRow][iColumn] = 'X';
        
        displayGrid();
        
        bWin = checkForWin();
        bDraw = checkForDraw();
        
        // Computer Player Turn
        if (!bWin and !bDraw)
        {
            std::tie(iRow, iColumn) = findFirstUnoccupiedGridSquare();
            this->pp_cGrid[iRow][iColumn] = 'O';
            displayGrid();
            
            bWin = checkForWin();
            bDraw = checkForDraw();
        }
        
        if (bDraw && !bWin)
        {
            std::cout << "Draw! " << std::endl;
        }
    }
    
    std::cout << "Game over." << std::endl;
    return;
}

std::tuple<int, int> TicTacToeGame::promptForGridCoord()
{
    int iRow = 0;
    int iColumn = 0;
    
    std::cout << "Please enter grid row number: " << std::endl;
    std::cin >> iRow;
    
    std::cout << "Please enter grid column number: " << std::endl;
    std::cin >> iColumn;
    
    std::tuple<int, int> tupleCoord = std::make_tuple(iRow, iColumn);
    
    return tupleCoord;
}

std::tuple<int, int> TicTacToeGame::findFirstUnoccupiedGridSquare()
{
    int iRowUnoccupied = -1;
    int iColumnUnoccupied = -1;
    
    bool bFound = false;
    
    for (int iRow = 0; (iRow < 3) && !bFound; iRow++)
    {
        for (int iColumn = 0; (iColumn < 3) && !bFound; iColumn++)
        {
            if (this->pp_cGrid[iRow][iColumn] == '~')
            {
                iRowUnoccupied = iRow;
                iColumnUnoccupied = iColumn;
                bFound = true;
            }
        }
    }
    
    std::tuple<int, int> tupleUnoccupiedGridSquare(iRowUnoccupied, iColumnUnoccupied);
    return tupleUnoccupiedGridSquare;
}

bool TicTacToeGame::checkForDraw()
{
    bool bContinue = false;
    
    // Continue game if there are open squares left.
    // Otherwise, it must be a win or a draw.
    
    // Checking the game is in continue mode or not
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iColumn = 0; iColumn < 3; iColumn++)
        {
            if (this->pp_cGrid[iRow][iColumn] != 'X' &&
                this->pp_cGrid[iRow][iColumn] != 'O')
                bContinue = true;
        }
    }
    
    return !bContinue;
}

bool TicTacToeGame::checkForWin()
{
    bool bWin = false;
    
    for (int iRow = 0; (iRow < 3) && !bWin; iRow++)
    {
        if (this->pp_cGrid[iRow][0] != '~')
        {
            if ((this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][1]) &&
                (this->pp_cGrid[iRow][0] == this->pp_cGrid[iRow][2]))
            {
                bWin = true;
                std::cout << "WINNER: " << this->pp_cGrid[iRow][0] << "!" << std::endl;
            }
        }
    }
    
    for (int iColumn = 0; (iColumn < 3) && !bWin; iColumn++)
    {
        if (this -> pp_cGrid[0][iColumn] != '~')
        {
            if ((this->pp_cGrid[0][iColumn] == this->pp_cGrid[1][iColumn]) &&
                (this->pp_cGrid[0][iColumn] == this->pp_cGrid[2][iColumn]))
            {
                bWin = true;
                std::cout << "WINNER: " << this->pp_cGrid[iColumn][0] << "!" << std::endl;
            }
        }
    }
    
    if (this->pp_cGrid[0][0] != '~')
    {
        if ((this->pp_cGrid[0][0] == this->pp_cGrid[1][1]) &&
            (this->pp_cGrid[0][0] == this->pp_cGrid[2][2]))
        {
            bWin = true;
            std::cout << "WINNER: " << this->pp_cGrid[0][0] << "!" << std::endl;
        }
    }
    
    if (this->pp_cGrid[0][2] != '~')
    {
        if ((this->pp_cGrid[0][2] == this->pp_cGrid[1][1]) &&
            (this->pp_cGrid[0][2] == this->pp_cGrid[2][0]))
        {
            bWin = true;
            std::cout << "WINNER: " << this->pp_cGrid[0][2] << "!" << std::endl;
        }
    }
    
    return bWin;
}

int main() {
    TicTacToeGame* p_game = new TicTacToeGame();
    
    p_game-> play();
    
    delete p_game;
    
    return 0;
}

