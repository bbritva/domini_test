#include "GameCore.h"

GameCore::GameCore() {
	_state = MENU;
	_stateChanged = true;
	_height = WINDOW_HEIGHT;
	_width = WINDOW_WIDTH;
}

GameCore::~GameCore() {

}

t_eState GameCore::getState() const {
	return _state;
}

void GameCore::setState(t_eState state) {
	if (_state != state) {
		_stateChanged = true;
		_state = state;
	}
}

bool GameCore::isStateChanged() const {
	return _stateChanged;
}

bool GameCore::isButtonPressed(t_eButton button) const {
	std::cout << "button mask = " << (int)_buttonPressedMask << "\n";
	return _buttonPressedMask & (1 << button);
}

void GameCore::resetButtons() {
	_stateChanged = true;
	_buttonPressedMask = 0;
}

void GameCore::setButtonPressed(t_eButton button) {
	_stateChanged = true;
	_buttonPressedMask |= (1 << button);
}

void GameCore::setStateChanged(bool state) {
	_stateChanged = state;
}

int GameCore::getHeight() const
{
	return _height;
}

void GameCore::setHeight(int height)
{
	_height = height;
}

int GameCore::getWidth() const
{
	return _width;
}

void GameCore::setWidth(int width)
{
	_width = width;
}
