#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

/*
ʵ��һ��ͨѶ¼��
�˵���Ϣ�����֡����䡢�Ա𡢵绰����ַ
���ܣ�	1.���100���˵���Ϣ
		2.������ϵ��
		3.ɾ��ָ����ϵ��
		4.������ϵ��
		5.�޸���ϵ��
		6.����
		7.��ʾ��ϵ��
*/

void menu()
{
	printf("***************************************************\n");
	printf("**************1.add    2.del   ********************\n");
	printf("**************3.search 4.modify********************\n");
	printf("**************5.show     6.sort********************\n");
	printf("**************  0.exit         ********************\n");
	printf("***************************************************\n");

}

int main()
{
	int input = 0;

	Contact con;

	/*��ʼ��ͨѶ¼*/
	InitContact(&con);

	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
			case 1:
				AddContact(&con);
				break;
			case 2:
				DelContact(&con);
				break;
			case 3:
				SerachContact(&con);
				break;
			case 4:
				ModifyContact(&con);
				break;
			case 5:
				ShowContact(&con);
				break;
			case 6:
				SortContact(&con);
				break;
			default:
				printf("ѡ�����");
			case 0:
				printf("�˳�");
				break;
		}
	} while (input);

	return 0;
}