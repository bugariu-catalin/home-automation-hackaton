#include "rpi.h"


int main() {
  printf("Starting rpi.\n");
  
  if (wiringPiSetup () == -1) {
    fprintf (stderr, "Error on wiringPiSetup") ;
    return 1 ;
  }
  
  //Setup pins
  pinMode (LIGHT_ON, OUTPUT) ;
  pinMode (DOOR_BELL, INPUT) ;

  if ((A_HANDLER = serialOpen (A_COM, A_BAUD)) < 0)
  {
    fprintf (stderr, "Unable to open serial device: %s to communicate with arduino\n", strerror (errno)) ;
    return 1 ;
  }
/*
  for (;;)
  {

    serialPuts (fd,s);
    putchar (serialGetchar (fd)) ;
    fflush (stdout) ;
  }
  */
   
  for (;;) {
	readSensors();
	//Read remote data
	while (serialDataAvail (fd))
    {
      printf (" -> %3d", serialGetchar (fd)) ;
      fflush (stdout) ;
    }
	saveAllStatus();
	notify();
	delay (100) ;//wait for next reading
  }

  if (A_HANDLER) {
	serialClose(A_HANDLER);
  }

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

void notify() {
	if (_Door_Bell==true) system("espeak -v ro --stdout 'E cineva la usa!' | aplay");
}

void readRemoteData() {
	while (serialDataAvail (A_HANDLER))
    {
      printf (" -> %3d", serialGetchar (A_HANDLER)) ;
      fflush (stdout) ;
    }
}

void saveAllStatus() {
	FILE * pFile;
	pFile = fopen (statusFile,"w+");
	if (pFile!=NULL) {
		if (_Light_Open==true) {
			fputs ("_Light_Open=true\n",pFile);
		} else {
			fputs ("_Light_Open=false\n",pFile);
		}
		if (_Light_Error==true) {
			fputs ("_Light_Error=true\n",pFile);
		} else {
			fputs ("_Light_Error=false\n",pFile);
		}
		if (_Sound_On==true) {
			fputs ("_Sound_On=true\n",pFile);
		} else {
			fputs ("_Sound_On=false\n",pFile);
		}
		if (_Motion_On==true) {
			fputs ("_Motion_On=true\n",pFile);
		} else {
			fputs ("_Motion_On=false\n",pFile);
		}
		if (_Door_Lock==true) {
			fputs ("_Door_Lock=true\n",pFile);
		} else {
			fputs ("_Door_Lock=false\n",pFile);
		}
		if (_Door_Bell==true) {
			fputs ("_Door_Bell=true\n",pFile);
		} else {
			fputs ("_Door_Bell=false\n",pFile);
		}
		fclose (pFile);
	}
}