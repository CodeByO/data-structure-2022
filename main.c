#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//[API] wcat 
//[DESC] 인자로 받은 파일을 열어서 안에 있는 문자열 데이터를 출력
//[TODO] 기능작성
//[DOING] 임의의 파일을 읽어서 출력

int main(int argc, char* argv[]){
    if (argc != 2) {
	    printf(stderr, "usage: wcat <file>\n");
	    exit(1);
    }

    FILE *fp = fopen(argv[1],"r");
    char* buffer;
    int size; 
    int count;

    if(fp == NULL){
        fprintf(stderr, "can not open file\n");
        exit(1);
    }




    fseek(fp, 0, SEEK_END); // 파일 크기를 읽기 위해 파일 포인터를 파일의 맨 끝으로 이동
    size = ftell(fp); // 파일 크기를 저장

    buffer = malloc(size+1); // 파일 크기에 따라 알맞는 크기로 동적 할당
    memset(buffer, 0, size + 1); // 동적할당된 변수를 0으로 초기화


    fseek(fp, 0, SEEK_SET); // 파일 데이터를 읽기 위해 파일 포인터를 다시 파일의 맨 처음으로 이동
    fread(buffer, size , 1 , fp); // 실제 파일 데이터를 읽음

    printf("%s\n", buffer); 

    fclose(fp);

    free(buffer);

    return 0;
}