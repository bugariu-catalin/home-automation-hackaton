#include "rpi.h"


int main ()
{
  if (wiringPiSetup () == -1) {
    fprintf (stderr, "Error on wiringPiSetup") ;
    return 1 ;
  }
  
  //Setup pins
  pinMode (LIGHT_ON, OUTPUT) ;
  saveAllStatus();
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
   
  
for (;;)
  {
 lightOn();   
 delay (500) ;		// mS
    lightOff();
    delay (500) ;
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

bool getLightOn() {
	return _Light_Open;
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
		fclose (pFile);
	}
}