#include "model_load_schedule.h"

int F_LOAD_SCHEDULE_OPEN_HTML(SignIn* signin) {
	char filename[20];
	sprintf(filename, "%s.html", signin->StudentID);
	FILE* file;
	if ((file = fopen(filename, "r")) == NULL) { // ������ ���°��
		return 0;
	}
	char locate[1024];
	TCHAR pwd[1024]; // directory path
	GetCurrentDirectory(1024, pwd);
	sprintf(locate, "%s/%s", pwd, filename); // ������ �ִ� ���
	ShellExecute(NULL, "open", locate, NULL, NULL, SW_SHOWNORMAL); //HTML ���� �Ѷ������ ����
	return 1;
}