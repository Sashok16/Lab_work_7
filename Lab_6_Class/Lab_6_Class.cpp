/**
@mainpage Class
@version 0.0.1
Полиморфизм классов
*/
/**
* Main file with implementation
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#include "mainLib.h"
/**
* @brief  Входная функция с которой начинается программа.
* @details  В функции StartMenu() будут проходить все манипуляции со списками. И после окончания манипуляций проверка на утечку памяти c помощью функции CheckMemory().
*/

int main()
{
	srand(time(NULL));
	StartMenu();
	CheckMemory();
	return 0;
}

