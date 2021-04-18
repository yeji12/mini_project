//manager.h
#include "product.h"
#include <stdio.h>

// 파일 저장
void saveFile(Product *p, int count);
// 파일 불러오기
int loadFile(Product *p, int count);
// 제품 이름검색
void searchProduct(Product *p, int count);
// 제품 가격 검색
void priceProduct(Product *p, int count);
//제품 별점검색
void starProduct(Product *p, int count);
//번호선택
int selectDataNo(Product *p, int count);
// 제품나열
void listProduct(Product *p, int count);
//메뉴선택
int selectMenu();
