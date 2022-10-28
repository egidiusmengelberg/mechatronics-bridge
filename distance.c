#include <avr/io.h>
#include <avr/iomxx0_1.h>
#include "config.h"

void InitDistance(void) {
    //set sensor pins both as input
    distance_1_ddr &= ~(1 << distance_1_num);
    distance_2_ddr &= ~(1 << distance_2_num);
}