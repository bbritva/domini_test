#ifndef DOMINI_TEST_GAMEFIELD_H
#define DOMINI_TEST_GAMEFIELD_H

class GameField {
public:
	GameField();
	virtual ~GameField();
	t_eCell getCell(int i, int j);

	void showPossibilities(int i, int j);

	void doMove(int i, int j);

private:
	t_eCell	_field[FIELD_SIZE][FIELD_SIZE];
	int		selectedCell[2];

	void dropPossibilities();
};

#endif //DOMINI_TEST_GAMEFIELD_H




