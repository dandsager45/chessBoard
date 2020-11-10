#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64;

#define NAME "bitboard 1.0"
#define BRD_SQ_NUM 64

#define MAXGAMEMOVES 2048

enum { EMPTY, wP, wN, wB, WR, WQ, wK, bP, bN, bB, bR, bQ, bK }; // pieces
enum { FILE_NONE, FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H }; //files
enum { RANK_NONE, RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8 }; 

enum { WHITE, BLACK, BOTH };

enum {
	A1 = 1, B1, C1, D1, E1, F1, G1, H1, \
	    A2, B2, C2, D2, E2, F2, G2, H2, \
		A3, B3, C3, D3, E3, F3, G3, H3, \
		A4, B4, C4, D4, E4, F4, G4, H4, \
		A5, B5, C5, D5, E5, F5, G5, H5, \
		A6, B6, C6, D6, E6, F6, G6, H6, \
		A7, B7, C7, D7, E7, F7, G7, H7, \
		A8, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE };

enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8 }; 		// 4 bit enumeraiton of castling status


typedef struct {
	
	int move; 
	int castlePerm;
	int enPas;
	U64 posKey;
	
} S_UNDO;




typedef struct {
	
	int pieces[BRD_SQ_NUM];
	U64 pawns[3]; 						//pawn array for white, black and both
	
	int KingSq[2]; 						//square that the two kings are on
		
	int side;  							//side to move
	int enPas;
	int fiftyMove;						//counter for 50 move stalemate
	
	int ply;							//depth of search
	int histPly;						//total number of half moves
	
	int castlePerm;
	
	U64 posKey;        					//unique identifier for boardstate
	
	int pceNum[13];						//listing of all active pieces on board
	int bigPieces[3];					//count of all pieces minus pawns
	int majPieces[3];					//rooks & queens
	int minPieces[3];					//knights & bishops
	
	S_UNDO history[MAXGAMEMOVES];
	
	
} S_BOARD;




#endif