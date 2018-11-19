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

int main()
{
return 0;
}
void get_board_data(ifstream& infile, gameBoard gameBoard1, gameBoard gameBoard2)
{
	infile.open("infile.txt");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			infile >> gameBoard1[i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) {
			infile >> gameBoard2[i][j];
		}
	}
  infile.close();
}

void print_board(gameBoard currentGameBoard)
{
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
    cout << currentGameBoard[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

