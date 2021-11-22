#pragma once

#ifndef __MODEL_SIGN_IN
#define __MODEL_SIGN_IN

#include <stdio.h>
#include <string.h>

// �α��� ���� ����ü
typedef struct _SignIn {
	char StudentID[20];
	char PassWord[20];
}SignIn;

int F_SIGN_IN_CHECK_IF_FILE_EXIST(SignIn* signin); // �й�.txt������ �����ϴ��� Ȯ��, ȸ�������� �ߴ��� Ȯ�� �Լ�
int F_SIGN_IN_CHECK_PASSWORD(const char* filename, SignIn* signin); // �н����� ��ġ ���� Ȯ�� �Լ�

#endif // !__MODEL_SIGN_IN