#include "controller_schedule_menu.h"

void F_SCHEDULE_MENU_RUN(SignIn* signin) {
	F_SCHEDULE_MENU_LOOP(signin);
	return;
}

void F_SCHEDULE_MENU_LOOP(SignIn* signin) {
	char key; // 키보드 입력받을 변수
	int selectedID = 0; // n번째 메뉴
	char* scheduleMenuData[] = { "Create New Schedule", "Load Latest Schedule", "EXIT"}; // 메뉴 데이터 
	char* scheduleCreateData[] = { "과목명", "요일1", "시간1", "요일2", "시간2", "학점" }; // 과목 정보 데이터

	while (1)
	{
		V_VIEW_SCHEDULE_MENU(scheduleMenuData, sizeof(scheduleMenuData) / sizeof(scheduleMenuData[0]), selectedID); // 메뉴 화면 생성
		key = _getch();
		if (key == UP && (selectedID >= 1 && selectedID <= 2)) {
			selectedID--;
		}
		else if (key == DOWN && (selectedID >= 0 && selectedID <= 1)) {
			selectedID++;
		}
		else if (key == '\r') {
			system("cls");
			if (selectedID == 0) // 시간표 생성 함수 실행
			{
				int subjectCnt = 0; // 입력할 과목 수
				struct SubjectInfo* subjectinfo; // 과목 정보 담을 구조체
				V_VIEW_CREATE_SCHEDULE_SUBJECTCNT(0); // 입력할 과목 수 화면 
				scanf("%d", &subjectCnt); // 과목 수 입력 받기
				subjectinfo = (struct SubjectInfo*)malloc(sizeof(struct SubjectInfo) * subjectCnt);// 과목 정보 구조체 동적할당
				for (int i = 0; i < subjectCnt; i++) // 과목 정보 입력 받기
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
				F_CREATE_SCHEDULE_RUN(subjectinfo, subjectCnt, signin);//시간표 조합 및 파일 생성
				system("cls");
			}
			else if (selectedID == 1) {// 시간표 불러오기
				if (!F_LOAD_SCHEDULE_OPEN_HTML(signin)) { // 불러올 파일이 없는 경우
					printf("NO FILE EXISTS");
					system("PAUSE");
				}
				system("cls");
			}
			else if (selectedID == 2) {// 프로그램 종료
				return;
			}
		}

	}
}