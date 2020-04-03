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
The constructor initializes the initial values of the object of this class. IN this case, the zeroing the values.
@return Nothing returns
*/
CSoftware::CSoftware() {
	numberOfOpenings = 0;
	date.SetDate(1, 1, 1980);
	numberOfUsers = 0;
	memory = 0;
	throjans.SearchThrojan(0);
	id = 0;
	corporation = "NoName";
}
/**
We pass as arguments the values that we write in the fields of the object of this class.

@param[in] numberOfOpenings Number of openings of this application (object)
@param[in] day The day this application was created
@param[in] mon The month that this application was created
@param[in] year The year this application was created
@param[in] numberOfUsers The number of users for this application
@param[in] memory The number of kilobytes that this application occupies
@param[in] throjan Presence of trojan in the program
@param[in] id Application ID (number)
@param[in] corporation The Corporation name that created the application

@return Nothing returns
*/
CSoftware::CSoftware(uint numberOfOpenings,uint day, uint mon,uint year,uint numberOfUsers,uint memory,bool throjan,uint id,string corporation) 
{
	this->numberOfOpenings = numberOfOpenings;
	this->date.SetDate(day, mon, year);
	this->numberOfUsers = numberOfUsers;
	this->memory = memory;
	this->throjans.SearchThrojan(throjan);
	this->corporation = corporation;
	this->id = id;
}
/**
	 @details The accepted object fills in the fields of the new object
	 @param[in]  object The object from which copies fields of the same class.
	 @return Nothing
*/
CSoftware::CSoftware(CSoftware& object ) 
{
	SetNumberOfOpenings(object.GetNumberOfOpenings());
	SetDate(object.date.GetDay(), object.date.GetMon(), object.date.GetYear());
	SetNumberOfUsers(object.GetNumberOfUsers());
	SetMemory(object.GetMemory());
	SetThrojan(object.GetThrojan());
	SetCorporation(object.GetCorporation());
	SetId(object.GetId());
}
/**
Works similar to the copy constructor only we use the equation of two objects
@param[in] object The object from which you copy.
@return Nothing return.
*/
CSoftware& CSoftware::operator =(const CSoftware& object) 
{
	SetNumberOfOpenings(object.GetNumberOfOpenings());
	SetDate(object.date.GetDay(), object.date.GetMon(), object.date.GetYear());
	SetNumberOfUsers(object.GetNumberOfUsers());
	SetMemory(object.GetMemory());
	SetThrojan(object.GetThrojan());
	SetCorporation(object.GetCorporation());
	SetId(object.GetId());
	return *this;
}
/**
 @return Line of corporation name.
*/
string CSoftware::GetCorporation() const {
	return corporation;
}
/**
 @return Number of amount memory.
*/
int CSoftware::GetMemory() const {
	return memory;
}
/**
@return whether the object (program) is a trojan (true or false).
*/
bool CSoftware::GetThrojan() const {
	return throjans.GetThrojan();
}
/**
@return Number of program openings. 
*/
int CSoftware::GetNumberOfOpenings() const {
	return numberOfOpenings;
}
/**
 @return Line of creation date.
 */
string CSoftware::GetDate() const {
	return date.GetDate();
}
/**
 @return Number of program users.
*/
int CSoftware::GetNumberOfUsers() const {
	return numberOfUsers;
}
/**
 @param[in] corporation Name of corporation which created program.
*/
void CSoftware::SetCorporation(string corporation) {
	this->corporation = corporation;
}
/**
 @param[in] numberOfOpenings Number of program openings.
*/
void CSoftware::SetNumberOfOpenings(int numberOfOpenings) {
	this->numberOfOpenings = numberOfOpenings;
}
/**
@param[in] day Day of program creation. 
@param[in] mon Month of program creation. 
@param[in] year Year of program creation. 
*/
void CSoftware::SetDate(uint day, uint mon, uint year) {
	this->date.SetDate(day, mon, year);
}
/**
 @param[in] numberOfUsers Number of program users.
*/
void CSoftware::SetNumberOfUsers(int numberOfUsers) {
	this->numberOfUsers = numberOfUsers;
}
/**
@param[in] memory The number of kilobytes that this application occupies
*/
void CSoftware::SetMemory(int memory) {
	this->memory = memory;
}
/**
 @param[in] throjan Whether the object (program) is a trojan (true or false).
*/
void CSoftware::SetThrojan(bool throjan) {
	this->throjans.SearchThrojan(throjan);
}

CSoftware::~CSoftware() {
}
/**
@return ID of program(number of program)
*/
uint CSoftware::GetId() const {
	return id;
}
/**
 @param[in] id ID of program(number of program)
*/
void CSoftware::SetId(uint id) {
	this->id = id;
}
/**
@return Year of program creation.
*/
int CSoftware::GetYear() const {
	return date.GetYear();
}
/**
@return Month of program creation.
*/
int CSoftware::GetMon() const {
	return date.GetMon();
}
/**
 @return Day of program creation.
*/
int CSoftware::GetDay() const {
	return date.GetDay();
}