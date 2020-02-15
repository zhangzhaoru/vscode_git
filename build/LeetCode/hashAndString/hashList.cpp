/*
 * @Author: Zhang Zhaoru
 * @Since: 2020-02-13 15:22:13
 * @LastTime     : 2020-02-13 16:47:05
 * @LastAuthor   : Zhang Zhaoru
 * @Path: \vscode_git\build\LeetCode\hashAndString\hashList.cpp
 * @Description: ʹ��������ʵ��hash��
 */
#include <malloc.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAXTABLESIZE 10000  //�����ٵ����ɢ�б���
#define KEYLENGTH 100       //�ؼ��ֵ���󳤶�

typedef int ElementType;
struct LNode {
    ElementType data;
    LNode *next;
};
typedef LNode *PtrToNode;
typedef PtrToNode LinkList;
struct TblNode {
    int tablesize;   //�����󳤶�
    LinkList heads;  //���ɢ�е�Ԫ���ݵ�����
};
typedef struct TblNode *HashTable;

/*���ش���n�Ҳ�����MAXTABLESIZE����С����*/
int NextPrime(int n) {
    int p = (n % 2) ? n + 2 : n + 1;  //�Ӵ���n����һ��������ʼ
    int i;
    while (p <= MAXTABLESIZE) {
        for (i = (int)sqrt(p); i > 2; i--) {
            if ((p % i) == 0) break;
        }
        if (i == 2)
            break;  //˵��������������
        else
            p += 2;
    }
    return p;
}

/*�����µĹ�ϣ��*/
HashTable CreateTable(int table_size) {
    HashTable h = (HashTable)malloc(sizeof(TblNode));
    h->tablesize = NextPrime(table_size);
    h->heads = (LinkList)malloc(h->tablesize * sizeof(LNode));
    //��ʼ����ͷ���
    for (int i = 0; i < h->tablesize; i++) {
        h->heads[i].next = NULL;
    }
    return h;
}

/*�������ݵĳ�ʼλ��*/
int Hash(ElementType key, int n) {
    //����ֻ��Դ�Сд
    return key % 11;
}

/*����Ԫ��λ��*/
LinkList Find(HashTable h, ElementType key) {
    int pos;

    pos = Hash(key, h->tablesize);  //��ʼɢ��λ��

    LinkList p = h->heads[pos].next;  //������ĵ�һ���ڵ㿪ʼ
    while (p && key != p->data) {
        p = p->next;
    }

    return p;
}

/*�����µ�Ԫ��*/
bool Insert(HashTable h, ElementType key) {
    LinkList p = Find(h, key);  //�Ȳ���key�Ƿ����
    if (!p) {
        //�ؼ���δ�ҵ������Բ���
        LinkList new_cell = (LinkList)malloc(sizeof(LNode));
        new_cell->data = key;
        int pos = Hash(key, h->tablesize);
        new_cell->next = h->heads[pos].next;
        h->heads[pos].next = new_cell;
        return true;
    } else {
        cout << "��ֵ�Ѵ��ڣ�" << endl;
        return false;
    }
}

/*��������*/
void DestroyTable(HashTable h) {
    int i;
    LinkList p, tmp;
    //�ͷ�ÿ���ڵ�
    for (i = 0; i < h->tablesize; i++) {
        p = h->heads[i].next;
        while (p) {
            tmp = p->next;
            free(p);
            p = tmp;
        }
    }
    free(h->heads);
    free(h);
}

int main(int argc, char const *argv[]) {
    int a[] = {47, 7, 29, 29, 11, 16, 92, 22, 8, 3, 50, 37, 89, 94, 21};
    int n = 15;
    HashTable h = CreateTable(n);
    for (int i = 0; i < n; i++) {
        Insert(h, a[i]);  //����Ԫ��
    }
    for (int i = 0; i < h->tablesize; i++) {
        LinkList p = h->heads[i].next;
        while (p) {
            cout << p->data << " ";  //��ӡ��ϣ��Ԫ��
            p = p->next;
        }
        cout << endl;
    }
    return 0;
}
