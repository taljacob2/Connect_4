// ID: <208632778>
// full name: <Tal Yacob>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//	DESCRIPTION OF PROGRAM:

//	This is a game called "Connect Four" / "Arba Be Shura".

//	This is a two - player connection board game in which the players first choose a color and
//	then take turns dropping one colored disc from the top into 
//	a seven - column, six - row vertically suspended grid.
//	The pieces fall straight down, occupying the lowest available space within the column.
//	The objective of the game is to be the first to form a horizontal, vertical, or diagonal line of four of one's own discs.
//	Connect Four is a solved game. The first player can always win by playing the right moves.

//	NOTE:
//	In this program we have replaced the "colors" of the discs by the signs of 'X' and 'O'.

//	Have Fun!

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//DEFINITIONS:
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//CONSTANTS:
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

//	Signs of Players:

#define P1 'X'
#define P2 'O'

#define P1_TURN 1
#define P2_TURN -1

//-+-+-+-+-+-+-+

//	Main Table Settings:

#define COLS_1 8				//	Size of Table
#define ROWS_A 7

#define TABLEFIELD (COLS_1 - 1) * (ROWS_A - 1)

#define	STARTCHECKFORWIN 5

#define EMPTY_Sign ' '

#define DESIREDSERIES 4			//	The default is to win by series of 4. But this way we are able to change it.

//-+-+-+-+-+-+-+
//	FOR THE FUNCTION: int need_to_check_win_by_diags():
	//	this function returns -1 if it signals there is a possibility for a win via Down Diagonals ONLY.
	//	this function returns 1 if it signals there is a possibility for a win via Up Diagonals ONLY.
	//	this function returns 0 if it signals there is a possibility for a win via BOTH Up Diagonals and Down Diagonals.
	//	this function returns -2 if it signals there is NO possibility for a win via BOTH Up Diagonals and Down Diagonals.

#define POS_WIN_BY_DOWN_DIAGS_ONLY -1
#define POS_WIN_BY_UP_DIAGS_ONLY 1
#define POS_WIN_BY_BOTH_DIAGS 0
#define NO_POS_WIN_BY_BOTH_DIAGS -2

//-+-+-+-+-+-+-+

//	Define struct of coordinate: (COOR):
typedef struct coordinate_ {
	char row_index;
	int col_index;
}COOR;

//	Define struct of win conditions: (WIN):
typedef struct win_condit {
	bool win_by_row;
	bool win_by_col;
	bool win_by_diagonal;
}WIN;




//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

//FUNCTIONS:
//-+-+-+-+-+-+-+-


//	NOTE::: THESE TWO FUNCTIONS ARE NOT USED!

int numOfEmptySpotsInThisCOL(char table[][COLS_1], int COL_num);
char covert_int_to_ASCII(int source_int);
//-+-+-+-+-+-+-+-


//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


