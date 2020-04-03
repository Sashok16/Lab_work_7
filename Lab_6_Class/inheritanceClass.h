/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
*/
#pragma once
#include "BaseClass.h"
#include "DateClass.h"
/**
@brief A hereditary class that overrides the abstract class methods and adds one of its own.
It is inherited from CSoftware because it also uses its functionality.
*/
class Avast : public CSoftware
{
private:
	bool copying;///Responsible for the ability to copy viruses.
	string name;///Responsible for virus name.
	string nameOfFile;///Responsible for virus filename.
	uint damage;///Responsible for the amount of damage caused.
public:
	/**
	 @brief Default constructor in "Avast" class.
	*/
	Avast();
	/**
	 @brief Constructor with parameters for the class "Avast"
	 */
	Avast(uint day, uint mon, uint year, string corporation, string name, string nameOfFile, uint damage, bool copying);
	/**
	 @brief Copying construct in "Avast" class.
	*/
	Avast(Avast& object);
	/**
	 @brief The overload of operator of the equation in "Avast" class.
	*/
	Avast& operator =(const Avast& object);

	/////////////////////////////////////////////////////////////////
	/**
	 @brief Implement a virtual function intended for list display.
	*/
	void ShowAll(list_ptr h) override;
	/**
	 @brief Implementation of virtual function intended for removal of one object of the list of viruses. 
	*/
	void RemoveOne(list_ptr h) override;
	/**
	 @brief Implement a virtual function to add one virus object by field.
	*/
	void AddOne(list_ptr h) override;
	/**
	 @brief Implement a virtual function to find objects by damage field.
	*/
	void FindFrom(list_ptr h) override;
	/**
	 @brief Implement a virtual function to show one object.
	 */
	string ShowElem(list_ptr, int) override;
	/**
	 @brief Implement a virtual function to write information to output file.
	*/
	void WriteToFile(list_ptr) override;

	//////////////////////////////////////////////////////////
	/**
	 @brief Field Getter copying
	 */
	bool GetCopying() const;
	/**
	 @brief Field Getter name
	*/
	string GetName() const;
	/**
	 @brief Field Getter nameOfFile
	*/
	string GetNameOfFile() const;
	/**
	 @brief Field Getter damage
	 */
	uint GetDamage() const;
	/**
	 @brief Field Setter copying
	*/
	void SetCopying(bool copying);
	/**
	 @brief  Field Setter name
	*/
	void SetName(string name);
	/**
	 @brief Field Setter nameOfFile
	*/
	void SetNameOfFile(string nameOfFile);
	/**
	 @brief Field Setter damage
	*/
	void SetDamage(uint damage);
};