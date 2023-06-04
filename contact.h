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

/*类型声明*/

/*人的信息*/
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;


/*通讯录*/
typedef struct Contact
{
	PeoInfo data[MAX];	/*存放人的信息*/
	int count;			/*记录当前实际人的个数*/
}Contact;

void InitContact(Contact* pc);			/*初始化通讯录*/
void AddContact(Contact* pc);			/*增加通讯录*/
void ShowContact(const Contact* pc);	/*显示通讯录信息*/
void DelContact(Contact* pc);			/*删除指定联系人*/
void SerachContact(Contact* pc);		/*查找指定联系人*/
void ModifyContact(Contact* pc);		/*修改指定联系人*/
void SortContact(Contact* pc);			/*排序联系人*/