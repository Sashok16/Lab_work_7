/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
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
@param[in] h Element of list
@return Nothing
*/
void Avast::ShowAll(list_ptr h)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	list_ptr pr = h->next;
	uint i = 1;
	cout << setw(20) << "date"
		<< setw(14) << "damage" << setw(19)
		<< "corporation" << setw(17)
		<< "copying" << setw(14)
		<< "name" << setw(28)
		<< "name of file" << endl;
	while (pr->next) {
		cout << pr->virus.ShowElem(pr, BROWN);
		pr = pr->next;
	}
	cout << endl;
}
/**
\brief This methods show one program
\details MyName
\param[in] el Element of list
\param[in] color Color of text
\return your mother
*/
string Avast::ShowElem(list_ptr el, int color) {
	list_ptr pr = el;
	string copy;
	if (pr->virus.GetCopying() == 1) copy = "true";
	else copy = "false";
	stringstream ss1, ss2;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	ss1 << "    virus -> ";
	SetConsoleTextAttribute(hConsole, (WORD)(color));
	ss2 << setw(7) << pr->virus.GetDate()
		<< setw(10) << pr->virus.GetDamage() << " $" << setw(17)
		<< pr->virus.GetCorporation() << setw(17)
		<< copy << setw(17)
		<< pr->virus.GetName() << setw(28) 
		<< pr->virus.GetNameOfFile() << endl;
	return ss1.str() + ss2.str();
}
/**
The method writes the information of its list to its output file.

@param[in] h Head of list
*/
void Avast::WriteToFile(list_ptr h)
{
	list_ptr pr = h->next;
	ofstream fout = FileOutput("outputVir.txt");
	fout << setw(20) << "date"
		<< setw(14) << "damage" << setw(19)
		<< "corporation" << setw(17)
		<< "copying" << setw(14)
		<< "name" << setw(28)
		<< "name of file" << endl;
	while (pr->next) {
		fout << "    virus -> ";
		fout << setw(7) << pr->virus.GetDate()
			<< setw(10) << pr->virus.GetDamage() << " $" << setw(17)
			<< pr->virus.GetCorporation() << setw(17)
			<< pr->virus.GetCopying() << setw(17)
			<< pr->virus.GetName() << setw(28)
			<< pr->virus.GetNameOfFile() << endl;
		pr = pr->next;
	}
	fout.close();
}
/**
The method asks which number you want to delete by checking the number entered by regular expression.

@param[in] h Head of list
*/
void Avast::RemoveOne(list_ptr h) {
		list_ptr head = h;
		list_ptr hd = h;
		string indexStr;
		uint amount = head->amount;
		int indexInt;
		bool check = true;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		while (check)
		{
			SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
			cout << "\nEnter namber of virus which you want to remove: ";
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

		if (head != NULL && indexInt < amount + 1 && indexInt >= 0) {
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
			cout << setw(20) << "date"
				<< setw(14) << "damage" << setw(19)
				<< "corporation" << setw(17)
				<< "copying" << setw(14)
				<< "name" << setw(28)
				<< "name of file" << endl;
			cout << temp->virus.ShowElem(temp, LIGHTRED);
			delete temp;////////
			amount--;
		}
		else {
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
			cout << "We dont have this virus" << endl << endl;
		}
		head->amount = amount;
}
/**
A new object is created that we fill in with the help of the setters and check each entered information with the help of regular expressions.
At the end, it is tied after the head element of this list.

@param[in] h Head of list
*/
void Avast::AddOne(list_ptr h)
{
	list_ptr add = new CList;
	list_ptr head = h;
	uint size = head->amount;
	int value1Int = 0, value2Int, value3Int, value4Int;
	string value1Str, value2Str, value3Str, value4Str;
	string name;
	bool check = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	///////////////////////////////////////////////////////////////
	
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

   ////////////////////////////////////////////////////////////////
	while (check)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter damage : ";
		cin >> value1Str;
		//Если есть ошибка, выводим сообщение 
		regex regex_integer("[1-9][0-9]{1,10}$");
		if (!regex_match(value1Str, regex_integer)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 10 to 9.999.999.999 $)\n";
			//Восстановили поток			
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			value1Int = atoi(value1Str.c_str());
			check = false;
		}
	}


	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter name of corporation : ";
		cin >> value2Str;
		regex regex_integer1("[A-Z][A-Za-z]{3,15}$");
		if (!regex_match(value2Str, regex_integer1)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter corractly! Repeat!\n";
			cout << "Not a suitable value (capital letter and latin letters next)\n";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
		}
	}



	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter copy ability (1 - yes; 0 - no) : ";
		cin >> value4Str;
		regex regex_integer3("[0-1]$");
		if (!regex_match(value4Str, regex_integer3)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 0 and 1)\n";

			cin.clear();

			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else {
			check = false;
			value4Int = atoi(value4Str.c_str());
		}
	}

	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter name of virus: ";
		cin >> name;
		regex regex_line("[A-Z][A-Za-z0-9]{2,9}");
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
	string File;
	check = true;
	while (check) {
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter name of file: ";
		cin >> File;
		regex regex_line("[A-Z][A-Za-z0-9?-]{2,20}\\.(exe|dll|TXT)$");
		if (!regex_match(File, regex_line)) {
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

	add->next = NULL;
	add->virus.SetDamage(value1Int);
	add->virus.SetCorporation(value2Str);
	add->virus.SetDate(d, m, y);
	add->virus.SetCopying(value4Int);
	add->virus.SetName(name);
	add->virus.SetNameOfFile(File);
	add->next = head->next;
	head->next = add;
	add->prev = head;
	size++;
	h->size = size;
}
/**
This method finds the viruses you need (asks the maximum amount of damage was) and marks them green.
The test is performed using regular expressions.

@param[in] h Head of list
*/
void Avast::FindFrom(list_ptr h)
{
	list_ptr pr = h->next;
	int memory, check = true;
	string memoryStr;
	int memoryInt;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	while (check)
	{
		SetConsoleTextAttribute(hConsole, (WORD)(BROWN));
		cout << "Enter the maximem damage you want to see in the printed viruses below: ";
		cin >> memoryStr;
		//Если есть ошибка, выводим сообщение 
		regex regex_integer("[0-9]{1,6}|[0-4][0-9]{1,6}$");///<Check the correctness of memory input by regular expressions
		if (!regex_match(memoryStr, regex_integer)) {
			SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
			cout << "Please enter numbers! Repeat!\n";
			cout << "Not a suitable value, please repeat (from 0 to 9.999.999 $)\n";
			//Восстановили поток
			cin.clear();
			//Почистили поток
			cin.ignore(cin.rdbuf()->in_avail());
			continue;
		}
		else check = false;
		memoryInt = atoi(memoryStr.c_str());///<Convert memory input to intager
	}
	cout << "\nAfter: \n\n";
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	cout << setw(20) << "date"
		<< setw(14) << "damage" << setw(19)
		<< "corporation" << setw(17)
		<< "copying" << setw(14)
		<< "name" << setw(28)
		<< "name of file" << endl;
	for (uint i = 1; pr->next; i++) {
		if (pr->virus.damage < memoryInt) {
			cout << pr->virus.ShowElem(pr, LIGHTGREEN);
		}
		else {
			cout << pr->virus.ShowElem(pr, LIGHTRED);
		}
		pr = pr->next;
	}
}


