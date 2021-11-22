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

void INIT_PAGE(); // �ʱ� console ���� �Լ�
void gotoxy(int x, int y); // console �� Ŀ�� ��ġ �̵� �Լ�
void COLORSET(int backgroundColor, int textColor); // console �� ���� �� ���ڻ� ���� �Լ�

#endif // !__MODEL_PAGESETTER__