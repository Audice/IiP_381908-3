// Лабораторная работа 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Game.h"
#include <time.h>

using namespace std;

int main() {
	srand(time(NULL));
	Game g;
	g.dispatcher();
}