void readEmptyContentTable(char table[][COLS_1]);
void read_COLStitle(char table[][COLS_1]);
void read_ROWStitle(char table[][COLS_1]);
void readWholeEmptyTable(char table[][COLS_1]);
void printWholeTable(char table[][COLS_1]);
void StartAsPlayer(int* currentPlayerIs);
char checkCurrectInput_Select_A_Player(char one_or_two);
void turnQuestion(int currentPlayerIs);
void switchPlayer(int* currentPlayerIs);
void readInput(char table[][COLS_1], char* COL_num_input, int* currentPlayerIs, COOR* placedCoordinate);
void checkCorrectInput_COL_num_input(char* COL_num_input);
int numOfFullSpotsInThisCOL(char table[][COLS_1], int COL_num);
int check_COL_is_not_taken_AND_write(char table[][COLS_1], char COL_num, char P1orP2, COOR* placedCoordinate);
char convert_CurrentPlayerIsINT_to_CHAR(int currentPlayerIs);
bool check_FINAL_Win(char table[][COLS_1], bool* win_by_row, bool* win_by_col, bool* win_by_diagonal, int* currentPlayerIs, COOR* placedCoordinate, int countTurns);
int need_to_check_win_by_diags(COOR* placedCoordinate, int* currentDownDiag_Length_TOTAL, int* currentUpDiag_Length_TOTAL, int* currentDownDiag_Length_UPSECTION_disincorporate_p, int* currentUpDiag_Length_DOWNSECTION_p);
void check_win_by_down_diags(char table[][COLS_1], int* currentPlayerIs, bool* win_by_diagonal, COOR* placedCoordinate, int currentDownDiag_Length_TOTAL, int currentDownDiag_Length_UPSECTION_disincorporate);
void check_win_by_up_diags(char table[][COLS_1], int* currentPlayerIs, bool* win_by_diagonal, COOR* placedCoordinate, int currentUpDiag_Length_TOTAL, int currentUpDiag_Length_DOWNSECTION);
void check_win_by_rows(char table[][COLS_1], int* currentPlayerIs, bool* win_by_row, COOR* placedCoordinate);
void check_win_by_cols(char table[][COLS_1], int* currentPlayerIs, bool* win_by_col, COOR* placedCoordinate);
void printWin(int currentPlayerIs);




//-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//MAIN:::



int main() {
	//Main Table:
	char table[ROWS_A][COLS_1];			//	Creates the Main Table:	
	readWholeEmptyTable(table);			//	Resets the table's structure:

	COOR inputCOOR;						//	The User's Specipic input coordinate will be saved in this variable.
	int currentPlayerIs = 0;			//	Current player indication.
	char COL_num_input = 0;				//	The User's keypress. (numbers between 1-7).

	//	Resets the Win Conditions:
	WIN win_c;
	win_c.win_by_row = false;
	win_c.win_by_col = false;
	win_c.win_by_diagonal = false;
	bool win = false;					//	default is false in Total;

	int countTurns = 0;

	//-+-+-+-+-+-+-+-

	
	printWholeTable(table);																														//	Prints the initial empty Table:

	StartAsPlayer(&currentPlayerIs);																											//	Choose a Player.

	while (!win && countTurns < TABLEFIELD) {																									//	The game ends when a Player has won, or when the Table's Field is FULL.
		turnQuestion(currentPlayerIs);																											//	Please make a move.
		readInput(table, &COL_num_input, &currentPlayerIs, &inputCOOR);																			//	The move.
		printWholeTable(table);																													//	Prints the Updated Table.
		win = check_FINAL_Win(table, &win_c.win_by_row, &win_c.win_by_col, &win_c.win_by_diagonal, &currentPlayerIs, &inputCOOR, countTurns);	//	Check if a Player has won.
		switchPlayer(&currentPlayerIs);																											//	The turn is passed to the next Player.

		countTurns++;																															//	Count the turns passed.	
	}

	if (win) {																																	//	We found a WINNER!
		switchPlayer(&currentPlayerIs);
		printWin(currentPlayerIs);
	}
	return 0;
}



//-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-





