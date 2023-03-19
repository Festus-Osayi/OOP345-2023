#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Person.h"

namespace sdds {

	// // a single function that creates instances on the `Person` hierarchy.
	Person* buildInstance(std::istream& in);
}
#endif
