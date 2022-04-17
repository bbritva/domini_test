#ifndef DOMINI_TEST_GAMECORE_H
#define DOMINI_TEST_GAMECORE_H

class GameCore {
private:
	t_eState	_state;
	bool		_stateChanged;
	uint8_t		_buttonPressedMask;
	int			_height;
	int			_width;
	int			_windowDescriptor;
	GameField	_gameField;

public:
	bool isStateChanged() const;
	void setStateChanged(bool state);
	void setState(t_eState state);
	bool isButtonPressed(t_eButton button) const;
	void setButtonPressed(t_eButton button);
	void resetButtons();

	t_eState getState() const;

	GameCore();

	int getHeight() const;

	void setHeight(int height);

	int getWidth() const;

	void setWidth(int width);

	~GameCore();

	void setButtonReleased(t_eButton button);

	void setWindowDescriptor(int windowDescriptor);

	t_eCell getCell(int i, int j);

	void showPossibilities(int i, int j);

	void doMove(int i, int j);
};


#endif //DOMINI_TEST_GAMECORE_H
