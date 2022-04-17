#include "main.h"

GameField::GameField() {
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			if (i < 3 && j < 3)
				_field[i][j] = CELL_PLAYER_1;
			else if (i >= FIELD_SIZE - 3 && j >= FIELD_SIZE - 3)
				_field[i][j] = CELL_PLAYER_2;
			else
				_field[i][j] = CELL_EMPTY;
		}
	}
}

GameField::~GameField() {

}

t_eCell GameField::getCell(int i, int j) {
	if (i < FIELD_SIZE && j < FIELD_SIZE)
		return _field[i][j];
	return CELL_WRONG;
}

void GameField::showPossibilities(int i, int j) {
	selectedCell[0] = i;
	selectedCell[1] = j;
	if (i > 0 && _field[i - 1][j] == CELL_EMPTY)
		_field[i - 1][j] = CELL_POSSIBLE_PLAYER_1;
	if (i < FIELD_SIZE - 1 && _field[i + 1][j] == CELL_EMPTY)
		_field[i + 1][j] = CELL_POSSIBLE_PLAYER_1;
	if (j > 0 && _field[i][j - 1] == CELL_EMPTY)
		_field[i][j - 1] = CELL_POSSIBLE_PLAYER_1;
	if (j < FIELD_SIZE - 1 && _field[i][j + 1] == CELL_EMPTY)
		_field[i][j + 1] = CELL_POSSIBLE_PLAYER_1;
}

void GameField::dropPossibilities() {
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			if (_field[i][j] == CELL_POSSIBLE_PLAYER_1)
				_field[i][j] = CELL_EMPTY;
		}
	}
}

void GameField::doMove(int i, int j) {
	_field[selectedCell[0]][selectedCell[1]] = CELL_EMPTY;
	_field[i][j] = CELL_PLAYER_1;
	dropPossibilities();
}
