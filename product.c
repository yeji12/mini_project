//product.c
#include "product.h"


// 제품 추가 함수
int createProduct(Product *p){
	printf("과일의 이름은?\n");
	getchar();
	scanf("%[^\n]s", p->name);

	printf("과일의 무게는?\n");
	getchar();
    	scanf("%d", &p->weight);

    	printf("과일의 가격은?\n");
	getchar();
    	scanf("%d", &p->price);

    	printf("과일의 별점은?\n");
	getchar();
    	scanf("%s", p->star);

    	printf("과일의 총 별점은?\n");
	getchar();
    	scanf("%d", &p->sm);
    	
	return 1;
}
// 하나의 제품 출력 함수
void readProduct(Product p){
	printf("Name   Weight   Price   Star   Starnum\n"); 	
	printf("%8s %6d  %6d  %4s  %5d\n", p.name, p.weight, p.price, p.star, p.sm);

}
// 제품 수정 함수
int updateProduct(Product *p){
	printf("과일의 이름은?\n");
	getchar();
	scanf("%[^\n]s", p->name);

	printf("과일의 무게는?\n");
	getchar();
    	scanf("%d", &p->weight);

    	printf("과일의 가격은?\n");
	getchar();
    	scanf("%d", &p->price);

    	printf("과일의 별점은?\n");
	getchar();
    	scanf("%s", p->star);

    	printf("과일의 총 별점은?\n");
	getchar();
    	scanf("%d", &p->sm);

	printf("수정되었습니다.\n");
    	
	return 1;
}
// 제품 삭제 함수
int deleteProduct(Product *p){
	p->price = -1;
	p->weight = 0;
	p->sm = 0;
    	return 1;
}
