#include "model_create_schedule.h"

void F_CREATE_SCHEDULE_RUN(struct SubjectInfo* subjectinfo, int subjectCnt, SignIn* signin) {
	FILE* file;
	char filename[20];
	sprintf(filename, "%s.html", signin->StudentID);
	if ((file = fopen(filename, "r")) != NULL) // �̹� ������ ������ ��� 
	{
		file = fopen(filename, "w+"); // ������ �ٽ� ����
		fclose(file);
	}
	
	int* arr = (int*)malloc(subjectCnt * sizeof(int)); // �������ŭ �迭 �����Ҵ�
	for (int i = 0; i < subjectCnt; i++)
	{
		arr[i] = i; 
	}
	for (int i = 4; i <= subjectCnt; i++) // �ּ� 4���� ������� �Է¹��� ���� �� ��ŭ�� ��� ���� ���
	{
		int* copy = (int*)malloc(i * sizeof(int)); // Combination �迭 �����Ҵ�
		F_CREATE_SCHEDULE_COMBINATION(arr, copy, subjectCnt, i, i, subjectinfo, signin); // ���� ���� �Լ� 
		free(copy);
	}
	free(arr);
}

void F_CREATE_SCHEDULE_COMBINATION(int* arr, int* copy, int n, int r, int depth, struct SubjectInfo* subjectinfo, SignIn* signin) {
	if (r == 0) { //�ϳ��� ���� ����
		F_CREATE_SCHEDULE_CHECK_CONDITION(subjectinfo, copy, depth, signin); // �ð�ǥ�� �� �� �ִ��� ���� Ȯ�� 
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
	// 12���� �̻� 18���� ������ �������� Ȯ��
	for (int i = 0; i < n; i++)
	{
		credit += subjectinfo[copy[i]].subjectCredit;
	}
	if (credit < 12 || credit > 18) {
		return;
	}
	// ��ġ�� ���� Ȯ��
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(subjectinfo[copy[i]].subjectName, subjectinfo[copy[j]].subjectName) == 0) {
				return;
			}
		}
	}
	// ���� ������ �ð�ǥ
	F_CREATE_SCHEDULE_MAKE_TIMETABLE(subjectinfo, copy, n, signin);
}

void F_CREATE_SCHEDULE_MAKE_TIMETABLE(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin) {
	int timetable[5][8] = {0, }; // �ð�ǥ ������ 2���� �迭, ��~��, 1~8����
	for (int i = 0; i < n; i++)
	{
		// ������ ������ timetable �迭�� �ֱ�
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��") || !strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��"))
			{
				timetable[0][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
				timetable[0][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "ȭ") || !strcmp(subjectinfo[copy[i]].subjectDay2, "ȭ")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "ȭ"))
			{
				timetable[1][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "ȭ")) {
				timetable[1][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��") || !strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��"))
			{
				timetable[2][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
				timetable[2][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��") || !strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��"))
			{
				timetable[3][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
				timetable[3][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
		if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��") || !strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
			if (!strcmp(subjectinfo[copy[i]].subjectDay1, "��"))
			{
				timetable[4][subjectinfo[copy[i]].subjectTime1 - 1] = copy[i] + 1;
			}
			else if (!strcmp(subjectinfo[copy[i]].subjectDay2, "��")) {
				timetable[4][subjectinfo[copy[i]].subjectTime2 - 1] = copy[i] + 1;
			}
		}
	}
	

	// html ���� �����
	char filename[20];
	sprintf(filename, "%s.html", signin->StudentID);
	char* Day[] = {"��", "ȭ", "��", "��", "��"};
	char* ColorBody[] = {"#FFD9EC","#D4F4FA","#E4F7BA","#EAEAEA","#FAECC5","#FAE0D4","#E8D9FF","#FAECC5","#FFFFFF","#ffff00"}; // html table cell ����
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
			if (timetable[j][i] == 0) // �ش� ��¥ ���ÿ� ������ ���� ���
			{
				fprintf(file, "<td>&nbsp;</td>\n");
			}
			else { // �ش� ��¥ ���ÿ� ������ �ִ� ���
				fprintf(file, "<td bgcolor=%s>%s</td>\n", ColorBody[timetable[j][i] - 1], subjectinfo[timetable[j][i] - 1].subjectName);
			}
		}
		fprintf(file, "</tr>\n<br>");
	}
	fclose(file);
}