//
//  Nurse.h
//  EmergencyRoom
//
//  Created by Rachel Wofford on 5/4/18.
//  Copyright © 2018 Rachel Wofford. All rights reserved.
//

#ifndef Nurse_h
#define Nurse_h

#include "EmergencyRoom.h"

class Nurse{
private:
    //Range of nurse service times
    int min_nurse_treatment_time = 1;
    int max_nurse_treatment_time = 10;
    
public:
    
    Nurse(int num_nurses): min_nurse_treatment_time(1), max_nurse_treatment_time(10) {};
    
    //Loop to move a Patient from the EmergencyRoom queue to the Discharge queue if they are done being treated by a nurse
    //If the Patient moves to Discharge, this loop takes a Patient from the WaitingRoom queue that can be treated by a nurse and adds it to the EmergencyRoom queue
    void update(int clock){
        // Executes if the EmergencyRoom is not empty
        if (!nurse_queue.empty()) {
            
            //Identifies Patient object at the front of the WaitingRoom priority queue
            Patient *patient = nurse_queue.front();
            
            //Checks if full treatment time has elapsed
            //If so, moves Patient from the EmergencyRoom queue to the Discharge queue
            if ((clock - patient->start_treatment_time) > patient->treatment_time) {
                
                //Removes Patient from the EmergencyRoom queue
                nurse_queue.pop();
                
                //Adds the Patient to the Discharge queue
                discharge_queue->the_queue.push(patient);
            }
        }
        
        //FACTOR IN HOW TO DIFFERENTIATE BETWEEN A DOCTOR AND A NURSE
        //Executes if a nurse is available to treat a Patient
        if (nurse_queue.empty()) {
            
            //Move a Patient from the WaitingRoom queue to the EmergencyRoom queue if the WaitingRoom is not empty
            if(!waiting_room_queue->the_queue.empty()){
                //Create a new Patient object pointing to the first Patient in the WaitingRoom queue
                Patient *patient = waiting_room_queue->the_queue.front();
                
                //If the Patient's priority number is less than 10, they can be treated by a nurse
                if (patient->priority <= 10)
                {
                    //Remove first Patient object from WaitingRoom queue
                    waiting_room_queue->the_queue.pop();
                }
                else
                {
                    //SORT THROUGH THE QUEUE
                }
                
                //Update the start_treatment_time attribute for the Patient
                int t_time = clock;
                patient->start_treatment_time = t_time;
                
                //Compute a random treatment time for the Patient between min_nurse_treatment_time and max_nurse_service_time
                int n = max_nurse_treatment_time - min_nurse_treatment_time;
                //Use my_random.next_int(n) to generate a random value between 0 and n
                //This number will not be in the correct range
                int treat_time = my_random.next_int(n);
                //Add the randomly generated treat_time to min_nurse_treatment_time to get a treatment time in the correct range of values
                int treatment_time = treat_time + min_nurse_treatment_time;
                //Set the patient's treatment time to the calculated treatment time
                patient->treatment_time = treatment_time;
                
                //Add the Patient to the EmergencyRoom queue for nurses
                nurse_queue.push(patient);
            }
            
        }
    }
};

#endif /* Nurse_h */
