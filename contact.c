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
		printf("ͨѶ¼�������޷����\n");
		return;
	}

	printf("���������֣�");
	scanf_s("%s", pc->data[pc->count].name, MAX_NAME);
	printf("���������䣺");
	scanf_s("%d", &pc->data[pc->count].age);
	printf("�������Ա�");
	scanf_s("%s", pc->data[pc->count].sex, MAX_SEX);
	printf("������绰��");
	scanf_s("%s", pc->data[pc->count].tele, MAX_TELE);
	printf("�������ַ��");
	scanf_s("%s", pc->data[pc->count].address, MAX_ADDRESS);

	pc->count++;
	printf("���ӳɹ���\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("ͨѶ¼Ϊ��");
		return;
	}

	printf("������ָ��ɾ���˵����֣�");
	scanf_s("%s", name, MAX_NAME);

	/*1.����*/
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
		return;
	}
	
	/*2.ɾ��*/
	for (int i = pos; i < pc->count - 1; i++)	/*���ǰ�Ḳ������*/
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	
	printf("ɾ���ɹ���\n");
}

void SerachContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("����������˵����֣�");
	scanf_s("%s", name, MAX_NAME);

	//1.����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	
	//2.��ӡ
	printf("%20s\t%5s\t%5s\t%12s\t%30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
	printf("������Ҫ�޸��˵����֣�");
	scanf_s("%s", name, MAX_NAME);

	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
		return;
	}
	printf("���޸�\n");
	printf("���������֣�");
	scanf_s("%s", pc->data[pos].name, MAX_NAME);
	printf("���������䣺");
	scanf_s("%d", &pc->data[pos].age);
	printf("�������Ա�");
	scanf_s("%s", pc->data[pos].sex, MAX_SEX);
	printf("������绰��");
	scanf_s("%s", pc->data[pos].tele, MAX_TELE);
	printf("�������ַ��");
	scanf_s("%s", pc->data[pos].address, MAX_ADDRESS);
	printf("�޸ĳɹ���\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	assert(pc);

	//1.��������������
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("����ɹ�!\n");
}