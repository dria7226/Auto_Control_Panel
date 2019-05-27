#ifdef WIN32
HANDLE hComm;                          // Handle to the Serial port
BOOL  Status;                          // Status of the various operations
DWORD dwEventMask;                     // Event mask to trigger
char  TempChar;                        // Temperory Character
char  SerialBuffer[256];               // Buffer Containing Rxed Data
DWORD NoBytesRead;                     // Bytes read by ReadFile()
int i = 0;
char port_name[] = "\\\\.\\COM24";
#endif
#ifdef UNIX
int fd;
char port_name[] = "/dev/ttyUSB0";
#endif

#include "open_rxtx_port.c"

#include "set_serial_parameters_and_timeouts.c"
