/*Filename: Utilities.h
Author:	Festus Osayi
Student Number : 170276216
-----------------------------------------------------------
Date: 2023/03/12
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Person.h"

namespace sdds {

	// // a single function that creates instances on the `Person` hierarchy.
	Person* buildInstance(std::istream& in);
}
#endif
