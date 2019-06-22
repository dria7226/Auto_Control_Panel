select_port = external_define("serial.dll", "select_port", dll_stdcall, ty_real, 1, ty_string);
open_rxtx_port = external_define("serial.dll", "open_rxtx_port", dll_stdcall, ty_real, 4, ty_real, ty_real, ty_real, ty_real);
send_bytes = external_define("serial.dll", "send_bytes", dll_stdcall, ty_real, 0);
receive_bytes = external_define("serial.dll", "receive_bytes", dll_stdcall, ty_real, 0);
close_rxtx_port = external_define("serial.dll", "close_rxtx_port", dll_stdcall,ty_real, 0);