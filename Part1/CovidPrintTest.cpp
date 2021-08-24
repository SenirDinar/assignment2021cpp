#include "CovidCase.h"

#include <string>
#include <sstream>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostringstream;

int main() {
    
    int retval = 0;
    
    
    {
        CovidCase patientA(51.5115, -0.1160, "PatientA", 48, 49);
        CovidCase patientB(51.5033, -0.1195, "PatientB", 51, 79);
        
        ostringstream str;
        str << patientA << patientB;
        
        string s = str.str();
        
        string shouldBe = "{51.5115, -0.116, \"PatientA\", 48, 49}{51.5033, -0.1195, \"PatientB\", 51, 79}";
        
        if (s == shouldBe) {
            cout << "0: Pass - operator<< gives the correct output\n";
        } else {
            cout << "0: Fail - operator<< gives incorrect output.\nExpected: " << shouldBe << "\nGot: " << s << "\n";
            ++retval;
        }
    }
    
    return retval;
}
