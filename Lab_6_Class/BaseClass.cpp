/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#include "BaseClass.h"
#include "inheritanceClass.h"
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
This method finds the programs you need (asks the maximum amount of memory occupied by the program) and marks them green.
The test is performed using regular expressions.

@param[in] h Head of list
@return Nothing
@warning '<': signed/unsigned mismatch	
@warning 'memory': unreferenced local variable

*/
void CSoftware::FindFrom(list_ptr h) {
	list_ptr pr = h->next;///Сreate variable to do not lose the head of the list Software
	int memory, check = true;
	string memoryStr;///
	int memoryInt;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (check)///In the loop, enter the required information and repeat until the correct expression is entered.
	{
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter the maximem memory you want to see in the printed programs below: ";
		cin >> memoryStr;
		regex regex_integer("[0-9]{1,6}|[0-4][0-9]{1,6}$");///Check the correctness of memory input by regular expressions
		if (!regex_match(memoryStr, regex_integer)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 0 to 5.000.000 kbytes)\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
			memoryInt = atoi(memoryStr.c_str());///Convert memory input to intager
		}
	}
	cout << "\nAfter: \n\n";
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	cout << setw(23) << "openings" << setw(10) << "users" << setw(18)
		<< "date of creation" << setw(16) << "memory(Kb)"
		<< setw(16) << "corporation" << endl;
	for (uint i = 1; pr->next; i++) {///In the loop, we display information in different colors: green and red. Green - those that are suitable for us, red - those that are not suitable.
		if (pr->info.memory < memoryInt) {
			cout << pr->info.ShowElem(pr, LIGHTGREEN);
		}
		else {
			cout << pr->info.ShowElem(pr, LIGHTRED);
		}
		pr = pr->next;
	}
}


/**
The method creates a complex string in which it writes information about the received list element and returns it as a string.

@param[in] el Element of list.
@param[in] color Color of text.
@return Object information string.
*/
string CSoftware::ShowElem(list_ptr el, int color) {
	CList* pr = el;///Сreate variable to do not lose the element of the list Software
	stringstream ss1, ss2;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	ss1 << "    program -> ";
	SetConsoleTextAttribute(hConsole, (WORD)(color));
	ss2 << setw(7) << pr->info.GetNumberOfOpenings()
		<< setw(10) << pr->info.GetNumberOfUsers() << setw(17)
		<< pr->info.GetDate() << setw(17)
		<< pr->info.GetMemory() << setw(17) << pr->info.GetCorporation() << endl;
	return ss1.str() + ss2.str();
}

/**
This method displays a list where the programs that have unsafe SOFTWARE are marked red and removed from the list.

@param[in] h Head of list
@return Nothing
*/
void CSoftware::deleteProgramWithTrojan(list_ptr h) {
	list_ptr pr = h->next;///Сreate variable to do not lose the head of the list Software.
	uint size = pr->size;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	cout << setw(23) << "openings" << setw(10) << "users" << setw(18)
		<< "date of creation" << setw(16)
		<< "memory(Kb)" << setw(16) << "corporation" << endl;
	for (uint i = 1; pr->next; i++) {///In the loop,checking for trojan and displayed in the corresponding color.
		if (!pr->info.GetThrojan()) {
			cout << pr->info.ShowElem(pr, BROWN);
		}
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			cout << pr->info.ShowElem(pr, LIGHTRED);
		}
		pr = pr->next;
	}
	cout << endl;
	list_ptr prDel = h->next;///Сreate new variable to do not lose the head of the list Software.
	for (uint i = 0; prDel->next; i++)///In the loop, the is checked for the presence of a Trojan and removed from the list in case of truth.
	{
		if (prDel->info.throjans.GetThrojan()) {
			list_ptr prev;
			list_ptr next;
			prev = prDel->prev; // узел, предшествующий prDel
			next = prDel->next; // узел, следующий за prDel
			if (prev != nullptr)
				prev->next = prDel->next; // переставляем указатель
			if (next != nullptr)
				next->prev = prDel->prev; // переставляем указатель
			delete prDel; // освобождаем память удаляемого элемента
			prDel = prev;
			size--;
		}
		prDel = prDel->next;
	}
	h->size = size;
}
/**
A method that displays list information using loops and functions ShowElem().
Displays the information returned by ShowEem() and moves the pointer to the next item in the list until the tail of the list is present.

@param[in] h Head of list
@return Nothing
*/
void CSoftware::ShowAll(list_ptr h)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	list_ptr pr = h->next;///Сreate variable to do not lose the head of the list Software.
	uint i = 1;
	cout << setw(23) << "openings" << setw(10)
		<< "users" << setw(20) << "date of creation"
		<< setw(16) << "memory(Kb)" << setw(16) << "corporation" << endl;
	while (pr->next) {
		cout << pr->info.ShowElem(pr, BROWN);
		pr = pr->next;
	}
	cout << endl;
}

