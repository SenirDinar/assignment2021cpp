#include "Countdown.h"

#include <iostream>
using std::cout;
using std::endl;

#include <string>

int main() {

    int retval = 0;
    
    {
        double answer = evaluateCountdown(std::string("3.0 4.0 +"));
        if (answer == 7.0) {
            cout << "1) Pass: evaluated '3.0 4.0 +', got 7.0\n";
        } else {
            cout << "1) Fail: evaluated '3.0 4.0 +' expecting 7.0, but got " << answer << std::endl;
            ++retval;
        }
    }
    
    {
        double answer = evaluateCountdown(std::string("3.0 4.0 - 4.0 +"));
        if (answer == 3.0) {
            cout << "2) Pass: evaluated '3.0 4.0 - 4.0 +', got 3.0\n";
        } else {
            cout << "2) Fail: evaluated '3.0 4.0 - 4.0 +' expecting 3.0, but got " << answer << std::endl;
            ++retval;
        }
    }
    
    {
        double answer = evaluateCountdown(std::string("3.0 4.0 - 2.0 *"));
        if (answer == -2.0) {
            cout << "3) Pass: evaluated '3.0 4.0 - 2.0 *', got -2.0\n";
        } else {
            cout << "3) Fail: evaluated '3.0 4.0 - 2.0 *' expecting -2.0, but got " << answer << std::endl;
            ++retval;
        }
    }
        

    {
        double answer = evaluateCountdown(std::string("100 20 / 4 +"));
        if (answer == 9) {
            cout << "4) Pass: evaluated '100 20 / 4 +', got 9\n";
        } else {
            cout << "4) Fail: evaluated '100 20 / 4 +' expecting 9, but got " << answer << std::endl;
            ++retval; 
        }
    }

    return retval;
}
