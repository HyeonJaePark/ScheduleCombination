#pragma once

#define _CRT_SECURE_NO_WARNINGS

#ifndef __MODEL_PAGESETTER__
#define __MODEL_PAGESETTER__

#include <stdio.h>
#include <Windows.h>

#include "preference_page.h"

typedef enum ColorKinds{
	black,
	blue,
	green,
	skyBlue,
	red,
	pink,
	orange,
	white,
	gray,
	lightBlue,
	brightGreen,
	sky,
	brightRed,
	brightPink,
	brightYellow,
	brightWhite,
}ColorKinds;

void INIT_PAGE(); // 초기 console 설정 함수
void gotoxy(int x, int y); // console 내 커서 위치 이동 함수
void COLORSET(int backgroundColor, int textColor); // console 내 배경색 및 글자색 설정 함수

#endif // !__MODEL_PAGESETTER__