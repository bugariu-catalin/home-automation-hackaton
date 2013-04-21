#include "rpi.h"

char remoteCmd[250] = "";

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

   lightOn();
  for (;;) {
	readSensors();
	readRemoteData();
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
	if (_Door_Bell==true) {
   		lightOn();
		delay(500);
		lightOff();
	}
}

void notify() {
	if (_Door_Bell==true) system("espeak -v ro --stdout 'E cineva la usa!' | aplay");
}

void readRemoteData() {
	char buffer[250] = "";
	char cmd[] = "";
	char data[] = "";
	char * tmp;
	int i = 0;
	strcpy(remoteCmd, "");
	while (serialDataAvail (A_HANDLER)) {
	  snprintf(buffer, sizeof(buffer), "%s%c", remoteCmd, serialGetchar (A_HANDLER));
	  strcpy(remoteCmd, buffer);
      }
      strcpy(buffer, "");

	
	if (strlen(remoteCmd) == 0) return;

	if (strncmp(remoteCmd,"RFID_AUTH=006AB71484", sizeof("RFID_AUTH=006AB71484")) == 0) {
		printf ("found %s\n", remoteCmd);
	} else {
		printf ("unknown %s\n", remoteCmd);
	}
	system("espeak --stdout 'Access denied!' | aplay");
		
/*
//	strcpy(remoteCmd, "");
	printf ("cmd=%s\ndata=%s\n", cmd, data) ;	
	
	//process known commands
	if (strncmp(cmd,"RFID_AUTH", sizeof(cmd)) == 0) {
		if (strncmp(data,"006AB71484", sizeof(data)) == 0) {
			//allow
			printf("allow\n");
		} else {
			//deny
			printf("deny\n");
		}
	} else {
              printf("UK com [%s][%s]",cmd,data);
        }
	

	
	strcpy(cmd, "");
	strcpy(data, "");*/
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

