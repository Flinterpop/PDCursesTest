
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


#include "curses.h"

#include "stdio.h"
#include "string.h"

#include "synchapi.h"

int ch;

HANDLE ptrTimerHandleSendAircraft;

int r = 0;
void __stdcall TimerCallbackUpdateAircraft(PVOID, BOOLEAN)//(PVOID lpParameter, BOOLEAN TimerOrWaitFired)
{
	clear();
	move(r, r++);    /* moves the cursor to rowth row and colth column */

	printw("In Timer Big string which i didn't care to type fully ");
	refresh();
}



int main()
{

	initscr();			/* Start curses mode 		*/

	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */
	start_color();			/* Start color functionality	*/

	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	const int UPDATE_INTERVAL = 1000; //this is ms //update Aircraft once per second
	CreateTimerQueueTimer(&ptrTimerHandleSendAircraft, NULL, TimerCallbackUpdateAircraft, NULL, 500, UPDATE_INTERVAL, WT_EXECUTEDEFAULT);


	printw("A Big string which i didn't care to type fully ");

	bool bRun = true;
	while (bRun == true)
	{
		int col, row;
		getyx(stdscr, row, col);		/* get the number of rows and columns */
		move(row + 1, 0);    /* moves the cursor to rowth row and colth column */

		printw("asdfasdasdasdddddddddddddddddddddddddddddddA Big string which i didn't care to type fully ");


		getyx(stdscr, row, col);		/* get the number of rows and columns */
		move(row + 1, col);    /* moves the cursor to rowth row and colth column */

		ch = getch();			/* If raw() hadn't been called
						 * we have to press enter before it
						 * gets to the program 		*/
		if (ch == KEY_F(1))		/* Without keypad enabled this will */
			printw("F1 Key pressed");/*  not get to us either	*/
		if (ch == KEY_F(2)) bRun = false;
		/* Without noecho() some ugly escape
		 * charachters might have been printed
		 * on screen			*/
		else
		{
			printw("The pressed key is ");
			attron(A_BOLD | A_UNDERLINE);
			printw("%c", ch);
			attroff(A_BOLD | A_UNDERLINE);
		}
		refresh();			/* Print it on to the real screen */
		//Sleep(2000);
	}

	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
}