#ifndef DOMINI_TEST_GAMECORE_H
#define DOMINI_TEST_GAMECORE_H
#include "main.h"

class GameCore {
private:
	t_eState	_state;
	bool		_stateChanged;

public:
	bool isStateChanged() const;
	t_eState getState() const;
	void setState(t_eState state);

	GameCore();
	~GameCore();
};


#endif //DOMINI_TEST_GAMECORE_H
