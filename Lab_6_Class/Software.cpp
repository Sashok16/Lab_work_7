/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#include "BaseClass.h"
#include "inheritanceClass.h"
#include "mainLib.h"
/**
 @brief Structure for lists
*/
struct CList {
	uint size;///Contains the number of items in the Software list
	uint amount;///Contains the number of items in the Avast list
	CSoftware info;///Contains information about the items in the Software list
	Avast virus;///Contains information about the items in the Avast list
	list_ptr next;///Pointer to the next item in the list
	list_ptr prev;///Pointer to the previous item in the list
};

/**
 @param[in] m Head of some list
 @param[in] t Tail of some list
 */
void Init(list_ptr& m, list_ptr& t) {
	m = new CList;
	t = new CList;
	m->prev = NULL; // указатель на следующий узел
	t->prev = m; // указатель на предыдущий узел
	m->next = t; // указатель на следующий узел
	t->next = NULL;
}


/**
@param[in] hP Head of CSoftware list
@param[in] hV Head of Avast list
@param[in] fileName Input CSoftware file with information for objects
@param[in] fileNameVir Input Avast file with information for objects
*/
void CreateSpisok(list_ptr hP, list_ptr hV, const char * fileName, const char* fileNameVir) {
	auto prog = hP;
	auto virus = hV;
	string value;
	int valueInt;
	uint size = 0;
	uint amount = 0;
	bool value2;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string name;
	if (fileName == "input.txt") {
		ifstream fOpen = FileCheck(fileName);
		while (!fOpen.eof()) {
			list_ptr add = new CList;
			add->next = prog->next;
			prog->next->prev = add;
			add->prev = prog;
			prog->next = add;
			fOpen >> value;

			regex regex_integer("[0-9]{1,4}|[0-4][0-9]{1,4}$");
			if (!regex_match(value, regex_integer)) {
				valueInt = 0;
			}
			else {
				valueInt = atoi(value.c_str());
			}
			add->info.SetNumberOfOpenings(valueInt);

			fOpen >> value;
			regex regex_integer1("[0-9]{1,3}|[1-2][0-9]{1,3}$");
			if (!regex_match(value, regex_integer1)) {
				valueInt = 0;
			}
			else {
				valueInt = atoi(value.c_str());
			}
			add->info.SetNumberOfUsers(valueInt);


			string day, mon, year;
			int d, m, y;

			fOpen >> day;
			regex regex_integer22("[1-9]|[1-2][0-9]|3[0-1]$");
			if (!regex_match(day, regex_integer22)) {
				d = 1;
			}
			else {
				d = atoi(day.c_str());
			}

			fOpen >> mon;
			regex regex_integer21("[1-9]|1[0-2]$");
			if (!regex_match(mon, regex_integer21)) {
				m = 1;
			}
			else {
				m = atoi(mon.c_str());
			}

			fOpen >> year;
			regex regex_integer2("19[8-9][0-9]|20[0-1][0-9]|2020$");
			if (!regex_match(year, regex_integer2)) {
				y = 1980;
			}
			else {
				y = atoi(year.c_str());
			}

			add->info.SetDate(d, m, y);

			fOpen >> value;
			regex regex_integer3("[0-9]{1,6}|[0-4][0-9]{1,6}$");
			if (!regex_match(value, regex_integer3)) {
				valueInt = 0;
			}
			else {
				valueInt = atoi(value.c_str());
			}
			add->info.SetMemory(valueInt);

			fOpen >> name;
			regex regex_line("[A-Z][A-Za-z0-9]{2,11}$");
			if (!regex_match(name, regex_line)) {
				name = "NoName";
			}
			add->info.SetCorporation(name);
			size++;
			value2 = rand() % 2;
			add->info.SetThrojan(value2);
			add->info.SetId(size);
			prog = prog->next;
		}
		hP->size = size;
		fOpen.close();
	}
	else exit(1);
	if (fileNameVir == "inputVir.txt") {
		ifstream fOpen = FileCheck(fileNameVir);
		while (!fOpen.eof()) {
			list_ptr addVir = new CList;
			addVir->next = virus->next;
			virus->next->prev = addVir;
			addVir->prev = virus;
			virus->next = addVir;
			//////////////////////////////////////////////////////

			string day, mon, year;
			int d, m, y;

			fOpen >> day;
			regex regex_integer22("[1-9]|[1-2][0-9]|3[0-1]$");
			if (!regex_match(day, regex_integer22)) {
				d = 1;
			}
			else {
				d = atoi(day.c_str());
			}

			fOpen >> mon;
			regex regex_integer21("[1-9]|1[0-2]$");
			if (!regex_match(mon, regex_integer21)) {
				m = 1;
			}
			else {
				m = atoi(mon.c_str());
			}

			fOpen >> year;
			regex regex_integer2("19[8-9][0-9]|20[0-1][0-9]|2020$");
			if (!regex_match(year, regex_integer2)) {
				y = 1980;
			}
			else {
				y = atoi(year.c_str());
			}

			addVir->virus.SetDate(d, m, y);

			/////////////////////////////////////////////////////
			fOpen >> value;
			regex regex_integer("[1-9][0-9]{1,10}$");
			if (!regex_match(value, regex_integer)) {
				valueInt = 0;
			}
			else {
				valueInt = atoi(value.c_str());
			}
			addVir->virus.SetDamage(valueInt);

			fOpen >> value;
			regex regex_integer1121("[A-Z][A-Za-z]{3,15}$");
			if (!regex_match(value, regex_integer1121)) {
				value = "World";
			}
			addVir->virus.SetCorporation(value);

			fOpen >> value;
			regex regex_integer3("[0-1]$");
			if (!regex_match(value, regex_integer3)) {
				valueInt = 1;
			}
			else {
				valueInt = atoi(value.c_str());
			}
			addVir->virus.SetCopying(valueInt);

			fOpen >> name;
			regex regex_line("[A-Z][A-Za-z0-9]{2,9}$");
			if (!regex_match(name, regex_line)) {
				name = "NoName";
			}
			addVir->virus.SetName(name);

			fOpen >> name;
			regex regex_line44("[A-Z][A-Za-z0-9?-]{2,20}\\.(exe|dll|TXT)$");
			if (!regex_match(name, regex_line44)) {
				name = "System.dll";
			}
			addVir->virus.SetNameOfFile(name);
			amount++;
			
			virus = virus->next;
		}
		hV->amount = amount;
		fOpen.close();
	}
	else exit(1);
}


