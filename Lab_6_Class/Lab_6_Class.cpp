/**
@mainpage Class
@version 0.0.1
����������� �������
*/
/**
* Main file with implementation
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#include "mainLib.h"
/**
* @brief  ������� ������� � ������� ���������� ���������.
* @details  � ������� StartMenu() ����� ��������� ��� ����������� �� ��������. � ����� ��������� ����������� �������� �� ������ ������ c ������� ������� CheckMemory().
*/

int main()
{
	srand(time(NULL));
	StartMenu();
	CheckMemory();
	return 0;
}

