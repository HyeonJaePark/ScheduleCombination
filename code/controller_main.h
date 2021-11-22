#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "view_main.h"
#include "view_sign_up.h"
#include "view_sign_in.h"
#include "model_sign_up.h"
#include "model_sign_in.h"

#include "controller_schedule_menu.h"

#ifndef __CONTROLLER_MAIN__
#define __CONTROLLER_MAIN__

void F_MAIN_RUN(); // 메인 실행 함수
void F_MAIN_LOOP(); // 메인 메뉴 반복 실행 함수

#endif // !__CONTROLLER_MAIN__
