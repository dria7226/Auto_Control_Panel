#ifdef WIN32
MSG  msg;
WNDCLASSW wc = {0};

wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpszClassName = L"O2 Monitor";
wc.hInstance     = hInstance;
wc.hbrBackground = CreateSolidBrush(RGB(0,0,0));
wc.lpfnWndProc   = WndProc;
wc.hCursor       = LoadCursor(0, IDC_ARROW);

RegisterClassW(&wc);
CreateWindowW(wc.lpszClassName, L"O2 Monitor",
      WS_OVERLAPPEDWINDOW | WS_VISIBLE,
      100, 100, 1025, 600, NULL, NULL, hInstance, NULL);

#endif
