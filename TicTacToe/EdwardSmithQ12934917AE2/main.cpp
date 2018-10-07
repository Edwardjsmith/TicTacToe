#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//Board array

char square[9]{ '1', '2', '3', '4', '5', '6', '7', '8', '9' }; 

//Function prototypes

void board(); 

void playermove(); 

void clearboard(); 

void AIMoveEasy();

void AIMoveHard();

void playercheckwin();

void AIcheckwin();

//Variables

int AI;

int playerwin = 0;

int AIwin = 0;

int difficulty;

int playersmove;

char playerpiece;

char AIPiece;

bool win = false;

int rounds = 0;


int main()
{
	char playerchoice; //Gives the player a choice whether or not to play

	cout << "Would you like to play Tic Tac Toe? y/n" << endl << endl << endl;

	cin >> playerchoice;
	
	if (playerchoice == 'y') //Moves on in program by giving player difficulty choice

		cout << "Would you like to play a easy or hard game?" << endl << endl << endl
		<< "Press 1 for easy" << endl << endl << endl << "Press 2 for hard." << endl << endl << endl;

	cin >> difficulty; 

	switch (difficulty) //Accepts difficulty choice

	{
	case 1:
		cout << "You selected easy." << endl << endl << endl;

		break;

	case 2:

	{
		cout << "You selected hard." << endl << endl << endl;

	}

	break;

	}

	cout << "Would you like to be X or O? please enter X or O" << endl << endl << endl;

	cin >> playerchoice; //Gives the player the option to be X or O, AI will be what ever the player doesn't choose

	if (playerchoice == 'X')
	{
		playerpiece = 'X';

		AIPiece = 'O';
	}

	if (playerchoice == 'O')

	{
		playerpiece = 'O';

		AIPiece = 'X';
	
	}

	else if (playerchoice == 'n') //Closes program

	{
		cout << "Bye bye!" << endl;

		getchar();

		return 0;
	}



	cout << "Okay, you are " << playerpiece << " and the AI is " << AIPiece << " lets play." << endl << endl << endl;

	

	do //Loops until rounds played equals to 5

	{	
		win = false; //Loops round until there is a winner
		
		board(); //Calls the board function that draws the board

		playermove(); //Calls the player move function

		if (difficulty == 1)

		{
			AIMoveEasy(); //Calls the easy AI to make a move
		}

		else if (difficulty == 2)

		{
			AIMoveHard(); //Calls hard AI to make a move

		}

		playercheckwin(); //Calls the playercheckwin to see if the player won after a move

		AIcheckwin(); //Calls the AIcheckwin to do the same

		if (win == true)

		{
			clearboard(); //Clears the board between rounds if there has been a winner
		}

		

		
	} while (rounds != 5);

	if (playerwin <= 3)
	{
		cout << "The player won overall! Number of rounds won: " << playerwin;

		

	}

	else if (AIwin <= 3)

	{
		cout << "The AI wins! Number of rounds won: " << AIwin;

		

	}

	else { cout << "It was a draw!";
	

	}


}
		
void playermove()

{	
	cin >> playersmove; //Takes move

	switch (playersmove) //Updates board depending on player choice
	{
	case 1: square[0] = playerpiece;

		break;
	
	case 2: square[1] = playerpiece;

		break;
	
	case 3: square[2] = playerpiece;

		break;

	case 4: square[3] = playerpiece;

		break;

	case 5: square[4] = playerpiece;

		break;

	case 6: square[5] = playerpiece;

		break;

	case 7: square[6] = playerpiece;

		break;

	case 8: square[7] = playerpiece;

		break;

	case 9: square[8] = playerpiece;

		break;
	}





}

void AIMoveEasy()


{
	int srand((time(NULL))); //Seeds rand with the computer clock

	int AIMove; //Declares AIMove as an int




	bool done = false; //Sets done to false 

	do {


		AIMove = rand() % 9 + 1; //Generates a number between 1 and 9

		switch (AIMove) //List of moves. The AI won't overwrite it's own or player moves due to conditions. Will cycle through until
			//a legal move is made
		{

		case 1:
			(square[0] != playerpiece || AIPiece);

			{
				square[0] = AIPiece;


			}



			break;

		case 2:

			(square[1] != playerpiece || AIPiece);

			{
				square[1] = AIPiece;


			}



			break;

		case 3:

			(square[2] != playerpiece || AIPiece);

			{
				square[2] = AIPiece;


			}



			break;

		case 4:

			(square[3] != playerpiece || AIPiece);
			{
				square[3] = AIPiece;


			}



			break;

		case 5:

			(square[4] != playerpiece || AIPiece);
			{
				square[4] = AIPiece;


			}



			break;

		case 6:

			(square[5] != playerpiece || AIPiece);
			{
				square[5] = AIPiece;


			}


			break;


		case 7:

			(square[6] != playerpiece || AIPiece);

			{
				square[6] = AIPiece;


			}


			break;

		case 8:

			(square[7] != playerpiece || AIPiece);

			{
				square[7] = AIPiece;


			}



			break;

		case 9:

			(square[8] != playerpiece || AIPiece);

			{
				square[8] = AIPiece;


			}

			break;

		default: continue; //Goes back to the beginning of the loop while done is false

		}

		break;


	} while (!done); //Will cycle through the switch, redoing rand(), until a legal move is made
}


