#include "model_sign_in.h"

int F_SIGN_IN_CHECK_IF_FILE_EXIST(SignIn* signin) {
	char filename[15];
	sprintf(filename, "%s.txt", signin->StudentID);
	
	FILE* file;
	if (file = fopen(filename, "r")) { // ȸ�������� �� ���
		fclose(file);
		return F_SIGN_IN_CHECK_PASSWORD(filename, signin); // ��й�ȣ Ȯ�Τ�
	}
	return 0; // ȸ�������� �� ���� ��� 
}

int F_SIGN_IN_CHECK_PASSWORD(const char* filename, SignIn* signin) {
	FILE* file;
	int lineNumber = 2; // password line
	int count = 0;
	if (file = fopen(filename, "r")) {
		char pw[20];
		while (fgets(pw, sizeof(pw), file) != NULL) {
			if (count == lineNumber) {
				for (int i = 0; i < sizeof(signin->PassWord); i++) {
					if (pw[i] == '\n') { // ��й�ȣ�� ���� ���
						fclose(file);
						return 1;
					}
					if (pw[i] != signin->PassWord[i]) { // ��й�ȣ�� �ٸ� ���
						fclose(file);
						return 0;
					}
				}
			}
			else {
				count++;
			}
		}
	}
	return 0;
}