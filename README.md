# PDCursesTest
My Code and procedures for using PDCurses:

https://github.com/wmcbrine/PDCurses

Info on Curses:
https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ref.html
http://www.ibiblio.org/pub/Linux/docs/HOWTO/other-formats/pdf/NCURSES-Programming-HOWTO.pdf
https://invisible-island.net/ncurses/ncurses-intro.html
https://rabbitboots.com/blog/2016/11/02/pdcurses/


Build PDCurses library using x86 Native Tools Command Prompt for VS 2022:
![image](https://github.com/user-attachments/assets/7e2e5efc-eb37-4741-b23a-d91d3c9019cc)

To Use:
Add pdcurse.lib to VS project

![image](https://github.com/user-attachments/assets/963cc9cb-479b-46b9-921b-6beed88667f8)

add ```#include "curses.h"```
to main source file

Temp Leave Curses:

```c
addstr("Shelling out...");
def_prog_mode();           /* save current tty modes */
endwin();                  /* restore original tty modes */
system("sh");              /* run shell */
printf("stuff");
addstr("returned.\n");     /* prepare return message */
refresh();                 /* restore save modes, repaint screen */
```
