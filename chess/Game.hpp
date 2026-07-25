#include <raylib.h>
#include <string>
#include <cstdint>
#include <iostream>

#ifndef S1
#define S1
//-- Window 
int Pixal = 90;
int SrcHeigth = (Pixal * 8);
int SrcWidth =  (Pixal * 8);
const char* Icon_local = "wn.png";
//--
//-- TO save some time
#define	IsMOUSE (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)|| IsMouseButtonPressed(MOUSE_BUTTON_LEFT)||IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)
typedef struct RecMin {
	uint16_t x = 0;
	uint16_t y = 0;
	uint16_t _2D = (uint16_t)Pixal;
	bool operator == (const RecMin& rm2) const {
		return (x == rm2.x && y == rm2.y && _2D == rm2._2D);
	}
	RecMin operator + (const RecMin& rm2) const {
		RecMin ref = *this;
		ref.x += rm2.x;
		ref.y += rm2.y;
		return ref;
	}
};
void DrawRecMin (RecMin rm ,Color C) {
	DrawRectangle(rm.x, rm.y, rm._2D, rm._2D, C);
}
bool CheckRecMinVec(RecMin rm, Vector2 v2) {
bool x = (rm.x <= v2.x && (rm.x + rm._2D) >= v2.x);
bool y = (rm.y <= v2.y && (rm.y + rm._2D) >= v2.y);
return (x && y); }
//--
//-- Game consts block
using turn_t = bool;
using state_t = bool;
using type_t = unsigned char;
namespace Game {
   constexpr turn_t PLAYER_1 = true;
   constexpr turn_t PLAYER_2 = false;
   constexpr state_t Selected = true;
   constexpr state_t UnSelected = false;
   constexpr Color PieceSelectColor = { 74,84,45,255 };
   constexpr Color RecLightColor = { 74, 112, 61,255 };
   constexpr Color RecDarkColor = { 238, 232, 213 ,255 };
   constexpr type_t _Wb = 0, _Wn = 1, _Wk = 2, _Wq = 3, _Wp = 4 , _Wr = 5;
   constexpr type_t _Bb = 6, _Bn = 7, _Bk = 8, _Bq = 9, _Bp = 10, _Br = 11;
}
//--
class Board {
public:
	RecMin _Board[8][8];
	Board() {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				_Board[row][col].x= (float)Pixal * (7 - col);
				_Board[row][col].y = (float)Pixal * (7 - row);
				_Board[row][col]._2D = Pixal;
			}
		}
	}
	void DrawBoard()const {
		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 8; col++) {
				if ((row + col) % 2 == 0) {
					DrawRecMin(_Board[row][col], Game:: RecLightColor);
				}
				else {
					DrawRecMin(_Board[row][col], Game::RecDarkColor);
				}
			}
		}
	}
};
//-- 
class Piece {
public : 
	state_t state = Game::UnSelected;
	type_t typ = { 0 };
	RecMin pos = { 0 };
	Texture tex = { 0 };
	void setPiece(RecMin rec, type_t ty) {

		this->pos = rec;
		this->typ = ty;
	
		std::string path = "picecs\\";

		     if (typ == Game::_Wp){ path += "wp.png"; }
		else if (typ == Game::_Wn){ path += "wn.png"; }
		else if (typ == Game::_Wb){ path += "wb.png"; }
		else if (typ == Game::_Wk){ path += "wk.png"; }
		else if (typ == Game::_Wq){ path += "wq.png"; }
		else if (typ == Game::_Wr){ path += "wr.png"; }
		else if (typ == Game::_Bp){ path += "bp.png"; }
		else if (typ == Game::_Bn){ path += "bn.png"; }
		else if (typ == Game::_Bb){ path += "bb.png"; }
		else if (typ == Game::_Br){ path += "br.png"; }
		else if (typ == Game::_Bk){ path += "bk.png"; }
		else if (typ == Game::_Bq){ path += "bq.png"; }

		Image tex = LoadImage(path.c_str());
		ImageResize(&tex, Pixal, Pixal);
		this->tex = LoadTextureFromImage(tex);

	}
};
void IntiSetof_16Piece(Board* Board, Piece Setof16Piece[], bool TypeofSet) {
	Setof16Piece[0] .setPiece((TypeofSet) ? Board->_Board[1][0] : Board->_Board[6][0], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[1] .setPiece((TypeofSet) ? Board->_Board[1][1] : Board->_Board[6][1], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[2] .setPiece((TypeofSet) ? Board->_Board[1][2] : Board->_Board[6][2], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[3] .setPiece((TypeofSet) ? Board->_Board[1][3] : Board->_Board[6][3], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[4] .setPiece((TypeofSet) ? Board->_Board[1][4] : Board->_Board[6][4], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[5] .setPiece((TypeofSet) ? Board->_Board[1][5] : Board->_Board[6][5], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[6] .setPiece((TypeofSet) ? Board->_Board[1][6] : Board->_Board[6][6], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[7] .setPiece((TypeofSet) ? Board->_Board[1][7] : Board->_Board[6][7], (TypeofSet) ? Game::_Wp : Game::_Bp);
	Setof16Piece[8] .setPiece((TypeofSet) ? Board->_Board[0][0] : Board->_Board[7][0], (TypeofSet) ? Game::_Wr : Game::_Br);
	Setof16Piece[9] .setPiece((TypeofSet) ? Board->_Board[0][1] : Board->_Board[7][1], (TypeofSet) ? Game::_Wn : Game::_Bn);
	Setof16Piece[10].setPiece((TypeofSet) ? Board->_Board[0][2] : Board->_Board[7][2], (TypeofSet) ? Game::_Wb : Game::_Bb);
	Setof16Piece[11].setPiece((TypeofSet) ? Board->_Board[0][3] : Board->_Board[7][3], (TypeofSet) ? Game::_Wk : Game::_Bk);
	Setof16Piece[12].setPiece((TypeofSet) ? Board->_Board[0][4] : Board->_Board[7][4], (TypeofSet) ? Game::_Wq : Game::_Bq);
	Setof16Piece[13].setPiece((TypeofSet) ? Board->_Board[0][5] : Board->_Board[7][5], (TypeofSet) ? Game::_Wb : Game::_Bb);
	Setof16Piece[14].setPiece((TypeofSet) ? Board->_Board[0][6] : Board->_Board[7][6], (TypeofSet) ? Game::_Wn : Game::_Bn);
	Setof16Piece[15].setPiece((TypeofSet) ? Board->_Board[0][7] : Board->_Board[7][7], (TypeofSet) ? Game::_Wr : Game::_Br);
}
void DrawAllPieces(Piece Wpiece[], Piece Bpieces[]) {
	for (int i = 0; i < 16;i++) {
		if (Wpiece[i].state) {
			DrawTexture(Wpiece[i].tex, Wpiece[i].pos.x, Wpiece[i].pos.y, Game::PieceSelectColor);
		}
		else {
			DrawTexture(Wpiece[i].tex, Wpiece[i].pos.x, Wpiece [i].pos.y, WHITE);
		}
	}
	for (int i = 0; i < 16;i++) {
		if (Bpieces[i].state) {
			DrawTexture(Bpieces[i].tex, Bpieces[i].pos.x, Bpieces[i].pos.y, Game::PieceSelectColor);
		}
		else {
			DrawTexture(Bpieces[i].tex, Bpieces[i].pos.x, Bpieces[i].pos.y, WHITE);
		}
	}
}
//-- functions
Piece * SelectPieceFromSetOf_16( Piece SetofPieces_16_Piece []) {
	for (int indexofPiece = 0; indexofPiece < 16; indexofPiece++) {
		if (IsMOUSE && CheckRecMinVec(SetofPieces_16_Piece[indexofPiece].pos, GetMousePosition())) {
			SetofPieces_16_Piece[indexofPiece].state = Game::Selected;
			return &SetofPieces_16_Piece[indexofPiece];
		}
	}
	return nullptr; 
};
RecMin * SelectPositionInTheBoard(Board BoardofChess_8X8size) {
	for (int indexofrow = 0; indexofrow < 8; indexofrow++) {
		for (int indexofcol = 0; indexofcol < 8; indexofcol++) {
			if (IsMOUSE&&CheckRecMinVec(BoardofChess_8X8size._Board[indexofrow][indexofcol], GetMousePosition())) {
				return &BoardofChess_8X8size._Board[indexofrow][indexofcol];
			}
		}
	}
	return nullptr; 
};
//-- Movement
//return a boolen val true if the move is vaild
bool TheRulesOfMovementForEveryPiece(Piece* Pointer_toPieceHadBeenSelected,RecMin* Pointer_toPositionHadBeenSelected){
	// pawn 
	//
	//
	//
	//
	//
}
bool TheMovementOfPiecesOnTheBoard(Piece Setof16Piece[], Board BoardofChess_8X8size) {
	// p to last piece cilck
	// p to new piece 
	// p to the position
	// func to know what piece is cilck
	// func to know what position is cilck
	// cond if the piece pos is a same pos that been selcet
	// set any one of the p's in nullptr
static Piece * Pointer_toPieceHadBeenSelected = nullptr;
	   Piece * Pointer_toPieceSelectedNow = nullptr;
	   RecMin * Pointer_toPositionHadBeenSelected = nullptr;

	Pointer_toPieceSelectedNow = SelectPieceFromSetOf_16(Setof16Piece);

	if (Pointer_toPieceSelectedNow != nullptr){
		Pointer_toPieceHadBeenSelected = Pointer_toPieceSelectedNow;
		Pointer_toPieceHadBeenSelected->state = Game::Selected;
	}
	
	if (Pointer_toPieceHadBeenSelected != nullptr){

		Pointer_toPositionHadBeenSelected = SelectPositionInTheBoard(BoardofChess_8X8size);

		if (Pointer_toPositionHadBeenSelected != nullptr && Pointer_toPieceHadBeenSelected->pos != *Pointer_toPositionHadBeenSelected) {

			Pointer_toPieceHadBeenSelected->pos = *Pointer_toPositionHadBeenSelected;
			Pointer_toPieceHadBeenSelected->state = Game::UnSelected;
			Pointer_toPieceHadBeenSelected = nullptr;

			return true;
		}

	}
	
	return false;
}

#endif
