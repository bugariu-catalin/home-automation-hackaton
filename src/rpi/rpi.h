#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#include <wiringSerial.h>
#include <wiringPi.h>

#include "config.h"

void lightOn();
void lightOff();
bool getLightOn();
void saveAllStatus();