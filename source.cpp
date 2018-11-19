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
  ifstream infile;
  gameBoard gameBoard1;
  gameBoard gameBoard2;
  string heading1, heading2;
  heading1 = "PLAYER 1's Game Board";
  heading2 = "PLAYER 2's Game Board";
  int numOfHits =0;
  bool end_game = false;
  int hitPlayer1 = 0, hitPlayer2 = 0;
  gameintro();

  get_board_data(infile, gameBoard1, gameBoard2);
  cout << heading1 << endl<<endl;
  print_board(gameBoard1);
  cout << heading2 <<endl<<endl;
  print_board(gameBoard2);
	
  while (winner_test(hitPlayer1, hitPlayer2) == end_game){
  	cout << "Player1 hits: " << hitPlayer1 << " Player 2 hits: " <<hitPlayer2<< endl;
  	cout << "Player1 - Enter your move (ie. 0 4): ";
  	fire(gameBoard2, numOfHits, end_game);
  	hitPlayer1 += numOfHits;
  	numOfHits =0;
     if(end_game==true){break;}
  	cout << "Player1 hits: " << hitPlayer1 << " Player 2 hits: " << hitPlayer2 << endl;
  	cout << "Player2 - Enter your move (ie. 0 4): ";
  	fire(gameBoard1, numOfHits, end_game);
  	hitPlayer2 += numOfHits;
  	numOfHits =0;
}
	
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

bool winner_test(int numOfHitsPlayer1, int numOfHitsPlayer2)
{
  if (numOfHitsPlayer1 == 10 || numOfHitsPlayer2 == 10){
    cout << "End of Game" << endl;
    cout << "Thanks for playing Battleship" << endl;
    return true;
  }
    return false;
}

void gameintro()
{
  cout<<"Welcome to My Battleship Game\n";
  cout<<"Dash(-) represent oceans, Hash'#' are your battleships\n";
  cout<<"Your shooting target lies between 0 and 9 for both rows and columns\n";
  cout<<"Type 10 10 at anytime to end prematurely\n";
  cout<<"10 hits(H) represent a win\n";
  cout<<"If you end prematurely, player with the highest hits(H) wins\n\n";
}
