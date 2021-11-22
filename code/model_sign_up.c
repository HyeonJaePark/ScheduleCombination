#include "model_sign_up.h"

int F_SIGN_UP_DUPLICATE(Member* member){
	char file[15];
	sprintf(file, "%s.txt", member->StudentID);
	if(!F_SIGN_UP_CHECK_IF_FILE_EXIST(file)){ // 회원가입을 이전에 안 한 경우
		F_SIGN_UP_MAKE_FILE(file, member); // 회원 정보 .txt파일 생성
		return 0;
	}
	else{
		return 1;
	}
}

int F_SIGN_UP_CHECK_IF_FILE_EXIST(const char* filename){
	FILE* file;
	if(file = fopen(filename, "r")){
		fclose(file);
		return 1;
	}
	return 0;
}

void F_SIGN_UP_MAKE_FILE(const char* filename, Member* member){
	FILE* file = fopen(filename, "a");
	fprintf(file, "%s\n", member->Name);
	fprintf(file, "%s\n", member->Department);
	fprintf(file, "%s\n", member->PassWord);
	fclose(file);
}