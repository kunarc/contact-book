#include "contact.h"
void menu()    //��ӡ�˵�
{
	printf("********************************\n");
	printf("********1.add  2.delect*********\n");
	printf("********     3.print  **********\n");
	printf("********4.modify 5.find*********\n");
	printf("************0.excit*************\n");
}

int main()
{
	
	Initcontact(&con);//��ʼ��ͨѶ¼
	int input = 0;
		do  //������ζ�Ҫ����һ��
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);//ѡ����
		
		switch (input)
		{
		case 1:
			Addcontact(&con);//�����ϵ��
			break;
		case 2:
			Delcontact(&con);//ɾ����ϵ��
			break;
		case 3:
			sort(&con);//����ϵ��
			break;
		case 4:
			printcontact(&con);//��ӡ��Ϣ
			break;
		case 5:
			modifycontact(&con);//�޸���ϵ��
			break;
		case 6:
			findcontact(&con);//������ϵ��
			break;
		case 0:
			savecontact(&con);//������ϵ��
			freecapacity(&con);//�ͷſռ�
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
	return 0;
}
