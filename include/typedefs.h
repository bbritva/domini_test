#ifndef DOMINI_TEST_TYPEDEFS_H
#define DOMINI_TEST_TYPEDEFS_H

typedef enum e_State {
	MENU,
	GAME,
	GAME_MOVE_POSSIBILITIES,
	GAME_MOVING,
	END_GAME
} t_eState;

typedef enum e_Button {
	START,
	CREDITS,
	EXIT
} t_eButton;

#endif //DOMINI_TEST_TYPEDEFS_H
