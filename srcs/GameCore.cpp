#include "GameCore.h"

GameCore::GameCore() {
	_state = MENU;
	_stateChanged = true;
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
