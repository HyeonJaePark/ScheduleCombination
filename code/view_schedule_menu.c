#include "view_schedule_menu.h"

void V_VIEW_SCHEDULE_MENU(char** data, size_t menuCnt, int selectedID) {
	ColorKinds colorkinds;
	COLORSET(red, white);
	gotoxy(TOTAL_VIEW_COL / 2 - 7, 15);
	for (int i = 0; i < menuCnt; i++) {
		if (i == selectedID) {
			COLORSET(brightRed, white);
		}
		else {
			COLORSET(black, white);
		}
		printf("%d. %s", i + 1, data[i]);
		gotoxy(TOTAL_VIEW_COL / 2 - 7, 15 + i + 1);
	}
}