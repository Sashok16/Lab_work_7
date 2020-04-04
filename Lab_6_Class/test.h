/**
* @author Kogutenko Aleksandr
* @date 2020.04.04
*/
#pragma once
#include "mainLib.h"
#include "BaseClass.h"
#include "inheritanceClass.h"
/**
@brief Test for the number of programs found under a given parameter
*/
string testCSoftwareFindFrom(list_ptr h);
/**
@brief Test for number of Trojan removals based on initial knowledge them amount
*/
string testCSoftwareDeleteProgramWithTrojan(list_ptr h);
/**
@brief Test for the number of viruses found under a given parameter
*/
string testAvastFindFrom(list_ptr h);