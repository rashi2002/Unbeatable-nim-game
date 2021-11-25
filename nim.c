#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "nim.h"

/*************************************function1*************************************/
int *new_board( int board_size ){
	int* newBoard = malloc(board_size*sizeof(int));
	if(newBoard==NULL){
		fprintf(stderr, "ERROR: Malloc failed.");
		exit(0);
	}
	return newBoard;
}

/*************************************function2*************************************/
struct node *mk_nim_hash( int max_hash, int board_size, int *start_board ){
	struct node* nodes = malloc(sizeof(struct node )*max_hash);
	if(nodes==NULL){
		fprintf(stderr, "ERROR: Malloc failed.");
		exit(0);
	}
	for(int i=0; i<max_hash;i++){
		nodes[i].moves =-1;
		nodes[i].move = NULL;
		nodes[i].nimsum= -1;
		nodes[i].board = hash2board(board_size, start_board,i);
	}
	return nodes;
}

/*************************************function3*************************************/
void free_board( int *board ){
	free(board);
}
/*************************************function4*************************************/
void free_nim_hash( int max_hash, struct node *nim_hash ){
	for(int i=0; i<max_hash;i++){
		free(nim_hash[i].move);
		free(nim_hash[i].board);
	}
	free(nim_hash);
}
/*************************************function5*************************************/
int *board_from_argv( int board_size, char **argv ){
	int* newBoard = new_board(board_size);
	for(int i=0; i<board_size;i++){
		newBoard[i] = atoi(argv[i]);
	}
	return newBoard;
}
/*************************************function6*************************************/
int *copy_board( int board_size, int *board ){
	int*newBoard = malloc(sizeof(int)*board_size);
	if(newBoard==NULL){
		fprintf(stderr, "ERROR: Malloc Failed");
	}
	for(int i=0; i<board_size;i++){
		newBoard[i]=board[i];
	}
	return newBoard;
}
/*************************************function7*************************************/
int game_over( int board_size, int *board ){
	int matchCount =0;
	for(int i=0; i<board_size;i++){
		matchCount+=board[i];
	}
	if(matchCount==1){
		return 1;
	}
	else{
		return 0;
	}
}
/*************************************function8*************************************/
void join_graph( struct node *nim_hash, int hash, int board_size, int *start_board ){
	int k=0;
	int*copyBoard=NULL;
	if(nim_hash[hash].moves != -1){
		//already been computed
		return;
	}
	else{
		nim_hash[hash].moves=0;
		//num of moves = num of matches in the board
		for(int i=0; i<board_size;i++){
			nim_hash[hash].moves += nim_hash[hash].board[i]; //total 
		}
		
		nim_hash[hash].move = (struct move*)malloc(sizeof(struct move)*nim_hash[hash].moves);

		//filling out moves 
		for(int i=0; i<board_size; i++){
			for(int j=1; j<=nim_hash[hash].board[i]; j++,k++){
				//setting everything in the move struct array 
				nim_hash[hash].move[k].row = i;
				nim_hash[hash].move[k].matches = j;
				//create a new board with that move
				copyBoard = copy_board(board_size, nim_hash[hash].board);
				copyBoard[i]-= j;
			
				//debugging statement
				//print_board(board_size,copyBoard);

				nim_hash[hash].move[k].hash = board2hash(board_size, start_board, copyBoard );
				//debugging statement

				join_graph(nim_hash, nim_hash[hash].move[k].hash ,board_size, start_board);
				nim_hash[hash].nimsum = compute_nimsum(board_size,nim_hash[hash].board);	

				
			}
		}
		//setting nimsum
	}
 }
/*************************************function9*************************************/
int compute_nimsum( int board_size, int *board ){
	int nimsum=0;
	int is1 =1;
	for(int i=0; i<board_size;i++){
		nimsum = nimsum^board[i];
		if(board[i]>1){
			is1=0;
		}
	}
	if(is1==0){
		return nimsum;
	}
	else{
		return 1^nimsum;
	}

}
/*************************************DONE*************************************/