void AIMoveHard() //My attempt at a harder AI. Buggy!

	{//I have gone through and tried to list as many moves as possible. This works by looking at the player moves and countering
	//Accordingly using conditions

		if (square[0] && square[1] == playerpiece)

		{
			if (square[2] != playerpiece)
			{
				square[2] = AIPiece;

			}
		}



		else if (square[0] && square[3] == playerpiece)

		{
			if (square[6] != playerpiece)
			{
				square[6] = AIPiece;

			}
		}


		else if (square[1] && square[4] == playerpiece)

		{
			if (square[7] != playerpiece)
			{
				square[7] = AIPiece;
			}
		}





		else if (square[2] && square[5] == playerpiece)

		{
			if (square[8] != playerpiece && square[4] != AIPiece)
			{
				square[8] = AIPiece;
			}
		}



		else if (square[0] && square[4] == playerpiece)

		{
			if (square[8] != playerpiece && square[4] != AIPiece)
			{
				square[8] = AIPiece;
			}
		}


		else if (square[0] && square[6] == playerpiece)

		{
			if (square[3] != playerpiece)
			{
				square[3] = AIPiece;
			}
		}



		else if (square[7] && square[8] == playerpiece)

		{
			if (square[6] != playerpiece)
			{
				square[6] = AIPiece;
			}
		}




		else if (square[6] && square[8] == playerpiece)

		{
			if (square[7] != playerpiece)
			{
				square[7] = AIPiece;
			}
		}



		else if (square[0] && square[2] == playerpiece)

		{
			if (square[1] != playerpiece)
			{
				square[1] = AIPiece;
			}
		}



		else if (square[7] == playerpiece)

		{
			if (square[6] != playerpiece)
			{
				square[6] = AIPiece;
			}

			else if (square[8] != playerpiece)

			{
				square[8] = AIPiece;
			}
		}


		else if (square[1] && square[2] == playerpiece)

		{
			if (square[0] != playerpiece)
			{
				square[0] = AIPiece;

			}
		}


		else if (square[3] && square[6] == playerpiece)

		{
			if (square[0] != playerpiece)
			{
				square[0] = AIPiece;
			}
		}


		else if (square[5] && square[8] == playerpiece)

		{
			if (square[2] != playerpiece)
			{
				square[2] = AIPiece;
			}
		}

		else if (square[3] && square[0] == playerpiece)

		{
			if (square[6] != playerpiece && square[4] != AIPiece)
			{
				square[6] = AIPiece;
			}
		}
		else if (square[4] && square[5] == playerpiece)

		{
			if (square[3] != playerpiece)
			{
				square[3] = AIPiece;
			}
		}

		else if (square[4] && square[2] == playerpiece)

		{
			if (square[8] != playerpiece)
			{
				square[8] = AIPiece;
			}
		}



	}



	

	
		




void playercheckwin()

{

	//Player win check

	{//Checks to see if a win has been achieved by looking for three player pieces in a row. 
		//Adds one to playerwin and rounds played. Also sets win to true to reset board.

		if (square[0] == square[1] && square[1] == square[2] && square[2] == playerpiece)
		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}

		else if (square[3] == square[4] && square[4] == square[5] && square[5] == playerpiece)

		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}

		else if (square[6] == square[7] && square[7] == square[8] && square[8] == playerpiece)

		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}

		else if (square[0] == square[4] && square[4] == square[8] && square[8] == playerpiece)

		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}

		else if (square[2] == square[4] && square[4] == square[6] && square[6] == playerpiece)

		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}


		else if (square[1] == square[5] && square[5] == square[8] && square[8] == playerpiece)

		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}

		else if (square[0] == square[3] && square[3] == square[6] && square[6] == playerpiece)

		{
			cout << "You win!" << endl;

			playerwin++;

			rounds++;

			win = true;

			
		}

	}
	

	
}

void AIcheckwin()

{
	//AI win check

	//Checks to see if a win has been achieved by looking for three AI pieces in a row. 
	//Adds one to AI and rounds played. Also sets win to true to reset board.


	{if (square[0] == square[1] && square[1] == square[2] && square[2] == AIPiece)
	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}

	else if (square[3] == square[4] && square[4] == square[5] && square[5] == AIPiece)

	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}

	else if (square[6] == square[7] && square[7] == square[8] && square[8] == AIPiece)

	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}

	else if (square[0] == square[4] && square[4] == square[8] && square[8] == AIPiece)

	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}

	else if (square[2] == square[4] && square[4] == square[6] && square[6] == AIPiece)

	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}


	else if (square[1] == square[5] && square[5] == square[8] && square[8] == AIPiece)

	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}

	else if (square[0] == square[3] && square[3] == square[6] && square[6] == AIPiece)

	{
		cout << "The AI wins!" << endl;

		AIwin++;

		rounds++;

		win = true;


	}



	}

}


void board()
{
	//Outputs my board

	cout << square[0] << "  " << square[1] << "  " << square[2] << endl << endl;

	cout << square[3] << "  " << square[4] << "  " << square[5] << endl << endl;

	cout << square[6] << "  " << square[7] << "  " << square[8] << endl << endl;

}

void clearboard()

{
	//Resets the board back to original state when called

	square[0] = '1';
	square[1] = '2';
	square[2] = '3';
	square[3] = '4';
	square[4] = '5';
	square[5] = '6';
	square[6] = '7';
	square[7] = '8';
	square[8] = '9';
	
		


	



}

			








		


