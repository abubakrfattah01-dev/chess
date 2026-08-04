#if 1
#include "Game.hpp"

int main()
{
	InitWindow(Window::SrcWidth, Window::SrcHeigth, Window::Title);
    SetTargetFPS(60);
    //-------------------------ICON
	SetWindowIcon(Window::Icon);
	UnloadImage(Window::Icon);
    Board BoardG;
	turn_t turnG = Game::PLAYER_1;
	Piece Bpieces[16] , Wpieces[16];
	Init_16Piece(&BoardG, Wpieces, Game::PLAYER_1);
	Init_16Piece(&BoardG, Bpieces, Game::PLAYER_2);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BoardG.DrawBoard();
        DrawAllPieces(Wpieces, Bpieces);
		if (turnG == Game::PLAYER_1) {
			if (TheMovementOfPiecesOnTheBoard(Wpieces, BoardG)) {
				//turnG = Game::PLAYER_2;
    }
    CloseWindow();
    return 0;
}
#endif 
/*#ifdef S2
    InitWindow(src_y, src_x, "Chess");
    SetTargetFPS(60);
    //-------------------------ICON
    Image Icon;
    Icon = LoadImage(Icon_local);
    SetWindowIcon(Icon);
    
    //------------------------------
    board chess;
    state_t state = PLAYER_1;
    Piece wp[16];
    _WInti(&chess, wp);
    Piece bp[16];
    _BInti(&chess, bp);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        chess.Draw();
        _Draw(wp,bp);
        if (state == PLAYER_1) {
            if (movement(wp, chess)) {
                state = PLAYER_2;
            }
        }
        else {
            if (movement(bp, chess)) {
                state = PLAYER_1;
            }
        }
        
        EndDrawing();
    }
    UnloadImage(Icon);
    CloseWindow();
	return 0;
}
#endif
/*else if (turnG == Game::PLAYER_2) {
			if (TheMovementOfPiecesOnTheBoard(Bpieces, BoardG)) {
				turnG = Game::PLAYER_1;
			}
*/