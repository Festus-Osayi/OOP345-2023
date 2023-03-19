#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "pair.h"

using namespace std;

namespace sdds{
    Pair::Pair(){};

    std::ostream &Pair::write(std::ostream &ostr) const{
        ostr<<right<<setw(20)<<this->m_key<<left<<": "<<this->m_value;
        return ostr;
    }

    std::ostream& operator<<(std::ostream &ostr, Pair const &os){
        if(!ostr.fail()){
            os.write(ostr);
        }
        return ostr;
    }
}