#ifdef WIN32
BOOL  Status;
hComm = CreateFile( port_name,                  // Name of the Port to be Opened
                    GENERIC_READ | GENERIC_WRITE, // Read/Write Access
                    0,                            // No Sharing, ports cant be shared
                    NULL,                         // No Security
                    OPEN_EXISTING,                // Open existing port only
                    0,                            // Non Overlapped I/O
                    NULL);                        // Null for Comm Devices

if (hComm == INVALID_HANDLE_VALUE) return 1;
#endif

#ifdef UNIX
fd = open(port_name,O_RDWR | O_NOCTTY);	/* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
                    /* O_RDWR   - Read/Write access to serial port       */
                    /* O_NOCTTY - No terminal will control the process   */
                    /* Open in blocking mode,read will wait              */

if(fd == -1) return 1;
#endif
