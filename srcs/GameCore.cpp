#include "main.h"

GameCore::GameCore() {
	_state = STATE_MENU;
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
	return _buttonPressedMask & (1 << button);
}

void GameCore::resetButtons() {
	_stateChanged = true;
	_buttonPressedMask = 0;
}

void GameCore::setButtonPressed(t_eButton button) {
	_stateChanged = true;
	_buttonPressedMask |= (1 << (int)button);
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
	_stateChanged = true;
	_height = height;
}

int GameCore::getWidth() const
{
	return _width;
}

void GameCore::setWidth(int width)
{
	_stateChanged = true;
	_width = width;
}

void GameCore::setButtonReleased(t_eButton button) {
	switch (button) {
		case START:
			setState(STATE_GAME);
			break;
		case CREDITS:
			setState(STATE_CREDITS);
			break;
		case EXIT:
			glutDestroyWindow(_windowDescriptor);
			break;
		default:
			break;
	}
}

void GameCore::setWindowDescriptor(int windowDescriptor) {
	_windowDescriptor = windowDescriptor;

}

t_eCell GameCore::getCell(int i, int j) {
	return _gameField.getCell(i,j);
}

void GameCore::showPossibilities(int i, int j) {
	_gameField.showPossibilities(i,j);
	setState(STATE_GAME_MOVE_POSSIBILITIES);
}

void GameCore::doMove(int i, int j) {
	_gameField.doMove(i,j);
	if (_gameField.isWin(PLAYER_HUMAN))
	{
		setState(STATE_END_GAME);
		setWinner(PLAYER_HUMAN);
		return;
	}
	doAIMove();
	gameCore->setStateChanged(true);
	if (_gameField.isWin(PLAYER_AI))
	{
		setState(STATE_END_GAME);
		setWinner(PLAYER_AI);
		return;
	}
	setState(STATE_GAME);
}

t_ePlayer GameCore::getWinner() const
{
	return _winner;
}

void GameCore::doAIMove()
{
	_aIPlayer.doMove(&_gameField);

}

void GameCore::setWinner(e_Player player)
{
	_winner = player;
}

void GameCore::restartGame()
{
	_gameField.restartGame();
	resetButtons();
}
