#include "main.h"

int main(int argc, char **argv)
{
	static MainWindow mainWindow(&argc, argv);
	mainWindow.start();

	return 0;
}