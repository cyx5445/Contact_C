#pragma once

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDRESS 30

/*��������*/

/*�˵���Ϣ*/
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;


/*ͨѶ¼*/
typedef struct Contact
{
	PeoInfo data[MAX];	/*����˵���Ϣ*/
	int count;			/*��¼��ǰʵ���˵ĸ���*/
}Contact;

void InitContact(Contact* pc);			/*��ʼ��ͨѶ¼*/
void AddContact(Contact* pc);			/*����ͨѶ¼*/
void ShowContact(const Contact* pc);	/*��ʾͨѶ¼��Ϣ*/
void DelContact(Contact* pc);			/*ɾ��ָ����ϵ��*/
void SerachContact(Contact* pc);		/*����ָ����ϵ��*/
void ModifyContact(Contact* pc);		/*�޸�ָ����ϵ��*/
void SortContact(Contact* pc);			/*������ϵ��*/