#include "contact.h"
void menu()    //打印菜单
{
	printf("********************************\n");
	printf("********1.add  2.delect*********\n");
	printf("********     3.print  **********\n");
	printf("********4.modify 5.find*********\n");
	printf("************0.excit*************\n");
}

int main()
{
	
	Initcontact(&con);//初始化通讯录
	int input = 0;
		do  //无论如何都要进行一次
	{
		menu();
		printf("请选择\n");
		scanf("%d", &input);//选择功能
		
		switch (input)
		{
		case 1:
			Addcontact(&con);//添加联系人
			break;
		case 2:
			Delcontact(&con);//删除联系人
			break;
		case 3:
			sort(&con);//对联系人
			break;
		case 4:
			printcontact(&con);//打印信息
			break;
		case 5:
			modifycontact(&con);//修改联系人
			break;
		case 6:
			findcontact(&con);//查找联系人
			break;
		case 0:
			savecontact(&con);//保存联系人
			freecapacity(&con);//释放空间
			break;
		default:
			printf("选择错误请重新选择：\n");
		}
	} while (input);
	return 0;
}
