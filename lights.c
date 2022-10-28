#include "config.h"
#include <avr/io.h>
#include <avr/iomxx0_1.h>

void InitLights() {
    //pins as output and turn to standby
    barrier_led_ddr |= (1 << barrier_led_num);
    boat_red_led_ddr |= (1 << boat_red_led_num);
    boat_green_led_ddr |= (1 << boat_green_led_num);
    boat_red_led_ddr2 |= (1 << boat_red_led_num2);
    boat_green_led_ddr2 |= (1 << boat_green_led_num2);
}

void ToggleBarrierLights() {
    //invert barrier lights
    barrier_led_port ^= (1 << barrier_led_num);
}

void SetReadyToOpenLights(char* state) {
    //red and green water lights
    boat_red_led_port |= (1 << boat_red_led_num);
    boat_green_led_port |= (1 << boat_green_led_num);
    boat_red_led_port2 |= (1 << boat_red_led_num2);
    boat_green_led_port2 |= (1 << boat_green_led_num2);
    //start barrier lights
    *state |= state_barrier_lights;
}

void SetOpenedLights() {
    //on green off red
    boat_red_led_port &= ~(1 << boat_red_led_num);
    boat_red_led_port2 &= ~(1 << boat_red_led_num2);
    boat_green_led_port |= (1 << boat_green_led_num);
    boat_green_led_port2 |= (1 << boat_green_led_num2);
}

void SetReadyToCloseLights() {
    //red and green water lights
    boat_red_led_port |= (1 << boat_red_led_num);
    boat_green_led_port |= (1 << boat_green_led_num);
    boat_red_led_port2 |= (1 << boat_red_led_num2);
    boat_green_led_port2 |= (1 << boat_green_led_num2);
}

void SetStandByLights(char* state) {
    //red water lights
    boat_red_led_port |= (1 << boat_red_led_num);
    boat_green_led_port &= ~(1 << boat_green_led_num);
    boat_red_led_port2 |= (1 << boat_red_led_num2);
    boat_green_led_port2 &= ~(1 << boat_green_led_num2);
    //turn off barrier lights
    *state &= ~state_barrier_lights; 
    barrier_led_port &= ~(1 << barrier_led_num); 
}