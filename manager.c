//manager.c
#include "manager.h"
#include <string.h>
#include <stdlib.h>

//파일 저장
void saveFile(Product *p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");
       
	for(int i = 0; i < count; i++){
		if(p[i].price == -1) continue;
        	fprintf(fp, "%s %d %d %s %d\n", p[i].name, p[i].weight, p[i].price, p[i].star, p[i].sm);
	}
    	fclose(fp);
    	printf("=> 저장됨!\n ");
}

// 파일 불러오기
int loadFile(Product *p, int count){
	int i = 0;
    	FILE *fp;
    	fp = fopen("product.txt", "rt");
    	for (i = 0; i < 50; i++){
		fscanf(fp, "%s", p[i].name);
        	if(feof(fp)) break;
        	fscanf(fp, "%d", &p[i].weight);
        	fscanf(fp, "%d", &p[i].price);
        	fscanf(fp, "%s", p[i].star);
        	fscanf(fp, "%d", &p[i].sm);
        	count++;
	}
    	fclose(fp);
    	if(fp == NULL)
        	printf("=> 파일없음\n");
	else
	{
		printf("=> 로딩 성공!\n");
        	return count;
    	}
	return 0;
}

// 제품 이름검색
void searchProduct(Product *p, int count){
	int scnt = 0;
    	char search[20];

    	printf("검색할 이름은? ");
    	scanf("%s", search);
    	printf("\nNo  과일이름  중량  가격  별점  별점개수\n");
    	printf("========================================\n");
    	for(int i = 0; i < count; i++){
        	if(p[i].price == -1) continue;
        	if(strstr(p[i].name, search)){
            		printf("%2d ", i+1);
            		readProduct(p[i]);
            		scnt++;
        	}	
    	}	
    	if(scnt == 0) printf("=> 검색된 데이터 없음!");
    	printf("\n");
}

// 제품 가격 검색
void priceProduct(Product *p, int count){
	int scnt = 0;
    	char search[5];
    	char price[5]; //문자형으로 바꿔준 것 넣어줄 변수
	int a;

    	printf("검색할 가격은? ");
    	scanf("%s", search);
    	printf("\nNo  과일이름  중량  가격  별점  별점개수\n");
    	printf("========================================\n");
    	for(int i = 0; i < count; i++){
		if(p[i].price == -1) continue;
        	sprintf(price, "%d",p[i].price);
        	if(strstr(price, search)){
			printf("%2d ", i+1);
            		readProduct(p[i]);
            		scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}

//제품 별점검색
void starProduct(Product *p, int count){
	int scnt = 0;
	char search[5];
	char star[5];

    	printf("검색할 별점은? ");
    	scanf("%s", search);
    	printf("\nNo  과일이름  중량  가격  별점  별점개수\n");
    	printf("========================================\n");
    	for(int i = 0; i < count; i++){
		if(p[i].price == -1) continue;
		sprintf(star, "%s", p[i].star); 
		if(strstr(star, search)){
			printf("%2d ", i+1);
            		readProduct(p[i]);
            		scnt++;
		}
	}
    	if(scnt == 0) printf("=> 검색된 데이터 없음!");
    	printf("\n");
}

void listProduct(Product *p, int count){
    	printf("\nNo  과일이름  중량  가격  별점  별점개수\n");
    	printf("============================================\n");
    	for(int i = 0; i < count; i++){
        	if(p[i].price == -1) continue;
        	printf("%2d", i+1);
        	readProduct(p[i]);
    	}
}

int selectDataNo(Product *p, int count){
	listProduct(p, count);
    	int no;
    	printf("번호는(취소:0)?");
    	scanf("%d", &no);
    	return no;
}

//메뉴선택
int selectMenu(){
	int menu;
    	printf("\n***상큼한 과일 상점***\n");
    	printf("1. 상품조회\n");
    	printf("2. 상품추가\n");
    	printf("3. 상품수정\n");
    	printf("4. 상품삭제\n");
	printf("5. 정보저장\n");
	printf("6. 정보검색\n");
    	printf("0. 종료\n\n");
    	printf("=> 원하는 메뉴는? ");
    	scanf("%d", &menu);
    	return menu;
}
