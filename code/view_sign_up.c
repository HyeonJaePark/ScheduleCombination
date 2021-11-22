#include "view_sign_up.h"

void V_VIEW_SIGN_UP_MENU(char* data, int times){
	gotoxy(TOTAL_VIEW_COL / 2 - 7, 15 + times);
	printf("%s : ", data);
}