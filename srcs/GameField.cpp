#include "main.h"

GameField::GameField() {
	restartGame();
}

GameField::~GameField() {

}

t_eCell GameField::getCell(int i, int j) {
	if (i < FIELD_SIZE && j < FIELD_SIZE)
		return _field[i][j];
	return CELL_WRONG;
}

void GameField::setCell(int i, int j, t_eCell cell) {
	if (i < FIELD_SIZE && j < FIELD_SIZE)
		_field[i][j] = cell;
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
	_field[i][j] = CELL_PLAYER_HUMAN;
	dropPossibilities();
}

bool GameField::isWin(e_Player player)
{
	int i_start = (player == PLAYER_HUMAN) ? FIELD_SIZE - 3 : 0;
	int j_start = (player == PLAYER_HUMAN) ? FIELD_SIZE - 3 : 0;
	t_eCell cell = (player == PLAYER_HUMAN) ? CELL_PLAYER_HUMAN : CELL_PLAYER_AI;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (_field[i + i_start][j + j_start] != cell)
				return false;
		}
	}
	return true;
}

bool GameField::isRowFilled(e_Cell cell, int i)
{
	int count = 0;
	for (int j = 0; j < FIELD_SIZE; ++j)
	{
		if (_field[i][j] == cell)
			count++;
	}
	return count > 2;
}

void GameField::restartGame()
{
	for (int i = 0; i < FIELD_SIZE; ++i) {
		for (int j = 0; j < FIELD_SIZE; ++j) {
			if (i < 3 && j < 3)
				_field[i][j] = CELL_PLAYER_HUMAN;
			else if (i >= FIELD_SIZE - 3 && j >= FIELD_SIZE - 3)
				_field[i][j] = CELL_PLAYER_AI;
			else
				_field[i][j] = CELL_EMPTY;
		}
	}
}
