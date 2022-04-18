#include "main.h"

AIPlayer::AIPlayer() : i_selected(0), j_selected(0){}

AIPlayer::~AIPlayer() {}

void AIPlayer::doMove(GameField *field)
{
	i_selected = 0;
	j_selected = 0;
	_field = field;

	getNextChecker();
	while (i_selected != FIELD_SIZE)
	{
		if (doGoodMove())
			return;
		getNextChecker();
	}
	i_selected = 0;
	j_selected = 0;
	getNextChecker();
	while (i_selected != FIELD_SIZE)
	{
		if (doBadMove())
			return;
		getNextChecker();
	}
}

void AIPlayer::getNextChecker()
{
	for (int i = i_selected; i < FIELD_SIZE; ++i) {
		for (int j = (i == i_selected) ? j_selected : 0; j < FIELD_SIZE; ++j) {
			if (_field->getCell(i, j) == CELL_PLAYER_AI && (i != i_selected || j != j_selected))
			{
				i_selected = i;
				j_selected = j;
				return;
			}
		}
	}
	i_selected = FIELD_SIZE;
}

bool AIPlayer::doGoodMove()
{
	if (i_selected > 0 && _field->getCell(i_selected - 1, j_selected) == CELL_EMPTY &&
		!_field->isRowFilled(CELL_PLAYER_AI, i_selected - 1))
	{
		_field->setCell(i_selected - 1, j_selected, CELL_PLAYER_AI);
		_field->setCell(i_selected, j_selected, CELL_EMPTY);
		return true;
	}
	else if (j_selected > 0 && _field->getCell(i_selected, j_selected - 1) == CELL_EMPTY)
	{
		_field->setCell(i_selected, j_selected - 1, CELL_PLAYER_AI);
		_field->setCell(i_selected, j_selected, CELL_EMPTY);
		return true;
	}
	return false;
}

bool AIPlayer::doBadMove()
{
	if (i_selected < FIELD_SIZE - 1 && _field->getCell(i_selected + 1, j_selected) == CELL_EMPTY)
	{
		_field->setCell(i_selected + 1, j_selected, CELL_PLAYER_AI);
		_field->setCell(i_selected, j_selected, CELL_EMPTY);
		return true;
	}
	else if (j_selected < FIELD_SIZE - 1 && _field->getCell(i_selected, j_selected + 1) == CELL_EMPTY)
	{
		_field->setCell(i_selected, j_selected + 1, CELL_PLAYER_AI);
		_field->setCell(i_selected, j_selected, CELL_EMPTY);
		return true;
	}
	return false;
}
