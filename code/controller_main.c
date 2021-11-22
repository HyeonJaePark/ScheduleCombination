#include "controller_main.h"

void F_MAIN_RUN(){
	V_SET_MAIN_VIEW();
	V_VIEW_MAIN_WELCOME();
	F_MAIN_LOOP();
}

void F_MAIN_LOOP(){
	char key; // 키보드 입력 받을 변수
	int selectedID = 0; // n번째 메뉴
	char* menuData[] = {"Sign Up", "Sign In","Exit"}; // 메뉴 선택지
	char* signUpMenuData[] = {"StudentID", "Name", "Department", "PassWord"}; // 회원가입 화면 출력 정보
	char* signInMenuData[] = { "StudentID", "Password"}; // 로그인 화면 출력 정보

	while(1){
		V_VIEW_MAIN_MENU(menuData, sizeof(menuData) / sizeof(menuData[0]), selectedID);
		key = _getch();
		if(key == UP && (selectedID >= 1 && selectedID <= 2)){
			selectedID--;
		}
		else if(key == DOWN && (selectedID >= 0 && selectedID <= 1)){
			selectedID++;
		}
		else if(key == '\r'){
			system("cls");
			if(selectedID == 0){ // 회원가입 메뉴 선택시
				Member member; // 회원가입 정보 구조체
				// 회원가입 입력 받기
				for(int i = 0; i < sizeof(signUpMenuData) / sizeof(signUpMenuData[0]); i++){
					V_VIEW_SIGN_UP_MENU(signUpMenuData[i], i);
					if(i == 0)	scanf_s("%s", member.StudentID, sizeof(member.StudentID));
					else if(i == 1)	scanf_s("%s", member.Name, sizeof(member.Name));
					else if(i == 2)	scanf_s("%s", member.Department, sizeof(member.Department));
					else if(i == 3)	scanf_s("%s", member.PassWord, sizeof(member.PassWord));
				}
				if(!F_SIGN_UP_DUPLICATE(&member)){ // 가입 파일이 없는 경우
					system("cls");
					V_VIEW_MAIN_WELCOME(); // 초기 메뉴 로고 실행하고 while문 처음으로 돌아감
				}
				else{ // 이미 파일이 존재하는 경우, 가입을 한 경우
					printf("이미 가입된 정보입니다.\n");
					system("PAUSE");
					system("cls");
					V_VIEW_MAIN_WELCOME(); // 초기 메뉴 로고 실행하고 while문 처음으로 돌아감
				}
			}
			else if(selectedID == 1){ //로그인 함수 선택시
				system("cls");
				SignIn signin; // 로그인 함수 구조체
				// 로그인 입력 받기
				for (int i = 0; i < sizeof(signInMenuData) / sizeof(signInMenuData[0]); i++) {
					V_VIEW_SIGN_IN_MENU(signInMenuData[i], i);

					if (i == 0) scanf_s("%s", signin.StudentID, sizeof(signin.StudentID));
					else if (i == 1) scanf_s("%s", signin.PassWord, sizeof(signin.PassWord));
				}
				if (F_SIGN_IN_CHECK_IF_FILE_EXIST(&signin)) { // model_sign_in 에서 파일 유무 및 로그인 확인, 로그인 성공시
					printf("로그인 성공\n");
					system("PAUSE");
					system("cls");
					F_SCHEDULE_MENU_RUN(&signin); // 시간표 생성 메뉴로 진입
					return; // 프로그램 종료
				}
				else { //로그인 실패
					printf("정보가 존재하지 않습니다.\n");
					system("PAUSE");
					system("cls");
					V_VIEW_MAIN_WELCOME();
				}
			}
			else if(selectedID == 2){ // 프로그램 종료
				return;
			}
		}
	}
}