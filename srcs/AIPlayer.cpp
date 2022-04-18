#include "main.h"

AIPlayer::AIPlayer() : i(0), j(0){}

AIPlayer::~AIPlayer() {}

void AIPlayer::doMove(GameField *field)
{
	i = 0;
	j = 0;
	_field = field;

	while (i != FIELD_SIZE)
	{
		getNextChecker();
		if (doGoodMove())
			return;
	}
	i = 0;
	j = 0;
	while (i != FIELD_SIZE)
	{
		getNextChecker();
		if (doBadMove())
			return;
	}
}

void AIPlayer::getNextChecker()
{
	for (; i < FIELD_SIZE; ++i) {
		for (j = 0; j < FIELD_SIZE; ++j) {
			if (_field->getCell(i, j) == CELL_PLAYER_AI)
				return;
		}
	}
}

bool AIPlayer::doGoodMove()
{
	if (i > 0 && _field->getCell(i - 1, j) == CELL_EMPTY)
	{
		_field->setCell(i - 1, j, CELL_PLAYER_AI);
		_field->setCell(i, j, CELL_EMPTY);
		return true;
	}
	else if (j > 0 && _field->getCell(i, j - 1) == CELL_EMPTY)
	{
		_field->setCell(i, j - 1, CELL_PLAYER_AI);
		_field->setCell(i, j, CELL_EMPTY);
		return true;
	}
	return false;
}

bool AIPlayer::doBadMove()
{
	if (i < FIELD_SIZE - 1 && _field->getCell(i + 1, j) == CELL_EMPTY)
	{
		_field->setCell(i + 1, j, CELL_PLAYER_AI);
		_field->setCell(i, j, CELL_EMPTY);
		return true;
	}
	else if (j < FIELD_SIZE - 1 && _field->getCell(i, j + 1) == CELL_EMPTY)
	{
		_field->setCell(i, j + 1, CELL_PLAYER_AI);
		_field->setCell(i, j, CELL_EMPTY);
		return true;
	}
	return false;
}
