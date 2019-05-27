LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch(msg) {

        case WM_PAINT:

            hdc = BeginPaint(hwnd, &ps);

            MoveToEx(hdc, 50, 50, NULL);
            LineTo(hdc, 250, 50);

            HPEN hWhitePen = GetStockObject(WHITE_PEN);
            HPEN hOldPen = SelectObject(hdc, hWhitePen);

            MoveToEx(hdc, 50, 100, NULL);
            LineTo(hdc, 250, 100);

            SelectObject(hdc, hOldPen);

            EndPaint(hwnd, &ps);
            break;

        case WM_DESTROY:

            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
