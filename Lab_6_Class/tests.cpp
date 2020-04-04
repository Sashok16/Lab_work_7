/**
* @author Kogutenko Aleksandr
* @date 2020.04.04
*/
#include "mainLib.h"
#include "test.h"
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
@param[in] h Head of CSoftware list
@return The row that shows the result of the data check 
*/
string testCSoftwareFindFrom(list_ptr h) {
	// initial data
	list_ptr pr = h->next;///Сreate variable to do not lose the head of the list Software
	// expected data
	const int memoryInt = 500000;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "Checking memory: " << memoryInt;
	int checkAmount = 7;
	int checkingVal = 0;
	cout << "\nAfter: \n\n";
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	cout << setw(23) << "openings" << setw(10) << "users" << setw(18)
		<< "date of creation" << setw(16) << "memory(Kb)"
		<< setw(16) << "corporation" << endl;
	for (uint i = 1; pr->next; i++) {///In the loop, we display information in different colors: green and red. Green - those that are suitable for us, red - those that are not suitable.
		if (pr->info.GetMemory() < memoryInt) {
			cout << pr->info.ShowElem(pr, LIGHTGREEN);
			checkingVal++;
		}
		else {
			cout << pr->info.ShowElem(pr, LIGHTRED);
		}
		pr = pr->next;
	}
	stringstream ss;
	// assertion
	if (checkingVal == checkAmount) {
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGREEN));
		ss << "\n\nMethod \"CSoftware::FindFrom\" works correctly\n" << "Everything went well.\n\n" ;
	}
	else {
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
		ss << "\n\nMethod \"CSoftware::FindFrom\" does not work correctly\n" 
			<< "It was " << checkAmount << " programs with throjan\n"
			<< "But it turned out " << checkingVal << " programs with throjan\n\n";
	}
	//resualt
	return ss.str();
}
/**
@param[in] h Head of CSoftware list
@return The row that shows the result of the data check
*/
string testCSoftwareDeleteProgramWithTrojan(list_ptr h) {
	list_ptr pr = h->next;///Сreate variable to do not lose the head of the list Software.
	uint size = pr->size;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	const int amountThrojans = 5;
	int amountDel = 0;
	cout << "Throjan programmes: " << amountThrojans << endl << endl;

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
		if (prDel->info.GetThrojan()) {
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
			amountDel++;
		}
		prDel = prDel->next;
	}
	stringstream line;
	if (amountThrojans == amountDel) {
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGREEN));
		line << "\n\nMethod \"CSoftware::deleteProgramWithTrojan()\" works correctly\n" << "Everything went well.\n\n";
	}
	else {
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
		line << "\n\nMethod \"CSoftware::deleteProgramWithTrojan()\" does not work correctly\n"
			<< "It was " << amountThrojans << " programs with throjan\n"
			<< "But it turned out " << amountDel << " programs with throjan\n\n";
	}
	return line.str();
}
/**
@param[in] h Head of Avast list
@return The row that shows the result of the data check
*/
string testAvastFindFrom(list_ptr h) {
	list_ptr pr = h->next;
	int check = true;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	int checkDamage = 500000;
	int amountDamage = 4;
	int checkAmountDamage = 0;
	cout << "Checking damage: " << checkDamage;

	cout << "\n\nAfter: \n\n";
	SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGRAY));
	cout << setw(20) << "date"
		<< setw(14) << "damage" << setw(19)
		<< "corporation" << setw(17)
		<< "copying" << setw(14)
		<< "name" << setw(28)
		<< "name of file" << endl;
	for (uint i = 1; pr->next; i++) {
		if (pr->virus.GetDamage() < checkDamage) {
			cout << pr->virus.ShowElem(pr, LIGHTGREEN);
			checkAmountDamage++;
		}
		else {
			cout << pr->virus.ShowElem(pr, LIGHTRED);
		}
		pr = pr->next;
	}

	stringstream ss;
	if (amountDamage == checkAmountDamage) {
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTGREEN));
		ss << "\n\nMethod \"Avast::FindFrom()\" works correctly\n" << "Everything went well.\n\n";
	}
	else {
		SetConsoleTextAttribute(hConsole, (WORD)(LIGHTRED));
		ss << "\n\nMethod \"Avast::FindFrom()\" does not work correctly\n"
			<< "It was " << amountDamage << " viruses which have damaged\n"
			<< "But it turned out " << checkAmountDamage << " viruses which have damaged\n\n";
	}
	return ss.str();
}