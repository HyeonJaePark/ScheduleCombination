#pragma once

#ifndef __VIEW_MAIN__
#define __VIEW_MAIN__

#include <stdio.h>
#include <Windows.h>

#include "model_pagesetter.h"
#include "preference_page.h"

void V_SET_MAIN_VIEW(); // �ʱ� console ���� �Լ�
void V_VIEW_MAIN_WELCOME(); // �ΰ� ��� �Լ�
void V_VIEW_MAIN_MENU(char** data, size_t menuCnt, int selectedID); // ���� �޴� ��� �Լ�

#endif // !__VIEW_MAIN__
