/**
* @author Kogutenko Aleksandr
* @date 2020.03.20
* @file BaseClass.h
*/
#pragma once
#include "mainLib.h"
#include "DateClass.h"
#include "AbstructClass.h"
/**
 @brief The class is an heir to an abstract class, with the implementation of virtual methods.

 The class contains fields: date created, Corporation, number of program opening, number of users, number of memory occupied,
the id in the list and the field responsible for marking whether the program is trojan or not.
Also, the class has methods inherited from the abstract class and its own.
*/
class CSoftware : public Framework {
public:
	/**
	 @brief Class a composition for a field that determines whether this program is trojan or not.	
	*/
	class Antivirus {
		bool throjan;///Whether the program is Trojan
	public:
		/**
		@brief Field Getter throjan
		@return Program is trojan or not
		*/
		bool GetThrojan() const {
			return throjan;
		}
		/**
		@brief Field Setter throjan
		*/
		void SearchThrojan(bool throjan) {
			this->throjan = throjan;
		}
	};
protected:
	CDate date;///Date of creation
	string corporation;///Name of corporation
	uint numberOfOpenings;///Number of openigs given programe
	uint numberOfUsers;///Number of users given programe
	uint memory;///Amount of memory given programe
	uint id;///Id of given programe
	Antivirus throjans;///This field is responsiblle for viruses given program
public:
	/**
	 @brief Default constructor in "CSoftware" class.
	*/
	CSoftware();
	/**
	@brief Constructor with parameters for the class "CSoftware"
	*/
	CSoftware( uint numberOfOpenings,uint day,uint mon,uint year,uint numberOfUsers,uint memory,bool throjan,uint id,string corporation);
	/**
	 @brief Copying construct in "CSoftware" class.
	*/
	CSoftware(CSoftware& object );
	/**
	 @brief The overload of operator of the equation in "CSoftware" class.
	*/
	CSoftware& operator =(const CSoftware& objCSoftware);
	/**
	 @brief Implement a virtual function intended for list display.
	*/
	 void ShowAll(list_ptr h) override;
	 /**
	 @brief Implementation of virtual function intended for removal of one object of the list of software.
	*/
	 void RemoveOne(list_ptr h) override;
	 /**
	 @brief Implement a virtual function to add one software list object by field.
	*/
	 void AddOne(list_ptr h) override;
	 /**
	 @brief  Implement a virtual function to add one software list object by line.
	 */
	 void addProgramLine( list_ptr h);
	 /**
	 @brief Implement a virtual function to find objects by memory field.
	 */
	 void FindFrom(list_ptr h) override;
	 /**
	 @brief Implement a virtual function to remove objects that have a trojan.
	 */
	 void deleteProgramWithTrojan(list_ptr h);
	 /**
	 @brief Implement a virtual function to show one object.
     */
	 string ShowElem(list_ptr el,int color) override;
	 /**
	 @brief Implement a virtual function to enter information in line and check it.
	 */
	 void enterValue(list_ptr);
	 /**
	 @brief Implement a virtual function to write information to output file.
	 */
	 void WriteToFile(list_ptr) override;

	//////////////////////////////////////////////
	/**
	 @brief Field Getter corporation
	*/
	string GetCorporation() const;
	/**
	 @brief Field Getter id
	*/
	uint GetId() const;
	/**
	 @brief Field Getter momory
	*/
	int GetMemory() const;
	/** 
	 @brief Field Getter throjan
	*/
	bool GetThrojan() const;
	/**
	 @brief Field Getter numberOfOpenings
	*/
	int GetNumberOfOpenings() const;
	/**
	 @brief Field Getter year
	*/
	int GetYear() const;
	/**
	 @brief Field Getter mon
	*/
	int GetMon() const;
	/**
	 @brief Field Getter day
	*/
	int GetDay() const;
	/**
	 @brief Field Getter date
	*/
	string GetDate() const;
	/**
	 @brief Field Getter numberOfUsers
	*/
	int GetNumberOfUsers() const;

	///////////////////////////////
	/**
	 @brief Field Setter id
	*/
	void SetId(uint);
	/**
	 @brief Field Setter corporation
	*/
	void SetCorporation(string);
	/**
	 @brief Field Setter numberOfOpenings
	*/
	void SetNumberOfOpenings(int);
	/**
	 @brief Field Setter date
	*/
	void SetDate(uint,uint,uint);
	/**
	 @brief Field Setter  numberOfUsers
	*/
	void SetNumberOfUsers(int);
	/**
	 @brief Field Setter memory
	*/
	void SetMemory(int);
	/**
	 @brief Field Setter throjan
	*/
	void SetThrojan(bool);
	/**
	 @brief Empty destruct
	*/
	~CSoftware();
};

