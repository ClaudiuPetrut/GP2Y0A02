#ifndef GP2Y0A02_H
#define GP2Y0A02_H

// Used for sensor pin and adc offset initialization
void initDistanceSensor(unsigned int pinNumber, float adc_offset_);
// This function use datasheet aproximation
unsigned int getDistance1(void);
// This function use measured aproximation
unsigned int getDistance2(void);
// Get filtered distance from sensor
unsigned int getFilteredDistance(void);

#endif