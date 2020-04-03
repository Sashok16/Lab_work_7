/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#include "DateClass.h"
/**
Defualt construct sets field to 01.01.1980
*/
CDate::CDate() {
	day = 1;
	mon = 1;
	year = 1980;

}
/**
Construct with parameters sets fields to vaulue in parameters 	 
@param[in] day Information about the "day" field
@param[in] mon Information about the "mon" field
@param[in] year Information about the "year" field
*/
CDate::CDate(uint day, uint mon, uint year) {
	this->day = day;
	this->mon = mon;
	this->year = year;
}
/**
The accepted object fills in the fields of the new object
@param[in] object The object from which you copy.
*/
CDate::CDate(CDate& object) {
	SetDay(object.GetDay());
	SetMon(object.GetMon());
	SetYear(object.GetYear());
}
/**
Works similar to the copy constructor only we use the equation of two objects.
 @param[in] object The object from which you copy.
*/
CDate& CDate::operator =(const CDate& object) {
	//јналогичные действи€ как с констуктором копировани€
	SetDay(object.GetDay());
	SetMon(object.GetMon());
	SetYear(object.GetYear());
	//¬озвращаем указатель this
	return *this;
}
/**
@return Field day.
*/
uint CDate::GetDay() const {
	return day;
}
/**
@return Field mon.
*/
uint CDate::GetMon() const {
	return mon;
}
/**
@return Field year.
*/
uint CDate::GetYear() const {
	return year;
}
/**
@param[in] day Veriable for field day
*/
void CDate::SetDay(uint day) {
	this->day = day;

}
/**
@param[in] mon Veriable for field mon
*/
void CDate::SetMon(uint mon) {
	this->mon = mon;

}
/**
@param[in] year Veriable for field year
*/
void CDate::SetYear(uint year) {
	this->year = year;
}
/**
@return A formatted string with information about a given date.
*/
string CDate::GetDate() const {
	stringstream ss;
	int day = GetDay(), mon = GetMon(), year = GetYear();
	string dayS = to_string(day), monS = to_string(mon), yearS = to_string(year);
	if (day < 10 && mon >= 10) {
		ss << setw(2) << "0" + dayS << "." << setw(2) << monS << "." << yearS;
	}
	else if (mon < 10 && day >= 10) {
		ss << setw(2) << dayS << "." << setw(2) << "0" + monS << "." << yearS;
	}
	else if (mon < 10 && day < 10) {
		ss << setw(2) << "0" + dayS << "." << setw(2) << "0" + monS << "." << yearS;
	}
	else {
		ss << setw(2) << dayS << "." << setw(2) << monS << "." << yearS;
	}
	return ss.str();
}
/**
@param[in] day Veriable for field day
@param[in] mon Veriable for field mon
@param[in] year Veriable for field year
*/
void CDate::SetDate(uint day, uint mon, uint year) {
	SetDay(day);
	SetMon(mon);
	SetYear(year);
}