#include <stdio.h>

#include <stdlib.h>
#include <string.h>
//对于未知元素进行交换
void swap(void  *a, void *b, int width){
	char *a1 = (char *)a;
	char *b1 = (char *)b;
	char tmp;
	while(width){
		tmp = *a1;
		*a1 = *b1;
		*b1 = tmp;
		a1++;
		b1++;
		width--;
	}
	a = (void *)a1;
	b = (void *)b1;
}

void sort_array(void *base, int num, int width,
				int (*compare)(const void *, const void *)){
	int i, j;
	void *temp = malloc(width);//申请临时空间用于交换
	//width记录元素类型所占空间大小
	for (i = 0; i < num; i++){
		for (j = i + 1; j < num; j++){			
			void *element1 = base + i * width;
			void *element2 = base + j * width;
			if (compare(element1, element2) > 0){  //调用回调函数
				swap(temp, element1, width);
				swap(element1, element2, width);
				swap(element2, temp, width);
			}
		}
	}
	free(temp);
}

//对于整数排序的回调函数
int int_cmp(const void *a, const void *b){
	return *(int *)a - *(int *)b;
}

//对于浮点排序的回调函数
int double_cmp(const void *a, const void *b){
	return *(double *)a > *(double *)b ? 1 : -1;
}


//对于double字符串相等的两个数作差结果不一定为零
//浮点型大小比较不损失精度
int str_cmp(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);	
}

int str_ptr_cmp(const void *a, const void *b){
	return strcmp(*(char **)a, *(char **)b);
}

int main(){
	int int_array[8] = {2, 50, 3, -7, 2, 9, 0, 0};
	double double_array[8] = {2.5, 13.12, -0.7, 0, -50, 9, -0.123, 0};
	const char *str_array_ptr[8] = {
		"zzz",
		"zzzz",
		"xxxxxxxxx",
		"p",
		"abc",
		"ccckkk",
		"aaa",
		"mmwordilovecoding"
	};
	char str_array[8][100] = {
		"zzz",
		"zzzz",
		"xxxxxxxxx",
		"p",
		"abc",
		"ccckkk",
		"aaa",
		"mmwordilovecoding"
	};
	int i;
		
	sort_array(int_array, 8, sizeof(int), int_cmp);
	printf("int_array:\n");
	for (i = 0; i < 8; i++){
		printf("%d ", int_array[i]);
	}
	printf("\n\n");
	
	sort_array(double_array, 8, sizeof(double), double_cmp);
	printf("double_array:\n");
	for (i = 0; i < 8; i++){
		printf("%lf ", double_array[i]);
	}
	printf("\n\n");
	
	sort_array(str_array_ptr, 8, sizeof(str_array_ptr[0]), str_ptr_cmp);
	printf("str_array_ptr:\n");
	for (i = 0; i < 8; i++){
		printf("%s\n", str_array_ptr[i]);
	}
	printf("\n");
	
	sort_array(str_array, 8, sizeof(str_array[0]), str_cmp);
	printf("str_array:\n");
	for (i = 0; i < 8; i++){
		printf("%s\n", str_array[i]);
	}
	system("pause");
	return 0;
}

