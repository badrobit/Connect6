#define BOARD_SIZE 19

#include <stdio.h>
#include <stdlib.h>

void initialize_game_board(); 
void print_game_board(); 
void human_place_piece(); 
void ai_move_offensively(); 

char game_board[BOARD_SIZE][BOARD_SIZE]; 

int last_move_x = 0; 
int last_move_y = 0; 

int main( void )
{
	initialize_game_board();

	while( 1 )
	{
		human_place_piece(); 
		ai_move_offensively(); 
	}

	return(0); 
}

//	A function which allows a user to place a piece on the 
// game board.
void human_place_piece()
{
	int x, y = 0; 

	printf( "Enter Coordonate to Place Piece In\n" ); 
	scanf( "%d", &x ); 
	scanf( "%d", &y ); 

	game_board[x-1][y-1] = 'B'; 

	print_game_board(); 
}

//	A function that will capture the offensive (game winning)
// movemnets of the AI. 
void ai_move_offensively()
{
	int x, y = 0;
	int planning = 1;  

	while( planning == 1 )
	{
		if( last_move_x == 0 && last_move_y == 0 )
		{
			x = 5; y = 5; 
		}

		if( game_board[x-1][y-1] == ' ' )
		{
			last_move_x = x; 
			last_move_y = y; 
			planning == 0; 
		}
	}
	game_board[x-1][y-1] = 'W';
	print_game_board(); 
}  

// Used to print out the game board for visual display to the 
// user. 
void print_game_board()
{
	int x, y = 0;  

	for( x = 0; x < (BOARD_SIZE*2)+1; x++ )
	{
		if( x%2 == 0 )
			printf( "+" ); 
		if( x%2 != 0 )
			printf( "|" );
		for( y = 0; y < BOARD_SIZE; y++ )
		{
			if( x%2 == 0 )
				printf( "---+" ); 
			if ( x%2 != 0 )
				printf( " %c |", game_board[x/2][y] ); 
		}
		printf( "\n" ); 
	}
}

void initialize_game_board()
{
	int x, y = 0;  

	for( x = 0; x < BOARD_SIZE; x++ )
	{
		for( y = 0; y < BOARD_SIZE; y++ )
		{
			game_board[x][y] = ' '; 
		}
	}
}