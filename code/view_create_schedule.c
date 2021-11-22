#include "view_create_schedule.h"

void V_VIEW_CREATE_SCHEDULE_SUBJECTCNT(int times) {
	gotoxy(TOTAL_VIEW_COL / 2 - 7, 15 + times);
	printf("%s", "과목 수를 입력하세요 : ");
}

void V_VIEW_CREATE_SCHEDULE_SUBJECTINFO(char* data, int times) {
	gotoxy(TOTAL_VIEW_COL / 2 - 7, 15 + times);
	printf("%s : ", data);
}