#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iomanip>
#include <cstring>
#include "Pair.h"
using namespace std;
namespace sdds
{
    // a no arguemnt constructor
    Pair::Pair(){};

    std::ostream &Pair::write(std::ostream &ostr) const
    {
        
            if(!ostr.fail()){
                ostr << right << setw(20) << this->m_key << left << ": "<<this->m_value;
            }
        
       
        return ostr;
    }
    // an insertion operator, which takes the reference of an ostream
    std::ostream &operator<<(std::ostream &ostr, const Pair &os)
    {
        if(!ostr.fail()){
            os.write(ostr);
        }
        return ostr;
    }
    // comparison between two keys, return true if valid, false otherwise..
    bool Pair::operator==(const Pair &compare)
    {
        return (m_key == compare.m_key);
    }
}