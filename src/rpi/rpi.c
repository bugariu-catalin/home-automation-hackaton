#include "rpi.h"


int main ()
{
  if (wiringPiSetup () == -1) {
    fprintf (stderr, "Error on wiringPiSetup") ;
    return 1 ;
  }
  
  //Setup pins
  pinMode (LIGHT_ON, OUTPUT) ;
  pinMode (DOOR_BELL, INPUT) ;
  /*
  if ((A_HANDLER = serialOpen (A_COM, A_BAUD)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s to communicate with arduino\n", strerror (errno)) ;
    return 1 ;
  }

  for (;;)
  {

    serialPuts (fd,s);
    putchar (serialGetchar (fd)) ;
    fflush (stdout) ;
  }
  
  if (A_HANDLER) {
	serialClose(A_HANDLER);
  }*/
   
  notify();
  /*
  for (;;) {
	readSensors();
	saveAllStatus();
	notify();
	delay (1000) ;//wait for next reading
  } */
  
  return 0;
}

void lightOn() {
	_Light_Open = true;
	digitalWrite(LIGHT_ON, 1);
}

void lightOff() {
	_Light_Open = false;
	digitalWrite(LIGHT_ON, 0);
}

void readSensors() {
	if (digitalRead(DOOR_BELL)==0) _Door_Bell = true; else _Door_Bell = false;
}

bool getLightOn() {
	return _Light_Open;
}

void notify() {
	//if (_Door_Bell) {
		char *args[] = {"-v", "ro", "--stdout", "'E cineva la usa'", "|", "aplay", NULL };
		execv("espeak", args);
	//}
}

void saveAllStatus() {
	FILE * pFile;
	pFile = fopen (statusFile,"w+");
	if (pFile!=NULL) {
		if (getLightOn) {
			fputs ("_Light_Open=true",pFile);
		} else {
			fputs ("_Light_Open=false",pFile);
		}
		if (_Light_Error) {
			fputs ("_Light_Error=true",pFile);
		} else {
			fputs ("_Light_Error=false",pFile);
		}
		if (_Sound_On) {
			fputs ("_Sound_On=true",pFile);
		} else {
			fputs ("_Sound_On=false",pFile);
		}
		if (_Motion_On) {
			fputs ("_Motion_On=true",pFile);
		} else {
			fputs ("_Motion_On=false",pFile);
		}
		if (_Door_Lock) {
			fputs ("_Door_Lock=true",pFile);
		} else {
			fputs ("_Door_Lock=false",pFile);
		}
		if (_Door_Bell) {
			fputs ("_Door_Bell=true",pFile);
		} else {
			fputs ("_Door_Bell=false",pFile);
		}
		fclose (pFile);
	}
}