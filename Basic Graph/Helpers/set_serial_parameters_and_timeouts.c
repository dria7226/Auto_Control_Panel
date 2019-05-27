#ifdef WIN32
DCB dcbSerialParams = { 0 };                         // Initializing DCB structure
dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

Status = GetCommState(hComm, &dcbSerialParams);      //retreives  the current settings

if (Status == FALSE)
    printf("\n    Error! in GetCommState()");

dcbSerialParams.BaudRate = CBR_9600;      // Setting BaudRate = 9600
dcbSerialParams.ByteSize = 8;             // Setting ByteSize = 8
dcbSerialParams.Parity = NOPARITY;        // Setting Parity = None
dcbSerialParams.StopBits = ONESTOPBIT;    // Setting StopBits = 1

Status = SetCommState(hComm, &dcbSerialParams);  //Configuring the port according to settings in DCB

if (Status == FALSE)
{
    printf("\n    Error! in Setting DCB Structure");
}
else //If Successfull display the contents of the DCB Structure
{
    printf("\n\n    Setting DCB Structure Successfull\n");
    printf("\n       Baudrate = %d", dcbSerialParams.BaudRate);
    printf("\n       ByteSize = %d", dcbSerialParams.ByteSize);
    printf("\n       StopBits = %d", dcbSerialParams.StopBits);
    printf("\n       Parity   = %d", dcbSerialParams.Parity);
}

Status = SetCommMask(hComm, EV_RXCHAR); //Configure Windows to Monitor the serial device for Character Reception

if (Status == FALSE)
    printf("\n\n    Error! in Setting CommMask");
else
    printf("\n\n    Setting CommMask successfull");

COMMTIMEOUTS timeouts = { 0 };
timeouts.ReadIntervalTimeout         = 50;
timeouts.ReadTotalTimeoutConstant    = 50;
timeouts.ReadTotalTimeoutMultiplier  = 10;
timeouts.WriteTotalTimeoutConstant   = 50;
timeouts.WriteTotalTimeoutMultiplier = 10;

if (SetCommTimeouts(hComm, &timeouts) == FALSE)
    printf("\n\n    Error! in Setting Time Outs");
else
    printf("\n\n    Setting Serial Port Timeouts Successfull");
#endif

#ifdef UNIX
struct termios SerialPortSettings;	/* Create the structure                          */

tcgetattr(fd, &SerialPortSettings);	/* Get the current attributes of the Serial port */

/* Setting the Baud rate */
cfsetispeed(&SerialPortSettings,B9600); /* Set Read  Speed as 9600                       */
cfsetospeed(&SerialPortSettings,B9600); /* Set Write Speed as 9600                       */

/* 8N1 Mode */
SerialPortSettings.c_cflag &= ~PARENB;   /* Disables the Parity Enable bit(PARENB),So No Parity   */
SerialPortSettings.c_cflag &= ~CSTOPB;   /* CSTOPB = 2 Stop bits,here it is cleared so 1 Stop bit */
SerialPortSettings.c_cflag &= ~CSIZE;	 /* Clears the mask for setting the data size             */
SerialPortSettings.c_cflag |=  CS8;      /* Set the data bits = 8                                 */

SerialPortSettings.c_cflag &= ~CRTSCTS;       /* No Hardware flow Control                         */
SerialPortSettings.c_cflag |= CREAD | CLOCAL; /* Enable receiver,Ignore Modem Control lines       */


SerialPortSettings.c_iflag &= ~(IXON | IXOFF | IXANY);          /* Disable XON/XOFF flow control both i/p and o/p */
SerialPortSettings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  /* Non Cannonical mode                            */

SerialPortSettings.c_oflag &= ~OPOST;/*No Output Processing*/

/* Setting Time outs */
SerialPortSettings.c_cc[VMIN] = 10; /* Read at least 10 characters */
SerialPortSettings.c_cc[VTIME] = 0; /* Wait indefinetly   */


if((tcsetattr(fd,TCSANOW,&SerialPortSettings)) != 0) /* Set the attributes to the termios structure*/
    printf("\n  ERROR ! in Setting attributes");
else
    printf("\n  BaudRate = 9600 \n  StopBits = 1 \n  Parity   = none");
#endif