void readEmptyContentTable(char table[][COLS_1]) {
	//	This function reads the empty spots in the Main Table:

	int i, j;

	for (i = 1; i < ROWS_A; i++) {
		for (j = 1; j < COLS_1; j++) {
			table[i][j] = EMPTY_Sign;
		}
	}
}
void readInput(char table[][COLS_1], char* COL_num_input, int* currentPlayerIs, COOR* placedCoordinate) {
	//	According to the Player, inserts the Matching Sign to the matching Column number (to the bottom of the Column) in the table.
	//	This function also checks whether the input is correct (between 1-7), and if the column is full it prints an error and the user is required to enter a correct input.

	int repeat = 0;

	printf("Please enter column input (a number between 1-%d): \n", COLS_1 - 1);
	scanf(" %c", COL_num_input);
	checkCorrectInput_COL_num_input(COL_num_input);

	switch (*currentPlayerIs) {
	case P1_TURN:
		repeat = check_COL_is_not_taken_AND_write(table, *COL_num_input, P1, placedCoordinate);
		if (repeat != 0) {
			readInput(table, COL_num_input, currentPlayerIs, placedCoordinate);
		}
		break;
	case P2_TURN:
		repeat = check_COL_is_not_taken_AND_write(table, *COL_num_input, P2, placedCoordinate);
		if (repeat != 0) {
			readInput(table, COL_num_input, currentPlayerIs, placedCoordinate);
		}
	}
}
int check_COL_is_not_taken_AND_write(char table[][COLS_1], char COL_num, char P1orP2, COOR* placedCoordinate) {
	//	this function checks if the 'bottom' spot in the table in this specific column is not taken.
	//	if it is empty, then the input will be placed at the 'bottom' of the column.
	//	if it is taken, then the input will be placed above the last 'bottom'.
	//	if it the column is full then, it will output the error code '-2'.

	int	COL_num_int = COL_num - '0';					//	convert ASCII value to real int;

	int numOfFullSpots = numOfFullSpotsInThisCOL(table, COL_num_int);

	if (numOfFullSpots < (ROWS_A - 1)) {
		table[(ROWS_A - 1) - numOfFullSpots][COL_num_int] = P1orP2;
		(*placedCoordinate).row_index = (ROWS_A - 1) - numOfFullSpots;			// save this specific position for the future!
		(*placedCoordinate).col_index = COL_num_int;							// save this specific position for the future!
		return 0;
	}
	else {
		printf("The current column is FULL!\n");		//	error message.
		return -2;										//	outputs error code.
														//	the error code may serve other functions to start over the process, and try again.
	}
}
int numOfFullSpotsInThisCOL(char table[][COLS_1], int COL_num) {
	//	this function tells how many 'full' (= not empty) spots are placed in this specific column.

	int i = ROWS_A - 1;
	while ((table[i][COL_num] != EMPTY_Sign) && i != 0) {
		i--;
	}
	return (ROWS_A - 1) - i;
}
void switchPlayer(int* currentPlayerIs) {
	//	This function changes indication of knowing who the current Player is.

	(*currentPlayerIs) *= -1;
}
void turnQuestion(int currentPlayerIs) {
	//	This function asks the correct Player to make a move:

	switch (currentPlayerIs) {
	case P1_TURN:
		printf("It's Player 1's turn (X).\n");
		break;
	case P2_TURN:
		printf("It's Player 2's turn (O).\n");
		break;
	}
}
void checkCorrectInput_COL_num_input(char* COL_num_input) {
	//	This function is checking for correct input when the user is selecting entering a Column number to input his "Sign of Player' to:
	//	in addition, UI prints are given for guidance.

	int cols = COLS_1;
	cols = cols + '0';

	if (!((*COL_num_input >= '1') && (*COL_num_input <= (cols - 1)))) {				//	check if the input is a digit number between 1 and 7.
		printf("Your input was illegal, Please enter a number between 1-%d: \n", COLS_1 - 1);
		scanf(" %c", COL_num_input);
		checkCorrectInput_COL_num_input(COL_num_input);
	}
}
void StartAsPlayer(int* currentPlayerIs) {
	//	This function asks the user what Player would he like to play as, for the rest of the game.
	//	This function would serve us for the initial phase of the game.
	//	According to the decision of the user, the function will output the according char 'SignOfPlayer': 'X' for P1, OR 'O' for P2;

	printf("Select a Player: (1 = X) / (2 = O): ");			//	UI message.
	char c;
	scanf("%c", &c);
	char res = checkCurrectInput_Select_A_Player(c);		//	checking for correct input.

	if (res == P1) {
		*currentPlayerIs = P1_TURN;
	}
	else if (res == P2) {
		*currentPlayerIs = P2_TURN;
	}
}
char checkCurrectInput_Select_A_Player(char one_or_two) {
	//checking for correct input when the user is selecting a Player to start with:
	//in addition, UI prints are given for guidance.

	if (one_or_two == '1' || one_or_two == P1 || one_or_two == 'x') {
		printf("You Chose %c !\n", P1);
		putchar('\n');			//	for aesthetics, print an empty line.
		return P1;
	}
	else if (one_or_two == '2' || one_or_two == P2 || one_or_two == 'o') {
		printf("You Chose %c !\n", P2);
		putchar('\n');			//	for aesthetics, print an empty line.
		return P2;
	}
	else {
		printf("Please try again...\n");
		scanf(" %c", &one_or_two);
		return checkCurrectInput_Select_A_Player(one_or_two);
	}
}
void read_COLStitle(char table[][COLS_1]) {
	//	This function sets the Columns' title to be the numbers from 1 till 7.

	int i;
	table[0][0] = ' ';				//	This is specifically the Top Left corner of the MainTable.
	for (i = 1; i < COLS_1; i++) {
		table[0][i] = i + '0';
	}
}
void read_ROWStitle(char table[][COLS_1]) {
	//	This function sets the Rows' title to be the numbers from A till F.

	int i;
	for (i = 1; i < ROWS_A; i++) {
		table[i][0] = i + 'A' - 1;
	}
}
void readWholeEmptyTable(char table[][COLS_1]) {
	//	This function is the skeleton of the MainTable, and resets the MainTable's structure.
	//	This function is the base of the program. The program relies on this function.

	read_ROWStitle(table);
	read_COLStitle(table);
	readEmptyContentTable(table);
}
void printWholeTable(char table[][COLS_1]) {
	//	This function prints the whole MainTable.

	system("cls");				//	cleans the last screen from view. (Works on Microsoft Windows' CMD)

	int i, j;

	for (i = 0; i < ROWS_A; i++) {
		for (j = 0; j < COLS_1; j++) {
			putchar(table[i][j]);
			putchar('\t');
		}
		putchar('\n');
	}
}
bool check_FINAL_Win(char table[][COLS_1], bool* win_by_row, bool* win_by_col, bool* win_by_diagonal, int* currentPlayerIs, COOR* placedCoordinate, int countTurns) {
	//	This function checks the Final Win condition.
	//	The condition for winning is to win by rows, or by columns, or by diagonals.
	//	This function checks and sums the status of all of the these win conditions, and updates the Total status in a return boolean.

	bool finalWin = false;
	int checkDiags;
	int currentDownDiag_Length_DOWNSECTION_disincorporate;
	int currentUpDiag_Length_DOWNSECTION_disincorporate;
	int currentDownDiag_Length_TOTAL;
	int currentUpDiag_Length_TOTAL;





	if (countTurns > STARTCHECKFORWIN) {			//there is no need to check the win status if the games has only started. This is the limit for start checking.
													//explanation: there is no posiblillity to win the game with less than STARTCHECKFORWIN turns;

		check_win_by_rows(table, currentPlayerIs, win_by_row, placedCoordinate);
		check_win_by_cols(table, currentPlayerIs, win_by_col, placedCoordinate);

		//check whether it is possible to win by diagonals, and tell which type of diagonals exactly (Up Diagonals / Down Diagonals).
		checkDiags = need_to_check_win_by_diags(placedCoordinate, &currentDownDiag_Length_TOTAL, &currentUpDiag_Length_TOTAL, &currentDownDiag_Length_DOWNSECTION_disincorporate, &currentUpDiag_Length_DOWNSECTION_disincorporate);



		//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-

		//SUMMARY OF need_to_check_win_by_diags :

		if (checkDiags == POS_WIN_BY_BOTH_DIAGS) {
			check_win_by_down_diags(table, currentPlayerIs, win_by_diagonal, placedCoordinate, currentDownDiag_Length_TOTAL, currentDownDiag_Length_DOWNSECTION_disincorporate);	//if win_by_diagonal is found, don't waste your time and check in check_win_by_up_diags
			if (!*win_by_diagonal) {
				check_win_by_up_diags(table, currentPlayerIs, win_by_diagonal, placedCoordinate, currentUpDiag_Length_TOTAL, currentUpDiag_Length_DOWNSECTION_disincorporate);
			}
		}
		else if (checkDiags == POS_WIN_BY_DOWN_DIAGS_ONLY) {
			check_win_by_down_diags(table, currentPlayerIs, win_by_diagonal, placedCoordinate, currentDownDiag_Length_TOTAL, currentDownDiag_Length_DOWNSECTION_disincorporate);
		}
		else if (checkDiags == POS_WIN_BY_UP_DIAGS_ONLY) {
			check_win_by_up_diags(table, currentPlayerIs, win_by_diagonal, placedCoordinate, currentUpDiag_Length_TOTAL, currentUpDiag_Length_DOWNSECTION_disincorporate);
		}
		else if (checkDiags == NO_POS_WIN_BY_BOTH_DIAGS) {
			*win_by_diagonal = false;
		}

		//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-



		finalWin = (*win_by_row || *win_by_col || *win_by_diagonal);


		if ((countTurns + 1) == TABLEFIELD) {																					//This is the Draw Condition.
			printf("It's a DRAW!\nGood Game!\n");
		}
	}
	return finalWin;

}
int need_to_check_win_by_diags(COOR* placedCoordinate, int* currentDownDiag_Length_TOTAL, int* currentUpDiag_Length_TOTAL, int* currentDownDiag_Length_DOWNSECTION_disincorporate_p, int* currentUpDiag_Length_DOWNSECTION_disincorporate_p) {
	//	there isn't a need to check all the possible diagonals.
	//	so this function checks, based on the coordinate, wether there is a possibility that there is a Win by Diagonals.

	//	this function calculates wether the length of the possible diagonal is >= 4, for EACH type of diagonal: the Down Diagonal or the Up Diagonal.

	//	this function returns -1 if it signals there is a possibility for a win via Down Diagonals ONLY.
	//	this function returns 1 if it signals there is a possibility for a win via Up Diagonals ONLY.
	//	this function returns 0 if it signals there is a possibility for a win via BOTH Up Diagonals and Down Diagonals.
	//	this function returns -2 if it signals there is NO possibility for a win via BOTH Up Diagonals and Down Diagonals.



	COOR Input = (*placedCoordinate);						//	read the Current input's coordinate.
	int row_Length = Input.col_index;						//	initialize lengths accordingly.
	int col_Length = ROWS_A - Input.row_index;
	int row_Right_length = COLS_1 - row_Length;
	int row_Right_length_disincorporate = COLS_1 - row_Length - 1;
	int col_Up_Length_disincorporate = ROWS_A - col_Length - 1;
	int row_Left_length_disincorporate = row_Length - 1;

	int currentDownDiag_Length_DOWNSECTION;
	int currentUpDiag_Length_DOWNSECTION;
	int currentDownDiag_Length_UPSECTION_disincorporate;
	int currentUpDiag_Length_UPSECTION_disincorporate;


	bool possible_win_viaDownDiags = false;
	bool possible_win_viaUpDiags = false;


	////// /////////////

	//	calculating the changing DOWN diagonal's length. - DOWNSECTION

	if (row_Right_length <= col_Length) {					//	the diagonal's length prioritises the shortest length of both.
		currentDownDiag_Length_DOWNSECTION = row_Right_length;
	}
	else currentDownDiag_Length_DOWNSECTION = col_Length;



	//	calculating the changing DOWN diagonal's length. - UPSECTION_disincorporate



	if (col_Up_Length_disincorporate <= row_Left_length_disincorporate) {					//	the diagonal's length prioritises the shortest length of both.
		currentDownDiag_Length_UPSECTION_disincorporate = col_Up_Length_disincorporate;
	}
	else currentDownDiag_Length_UPSECTION_disincorporate = row_Left_length_disincorporate;


	////// /////////////////// /////////////////// /////////////
	////// /////////////////// /////////////////// /////////////



	//	calculating the changing UP diagonal's length. - DOWNSECTION

	if (col_Length <= row_Length) {															//	the diagonal's length prioritises the shortest length of both.
		currentUpDiag_Length_DOWNSECTION = col_Length;
	}
	else currentUpDiag_Length_DOWNSECTION = row_Length;



	//	calculating the changing UP diagonal's length. - UPSECTION_disincorporate


	if (col_Up_Length_disincorporate <= row_Right_length_disincorporate) {					//	the diagonal's length prioritises the shortest length of both.
		currentUpDiag_Length_UPSECTION_disincorporate = col_Up_Length_disincorporate;
	}
	else currentUpDiag_Length_UPSECTION_disincorporate = row_Right_length_disincorporate;




	////// /////////////



	//	calculating Total length of both of the diagonals:


	* currentDownDiag_Length_TOTAL = currentDownDiag_Length_DOWNSECTION + currentDownDiag_Length_UPSECTION_disincorporate;
	*currentUpDiag_Length_TOTAL = currentUpDiag_Length_DOWNSECTION + currentUpDiag_Length_UPSECTION_disincorporate;


	//	checking Possibilty for a win via the current Down Diagonal & Up Digonal.

	if (*currentDownDiag_Length_TOTAL >= DESIREDSERIES) {
		possible_win_viaDownDiags = true;
	}

	if (*currentUpDiag_Length_TOTAL >= DESIREDSERIES) {
		possible_win_viaUpDiags = true;
	}




	//	these lengths will serve the checking diags functions:
	*currentDownDiag_Length_DOWNSECTION_disincorporate_p = currentDownDiag_Length_DOWNSECTION - 1;
	*currentUpDiag_Length_DOWNSECTION_disincorporate_p = currentUpDiag_Length_DOWNSECTION - 1;




	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-



	//	SUMMARY:

	if (possible_win_viaDownDiags && possible_win_viaUpDiags) {
		return POS_WIN_BY_BOTH_DIAGS;
	}
	else if (possible_win_viaDownDiags) {
		return POS_WIN_BY_DOWN_DIAGS_ONLY;
	}
	else if (possible_win_viaUpDiags) {
		return POS_WIN_BY_UP_DIAGS_ONLY;
	}
	else {
		return NO_POS_WIN_BY_BOTH_DIAGS;
	}
}
void check_win_by_down_diags(char table[][COLS_1], int* currentPlayerIs, bool* win_by_diagonal, COOR* placedCoordinate, int currentDownDiag_Length_TOTAL, int currentDownDiag_Length_DOWNSECTION_disincorporate) {
	//	This function checks the win condition for Down diagonals.
	//	There is a need for a series of 4 of the same 'Sign of Player' in a specific column, in order to trigger this win condition.

	//	Converts currentPlayerIs from 'int' to its 'char' 'Sign of Player';
	char P1orP2 = convert_CurrentPlayerIsINT_to_CHAR(*currentPlayerIs);
	///BACKUP:	//	char NOT_P1orP2 = convert_CurrentPlayerIsINT_to_CHAR((*currentPlayerIs) * -1);         -NOT USED

	int i;
	int countSeries = 0;

	COOR Input = (*placedCoordinate);								//	read the Current input's coordinate.

	int row_indx = Input.row_index;									//	initialize counters' starting point accordingly.
	int col_indx = Input.col_index;

	int row_Length = Input.col_index;								//	initialize lengths accordingly.
	int col_Length = ROWS_A - Input.row_index;
	int col_Up_Length_disincorporate = ROWS_A - col_Length - 1;
	int row_Right_length_disincorporate = COLS_1 - row_Length - 1;






	//	check this specific down diagonal:
	for (i = 0; i < currentDownDiag_Length_TOTAL; i++) {			//	we reset the starting position and count the exact amount.

		if (table[row_indx + currentDownDiag_Length_DOWNSECTION_disincorporate][col_indx + currentDownDiag_Length_DOWNSECTION_disincorporate] == P1orP2) {
			countSeries++;
			row_indx--, col_indx--;
		}
		else countSeries = 0, row_indx--, col_indx--;				//	reset the series counter.

		//	check the win condition.
		if (countSeries >= DESIREDSERIES) {
			(*win_by_diagonal) = true;
			return;
		}
	}
	(*win_by_diagonal) = false;										//in case we didn't find a win.
	return;
}
void check_win_by_up_diags(char table[][COLS_1], int* currentPlayerIs, bool* win_by_diagonal, COOR* placedCoordinate, int currentUpDiag_Length_TOTAL, int currentUpDiag_Length_DOWNSECTION_disincorporate) {
	//	This function checks the win condition for Up diagonals.
	//	There is a need for a series of 4 of the same 'Sign of Player' in a specific column, in order to trigger this win condition.

	//	Converts currentPlayerIs from 'int' to its 'char' 'Sign of Player';
	char P1orP2 = convert_CurrentPlayerIsINT_to_CHAR(*currentPlayerIs);
	///BACKUP:	//	char NOT_P1orP2 = convert_CurrentPlayerIsINT_to_CHAR((*currentPlayerIs) * -1);         -NOT USED

	int i;
	int countSeries = 0;

	COOR Input = (*placedCoordinate);									//	read the Current input's coordinate.

	int row_indx = Input.row_index;										//	initialize counters' starting point accordingly.
	int col_indx = Input.col_index;

	int row_Length = Input.col_index;									//	initialize lengths accordingly.
	int col_Length = ROWS_A - Input.row_index;
	int row_Right_length_disincorporate = COLS_1 - row_Length - 1;
	int col_Up_Length_disincorporate = ROWS_A - col_Length - 1;




	//	check this specific up diagonal:
	for (i = 0; i < currentUpDiag_Length_TOTAL; i++) {					//	we reset the starting position and count the exact amount.

		if (table[row_indx + currentUpDiag_Length_DOWNSECTION_disincorporate][col_indx - currentUpDiag_Length_DOWNSECTION_disincorporate] == P1orP2) {
			countSeries++;
			row_indx--, col_indx++;
		}
		else countSeries = 0, row_indx--, col_indx++;					//	reset the series counter.

		//	check the win condition.
		if (countSeries >= DESIREDSERIES) {
			(*win_by_diagonal) = true;
			return;
		}
	}
	(*win_by_diagonal) = false;											//	in case we didn't find a win.
	return;
}
void check_win_by_rows(char table[][COLS_1], int* currentPlayerIs, bool* win_by_row, COOR* placedCoordinate) {
	//	This function checks the win condition for rows.
	//	There is a need for a series of 4 of the same 'Sign of Player' in a specific row, in order to trigger this win condition.

	//	Converts currentPlayerIs from 'int' to its 'char' 'Sign of Player';
	char P1orP2 = convert_CurrentPlayerIsINT_to_CHAR(*currentPlayerIs);
	///BACKUP:	//	char NOT_P1orP2 = convert_CurrentPlayerIsINT_to_CHAR((*currentPlayerIs) * -1);         -NOT USED


	int countSeries = 0;
	bool winFound = false;
	bool whole_ROW_Checked = false;
	int count_ROWS_Checked = 0;

	COOR Input = (*placedCoordinate);										//	read the Current input's coordinate.
	int row_indx = Input.row_index;											//	initialize counters' starting point accordingly.
	int col_indx = 0;														//	here we start the search from the start of the column.


	//start position was found! check from here.
	//check the whole of the specific row:
	while (col_indx < COLS_1) {

		if ((col_indx > COLS_1 - DESIREDSERIES) && (countSeries < 1)) {		//	there is no need to really check until the end of the row if it not possible to receive a series of 4 there.
			(*win_by_row) = false;
			return;
		}

		if (table[row_indx][col_indx] == P1orP2) {
			countSeries++;
			col_indx++;
		}
		else countSeries = 0, col_indx++;									//	reset the series counter.

		//	check the win condition.
		if (countSeries >= DESIREDSERIES) {
			(*win_by_row) = true;
			return;
		}

		if (col_indx == COLS_1) {
			(*win_by_row) = false;
			return;
		}
	}
}
void check_win_by_cols(char table[][COLS_1], int* currentPlayerIs, bool* win_by_col, COOR* placedCoordinate) {
	//	This function checks the win condition for columns.
	//	There is a need for a series of 4 of the same 'Sign of Player' in a specific column, in order to trigger this win condition.

	//	Converts currentPlayerIs from 'int' to its 'char' 'Sign of Player';
	char P1orP2 = convert_CurrentPlayerIsINT_to_CHAR(*currentPlayerIs);
	///BACKUP:	//	char NOT_P1orP2 = convert_CurrentPlayerIsINT_to_CHAR((*currentPlayerIs) * -1);         -NOT USED

	int countSeries = 0;

	bool whole_COL_Checked = false;
	int count_COLS_Checked = 0;

	COOR Input = (*placedCoordinate);										//	read the Current input's coordinate.
	int row_indx = Input.row_index;											//	initialize counters' starting point accordingly.
	int col_indx = Input.col_index;



	//	checks the specific column.

	//	start position was found! check from here.
	//	&& ((ROWS_A - 1 - row_indx) >= DESIREDSERIES)
	while (row_indx < ROWS_A) {

		if ((row_indx > ROWS_A - DESIREDSERIES) && (countSeries < 1)) {		//	there is no need to really check until the end of the column if it not possible to receive a series of 4 there.
			(*win_by_col) = false;
			return;
		}

		if (table[row_indx][col_indx] == P1orP2) {
			countSeries++;
			row_indx++;
		}
		else countSeries = 0, row_indx++;									//	reset the series counter.

		//	check the win condition.
		if (countSeries >= DESIREDSERIES) {
			(*win_by_col) = true;
			return;
		}

		if (row_indx == ROWS_A) {
			(*win_by_col) = false;
			return;
		}
	}
}
void printWin(int currentPlayerIs) {
	//	This function prints who is the winning Player.

	if (currentPlayerIs == P1_TURN) {
		printf("Congrats! Player 1 (%c) has WON!\n", P1);
	}
	else if (currentPlayerIs == P2_TURN) {
		printf("Congrats! Player 2 (%c) has WON!\n", P2);
	}
}
char convert_CurrentPlayerIsINT_to_CHAR(int currentPlayerIs) {
	//	This function converts currentPlayerIs from 'int' to its 'char' 'Sign of Player';

	char P1orP2 = 0;
	if (currentPlayerIs == P1_TURN) {
		P1orP2 = P1;
	}
	if (currentPlayerIs == P2_TURN) {
		P1orP2 = P2;
	}
	return P1orP2;
}



//	NOTE::: THESE TWO FUNCTIONS ARE NOT USED!
char covert_int_to_ASCII(int source_int) {
	//	This function makes a convertion from real Int to ASCII code;

	int num_char = source_int;
	char res;

	while (num_char >= 256) {
		num_char -= 256;
	}
	while (num_char < 0) {
		num_char += 256;
	}
	res = num_char + '0';
	return res;
}
int numOfEmptySpotsInThisCOL(char table[][COLS_1], int COL_num) {
	//	this function tells how many Empty spots are placed in this specific column.

	int i = ROWS_A - 1;
	while ((table[i][COL_num] != EMPTY_Sign) && i != 0) {
		i--;
	}
	return i;
}