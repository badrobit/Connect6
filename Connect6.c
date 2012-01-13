#define BOARD_SIZE 19

#include <stdio.h>
#include <stdlib.h>

char game_board[BOARD_SIZE][BOARD_SIZE]; 

void print_game_board(); 
void human_place_piece(); 

int main( void )
{
	while( 1 )
	{
		human_place_piece(); 
	}

	return(0); 
}

void human_place_piece()
{
	int x, y = 0; 

	printf( "Enter Coordonate to Place Piece In\n" ); 
	scanf( "%d", &x ); 
	scanf( "%d", &y ); 

	game_board[x-1][y-1] = 'B'; 
	print_game_board(); 
}

void print_game_board()
{
	int x, y = 0;  

	for( x = 0; x < BOARD_SIZE; x++ )
	{
		printf( "|" );
		for( y = 0; y < BOARD_SIZE; y++ )
		{
			printf( " %c |", game_board[x][y] ); 
		}
		printf( "\n" ); 
	}
}