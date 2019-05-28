LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch(msg) {

        case WM_PAINT:

            hdc = BeginPaint(hwnd, &ps);
            SelectObject(hdc, GetStockObject(DC_PEN));
            SelectObject(hdc, GetStockObject(DC_BRUSH));
            SetDCBrushColor(hdc, RGB(0,0,0));

            //boxes
            SetDCPenColor(hdc, RGB(0,255,0));
            Rectangle(hdc, 50, 100, 450, 100+400);
            Rectangle(hdc, 50 + 500, 100, 450 + 500, 100+400);
            MoveToEx(hdc, 50, 200, NULL);
            LineTo(hdc, 450, 200);
            MoveToEx(hdc, 50, 400, NULL);
            LineTo(hdc, 450 + 500, 400);
            MoveToEx(hdc, 550, 200, NULL);
            LineTo(hdc, 450 + 500, 200);

            SetDCPenColor(hdc, RGB(255,255,255));
            wchar_t* text = L"Sensor 1";
            TextOutW(hdc, 50, 70, text, lstrlenW(text));
            text = L"Sensor 2";
            TextOutW(hdc, 50 + 500, 70, text, lstrlenW(text));
            text = L"0.55V";
            TextOutW(hdc, 10, 190, text, lstrlenW(text));
            text = L"0.4V";
            TextOutW(hdc, 10, 390, text, lstrlenW(text));
            text = L"0.5V";
            TextOutW(hdc, 515, 190, text, lstrlenW(text));

            int sensor_id;
            for(sensor_id = 0; sensor_id < 2; sensor_id++)
            {
                //line graph
                MoveToEx(hdc, 50 + 500*sensor_id, 500, NULL);
                int data_point;
                for(data_point = 0; data_point < MAX_DATA_POINTS; data_point++)
                {
                    LineTo(hdc, 50 + (int)data_point/MAX_DATA_POINTS*400 + 500*sensor_id, 500 - sensor_readings[sensor_id][data_point]);
                }
            }

            EndPaint(hwnd, &ps);
            break;

        #define DELAY (int)1000/960*2
        case WM_INITDIALOG:
           SetTimer( hwnd, DELAY, DELAY, NULL );
           break;

        case WM_TIMER:
           if( wParam == DELAY )
           {
               InvalidateRect( hwnd, NULL, FALSE );   // invalidate whole window
           }
           break;

        case WM_MOUSEMOVE:
            if(i >= MAX_DATA_POINTS) i = 0;

            sensor_readings[0][i] = GET_X_LPARAM(lParam);;
            sensor_readings[1][i] = GET_Y_LPARAM(lParam);;

            i++;
            break;

        case WM_DESTROY:

            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