/**
The method asks which number you want to delete by checking the number entered by regular expression.

@param[in] h Head of list
@return Nothing
*/
void CSoftware::RemoveOne(list_ptr h) {
	list_ptr head = h;///Сreate variable to do not lose the head of the list Software.
	string indexStr;
	uint size = head->size;
	int indexInt;
	bool check = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (check)///In the loop, enter the required information and repeat until the correct expression is entered.
	{
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "\nEnter namber of program which you want to remove: ";
		cin >> indexStr;
		//Если есть ошибка, выводим сообщение
		regex regex_integer("[0-9]{1,2}$");
		if (!regex_match(indexStr, regex_integer)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
		}
		else check = false;
	}
	SetConsoleTextAttribute(hConsole, (WORD)(RED));
	cout << "Removed program: \n";
	indexInt = atoi(indexStr.c_str());
	/**
	Checks the number that you entered. If this program is available, the program itself is displayed, 
	otherwise an error is displayed that indicates that there is no such program.
	@warning '<': signed/unsigned mismatch
	@warning '<=': signed/unsigned mismatch
	*/
	if (head != NULL && indexInt <= size + 1 && indexInt >= 0) {
		list_ptr temp = head;
		list_ptr p1 = head;
		for (uint i = 0; i < indexInt; i++) {
			p1 = temp;
			temp = temp->next;
		}
		if (temp == head) {
			head = temp->next;
		}
		else {
			p1->next = temp->next;
		}

		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
		cout << setw(23) << "openings" << setw(10) << "users"
			<< setw(18) << "date of creation" << setw(16) << "memory(Kb)"
			<< setw(16) << "corporation" << endl;
		cout << temp->info.ShowElem(temp, LIGHTRED);
		delete temp;////////
		size--;
	}
	else {
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
		cout << "We dont have this programe" << endl << endl;
	}
	/**
	@warning Dereferencing NULL pointer. 'h' contains the same NULL value as 'head' did. See line 169 for an earlier location where this can occur.	
	*/
	h->size = size;
}

