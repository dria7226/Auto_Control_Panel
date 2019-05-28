#ifdef WIN32
while (GetMessage(&msg, NULL, 0, 0))
{
    TranslateMessage(&msg);
    DispatchMessage(&msg);
}
#endif

//read o2 sensor


//graph o2 sensor
