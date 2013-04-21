//define arduino comunication params
char *A_COM = "/dev/ttyACM0";
int   A_BAUD = 9600;
int   A_HANDLER;

//Status
char *statusFile = "/home/pi/.all_status";
bool _Door_Open = false;
bool _Door_Bell = false;
bool _Door_Lock = false;

bool _Light_Open = false;
bool _Light_Error = false;
	
bool _Sound_On = true;
bool _Motion_On = true;
	
//Pins
#define	LIGHT_ON 4 //GPIO23
#define DOOR_BELL 8 //GPIO2

//AUTH keys
const char *keys[1];
keys[0] = "006AB71484";