gcc -c main.c -o serial.o
gcc -shared -o serial.dll serial.o
