/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#pragma once

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15
#define DEBUG
#include <windows.h>
#include <fstream>
#include <conio.h> 
#include <iomanip>
#include <stddef.h>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <time.h>
#include <ctime>
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stringstream;
using std::string;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::ios_base;
using std::getline;
using std::istream;
using std::regex;
using std::regex_match;
using std::regex_search;
using std::to_string;
/**
 @brief Structure for lists
*/
struct CList;

typedef unsigned int uint;///new name for unsigned int
typedef CList* list_ptr;///new name for structure pointer -> CList*
/**
 @brief Class responsible for storing information about the date of a given object
 */
class CDate;
/**
 @brief Inheritance class stores information about the software and manipulations with this information
*/
class CSoftware;
/**
 @brief Inheritance class stores information about virus software and manipulations with this information
*/
class Avast;
/**
 @brief A prototype of a function that checks for memory leakage
*/
void CheckMemory();
/**
 @brief A prototype of a function that manipulates lists
*/
void StartMenu();
/**
 @brief A prototype of a function that initializes the head and end of a two-linked list
*/
void Init(list_ptr&, list_ptr&);
/**
 @brief A prototype of a function that creates lists from received text files
*/
void CreateSpisok(list_ptr, list_ptr, const char*, const char*);
/**
 @brief A prototype of a function that is responsible for removing lists
*/
void DelSpisok(list_ptr);

/**
 @brief A prototype of a function that is responsible for checking the presence of an input file
*/
ifstream FileCheck(const char*);
/**
 @brief A prototype of a function that is responsible for the presence of an output file
*/
ofstream FileOutput(const char*);

/**
 @brief Prototype of a function that is responsible for sorting only the "Software" list
*/
void SortSpisok(list_ptr, list_ptr);
/**
 @brief A prototype of a function that is responsible for the output result of comparing the selected fields

After the accepted parameters, the function will compare certain fields of the received elements that the user selected
*/
bool Condition(string, CSoftware, CSoftware);
/**
 @brief A prototype of a function that already sorts the list by the selected parameters
*/
void SortElem(list_ptr, list_ptr, string, string);

/**
 @brief A prototype of a function that calculates the length and width of the console at a given moment
*/
void SizeOfConsole(int&, int&);
