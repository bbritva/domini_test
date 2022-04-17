#ifndef DOMINI_TEST_GAMEFIELD_H
#define DOMINI_TEST_GAMEFIELD_H

class GameField {
public:
	GameField();
	virtual ~GameField();
	void moveCell(int i, int j, t_eDirection direction);
	t_eCell getCell(int i, int j);

	void showPossibilities(int i, int j);

private:
	t_eCell _field[FIELD_SIZE][FIELD_SIZE];
};

#endif //DOMINI_TEST_GAMEFIELD_H




