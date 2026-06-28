#include "Cursor_Switch.hpp"

void* handle;
CONSOLE_CURSOR_INFO CursorInfo;

void LoadCursorInfo()
{
    handle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(handle, &CursorInfo);
}

void CursorOn()
{
    CursorInfo.bVisible = TRUE;
    SetConsoleCursorInfo(handle, &CursorInfo);
}

void CursorOff()
{
    CursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(handle, &CursorInfo);
}