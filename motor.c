#include "config.h"

void MotorInit() {
    //set motor pins as outputs
    motor_l_ddr |= (1 << motor_l_num);
    motor_r_ddr |= (1 << motor_r_num);

    //turn motor off
    motor_l_port &= ~(1 << motor_l_num);
    motor_r_port &= ~(1 << motor_r_num);
}

void MotorRun(char dir) {
    //start motor based on direction input
    if (dir > 0) {
        motor_l_port |= (1 << motor_l_num);
        motor_r_port &= ~(1 << motor_r_num);
    } else {
        motor_l_port &= ~(1 << motor_l_num);
        motor_r_port |= (1 << motor_r_num);
    }
}

void MotorStop() {
    //stop motor
    motor_l_port &= ~(1 << motor_l_num);
    motor_r_port &= ~(1 << motor_r_num);
}