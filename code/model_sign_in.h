#pragma once

#ifndef __MODEL_SIGN_IN
#define __MODEL_SIGN_IN

#include <stdio.h>
#include <string.h>

// 로그인 정보 구조체
typedef struct _SignIn {
	char StudentID[20];
	char PassWord[20];
}SignIn;

int F_SIGN_IN_CHECK_IF_FILE_EXIST(SignIn* signin); // 학번.txt파일이 존재하는지 확인, 회원가입을 했는지 확인 함수
int F_SIGN_IN_CHECK_PASSWORD(const char* filename, SignIn* signin); // 패스워드 일치 여부 확인 함수

#endif // !__MODEL_SIGN_IN