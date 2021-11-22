#pragma once

#define _CRT_SECURE_NO_WARNINGS

#ifndef __MODEL_SIGN_UP__
#define __MODEL_SIGN_UP__

#include <stdio.h>
#include <string.h>

// 회원가입 정보 구조체
typedef struct _Member{
	char StudentID[20];
	char Name[20];
	char Department[40];
	char PassWord[20];
}Member;


int F_SIGN_UP_DUPLICATE(Member* member); // 중복된 학번 파일이 존재하는지 확인 함수
int F_SIGN_UP_CHECK_IF_FILE_EXIST(const char* filename); // 중복된 학번 파일이 존재하는지 확인 함수
void F_SIGN_UP_MAKE_FILE(const char* filename, Member* member); // 회원정보 .txt 파일 생성 함수


#endif // !__MODEL_SIGN_UP__
