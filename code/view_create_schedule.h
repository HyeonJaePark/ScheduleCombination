#pragma once

#ifndef __VIEW_CREATE_SCHEDULE__
#define __VIEW_CREATE_SCHEDULE__

#include "model_pagesetter.h"
#include "preference_page.h"

void V_VIEW_CREATE_SCHEDULE_SUBJECTCNT(int times); // 과목 수 입력 받을 화면 함수
void V_VIEW_CREATE_SCHEDULE_SUBJECTINFO(char* data, int times); // 과목 정보 입력 받을 화면 함수

#endif // !__VIEW_CREATE_SCHEDULE__
