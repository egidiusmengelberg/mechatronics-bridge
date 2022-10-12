#include <avr/io.h>
#include <avr/iomxx0_1.h>

void InitDistance(void) {
    ADCSRA = 0b10000111;
}

unsigned int readDistance1(void){
    ADMUX = 0b01100110;
    ADCSRA = ADCSRA | (1 << ADSC);	
	while(ADCSRA & (1 << ADSC));
    return ADCH
}

unsigned int readDistance2(void){
    ADMUX = 0b01100111;
    ADCSRA = ADCSRA | (1 << ADSC);	
	while(ADCSRA & (1 << ADSC));
    return ADCH
}