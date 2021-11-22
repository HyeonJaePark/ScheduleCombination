#pragma once

#ifndef __MODEL_CREATE_SCHEDULE__
#define __MODEL_CREATE_SCHEDULE__

#include <stdio.h>
#include <string.h>

#include "controller_main.h"

// 과목 정보 구조체
struct SubjectInfo {
	char subjectName[20];
	char subjectDay1[4];
	int subjectTime1;
	char subjectDay2[4];
	int subjectTime2;
	int subjectCredit;
};

void F_CREATE_SCHEDULE_RUN(struct SubjectInfo* subjectinfo, int subjectCnt, SignIn* signin); // 시간표 조합 생성 메인 함수
void F_CREATE_SCHEDULE_COMBINATION(int* arr, int* copy, int n, int r, int depth, struct SubjectInfo* subjectinfo, SignIn* signin); // 시간표 조합 Combination 함수
void F_CREATE_SCHEDULE_CHECK_CONDITION(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin); // 시간표 조합 조건 체크 함수
void F_CREATE_SCHEDULE_MAKE_TIMETABLE(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin); // 시간표 조합 HTML 파일 생성 함수


#endif // !__MODEL_CREATE_SCHEDULE__
