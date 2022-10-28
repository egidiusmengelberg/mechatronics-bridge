// includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iomxx0_1.h>
#include <util/delay.h>

#include "config.h"
#include "weight.h"
#include "distance.h"
#include "lights.h"
#include "servo.h"
#include "motor.h"

// state flags 1=estop, 2=boat_detected, 3=barrier_lights, 4=bridge_empty
char state;

int main(void)
{
	// stop interrupts
	cli();

	// init lights
	InitLights();
	SetStandByLights(&state);

	// init buttons
	estop_ddr &= ~(0 << estop_num);
	start_ddr &= ~(0 << start_num);

	// init endstops
	endstop_open_ddr &= ~(0 << endstop_open_num);
	endstop_close_ddr &= ~(0 << endstop_close_num);
	endstop_open_port |= (1 << endstop_open_num);
	endstop_close_port |= (1 << endstop_close_num);

	// init buzzer
	buzzer_ddr |= (1 << buzzer_num);
	buzzer_port |= (1 << buzzer_num);

	// init weight sensor
	InitWeight();

	// init distance sensors
	InitDistance();

	ServoInit();
	SetServo1(-50);
	SetServo2(-50);
	// init hbridge

	// set timer4 interrupt at 2Hz
	TCCR4A = 0;								// set entire TCCR1A register to 0
	TCCR4B = 0;								// same for TCCR1B
	TCNT4 = 0;								// initialize counter value to 0
	OCR4A = 7812;							// = (16*10^6) / (1*1024) - 1 / 2 (must be <65536) set compare match register for 2hz increments
	TCCR4B |= (1 << WGM12);					// turn on CTC mode
	TCCR4B |= (1 << CS12) | (1 << CS10);	// Set CS12 and CS10 bits for 1024 prescaler
	TIMSK4 |= (1 << OCIE4A);				// enable timer compare interrupt

	sei(); // allow interrupts

	while (1)
	{
		// check for boats
		if (!(distance_1_pin & (1<<distance_1_num)))
		{

			// set lights
			SetReadyToOpenLights(&state);
			// wait until bridge is empty
			// while (ReadWeight() > empty_bridge_weight)
			// {
			// }

			// sound alarm and close barriers
			buzzer_port &= ~(1 << buzzer_num);
			_delay_ms(1000);
			for (signed char i = -50; i <= 100; i++)
			{
				SetServo1(i);
				SetServo2(i);
				_delay_ms(5);
			}
			_delay_ms(1000);
			buzzer_port |= (1 << buzzer_num);

			_delay_ms(1000);
			// open bridge till endstop
			while (endstop_open_pin & (1 << endstop_open_num))
			{
				// run motor open
				MotorRun(0);
			}

			MotorStop();
			_delay_ms(1000);
			// set waterway lights
			SetOpenedLights();
			// wait for boat to pass
			// delay for some simulated time
			_delay_ms(10000);

			// turn off waterway lights
			SetReadyToCloseLights();
			_delay_ms(1000);

			// close bridge till endstop
			while (endstop_close_pin & (1 << endstop_close_num))
			{
				MotorRun(1);
			}
			MotorStop();
			_delay_ms(1000);
			// sound alarm and open barriers
			buzzer_port &= ~(1 << buzzer_num);
			_delay_ms(1000);
			for (signed char i = 100; i >= -50; i--)
			{
				SetServo1(i);
				SetServo2(i);
				_delay_ms(5);
			}
			_delay_ms(1000);
			buzzer_port |= (1 << buzzer_num);

			// lights off
			SetStandByLights(&state);

			// boat has passed so disable state flag
			state &= ~state_boat_detected;
		}
		
	}
}

ISR(TIMER4_COMPA_vect)
{ // timer4 interrupt 1Hz
	// if estop pressed set estop bit in state
 if ((estop_pin & (1 << estop_num)) == (1 << estop_num)) {
		state |= state_estop;
 }

 if ((start_pin & (1 << start_num)) == (1 << start_num)) {
		state |= state_boat_detected;
 }

 // if boat detected set boat_detected bit in state
 if (distance_1_pin & (1<<distance_1_num)) {
    state |= state_boat_detected;
 }

 if ((distance_2_pin & (1<<distance_2_num)) == 0) {
    state |= state_boat_detected;
 }

 if(state & state_barrier_lights) {
		ToggleBarrierLights();
 } else {
	//turn off barrier lights
	barrier_led_port &= ~(0 << barrier_led_num);
 }
}
