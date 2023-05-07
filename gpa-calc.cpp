#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int grade, classload, i, row, col;
	int gsum = 0;

	initscr();
	raw();
	getmaxyx(stdscr, row, col);
	
	mvprintw(0, 0, "Enter single-digit number of classes: ");
	classload = getch();	
	while (classload > 57 or classload < 48) {
		mvprintw(10, 0, "Invalid");
		refresh();
		mvprintw(10, 0, "       ");
		move(0, 38);
		classload = getch();
		
	}
	mvprintw(1, 0, "Enter grades: ");

	for (i = 1; i < (classload - 48) + 1; i++) {
		move(i, 15);
		grade = getch(); 
		switch(grade) {
			case 65 :
				mvprintw(i, 20, "4.0");
				gsum += 4;
				break;
			case 66 :
                        	mvprintw(i, 20, "3.0");
				gsum += 3;
                        	break;
			case 67 :
                        	mvprintw(i, 20, "2.0");
				gsum += 2;
   	                     	break;
			case 68 :
                        	mvprintw(i, 20, "1.0");
				gsum += 1;
				break;
                	case 70 :
				mvprintw(i, 20, "0.0");
				gsum += 0;
				break;
			default :
				mvprintw(i, 20, "Invalid");
				refresh();
				mvprintw(i, 20, "       ");
				move(i, 20);
				i -= 1;
				break;
		}
	}
	mvprintw(row/2, col/2,"%d", gsum);
	refresh();
	getch();
	endwin();
}
