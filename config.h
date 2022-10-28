#include <avr/io.h>
#include <avr/iomxx0_1.h>

// config

// leds
#define barrier_led_port PORTA
#define barrier_led_pin PINA
#define barrier_led_ddr DDRA
#define barrier_led_num 7 // D29

#define boat_red_led_port PORTA
#define boat_red_led_pin PINA
#define boat_red_led_ddr DDRA
#define boat_red_led_num 3 // D25

#define boat_red_led_port2 PORTA
#define boat_red_led_pin2 PINA
#define boat_red_led_ddr2 DDRA
#define boat_red_led_num2 5 // D27

#define boat_green_led_port PORTC
#define boat_green_led_pin PINC
#define boat_green_led_ddr DDRC
#define boat_green_led_num 4 // D33

#define boat_green_led_port2 PORTC
#define boat_green_led_pin2 PINC
#define boat_green_led_ddr2 DDRC
#define boat_green_led_num2 6 // D31

// weight sensor
#define weight_data_port PORTG
#define weight_data_pin PING
#define weight_data_ddr DDRG
#define weight_data_num 0 // D41

#define weight_clock_port PORTG
#define weight_clock_pin PING
#define weight_clock_ddr DDRG
#define weight_clock_num 1 // D40

// distance sensors
#define distance_1_port PORTD
#define distance_1_pin PIND
#define distance_1_ddr DDRD
#define distance_1_num 7 // D38

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
#define endstop_open_port PORTB
#define endstop_open_pin PINB
#define endstop_open_ddr DDRB
#define endstop_open_num 0 //D53

#define endstop_close_port PORTB
#define endstop_close_pin PINB
#define endstop_close_ddr DDRB
#define endstop_close_num 2 //D51

// buzzer
#define buzzer_port PORTE
#define buzzer_pin PINE
#define buzzer_ddr DDRE
#define buzzer_num 5 // D3

// motor
#define motor_l_port PORTB
#define motor_l_pin PINB
#define motor_l_ddr DDRB
#define motor_l_num 1 // D52

#define motor_r_port PORTB
#define motor_r_pin PINB
#define motor_r_ddr DDRB
#define motor_r_num 3 // D50

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