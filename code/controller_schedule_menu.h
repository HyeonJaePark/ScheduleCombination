#pragma once

#ifndef __CONTROLLER_SCHEDULE_MENU__
#define __CONTROLLER_SCHEDULE_MENU__

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "view_schedule_menu.h"
#include "view_create_schedule.h"
#include "model_create_schedule.h"
#include "model_load_schedule.h"

void F_SCHEDULE_MENU_RUN(SignIn* signin); // 시간표 생성 메뉴 메인 실행 함수
void F_SCHEDULE_MENU_LOOP(SignIn* signin); // 시간표 생성 메뉴 반복 실행 함수

#endif // !__CONTROLLER_SCHEDULE_MENU__
