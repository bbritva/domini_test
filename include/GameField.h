#ifndef DOMINI_TEST_GAMEFIELD_H
#define DOMINI_TEST_GAMEFIELD_H

class GameField {
public:
	GameField();
	virtual ~GameField();
	t_eCell getCell(int i, int j);
	void setCell(int i, int j, t_eCell cell);

	void showPossibilities(int i, int j);

	void doMove(int i, int j);

	bool isWin(e_Player player);

private:
	t_eCell	_field[FIELD_SIZE][FIELD_SIZE];
	int		selectedCell[2];

	void dropPossibilities();
};

#endif //DOMINI_TEST_GAMEFIELD_H




