///C++����
class Stu {
public:
	Stu() {
		name = new char[20]; 
		age = 10; 
	}
	~Stu() {
		if (name) delete[] name; 
	}
private:
	char *name;
	int age;
};
int main() {
	//����st1���ڴ�
	Stu *st1 = new Stu;
	delete st1;
	return 0;
}