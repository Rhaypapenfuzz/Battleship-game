#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//const string filepath = "C:\\Users\\Rhaypapenfuzz\\source\repos\\Lab 13 - Gameboard\\Lab 13 - Gameboard\\infile.txt";
typedef char gameBoard[10][10];
void get_board_data(ifstream&, gameBoard, gameBoard);
void fire(gameBoard, int&, bool&);
void print_board(gameBoard);
bool winner_test(int, int);
void gameintro();
