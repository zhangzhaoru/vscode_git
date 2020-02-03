//单例模型
//将默认构造函数与析构函数的声明为私有没外部无法创建与销毁
//使用私有静态本类类型的指针变量用来指向该类的唯一实力
//用一个共有的静态方法获取该实例，第一次调用该方法时创建实力并返回，
//以后调用直接返回
//用一个共有的静态方法来删除实例，以保证实例只会被删除一次
#include<iostream>
using namespace std;
class A{
    private:
        A(){};
        ~A(){};
    public:
    static A* GetInsatnce(){
        if(NULL==m_pInstance)
            m_pInstance = new A;
        return m_pInstance;
    }
    static void DeleteInstance(){
        if(m_pInstance!=NULL)
            delete m_pInstance;
        m_pInstance = NULL;
    }
    private:
        static A* m_pInstance;
        int count;
};

A *A::m_pInstance = NULL;
//懒汉式
//A *A::m_pInstance = new A;
//恶汉式
int main(){
    A *pa = A::GetInsatnce();
    A *pb = A::GetInsatnce();
    cout<<pa<<" "<<pb<<endl;
    A::DeleteInstance();
    system("pause");
    return 0;
}