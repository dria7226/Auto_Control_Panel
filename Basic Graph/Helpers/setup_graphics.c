#ifdef WIN32
MSG  msg;
WNDCLASSW wc = {0};

wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpszClassName = L"Lines";
wc.hInstance     = hInstance;
wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
wc.lpfnWndProc   = WndProc;
wc.hCursor       = LoadCursor(0, IDC_ARROW);

RegisterClassW(&wc);
CreateWindowW(wc.lpszClassName, L"O2 Monitor",
      WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      100, 100, 300, 200, NULL, NULL, hInstance, NULL);

#endif