/**
A new object is created that we fill in with the help of the setters and check each entered information with the help of regular expressions.
At the end, it is tied after the head element of this list.

@param[in] h Head of list
@return Nothing
*/
void CSoftware::AddOne(list_ptr h) {
	list_ptr add = new CList;
	list_ptr head = h;
	uint size = head->size;
	int value1Int, value2Int, value3Int, value4Int, value5;
	string value1Str, value2Str, value3Str, value4Str;
	string name;
	bool check = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	///You enter the number of program openings
	while (check)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter number of openigs : ";
		cin >> value1Str;
		//Если есть ошибка, выводим сообщение 
		regex regex_integer("[0-9]{1,4}|[0-4][0-9]{1,4}$");
		if (!regex_match(value1Str, regex_integer)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 0 to 50.000 openings)\n";
			//Восстановили поток			
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
		value1Int = atoi(value1Str.c_str());
	}

	///You enter the number of users 
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter number of users : ";
		cin >> value2Str;
		regex regex_integer1("[0-9]{1,3}|[1-2][0-9]{1,3}$");
		if (!regex_match(value2Str, regex_integer1)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 0 to 2.000 users)\n";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
		value2Int = atoi(value2Str.c_str());
	}

	///You enter the date of program creation
	string day, mon, year;
	int d, m, y;
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter year of creation : ";
		cin >> year;
		regex regex_integer2("19[8-9][0-9]|20[0-1][0-9]|2020$");
		if (!regex_match(year, regex_integer2)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 1980 to 2020 years)\n";
			//Восстановили поток
			/*
			cin.clear() очищает флаг ошибки cin (так что будущие операции ввода-вывода будут работать правильно)
			*/
			cin.clear();
			//Почистили поток
			//Извлекает из потока символы и отбрасывает их.
			//У потока ввода есть буфер чтения, в котором он хранит символы.
			//Мы обращаемся к нему, вызывая функцию rdbuf().
			//А любой уважающий себя буфер знает, сколько символов в нем содержится.
			//Поскольку и мы хотим это узнать, мы вызываем функцию in_avail() этого буфера.
			//Это количество символов нам и нужно проигнорировать, что достигается так :
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
		y = atoi(year.c_str());
	}
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter month of creation : ";
		cin >> mon;
		regex regex_integer3("[1-9]|1[0-2]$");
		if (!regex_match(mon, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 1 to 12 month)\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
		m = atoi(mon.c_str());
	}
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter day of creation : ";
		cin >> day;
		regex regex_integer3("[1-9]|[1-2][0-9]|3[0-1]$");
		if (!regex_match(day, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 1 to 31 date)\n";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
		d = atoi(day.c_str());
	}

	///You enter the amount of memory
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter amount of memory : ";
		cin >> value4Str;
		regex regex_integer3("[0-9]{1,6}|[0-4][0-9]{1,6}$");
		if (!regex_match(value4Str, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 0 to 5.000.000 kbytes)\n";

			cin.clear();

			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}

		value4Int = atoi(value4Str.c_str());
	}

	///You enter the name of corporation
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter name of corporation: ";
		cin >> name;
		regex regex_line("[A-Z][A-Za-z0-9]{2,11}$");
		if (!regex_match(name, regex_line)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter corractly! Repeat!\n";

			cin.clear();

			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
	}
	///Your values will be written to your object's fields with the help of the setters.
	value5 = rand() % 2;
	add->next = NULL;
	add->info.SetNumberOfOpenings(value1Int);
	add->info.SetNumberOfUsers(value2Int);
	add->info.SetDate(d, m, y);
	add->info.SetMemory(value4Int);
	add->info.SetThrojan(value5);
	add->info.SetCorporation(name);
	add->next = head->next;
	head->next->prev = add;
	head->next = add;
	add->prev = head;
	size++;
	h->size = size;
}

/**
The method creates a new object that is filled in the enterValue() method and tied after the head element.

@param[in] h Head of list
@return Nothing
*/
void CSoftware::addProgramLine(list_ptr h) {
	list_ptr add = new CList;
	list_ptr head = h;
	uint size = head->size;
	head->info.enterValue(add);
	add->next = NULL;
	add->next = head->next;
	head->next = add;
	add->prev = head;
	size++;
	h->size = size;
}

