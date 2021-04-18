//main.c
#include "product.h"
#include "manager.h"

int main(){

        int result = 0;
        Product p[50];
        int menu = 0;
	int index = 0;
	
	count = loadFile(p, index);
	index = count;
        
	while(1){

                menu = selectMenu();
                if(menu == 0){
                        printf("종료\n");
                        break;
                }
                else if(menu == 1){
			readProduct(p,index);
                }
                else if(menu == 2){
                        count += createProduct(&p[index++]);
                }
                else if(menu == 3){
			int no = selectDataNo(p, index);
			if(no> 0)
				updateProduct(&p[no-1]);
			else
				printf("취소됨!\n");
                }
                else if(menu == 4){
			int no = selectDataNo(p, index);
			if(no>0){
				printf("정말로 삭제하시겠습니까? (삭제:1) ");
				int deleteok;
				scanf("%d", &deleteok);
				if(deleteok == 1){
					deleteProduct(&p[no-1]);
					printf("삭제되었습니다! \n");
					count--;
				}
			}
			else
				printf("취소하셨습니다.!\n");
		}
                 else if(menu == 5){
			saveFile(p, index);
                }
		else if (menu == 6){
			searchProduct(p, index);
		}
        }
        return 0;
}
