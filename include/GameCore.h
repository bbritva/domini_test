#ifndef DOMINI_TEST_GAMECORE_H
#define DOMINI_TEST_GAMECORE_H
#include "main.h"

class GameCore {
private:
	t_eState	_state;
	bool		_stateChanged;
	uint8_t		_buttonPressedMask;

public:
	bool isStateChanged() const;
	void setStateChanged(bool state);
	void setState(t_eState state);
	bool isButtonPressed(t_eButton button) const;
	void setButtonPressed(t_eButton button);
	void resetButtons();

	t_eState getState() const;

	GameCore();
	~GameCore();
};


#endif //DOMINI_TEST_GAMECORE_H
