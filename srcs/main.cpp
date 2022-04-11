#include "main.h"

void signal_handler(int signal) {
	if (signal == SIGQUIT || signal == SIGTERM || signal == SIGINT) {
        exit(0);
    }
}

int main()
{
	std::signal(SIGINT, signal_handler);
	auto *gameField = new GameField();
	delete gameField;
	return 0; 
}
