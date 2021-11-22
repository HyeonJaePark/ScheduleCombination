#pragma once

#ifndef __VIEW_MAIN__
#define __VIEW_MAIN__

#include <stdio.h>
#include <Windows.h>

#include "model_pagesetter.h"
#include "preference_page.h"

void V_SET_MAIN_VIEW(); // 초기 console 설정 함수
void V_VIEW_MAIN_WELCOME(); // 로고 출력 함수
void V_VIEW_MAIN_MENU(char** data, size_t menuCnt, int selectedID); // 메인 메뉴 출력 함수

#endif // !__VIEW_MAIN__
