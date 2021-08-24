#include "CovidCaseMap.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::ostringstream;
using std::pair;
using std::vector;

int main() {
    
    int retval = 0;
    
    
    CovidCaseMap m;
    m.addCase(CovidCase(51.75186263338416,-0.3356807902,"48763f26d6b",21,5));
    m.addCase(CovidCase(51.75166927531987,-0.3455440017,"48763f3b5ef",24,8));
    m.addCase(CovidCase(51.75293227875113,-0.3363451467,"48763f26e9b",19,73));
    m.addCase(CovidCase(51.751442536246415,-0.3384676374,"48763f23ff9",35,117));
    m.addCase(CovidCase(51.750621522352574,-0.3373409116,"48763f21445",42,142));
    
    double routeLength = m.supportVisitGreedyTSP(51.751, -0.336, 120, 336);

    double shouldBe = 0.991819;
    
    if (routeLength >= shouldBe - 0.001 && routeLength <= shouldBe + 0.001) {
        cout << "Pass: returned a route length of " << routeLength << ", which is the same (or close to) " << shouldBe << "\n";
    } else {
        cout << "Fail: returned a route length of " << routeLength << ", but should have been " << shouldBe << "\n";

        ++retval;
    }

    return retval;
}
