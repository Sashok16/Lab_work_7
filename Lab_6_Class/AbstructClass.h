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
	*/
	virtual void ShowAll(list_ptr) = 0;
	/**
	@brief Virtual function for adding one object
	*/
	virtual void AddOne(list_ptr) = 0;
	/**
	@brief Virtual function for removeing one object
	*/
	virtual void RemoveOne(list_ptr) = 0;
	/**
	@brief Virtual function for finding from one of fields
	*/
	virtual void FindFrom(list_ptr) = 0;
	/**
	@brief Virtual function for writeing information to file
	*/
	virtual void WriteToFile(list_ptr) = 0;
	/**
	@brief Virtual function for showing one object
	*/
	virtual string ShowElem(list_ptr, int) = 0;
};