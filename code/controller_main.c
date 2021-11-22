#include "controller_main.h"

void F_MAIN_RUN(){
	V_SET_MAIN_VIEW();
	V_VIEW_MAIN_WELCOME();
	F_MAIN_LOOP();
}

void F_MAIN_LOOP(){
	char key; // Ű���� �Է� ���� ����
	int selectedID = 0; // n��° �޴�
	char* menuData[] = {"Sign Up", "Sign In","Exit"}; // �޴� ������
	char* signUpMenuData[] = {"StudentID", "Name", "Department", "PassWord"}; // ȸ������ ȭ�� ��� ����
	char* signInMenuData[] = { "StudentID", "Password"}; // �α��� ȭ�� ��� ����

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
			if(selectedID == 0){ // ȸ������ �޴� ���ý�
				Member member; // ȸ������ ���� ����ü
				// ȸ������ �Է� �ޱ�
				for(int i = 0; i < sizeof(signUpMenuData) / sizeof(signUpMenuData[0]); i++){
					V_VIEW_SIGN_UP_MENU(signUpMenuData[i], i);
					if(i == 0)	scanf_s("%s", member.StudentID, sizeof(member.StudentID));
					else if(i == 1)	scanf_s("%s", member.Name, sizeof(member.Name));
					else if(i == 2)	scanf_s("%s", member.Department, sizeof(member.Department));
					else if(i == 3)	scanf_s("%s", member.PassWord, sizeof(member.PassWord));
				}
				if(!F_SIGN_UP_DUPLICATE(&member)){ // ���� ������ ���� ���
					system("cls");
					V_VIEW_MAIN_WELCOME(); // �ʱ� �޴� �ΰ� �����ϰ� while�� ó������ ���ư�
				}
				else{ // �̹� ������ �����ϴ� ���, ������ �� ���
					printf("�̹� ���Ե� �����Դϴ�.\n");
					system("PAUSE");
					system("cls");
					V_VIEW_MAIN_WELCOME(); // �ʱ� �޴� �ΰ� �����ϰ� while�� ó������ ���ư�
				}
			}
			else if(selectedID == 1){ //�α��� �Լ� ���ý�
				system("cls");
				SignIn signin; // �α��� �Լ� ����ü
				// �α��� �Է� �ޱ�
				for (int i = 0; i < sizeof(signInMenuData) / sizeof(signInMenuData[0]); i++) {
					V_VIEW_SIGN_IN_MENU(signInMenuData[i], i);

					if (i == 0) scanf_s("%s", signin.StudentID, sizeof(signin.StudentID));
					else if (i == 1) scanf_s("%s", signin.PassWord, sizeof(signin.PassWord));
				}
				if (F_SIGN_IN_CHECK_IF_FILE_EXIST(&signin)) { // model_sign_in ���� ���� ���� �� �α��� Ȯ��, �α��� ������
					printf("�α��� ����\n");
					system("PAUSE");
					system("cls");
					F_SCHEDULE_MENU_RUN(&signin); // �ð�ǥ ���� �޴��� ����
					return; // ���α׷� ����
				}
				else { //�α��� ����
					printf("������ �������� �ʽ��ϴ�.\n");
					system("PAUSE");
					system("cls");
					V_VIEW_MAIN_WELCOME();
				}
			}
			else if(selectedID == 2){ // ���α׷� ����
				return;
			}
		}
	}
}