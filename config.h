#include <avr/io.h>
#include <avr/iomxx0_1.h>

// config

// leds
#define barrier_led_port PORTA
#define barrier_led_pin PINA
#define barrier_led_ddr DDRA
#define barrier_led_num 0 // D22

#define boat_red_led_port PORTA
#define boat_red_led_pin PINA
#define boat_red_led_ddr DDRA
#define boat_red_led_num 0 // D22

#define boat_green_led_port PORTA
#define boat_green_led_pin PINA
#define boat_green_led_ddr DDRA
#define boat_green_led_num 0 // D22

// weight sensor
#define weight_data_port PORTA
#define weight_data_pin PINA
#define weight_data_ddr DDRA
#define weight_data_num 0 // D22

#define weight_clock_port PORTA
#define weight_clock_pin PINA
#define weight_clock_ddr DDRA
#define weight_clock_num 1 // D23

// distance sensors
#define distance_1_port PORTK
#define distance_1_pin PINK
#define distance_1_ddr DDRK
#define distance_1_num 0 // A8

#define distance_2_port PORTK
#define distance_2_pin PINK
#define distance_2_ddr DDRK
#define distance_2_num 1 // A9

// buttons
#define estop_port PORTF
#define estop_pin PINF
#define estop_ddr DDRF
#define estop_num 1 // A1

#define start_port PORTF
#define start_pin PINF
#define start_ddr DDRF
#define start_num 2 // A2

// endstops
#define endstop_open_port PORTF
#define endstop_open_pin PINF
#define endstop_open_ddr DDRF
#define endstop_open_num 1

#define endstop_close_port PORTF
#define endstop_close_pin PINF
#define endstop_close_ddr DDRF
#define endstop_close_num 1

// buzzer
#define buzzer_port PORTE
#define buzzer_pin PINE
#define buzzer_ddr DDRE
#define buzzer_num 5 // D3

// motor
#define motor_l_port PORTE
#define motor_l_pin PINE
#define motor_l_ddr DDRF
#define motor_l_num 5 // D3

#define motor_r_port PORTE
#define motor_r_pin PINE
#define motor_r_ddr DDRF
#define motor_r_num 5 // D3

// settings
#define empty_bridge_weight 1000000UL
#define boat_seen_distance 500

#define state_estop 0x01
#define state_boat_detected 0x02
#define state_barrier_lights 0x04
#define state_bridge_empty 0x08
#define BOOL5 0x10
#define BOOL6 0x20
#define BOOL7 0x40
#define BOOL8 0x80