#include "main.h"

GameField::GameField() {
	std::cout << "gamefield created\n";
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

void GameField::moveCell(int i, int j, t_eDirection direction) {
	t_eCell cell = _field[i][j];
	_field[i][j] = CELL_EMPTY;
	switch (direction) {
		case DIRECTION_UP:
			_field[i - 1][j] = cell;
			break;
		case DIRECTION_DOWN:
			_field[i + 1][j] = cell;
			break;
		case DIRECTION_LEFT:
			_field[i][j - 1] = cell;
			break;
		case DIRECTION_RIGHT:
			_field[i][j + 1] = cell;
			break;
	}

}

t_eCell GameField::getCell(int i, int j) {
	if (i < FIELD_SIZE && j < FIELD_SIZE)
		return _field[i][j];
	return CELL_WRONG;
}
