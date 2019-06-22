#include "includes.c"

#ifdef WIN32
HANDLE hComm;
#endif

#ifdef UNIX
int fd;
#endif

char* port_name;

extern __declspec(dllexport) int __stdcall select_port(char* arg_port)
{
    #ifdef WIN32
    sprintf(port_name, "\\\\.\\%s",arg_port);
    #endif

    #ifdef UNIX
    sprintf(port_name, "/dev/%s", arg_port);
    #endif
    return 0;
}

extern __declspec(dllexport) int __stdcall open_rxtx_port(int arg_baudrate, int arg_parity, int arg_bytesize, int arg_stopbits)
{
    #include "Helpers/setup_port.c"
}

extern __declspec(dllexport) int __stdcall send_bytes()
{
    #include "Helpers/send_bytes.c"
}

extern __declspec(dllexport) int __stdcall receive_bytes()
{
    #include "Helpers/receive_bytes.c"
}

extern __declspec(dllexport) int _stdcall close_rxtx_port()
{
    #ifdef WIN32
    CloseHandle(hComm);
    #endif

    #ifdef UNIX
    close(fd);
    #endif
    return 0;
}
