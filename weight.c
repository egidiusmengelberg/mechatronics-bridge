#include "config.h"
#include <avr/io.h>
#include <avr/iomxx0_1.h>

void InitWeight(void) {
    //set cl output and dt input
    weight_clock_ddr |= (1 << weight_clock_num);
    weight_data_ddr &= ~(0 << weight_data_num);
}

unsigned long ReadWeight(){
    weight_data_port |= (1 << weight_data_num); //set DO 1
    weight_clock_port &= ~(1 << weight_clock_num); // set CL 0

    unsigned long value = 0; //init value
    
    while((weight_data_pin & (1 << weight_data_num)) == (1 << weight_data_num)); //wait for ADDO to be 0

    for (char i=0; i<24; i++){
        weight_clock_port |= (1 << weight_clock_num); //set clock 1
        value=value<<1; //shift value up
        weight_clock_port &= ~(1 << weight_clock_num); //clock low
        if( (weight_data_pin & (1 << weight_data_num)) == (1 << weight_data_num)) value++; //read data and add to value
    }

    return ~value;
}