#ifndef TYPE_H
#define TYPE_H

#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cctype>

#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#endif

typedef unsigned char byte, uchar;
typedef unsigned int uint;
typedef short int sint;
typedef unsigned long ulong;
typedef long double Ldbl;

#define _L(x) ((Ldbl)*(x))
#define _(x) *(x)
#define PI 3.14159265358979323846

template<class T>
void swap(T *px, T *py)
{
    T tmp = *px;
    *px = *py;
    *py = tmp;
}

inline char GETCH()
{
#ifdef _WIN32
    return toupper(_getch());
#else
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return toupper(ch);
#endif
}

#endif
