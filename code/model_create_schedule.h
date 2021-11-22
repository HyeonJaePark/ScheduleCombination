#pragma once

#ifndef __MODEL_CREATE_SCHEDULE__
#define __MODEL_CREATE_SCHEDULE__

#include <stdio.h>
#include <string.h>

#include "controller_main.h"

// ���� ���� ����ü
struct SubjectInfo {
	char subjectName[20];
	char subjectDay1[4];
	int subjectTime1;
	char subjectDay2[4];
	int subjectTime2;
	int subjectCredit;
};

void F_CREATE_SCHEDULE_RUN(struct SubjectInfo* subjectinfo, int subjectCnt, SignIn* signin); // �ð�ǥ ���� ���� ���� �Լ�
void F_CREATE_SCHEDULE_COMBINATION(int* arr, int* copy, int n, int r, int depth, struct SubjectInfo* subjectinfo, SignIn* signin); // �ð�ǥ ���� Combination �Լ�
void F_CREATE_SCHEDULE_CHECK_CONDITION(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin); // �ð�ǥ ���� ���� üũ �Լ�
void F_CREATE_SCHEDULE_MAKE_TIMETABLE(struct SubjectInfo* subjectinfo, int* copy, int n, SignIn* signin); // �ð�ǥ ���� HTML ���� ���� �Լ�


#endif // !__MODEL_CREATE_SCHEDULE__
