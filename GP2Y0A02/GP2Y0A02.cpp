#include <Arduino.h>
#include <GP2Y0A02.h>

uint16_t adc_value;
float voltage, voltage2, voltage3, voltage4, distance;
float ADC_OFFSET = 0.06;
unsigned int pinSensor, previousDistance = 0;

void initDistanceSensor(unsigned int pinNumber, float adc_offset_)
{
    pinMode(pinNumber, INPUT);
    pinSensor = pinNumber;
    ADC_OFFSET = adc_offset_;
}

unsigned int getDistance1(void)
{
    adc_value = analogRead(pinSensor);
    // 0.06 is ADC offset - you can adjust this value
    voltage = adc_value * 5.0 / 1023.0 + 0.06;
    voltage2 = voltage * voltage;
    voltage3 = voltage2 * voltage;
    voltage4 = voltage3 * voltage;
    // Datasheet polynom
    distance = 14.941 * voltage4 - 122.14 * voltage3 + 367.68 * voltage2 - 503.59 * voltage + 305.34;

    return (uint16_t)distance;
}

unsigned int getDistance2(void)
{
    adc_value = analogRead(pinSensor);
    // 0.06 is ADC offset - you can adjust this value
    voltage = adc_value * 5.0 / 1023.0 + 0.06;
    voltage2 = voltage * voltage;
    voltage3 = voltage2 * voltage;
    voltage4 = voltage3 * voltage;
    // Measured polynom
    distance = 22.053 * voltage4 - 158.81 * voltage3 + 416.79 * voltage2 - 496.55 * voltage + 269.31;

    return (uint16_t)distance;
}

unsigned int getFilteredDistance(void)
{
    previousDistance = previousDistance * 0.8 + distance * 0.2;
    return previousDistance;
}
