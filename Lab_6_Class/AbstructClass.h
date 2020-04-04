/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
* @file AbstructClass.h
*/
#pragma once
#include "mainLib.h"
/**
 @brief Abstract class that stores virtual functions
*/
class Framework {
public:
	/**
	@brief Virtual function for displaying lists
	@param[in] h Head of list
	*/
	virtual void ShowAll(list_ptr h) = 0;
	/**
	@brief Virtual function for adding one object
	@param[in] h Head of list
	*/
	virtual void AddOne(list_ptr h) = 0;
	/**
	@brief Virtual function for removeing one object
	@param[in] h Head of list
	*/
	virtual void RemoveOne(list_ptr h) = 0;
	/**
	@brief Virtual function for finding from one of fields
	@param[in] h Head of list
	*/
	virtual void FindFrom(list_ptr h) = 0;
	/**
	@brief Virtual function for writeing information to file
	@param[in] h Head of list
	*/
	virtual void WriteToFile(list_ptr h) = 0;
	/**
	@brief Virtual function for showing one object
	@param[in] el List entry.
	@param[in] color Output text color.
	@return Formatted input element
	*/
	virtual string ShowElem(list_ptr el, int color) = 0;
};