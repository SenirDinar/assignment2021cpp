#include "CovidCase.h"

#include <iostream>
using std::cout;
using std::endl;

int main() {

    int retval = 0;
    
    {        
        
        cout << "Making two patients with the two constructors, that should be identical\n";
        
        CovidCase patientA1(51.5115, -0.1160, "PatientA", 48, 49);
        
        CovidCase patientA2("51.5115, -0.1160, \"PatientA\", 48, 49");
        
        if (patientA1.getLatitude() == patientA2.getLatitude()) {
            cout << "Latitude is the same\n";
        } else {
            cout << "Latitude should be the same, but it is not\n";
            ++retval;
        } 
        
        if (patientA1.getLongitude() == patientA2.getLongitude()) {
            cout << "Longitude is the same\n";
        } else {
            cout << "Longitude should be the same, but it is not\n";
            ++retval;
        } 
        
        
        if (patientA1.getName() == patientA2.getName()) {
            cout << "name is the same\n";
        } else {
            cout << "name should be the same, but it is not\n";
            ++retval;
        } 
        
        
        
        if (patientA1.getAge() == patientA2.getAge()) {
            cout << "Age is the same\n";
        } else {
            cout << "Age should be the same, but it is not\n";
            ++retval;
        } 
        
        
        if (patientA1.getTime() == patientA2.getTime()) {
            cout << "Time is the same\n";
        } else {
            cout << "Time should be the same, but it is not\n";
            ++retval;
        } 
        
        if (retval != 0) {
            cout << "Not testing operator== -- the getters return different values\n";
            return retval;
        }
        
        
        
        if (patientA1 == patientA2) {
            cout << "operator== correctly returns true for the identical patients\n";
        } else {
            cout << "operator== test failed: returns false for two identical patients\n";
            ++retval;
        }
        
        CovidCase patientB("41.5115, -1.234, \"PatientB\", 44, 60");
        
        if (!(patientA1 == patientB)) {
            cout << "operator== correctly returns false for two different patients\n";
        } else {
            cout << "operator== test failed: returns true for two different patients\n";
            ++retval;
        }
    }
        
    return retval;
}
