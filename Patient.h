//
//  Patient.h
//  EmergencyRoom
//
//  Created by Rachel Wofford on 5/4/18.
//  Copyright © 2018 Rachel Wofford. All rights reserved.
//

#ifndef Patient_h
#define Patient_h

#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

struct Patient{
/*private:
    int priority;
    int CurrentPriority(){
        srand(time(NULL));
        int n = rand() % 10;
        if (n <= 7){
            priority = 1;
        }
        if (n > 7 && n < 10)
        {
            priority = 2;
        }
        else
        {
            priority = 3;
        }
        
        return priority;
    }*/
    
    Patient(int clock, int priority_level, std::string name) : priority(-1), name(""), patient_visits(-1), arrival_time(clock), start_treatment_time(-1), treatment_time(-1) {}

    int priority; 
    std::string name;
    int patient_visits;
    int arrival_time;
    int start_treatment_time;
    int treatment_time;
    
    std::multiset<int> patient_record;
};

#endif /* Patient_h */
