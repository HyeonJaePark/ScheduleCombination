#pragma once

#define _CRT_SECURE_NO_WARNINGS

#ifndef __MODEL_SIGN_UP__
#define __MODEL_SIGN_UP__

#include <stdio.h>
#include <string.h>

// ȸ������ ���� ����ü
typedef struct _Member{
	char StudentID[20];
	char Name[20];
	char Department[40];
	char PassWord[20];
}Member;


int F_SIGN_UP_DUPLICATE(Member* member); // �ߺ��� �й� ������ �����ϴ��� Ȯ�� �Լ�
int F_SIGN_UP_CHECK_IF_FILE_EXIST(const char* filename); // �ߺ��� �й� ������ �����ϴ��� Ȯ�� �Լ�
void F_SIGN_UP_MAKE_FILE(const char* filename, Member* member); // ȸ������ .txt ���� ���� �Լ�


#endif // !__MODEL_SIGN_UP__
