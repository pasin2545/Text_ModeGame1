#include<stdio.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void del(int x, int y) {
	gotoxy(x, y);
	printf("       ");
}
void draw_ship(int x, int y) {
	x = max(x,0);
	y = max(y,0);
	x = min(x,80);
	y = min(y,25);
	gotoxy(x, y);
	printf("<-0->");
}
int main()
{
	char ch = ' ';
	int x=0, y=20;
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { 
				del(x, y);
				draw_ship(--x, y);
			}
			if (ch == 'd') { 
				del(x, y);
				draw_ship(++x, y); 
			}
			if (ch == 's') {
				del(x, y);
				draw_ship(x, ++y);
			}
			if (ch == 'w') {
				del(x, y);
				draw_ship(x, --y);
			}
			fflush(stdin);
		}
		Sleep(500);
	} 
	while (ch != 'x');
	return 0;
}