#include <iostream>
#include <array>

/*
This module simulate the class Sensor contained in led.h, since we can't connect a led to our laptop
*/

void debug(char* s)
{
    printf("%s", s);
}

void info(const char* s)
{
    printf("%s", s);
}

void error(const char* s)
{
    printf("%s", s);
}


std::array<std::string, 4> simulatedLed = {"BLUE LED","YELLOW LED","YELLOW LED","GREEN LED"};

void interaction(int ledIndex,int ledIndexOld){
    std::cout << "Turned off " << simulatedLed[ledIndexOld] << std::endl;
    std::cout << simulatedLed[ledIndex] << " ON" << std::endl;
}