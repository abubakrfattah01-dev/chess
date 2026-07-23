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
		}
		
		
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
#endif 
/*else if (turnG == Game::PLAYER_2) {
			if (TheMovementOfPiecesOnTheBoard(Bpieces, BoardG)) {
				turnG = Game::PLAYER_1;
			}
*/