/**
As in the AddOne() method, each field is filled with the help of the setters and checked by a regular expression.

@param[in] add Head of list
@return Nothing
*/
void CSoftware::enterValue(list_ptr add) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string corporation, numberOfOpenings, day, mon, year, numberOfUsers, memory;
	bool throjan, check = true;
	cout << "\nEnter these options through the space, in this order: \n";
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTCYAN));
	cout << "openings | users | day, month, year of creation | memory(Kb) | corporation" << endl;
	cout << "Like this: 123 213 1 1 1980 123 qwerty\nEnter values:\n";
	SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
	cin >> numberOfOpenings >> numberOfUsers >> day >> mon >> year >> memory >> corporation;
	int numberOfOpeningsNum, d, m, y,
		numberOfUsersNum, memoryNum;
	while (check)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		//Если есть ошибка, выводим сообщение 
		regex regex_integer("[0-9]{1,4}|[0-4][0-9]{1,4}$");
		if (!regex_match(numberOfOpenings, regex_integer)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers correctly! Repeat!\nNot a suitable value, please repeat (from 0 to 50.000 openings)\n\nEnter number of openings: ";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> numberOfOpenings;
			continue;
		}
		else {
			check = false;
			numberOfOpeningsNum = atoi(numberOfOpenings.c_str());
		}
	}

	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		regex regex_integer1("[0-9]{1,3}|[1-2][0-9]{1,3}$");
		if (!regex_match(numberOfUsers, regex_integer1)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers correctly! Repeat!\nNot a suitable value, please repeat (from 0 to 2.000 users)\n\nEnter number of users: ";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> numberOfUsers;
			continue;
		}
		else {
			check = false;
			numberOfUsersNum = atoi(numberOfUsers.c_str());
		}
	}

	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));


		regex regex_integer2("19[8-9][0-9]|20[0-1][0-9]|2020$");
		if (!regex_match(year, regex_integer2)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 1980 to 2020 years)\n";
			cout << "Enter year of creation : ";
			//Восстановили поток
			/*
			cin.clear() очищает флаг ошибки cin (так что будущие операции ввода-вывода будут работать правильно)
			*/
			cin.clear();
			//Почистили поток
			//Извлекает из потока символы и отбрасывает их.
			//У потока ввода есть буфер чтения, в котором он хранит символы.
			//Мы обращаемся к нему, вызывая функцию rdbuf().
			//А любой уважающий себя буфер знает, сколько символов в нем содержится.
			//Поскольку и мы хотим это узнать, мы вызываем функцию in_avail() этого буфера.
			//Это количество символов нам и нужно проигнорировать, что достигается так :
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> year;
			continue;
		}
		else {
			check = false;
			y = atoi(year.c_str());
		}

	}
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));

		regex regex_integer3("[1-9]|1[0-2]$");
		if (!regex_match(mon, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 1 to 12 month)\n";
			cout << "Enter month of creation : ";

			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> mon;
			continue;
		}
		else {
			check = false;
			m = atoi(mon.c_str());
		}

	}
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));

		regex regex_integer3("[1-9]|[1-2][0-9]|3[0-1]$");
		if (!regex_match(day, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 1 to 31 date)\n";
			cout << "Enter day of creation : ";

			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> day;
			continue;
		}
		else {
			check = false;
			d = atoi(day.c_str());
		}

	}

	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		regex regex_integer3("[0-9]{1,6}|[0-4][0-9]{1,6}$");
		if (!regex_match(memory, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\nNot a suitable value, please repeat (from 0 to 5.000.000 kbytes)\n\nEnter amount of memory: ";

			cin.clear();

			cin.ignore(cin.rdbuf()->in_avail());
			cin >> memory;
			continue;
		}
		else {
			check = false;
			memoryNum = atoi(memory.c_str());
		}
	}
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		regex regex_line("[A-Z][A-Za-z0-9]{2,11}$");
		if (!regex_match(corporation, regex_line)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter neme of corporation corractly! Repeat!\nEnter name of corporation: ";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> corporation;
			continue;
		}
		else {
			check = false;
		}
	}
	throjan = rand() % 2;
	add->info.SetNumberOfOpenings(numberOfOpeningsNum);
	add->info.SetNumberOfUsers(numberOfUsersNum);
	add->info.SetDate(d, m, y);
	add->info.SetMemory(memoryNum);
	add->info.SetThrojan(throjan);
	add->info.SetCorporation(corporation);

}

/**
The method writes the information of its list to its output file.

@param[in] h Head of list
@return Nothing
*/
void CSoftware::WriteToFile(list_ptr h) {
	list_ptr head = h->next;
	ofstream fout = FileOutput("output.txt");
	fout << setw(23) << "openings" << setw(25) << "users"
		<< setw(18) << "date of creation"
		<< setw(16) << "memory(Kb)" << setw(16) << "corporation" << endl;
	while (head->next) {
		fout << "    program -> ";
		fout << setw(7) << head->info.GetNumberOfOpenings()
			<< setw(10) << head->info.GetNumberOfUsers() << setw(13)
			<< head->info.GetDate() << " y." << setw(17)
			<< head->info.GetMemory() << setw(17) << head->info.GetCorporation() << endl;
		head = head->next;
	}
	fout.close();
}

