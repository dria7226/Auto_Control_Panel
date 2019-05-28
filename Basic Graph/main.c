#include "includes.c"

int i = 0;
#define MAX_DATA_POINTS 200
unsigned char sensor_readings[2][MAX_DATA_POINTS];

#ifdef WIN32
#include "Helpers/wnd_proc.c"
#endif

#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif
#ifdef UNIX
int main()
#endif
{
    #include "setup.c"

    #include "loop.c"

    #ifdef WIN32
    CloseHandle(hComm); return (int) msg.wParam;
    #endif
    #ifdef UNIX
    close(fd); return 0;
    #endif
}
