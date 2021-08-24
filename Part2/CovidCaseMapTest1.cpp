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
    
    vector<pair<int,int> > rightAnswer;
    rightAnswer.emplace_back(0,0);
    rightAnswer.emplace_back(5,1);
    rightAnswer.emplace_back(8,2);
    rightAnswer.emplace_back(73,3);
    rightAnswer.emplace_back(117,4);
    rightAnswer.emplace_back(125,3);
    rightAnswer.emplace_back(128,2);
    rightAnswer.emplace_back(142,3);
    rightAnswer.emplace_back(193,2);
    rightAnswer.emplace_back(237,1);
    rightAnswer.emplace_back(262,0);
    
    
    vector<TimeAndCaseData> active = m.getCasesOverTime(120);
    
    if (active.size() == 0) {
        cout << "An empty vector was returned, the test cannot pass\n";
        return 1;
    }
    
    for (int i = 0; i < rightAnswer.size(); ++i) {        
        
        cout << "Entry " << i << ": expecting time = " << rightAnswer[i].first << ", cases = " << rightAnswer[i].second; 
        
        if (i >= active.size()) {
            cout << " -- not enough entries in the answer from the getCasesOverTime function\n";
            ++retval;
            continue;            
        }
        if (rightAnswer[i].first == active[i].getTime() && rightAnswer[i].second == active[i].getNumberOfCases()) {
            cout << " -- got it\n";
        } else {
            cout << " -- instead got time = " << active[i].getTime() << ", cases = " << active[i].getNumberOfCases() << "\n";
            ++retval;
        }
    }
    
    return retval;
}
