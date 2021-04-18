//product.h
#include <stdio.h>

typedef struct {
    char name[20];
    int weight;
    int price;
    char star[5];
    int sm; //별점개수
} Product;

// 제품 추가 함수
int createProduct(Product *p);
// 하나의 제품 출력 함수
void readProduct(Product p);
// 제품 수정 함수
int updateProduct(Product *p);
// 제품 삭제 함수
int deleteProduct(Product *p);
