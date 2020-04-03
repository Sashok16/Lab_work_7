/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#pragma once
#include "mainLib.h"
/**
@brief Date Class
*/
class CDate {
	uint day;
	uint mon;
	uint year;
public:
	/**
	 @brief Default constructor
	*/
	CDate();
	/**
	 @brief Constructor with parameters
	*/
	CDate(uint, uint, uint);
	/**
	 @brief Copying construct
	*/
	CDate(CDate&);
	/**
	 @brief The overload of operator of the equation.
	*/
	CDate& operator =(const CDate& objCDate);
	/**
	 @brief Getter date.
	*/
	string GetDate() const;
	/**
	 @brief Setter date.
	*/
	void SetDate(uint, uint, uint);
	/**
	 @brief Field Getter day.
	*/
	uint GetDay() const;
	/**
	 @brief Field Getter mon.
	*/
	uint GetMon() const;
	/**
	 @brief Field Getter year.
	*/
	uint GetYear() const;
	/**
	 @brief Field Setter day.
	*/
	void SetDay(uint);
	/**
	 @brief Field Setter mon.
	*/
	void SetMon(uint);
	/**
	 @brief Field Setter year.
	*/
	void SetYear(uint);
};