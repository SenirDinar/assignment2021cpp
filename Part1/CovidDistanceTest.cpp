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
        
        double distance = patientA.distanceTo(patientB);
        
        double shouldBe = 0.586402;
        
        if (distance >= shouldBe - 0.01 && distance <= shouldBe + 0.01) {
            cout << "0: Pass - the distance is correctly equal (or close to) to 0.586402\n";
        } else {
            cout << "0: Fail - distance should be " << shouldBe << ", but got " << distance << "\n";
            ++retval;
        }
    }
    
    return retval;
}
