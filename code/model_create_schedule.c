#include "model_create_schedule.h"

void F_CREATE_SCHEDULE_RUN(struct SubjectInfo* subjectinfo, int subjectCnt, SignIn* signin) {
	FILE* file;
	char filename[20];
	sprintf(filename, "%s.html", signin->StudentID);
	if ((file = fopen(filename, "r")) != NULL) // 이미 파일이 존재할 경우 
	{
		file = fopen(filename, "w+"); // 파일을 다시 생성
		fclose(file);
	}
	
	int* arr = (int*)malloc(subjectCnt * sizeof(int)); // 과목수만큼 배열 동적할당
	for (int i = 0; i < subjectCnt; i++)
	{
		arr[i] = i; 
	}
	for (int i = 4; i <= subjectCnt; i++) // 최소 4개의 과목부터 입력받은 과목 수 만큼의 모든 조합 계산
	{
		int* copy = (int*)malloc(i * sizeof(int)); // Combination 배열 동적할당
		F_CREATE_SCHEDULE_COMBINATION(arr, copy, subjectCnt, i, i, subjectinfo, signin); // 조합 생성 함수 
		free(copy);
	}
	free(arr);
}

void F_CREATE_SCHEDULE_COMBINATION(int* arr, int* copy, int n, int r, int depth, struct SubjectInfo* subjectinfo, SignIn* signin) {
	if (r == 0) { //하나의 조합 생성
		F_CREATE_SCHEDULE_CHECK_CONDITION(subjectinfo, copy, depth, signin); // 시간표가 될 수 있는지 조건 확인 
		return;
	}
	if (n < r) {
		return;
	}
	else {
		copy[r - 1] = arr[n - 1];
		F_CREATE_SCHEDULE_COMBINATION(arr, copy, n - 1, r - 1, depth, subjectinfo, signin);
		F_CREATE_SCHEDULE_COMBINATION(arr, copy, n - 1, r, depth, subjectinfo, signin);
	}
}

void F_CREATE_SCHEDULE_CHECK_CONDITION(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin) {
	int credit = 0;
	// 12학점 이상 18학점 이하인 조합인지 확인
	for (int i = 0; i < n; i++)
	{
		credit += subjectinfo[copy[i]].subjectCredit;
	}
	if (credit < 12 || credit > 18) {
		return;
	}
	// 겹치는 과목 확인
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(subjectinfo[copy[i]].subjectName, subjectinfo[copy[j]].subjectName) == 0) {
				return;
			}
		}
	}
	// 조합 가능한 시간표
	F_CREATE_SCHEDULE_MAKE_TIMETABLE(subjectinfo, copy, n, signin);
}

void F_CREATE_SCHEDULE_MAKE_TIMETABLE(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin) {
	int timetable[5][8] = {0, }; // 시간표 형태의 2차원 배열, 월~금, 1~8교시
	for (int i = 0; i < n; i++)
	{
		// 각각의 과목을 timetable 배열에 넣기
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "월") || !strcmp(subjectinfo[copy[i]].subjectDay2, "월")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "월"))
			{
				timetable[0][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "월")) {
				timetable[0][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "화") || !strcmp(subjectinfo[copy[i]].subjectDay2, "화")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "화"))
			{
				timetable[1][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "화")) {
				timetable[1][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "수") || !strcmp(subjectinfo[copy[i]].subjectDay2, "수")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "수"))
			{
				timetable[2][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "수")) {
				timetable[2][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "목") || !strcmp(subjectinfo[copy[i]].subjectDay2, "목")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "목"))
			{
				timetable[3][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "목")) {
				timetable[3][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "금") || !strcmp(subjectinfo[copy[i]].subjectDay2, "금")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "금"))
			{
				timetable[4][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "금")) {
				timetable[4][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
	}
	

	// html 파일 만들기
	char filename[20];
	sprintf(filename, "%s.html", signin->StudentID);
	char* Day[] = {"월", "화", "수", "목", "금"};
	char* ColorBody[] = {"#FFD9EC","#D4F4FA","#E4F7BA","#EAEAEA","#FAECC5","#FAE0D4","#E8D9FF","#FAECC5","#FFFFFF","#ffff00"}; // html table cell 색상
	FILE* file = fopen(filename, "a+");
	fprintf(file, "<table border=1 width=700 style='table-layout:fixed'>\n<tr>\n<td width=5%></td>\n");
	for (int i = 0; i < sizeof(Day) / sizeof(Day[0]); i++)
	{
		fprintf(file, "<td width=19%>%s</td>\n", Day[i]);
	}
	fprintf(file, "</tr>");
	for (int i = 0; i < 8; i++)
	{
		fprintf(file, "<tr><td>%d</td>\n", i + 1);
		for (int j = 0; j < sizeof(Day) / sizeof(Day[0]); j++)
		{
			if (timetable[j][i] == 0) // 해당 날짜 교시에 수업이 없는 경우
			{
				fprintf(file, "<td>&nbsp;</td>\n");
			}
			else { // 해당 날짜 교시에 수업이 있는 경우
				fprintf(file, "<td bgcolor=%s>%s</td>\n", ColorBody[timetable[j][i] - 1], subjectinfo[timetable[j][i] - 1].subjectName);
			}
		}
		fprintf(file, "</tr>\n<br>");
	}
	fclose(file);
}