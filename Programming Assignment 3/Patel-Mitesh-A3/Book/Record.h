#include <cstdlib>
#include <iostream>
using namespace std;

class Record
{
    
public:
    string lastName;
    string firstName;
    int UIN;
    long int number;
    
    bool operator <(const Record& r)
    {
        if (lastName < r.lastName)
            return true;
        if (lastName == r.lastName && firstName < r.firstName) // if last names are equal and firse name is less than one being compared to
            return true;
        if (lastName == r.lastName && firstName == r.firstName && UIN < r.UIN) // if both names equal then compar UINS
            return true;
        return false;
    }

};


ostream& operator<<(ostream& out, const Record& r)
{
    out << r.lastName << endl;
    out << r.firstName << endl;
    out << "UIN: " << r.UIN << endl;
    out << "Phone " << r.number << endl;
    out << endl;
    return out;
}