/**
The function is responsible for the list action menu. 
The first question is which list we want to work with. 
When the user selects, the menu will go to another menu where all possible operations with the selected list will be presented. 
Also in each such menu there is an item where in case of switching to another list it is possible to return to the main menu without changes, 
to return to the original lists, or to exit at all.

Elections are verified through regular expressions.
*/
void StartMenu() {
	int choiceMain = 0, choiceNext = 1, choiseList, restart = 1;
	string choiseListStr, choiceMainStr;
	HANDLE hCon;
	COORD cPos;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	while (restart == 1) {
		list_ptr progHead;
		list_ptr progTail;
		list_ptr virHead;
		list_ptr virTail;
		Init(progHead, progTail);
		Init(virHead, virTail);
		progHead->size = 0;
		virHead->amount = 0;
		CreateSpisok(progHead, virHead, "input.txt", "inputVir.txt");
		cout << endl;
		cout << "  Choose the list you want to manage:"
			<< "\n\tlist \"Software\" -> 1"
			<< "\n\tlist \"Virus\" ----> 2";

		bool check = true;
		while (check)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
			cout << "\n  Enter choice -> ";
			cin >> choiseListStr;
			//Если есть ошибка, выводим сообщение
			regex regex_integer("[1-2]");
			if (!regex_match(choiseListStr, regex_integer)) {
				SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
				cout << "Please enter numbers! Repeat!\n";
				//Восстановили поток
				cin.clear();
				//Почистили поток
				cin.ignore(cin.rdbuf()->in_avail());
			}
			else {
				choiseList = atoi(choiseListStr.c_str());
				check = false;
			}
		}
		switch (choiseList)
		{
			case 1:
			{
				progHead->info.ShowAll(progHead);
				choiceNext = 1;
				while (choiceNext == 1) {
					SetConsoleTextAttribute(hConsole, (WORD)(LIGHTCYAN));
					cout << "\n  show all programs ------------> 1\n"
						<< "  add one program --------------> 2\n"
						<< "  add one program in line ------> 3\n"
						<< "  remove one program -----------> 4\n"
						<< "  find the program from memory -> 5\n"
						<< "  find program with trojan -----> 6\n"
						<< "  sorting list -----------------> 7\n"
						<< "  restart ----------------------> 8\n"
						<< "  go to main menu --------------> 9\n"
						<< "  exit -------------------------> 10\n\n";
					bool check = true;
					while (check)
					{
						SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
						cout << "  Enter choice -> ";
						cin >> choiceMainStr;
						//Если есть ошибка, выводим сообщение
						regex regex_integer("[1-9]|10");
						if (!regex_match(choiceMainStr, regex_integer))
						{
							SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
							cout << "Please enter numbers! Repeat!\n";
							//Восстановили поток
							cin.clear();
							//Почистили поток
							cin.ignore(cin.rdbuf()->in_avail());
						}
						else {
							choiceMain = atoi(choiceMainStr.c_str());
							check = false;
						}
					}
					switch (choiceMain)
					{
					case 1:
					{
						system("cls");
						progHead->info.ShowAll(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 2:
					{
						system("cls");
						progHead->info.AddOne(progHead);
						cout << "Your program is first:\n";
						progHead->info.ShowAll(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 3:
					{
						system("cls");
						progHead->info.addProgramLine(progHead);
						cout << "Your program is first:\n";
						progHead->info.ShowAll(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 4:
					{
						system("cls");
						progHead->info.ShowAll(progHead);
						progHead->info.RemoveOne(progHead);
						progHead->info.ShowAll(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 5:
					{
						system("cls");
						cout << "\nBefor: \n";
						progHead->info.ShowAll(progHead);
						progHead->info.FindFrom(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 6:
					{
						system("cls");
						progHead->info.deleteProgramWithTrojan(progHead);
						SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
						cout << "After deleting throjan:\n";
						progHead->info.ShowAll(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 7:
					{
						system("cls");
						SortSpisok(progHead, progTail);
						system("cls");
						cout << "\nAfter sorting list:\n";
						progHead->info.ShowAll(progHead);
						progHead->info.WriteToFile(progHead);
						break;
					}
					case 8:
					{
						choiceNext = 0;
						for (int i = 0; i < 32; i++) {
							system("cls");
							int width = 0, height = 0;
							SizeOfConsole(width, height);
							hCon = GetStdHandle(STD_OUTPUT_HANDLE);
							cPos.Y = height / 2;
							cPos.X = (width - strlen("Reboot")) / 2;
							SetConsoleCursorPosition(hCon, cPos);
							cout << "Reboot";
							cPos.Y = (height / 2) + 1;
							cPos.X = (width - strlen("================================")) / 2;
							SetConsoleCursorPosition(hCon, cPos);
							for (int j = 0; j < i; j++) {
								cout << "=";
							}
							cout << "=";
							Sleep(150);
						}
						system("cls");
						break;
					}
					case 9:
					{
						choiceNext = 0;
						system("cls");
						break;
					}
					case 10:
					{
						restart = 0;
						choiceNext = 0;
						system("cls");
						int width = 0, height = 0;
						SizeOfConsole(width, height);
						cout << "width: " << width << "\nheight: " << height << endl;
						hCon = GetStdHandle(STD_OUTPUT_HANDLE);
						cPos.Y = height / 2;
						cPos.X = (width - strlen("GOOD BYE :-)")) / 2;
						SetConsoleCursorPosition(hCon, cPos);
						cout << "GOOD BYE :-)";
						system("cls");
						break;
					}
					default:
					{
						system("cls");
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
						cout << "\nEnter carefully, please";
						SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
						cout << "\nDo you want to continue? (1 - yes , 0 - no)\n";
						cin >> choiceNext;
						break;
					}
					}
				}
			}
			case 2:
			{
				system("cls");
				virHead->virus.ShowAll(virHead);
				choiceNext = 1;
				while (choiceNext == 1) {
					SetConsoleTextAttribute(hConsole, (WORD)(LIGHTCYAN));
					cout << "\n  show all virus -----------------> 1\n"
						<< "  removed one virus --------------> 2\n"
						<< "  add one virus ------------------> 3\n"
						<< "  find the virus from damage -----> 4\n"
						<< "  go to main menu ----------------> 5\n"
						<< "  restart ------------------------> 6\n"
						<< "  exit ---------------------------> 7\n\n";
					bool check = true;
					while (check)
					{
						SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
						cout << "  Enter choice -> ";
						cin >> choiceMainStr;
						//Если есть ошибка, выводим сообщение
						regex regex_integer("[1-9]|10");
						if (!regex_match(choiceMainStr, regex_integer))
						{
							SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
							cout << "Please enter numbers! Repeat!\n";
							//Восстановили поток
							cin.clear();
							//Почистили поток
							cin.ignore(cin.rdbuf()->in_avail());
						}
						else {
							choiceMain = atoi(choiceMainStr.c_str());
							check = false;
						}
					}
					switch (choiceMain)
					{
					case 1:
					{
						system("cls");
						virHead->virus.ShowAll(virHead);
						virHead->virus.WriteToFile(virHead);
						break;
					}
					case 2:
					{
						system("cls");
						virHead->virus.ShowAll(virHead);
						virHead->virus.RemoveOne(virHead);
						virHead->virus.ShowAll(virHead);
						virHead->virus.WriteToFile(virHead);
						break;
					}
					case 3:
					{
						system("cls");
						virHead->virus.AddOne(virHead);
						cout << "Your virus is first:\n";
						virHead->virus.ShowAll(virHead);
						virHead->virus.WriteToFile(virHead);
					}
					case 4:
					{
						system("cls");
						virHead->virus.ShowAll(virHead);
						virHead->virus.FindFrom(virHead);
						virHead->virus.WriteToFile(virHead);
						break;
					}
					case 5:
					{
						choiceNext = 0;
						system("cls");
						break;
					}
					case 6:
					{
						choiceNext = 0;
						for (int i = 0; i < 32; i++) {
							system("cls");
							int width = 0, height = 0;
							SizeOfConsole(width, height);
							hCon = GetStdHandle(STD_OUTPUT_HANDLE);
							cPos.Y = height / 2;
							cPos.X = (width - strlen("Reboot")) / 2;
							SetConsoleCursorPosition(hCon, cPos);
							cout << "Reboot";
							cPos.Y = (height / 2) + 1;
							cPos.X = (width - strlen("================================")) / 2;
							SetConsoleCursorPosition(hCon, cPos);
							for (int j = 0; j < i; j++) {
								cout << "=";
							}
							cout << "=";
							Sleep(150);
						}
						system("cls");
						break;
					}
					case 7:
					{
						restart = 0;
						choiceNext = 0;
						system("cls");
						int width = 0, height = 0;
						SizeOfConsole(width, height);
						cout << "width: " << width << "\nheight: " << height << endl;
						hCon = GetStdHandle(STD_OUTPUT_HANDLE);
						cPos.Y = height / 2;
						cPos.X = (width - strlen("GOOD BYE :-)")) / 2;
						SetConsoleCursorPosition(hCon, cPos);
						cout << "GOOD BYE :-)";
						system("cls");
						break;
					}
					default:
					{
						system("cls");
						HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
						cout << "\nEnter carefully, please";
						SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
						cout << "\nDo you want to continue? (1 - yes , 0 - no)\n";
						cin >> choiceNext;
						break;
					}
					}
				}
			}
			case 3:
			{

			}

		}
		DelSpisok(virHead);
		DelSpisok(progHead);
	}
}

/**
The head unit transferred deletes all items in that head's list.

 @param[in] el Head of list which deleted
*/
void DelSpisok(list_ptr el) {
	list_ptr p = el;
	while (el) {
		p = el;
		el = el->next;
		delete p;
	}
	delete el;
}

/**
The function displays a message indicating a memory leak in the program.
*/
void CheckMemory() {
	int memory = _CrtDumpMemoryLeaks();
	if (memory == 0)
	{
		cout << "\nThere is NO memory leak :-)\nHeve a good day!\n";
	}
	else {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
		cout << "\n\nThere is memory leak. Check your program!\n";
	}
}

/**
@param[in] name Input file
@param[out] fOpen Checked input file variable
@return Input file variable
*/
ifstream FileCheck(const char* name)
{
	ifstream fOpen;
	fOpen.open(name, ios_base::in);
	if (!fOpen)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
		cout << "File is not open\n\n";
		exit(1);
	}
	return fOpen;
}
/**
@param[in] name Output file.
@param[out] fOpen Checked output file variable.
@return Output file variable
*/
ofstream FileOutput(const char* name) {
	ofstream fOut;
	fOut.open(name, ios_base::out | ios_base::trunc);
	if (!fOut)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
		cout << "File is not open\n\n";
		exit(1);
	}
	return fOut;
}

/**
Sorts the list by the selected direction and field.
 @param[in] h Head of list.
 @param[in] t Tail of list.
*/
void SortSpisok(list_ptr h, list_ptr t) {
	list_ptr prH = h;
	list_ptr prT = t;
	string field;
	string method;
	int i = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Enter the field you want to sort and the execution method" << endl;
	cout << "Fields:\n\tnumber of openings -> 1\n\t" <<
		"number of users ----> 2\n\t" <<
		"date of creation ---> 3\n\t" <<
		"memory -------------> 4\n\t" <<
		"corporation --------> 5\n" <<
		"Methods:\n\tfrom highest to lowest > 1\n" <<
		"\tfrom lowest to highest > 2";
	bool check = true;
	while (check) {
		cout << "\n\nEnter the field --> ";
		cin >> field;
		cout << "\n\nEnter the method -> ";
		cin >> method;
		regex regex_integer1("[1-5]");
		regex regex_integer2("[1-2]");
		if (!regex_match(field, regex_integer1) && !regex_match(method, regex_integer2)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers correctly! Repeat!\nNot a suitable value, please repeat (from 0 to 50.000 openings)\n\nEnter number of openings: ";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else check = false;
	}
	list_ptr iH = prH;
	list_ptr iT = prT;
	SortElem(iH, iT, field, method);
}
/**

@param[in] field Selected field to sort
@param[in] aH The first items in the list that are compared
@param[in] bH The second items in the list that are compared
@return True if the first element is smaller than the second, otherwise false
*/
bool Condition(string field, CSoftware aH, CSoftware bH)
{
	return (field == "1" && aH.GetNumberOfOpenings() < bH.GetNumberOfOpenings())
		|| (field == "2" && aH.GetNumberOfUsers() < bH.GetNumberOfUsers())
		|| (field == "3" && (aH.GetYear() < bH.GetYear()
			|| aH.GetYear() == bH.GetYear() && aH.GetMon() < bH.GetMon()
			|| aH.GetMon() == bH.GetMon() && aH.GetYear() == bH.GetYear() && aH.GetDay() == bH.GetDay()))
		|| (field == "4" && aH.GetMemory() < bH.GetMemory())
		|| (field == "5" && aH.GetCorporation()[0] < bH.GetCorporation()[0]);
}
/**
Sorts the list by the already selected options.
@param[in] i Head of list
@param[in] i2 Tail of list 
@param[in] field Selected field to sort
@param[in] method Selected sort direction
*/
void SortElem(list_ptr i, list_ptr i2, string field, string method) {
	list_ptr p1;
	list_ptr p2;
	list_ptr pr = i;
	int po;
	if (method == "1") {
		if (pr != NULL) {
			do {
				po = 0;
				pr = i;
				while (pr->next->next->next != NULL) {
					p1 = pr->next;
					p2 = p1->next;
					if (Condition(field, p1->info, p2->info)) {
						p2->prev = p1->prev;
						p1->prev->next = p2;
						p1->next = p2->next;
						p2->next->prev = p1;
						p1->prev = p2;
						p2->next = p1;
						po = 1;
					}
					pr = pr->next;
				}

			} while (po == 1);
		}
	}
	else {
		if (pr != NULL) {
			do {
				po = 0;
				pr = i2;
				while (pr->prev->prev->prev != NULL) {
					p1 = pr->prev;
					p2 = p1->prev;
					if (Condition(field, p1->info, p2->info)) {
						p2->next = p1->next;
						p1->next->prev = p2;
						p1->prev = p2->prev;
						p2->prev->next = p1;
						p1->next = p2;
						p2->prev = p1;
						po = 1;
					}
					pr = pr->prev;
				}
			} while (po == 1);
		}
	}
}

/**
Built-in classes determine the size of the console and write to the received parameters.
Used to determine the size of the console to display information in the center of the console.
@param[in] WIDTHCONSL Width of console.
@param[in] HIGHTCONSL Hight of console.
*/
void SizeOfConsole(int& WIDTHCONSL, int& HIGHTCONSL)
{
	HANDLE hWndConsole;
	if (hWndConsole = GetStdHandle(-12))
	{
		CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
		if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
		{
			WIDTHCONSL = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
			HIGHTCONSL = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
		}
		else
			cout << "Error: " << GetLastError() << endl;
	}
	else
		cout << "Error: " << GetLastError() << endl;
}
