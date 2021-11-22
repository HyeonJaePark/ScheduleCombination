#include "view_main.h"

void V_SET_MAIN_VIEW(){
	INIT_PAGE();
}

void V_VIEW_MAIN_WELCOME(){
	printf("\n\n\n\n");
	printf("\t\t\t\t_________ ___   __   __  _______    _______  _______  _______  ___      _______ \n");
	printf("\t\t\t\t|       ||   | |  |_|  ||       |  |       ||   _   ||  _    ||   |    |       |\n");
	printf("\t\t\t\t|_     _||   | |       ||    ___|  |_     _||  |_|  || |_|   ||   |    |    ___|\n");
	printf("\t\t\t\t  |   |  |   | |       ||   |___     |   |  |       ||       ||   |    |   |___ \n");
	printf("\t\t\t\t  |   |  |   | |       ||    ___|    |   |  |       ||  _   | |   |___ |    ___|\n");
	printf("\t\t\t\t  |   |  |   | | ||_|| ||   |___     |   |  |   _   || |_|   ||       ||   |___ \n");
	printf("\t\t\t\t  |___|  |___| |_|   |_||_______|    |___|  |__| |__||_______||_______||_______|\n");
	printf("\n");
}

void V_VIEW_MAIN_MENU(char** data, size_t menuCnt, int selectedID){
	ColorKinds colorkinds;
	//COLORSET(red, white);
	gotoxy(TOTAL_VIEW_COL / 2 - 7, 15);
	for(int i = 0; i < menuCnt; i++){
		if(i == selectedID){
			COLORSET(brightRed, white);
		}
		else{
			COLORSET(black, white);
		}
		printf("%d. %s", i + 1, data[i]);
		gotoxy(TOTAL_VIEW_COL / 2 - 7, 15 + i + 1);
	}
}