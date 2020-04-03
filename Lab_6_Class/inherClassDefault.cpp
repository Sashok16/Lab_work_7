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
The constructor initializes the initial values of the object of this class. IN this case, the zeroing the numbers values and strings.
*/
Avast::Avast() {
	date.SetDate(1, 1, 1980);
	corporation = "NoName";
	copying = 0;
	name = "NoName";
	nameOfFile = "NoName";
	damage = 0;
}
/**
We pass as arguments the values that we write in the fields of the object of this class.

@param[in] day The day this virus was created
@param[in] mon The month this virus was created
@param[in] year The year this virus was created
@param[in] corporation The Corporation name that attacted by this virus
@param[in] name Virus name
@param[in] nameOfFile Name of infected file 
@param[in] damage Damage from this virus
@param[in] copying Copying ability
*/
Avast::Avast(uint day, uint mon, uint year, string corporation, string name, string nameOfFile, uint damage, bool copying) {
	this->date.SetDate(day, mon, year);
	this->copying = copying;
	this->corporation = corporation;
	this->name = name;
	this->nameOfFile = nameOfFile;
	this->damage = damage;
}
/**
The accepted object fills in the fields of the new object
@param[in] object  The object from which copies fields of the same class.
*/
Avast::Avast(Avast& object) {
	SetCopying(object.GetCopying());
	SetName(object.GetName());
	SetNameOfFile(object.GetNameOfFile());
	SetDamage(object.GetDamage());
	SetCorporation(object.GetCorporation());
}
/**
Works similar to the copy constructor only we use the equation of two objects
@param[in] object The object from which you copy.
*/
Avast& Avast::operator =(const Avast& object) {
	//јналогичные действи€ как с констуктором копировани€
	SetCopying(object.GetCopying());
	SetName(object.GetName());
	SetNameOfFile(object.GetNameOfFile());
	SetDamage(object.GetDamage());
	SetCorporation(object.GetCorporation());
	//¬озвращаем указатель this
	return *this;
}
/**
@return Copying ability
*/
bool Avast::GetCopying() const {
	return copying;
}
/**
 @return Virus name
*/
string Avast::GetName() const {
	return name;
}
/**
@return Name of infected file 
*/
string Avast::GetNameOfFile() const {
	return nameOfFile;
}
/**
@return Damage from this virus
*/
uint Avast::GetDamage() const {
	return damage;
}
/**
@param copying Copying ability
*/
void Avast::SetCopying(bool copying) {
	this->copying = copying;
}
/**
 @param name Virus name
*/
void Avast::SetName(string name) {
	this->name = name;
}
/**
 @param nameOfFile Name of infected file 
*/
void Avast::SetNameOfFile(string nameOfFile) {
	this->nameOfFile = nameOfFile;
}
/**
@param damage Damage from this virus
*/
void Avast::SetDamage(uint damage) {
	this->damage = damage;
}