#include<stdlib.h>
#include<stdio.h>

typedef struct LNode{
	int data;//������ 
	struct LNode *next;//ָ���� 
}LNode, *LinkList;

//����ͷ�巨����������
LinkList List_HeadInsert(LinkList &L){ //������������ 
	LNode *s; int x;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	scanf("%d",&x);
	while(x!=9999) {
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d",&x);
	}
	return L;
}

//����β�巨����������
LinkList List_TailInsert(LinkList &L){//������������ 
	int x;
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s,*r=L;
	scanf("%d", &x);
	while(x!=9999){
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	return L;
} 


//bool InitList(LinkList &L) { //����ͷ��� 
//	L = NULL;
//	return true;
//}

bool InitList(LinkList &L) { //��ͷ��� 
	L = (LNode *)malloc(sizeof(LNode));
	if(L==NULL) return false;
	L->next = NULL;
	return true;
}

bool Empty(LinkList L) {
	if(L->next==NULL) 
		return true;
	else 
		return false;//��ͷ��� 
//	return (L==NULL);//����ͷ��� 
}

//��λ���ң����ص�i��Ԫ�أ���ͷ��㣩
LNode *GetElem(LinkList L, int i){
	int j=1;
	LNode *p=L->next;
	if(i==0) return L;
	if(i<1) return NULL;
	while(p!=NULL && j<i){
		p=p->next;
		j++;
	}
	return p;
}

//��ֵ���룬�ҵ�������==e�Ľ��
LNode * LocateElem(LinkList L, int e){
	LNode *p = L->next;
	while(p!=NULL && p->data!=e)
		p = p->next;
	return p;
}

//���ĳ���
int Length(LinkList L){
	LNode *p = L;
	int len = 0;
	while(p->next != NULL){
		len++;
		p = p->next;
	}
	return len;
} 

//bool ListInsert(LinkList &L, int i, int e){//����ͷ��� 
//	if(i<1) return false;
//	if(i==1){
//		LNode *s=(LNode *)malloc(sizeof(LNode));
//		s->data = e;
//		s->next = L;
//		L = s;
//		return true;
//	} 
//	LNode *p;
//	int j=1;
//	p = L;
//	while (p!=NULL && j<i-1) {
//		p=p->next;
//		j++;
//	}
//	if(p==NULL) return false;
//	LNode *s = (LNode *)malloc(sizeof(LNode));
//	s->data=e;
//	s->next=p->next;
//	p->next=s;
//	return ture;
//}

bool ListInsert(LinkList &L, int i, int e){//��ͷ��� 
	//LNode *p = GetElem(L, i-1)
	if(i<1) return false;
	LNode *p;
	int j=0;
	p = L;
	while (p!=NULL && j<i-1) {
		p=p->next;
		j++;
	}
	// return InsertNextNode(p, e) ��װ�ĺô� 
	if(p==NULL) return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

//����������p���֮�����e 
bool InsertNextNode(LNode *p, int e){
	if(p==NULL) return false;
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true;
}

//ǰ���������p���֮ǰ������s 
bool InsertPriorNode(LNode *p, LNode *s){
	if(p==NULL) return false;
	if(s==NULL) return false;
	s->next = p->next;
	p->next = s;
	int temp = p->data;
	p->data = s->data;
	s->data = temp;
	return true;
} 

//��λ��ɾ������ͷ��㣩
bool ListDelete(LinkList &L, int i, int &e){
	if(i<1) return false;
	LNode *p;
	int j=0;
	p = L;
	while (p!=NULL && j<i-1) {
		p=p->next;
		j++;
	}
	if(p==NULL) return false;
	LNode *q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
} 

//ɾ��ָ�����p
bool DeleteNode(LNode *p){
	if(p==NULL) return false;
	LNode *q = p->next;
	p->data = q->data;
	p->next = q->next;
	free(q);
	return true;
} 


int main(){
	LinkList L;
	InitList(L);
	return 0;
}
