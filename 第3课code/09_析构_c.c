///������������ c����
struct Stu {
	char *name;
	int age;
};
int main() {
	//����st1���ڴ�
	struct Stu *st1 = 
	   (struct Stu*)malloc(sizeof(struct Stu));
	//����st1��name���ڴ�
	st1->name = (char*)malloc(sizeof(char)*20);
	//�ͷ�st1��name���ڴ�
	free(st1->name);
	//�ͷ�st1������ڴ�
	free(st1);
	return 0;
}