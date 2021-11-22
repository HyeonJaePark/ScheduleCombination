#include "controller_schedule_menu.h"

void F_SCHEDULE_MENU_RUN(SignIn* signin) {
	F_SCHEDULE_MENU_LOOP(signin);
	return;
}

void F_SCHEDULE_MENU_LOOP(SignIn* signin) {
	char key; // Ű���� �Է¹��� ����
	int selectedID = 0; // n��° �޴�
	char* scheduleMenuData[] = { "Create New Schedule", "Load Latest Schedule", "EXIT"}; // �޴� ������ 
	char* scheduleCreateData[] = { "�����", "����1", "�ð�1", "����2", "�ð�2", "����" }; // ���� ���� ������

	while (1)
	{
		V_VIEW_SCHEDULE_MENU(scheduleMenuData, sizeof(scheduleMenuData) / sizeof(scheduleMenuData[0]), selectedID); // �޴� ȭ�� ����
		key = _getch();
		if (key == UP && (selectedID >= 1 && selectedID <= 2)) {
			selectedID--;
		}
		else if (key == DOWN && (selectedID >= 0 && selectedID <= 1)) {
			selectedID++;
		}
		else if (key == '\r') {
			system("cls");
			if (selectedID == 0) // �ð�ǥ ���� �Լ� ����
			{
				int subjectCnt = 0; // �Է��� ���� ��
				struct SubjectInfo* subjectinfo; // ���� ���� ���� ����ü
				V_VIEW_CREATE_SCHEDULE_SUBJECTCNT(0); // �Է��� ���� �� ȭ�� 
				scanf("%d", &subjectCnt); // ���� �� �Է� �ޱ�
				subjectinfo = (struct SubjectInfo*)malloc(sizeof(struct SubjectInfo) * subjectCnt);// ���� ���� ����ü �����Ҵ�
				for (int i = 0; i < subjectCnt; i++) // ���� ���� �Է� �ޱ�
				{
					system("cls");
					for (int j = 0; j < sizeof(scheduleCreateData) / sizeof(scheduleCreateData[0]); j++)
					{
						V_VIEW_CREATE_SCHEDULE_SUBJECTINFO(scheduleCreateData[j], j);
						if (j == 0) scanf_s("%s", &subjectinfo[i].subjectName, sizeof(subjectinfo[i].subjectName));
						else if(j == 1) scanf_s("%s", &subjectinfo[i].subjectDay1, sizeof(subjectinfo[i].subjectDay1));
						else if (j == 2) scanf_s("%d", &subjectinfo[i].subjectTime1, sizeof(subjectinfo[i].subjectTime1));
						else if (j == 3) scanf_s("%s", &subjectinfo[i].subjectDay2, sizeof(subjectinfo[i].subjectDay2));
						else if (j == 4) scanf_s("%d", &subjectinfo[i].subjectTime2, sizeof(subjectinfo[i].subjectTime2));
						else if (j == 5) scanf_s("%d", &subjectinfo[i].subjectCredit, sizeof(subjectinfo[i].subjectCredit));
					}
				}
				F_CREATE_SCHEDULE_RUN(subjectinfo, subjectCnt, signin);//�ð�ǥ ���� �� ���� ����
				system("cls");
			}
			else if (selectedID == 1) {// �ð�ǥ �ҷ�����
				if (!F_LOAD_SCHEDULE_OPEN_HTML(signin)) { // �ҷ��� ������ ���� ���
					printf("NO FILE EXISTS");
					system("PAUSE");
				}
				system("cls");
			}
			else if (selectedID == 2) {// ���α׷� ����
				return;
			}
		}

	}
}