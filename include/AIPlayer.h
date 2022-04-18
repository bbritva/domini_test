#ifndef DOMINI_TEST_AIPLAYER_H
#define DOMINI_TEST_AIPLAYER_H

class AIPlayer {
private:
	int i_selected;
	int j_selected;
	GameField *_field;

public:
	AIPlayer();
	~AIPlayer();

	void doMove(GameField *field);

	void getNextChecker();

	bool doGoodMove();

	bool doBadMove();
};


#endif //DOMINI_TEST_AIPLAYER_H
