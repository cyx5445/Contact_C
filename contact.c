#include "contact.h"


void InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->count == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}

	printf("请输入名字：");
	scanf_s("%s", pc->data[pc->count].name, MAX_NAME);
	printf("请输入年龄：");
	scanf_s("%d", &pc->data[pc->count].age);
	printf("请输入性别：");
	scanf_s("%s", pc->data[pc->count].sex, MAX_SEX);
	printf("请输入电话：");
	scanf_s("%s", pc->data[pc->count].tele, MAX_TELE);
	printf("请输入地址：");
	scanf_s("%s", pc->data[pc->count].address, MAX_ADDRESS);

	pc->count++;
	printf("增加成功！\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%30s\n",	pc->data[i].name, 
												pc->data[i].age, 
												pc->data[i].sex, 
												pc->data[i].tele, 
												pc->data[i].address);
	}
}

static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };

	if (pc->count == 0)
	{
		printf("通讯录为空");
		return;
	}

	printf("请输入指定删除人的名字：");
	scanf_s("%s", name, MAX_NAME);

	/*1.查找*/
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
		return;
	}
	
	/*2.删除*/
	for (int i = pos; i < pc->count - 1; i++)	/*逐个前提覆盖数据*/
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	
	printf("删除成功！\n");
}

void SerachContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("请输入查找人的名字：");
	scanf_s("%s", name, MAX_NAME);

	//1.查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
		return;
	}
	
	//2.打印
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%20s\t%3d\t%5s\t%12s\t%30s\n",	pc->data[pos].name,
											pc->data[pos].age,
											pc->data[pos].sex,
											pc->data[pos].tele,
											pc->data[pos].address);
}

void ModifyContact(Contact* pc)
{
	assert(pc);

	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字：");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}
	printf("请修改\n");
	printf("请输入名字：");
	scanf_s("%s", pc->data[pos].name, MAX_NAME);
	printf("请输入年龄：");
	scanf_s("%d", &pc->data[pos].age);
	printf("请输入性别：");
	scanf_s("%s", pc->data[pos].sex, MAX_SEX);
	printf("请输入电话：");
	scanf_s("%s", pc->data[pos].tele, MAX_TELE);
	printf("请输入地址：");
	scanf_s("%s", pc->data[pos].address, MAX_ADDRESS);
	printf("修改成功！\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	assert(pc);

	//1.按照名字来排序
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功!\n");
}