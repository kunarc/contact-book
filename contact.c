#include "contact.h"
void Loadcontact(contact* p)  实现通讯录加载函数
{
	FILE* pf = fopen（“contact.dat“， ”r“）;
	if (pf == NULL)
	{
		perror("Loadcontact");
		return;
	}
	int i = 0;
	while (fread(p->date+i, sizeof(struct people), 1, pf))
	{
		p->sz++; i++; 
		if (p->sz == p->capacity)
		{
			struct people* ptr = (struct people*)realloc(p->date, (ADD + p->capacity) * sizeof(struct people));
			if (ptr == NULL)
			{
				perror(" Loadcontact");
				return;
			}
			p->date = ptr;
			p->capacity += ADD;
			
						}
	}
	fclose(pf);
	pf = NULL;
}
void Initcontact(contact* p)  初始化通讯录
{
	p->sz = 0; p->capacity = MAXCONTACT;
	struct people*ptr= (struct people*)malloc(MAXCONTACT * sizeof(struct people));
	if (ptr == NULL)
	{
		perror("Initcontact");
		return;
	}
	p->date = ptr;
	Loadcontact(p);
	}
void savecontact(contact* p) 保存联系人
{ 
 利用文件函数存储联系人信息
	FILE* pf = fopen("contact.dat", "w");
	if (pf == NULL)  
	{
		perror("savecontact");
		return;
	}
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		fwrite(p->date + i, sizeof(struct people), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
int Find_by_name(contact* p, char* name) 用名字查找联系人
{
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(p->date[i].name, name) == 0)
		{
			return i;
		}
		
	}
		
		return -1;
	}
void Addcontact(contact* p) 添加联系人
{
	if (p->sz == MAX)
	{
		printf("联系人已满，无法添加\n");
		return;
	}
	if (p->capacity > p->sz)
	{
		printf("请输入姓名\n");
		scanf("%s", p->date[p->sz].name);
		printf("请输入性别\n");
		scanf("%s", p->date[p->sz].sex);
		printf("请输入年龄\n");
		scanf("%d", &(p->date[p->sz].age));
		printf("请输入地址\n");
		scanf("%s", p->date[p->sz].add);
		printf("请输入电话\n");
		scanf("%s", p->date[p->sz].tell);
		p->sz++;
		printf("添加成功\n");
	}
	else
	{
		struct people* ptr = (struct people*)realloc(p->date, (ADD + p->capacity) * sizeof(struct people));
		if (ptr == NULL)
		{
			perror("Addcontact");
			return;
		}
		p->date = ptr;
		p->capacity += ADD;
	}
}
	
void Delcontact(contact* p) 删除联系人
{
	char name[20] = { 0 };
	printf("请输入你要删除的姓名\n");
	scanf("%s", name);
	int ret=Find_by_name(p, name);
	if (ret == -1)
	{
		printf("没有找到该联系人\n");
		return;
	}
	else
	{
		int i = ret;
		for (i = ret; i <p-> sz-1; i++)
		{
			p->date[i] = p->date[i + 1];
		}
		p->sz--;
		p->capacity--;
		struct people* ptr = (struct people*)realloc(p->date, (p->capacity) * sizeof(struct people));
		if (ptr == NULL)
		{
			perror("Delcontact");
			printf("删除失败\n");
			return;
		}
		p->date = ptr;
		
	}
	printf("联系人已经删除\n");
}
void printcontact(contact* p)  打印联系人信息
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
	for (i = 0; i < p->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-20s\t%-12s\n", p->date[i].name, p->date[i].age, p->date[i].sex, p->date[i].add, p->date[i].tell);
	}
}
void modifycontact(contact* p) 修改通讯录
{
	char name[20] = { 0 };
	printf("请输入你要修改的姓名\n");
	scanf("%s", name);
	int ret = Find_by_name(p, name);
	if (ret == -1)
	{
		printf("没有找到该联系人\n");
		return;
	}
	else
	{
		printf("请输入姓名\n");
		scanf("%s", p->date[ret].name);
		printf("请输入性别\n");
		scanf("%s", p->date[ret].sex);
		printf("请输入年龄\n");
		scanf("%d", &(p->date[ret].age));
		printf("请输入地址\n");
		scanf("%s", p->date[ret].add);
		printf("请输入电话\n");
		scanf("%s", p->date[ret].tell);
		printf("修改成功\n");
		return;
	}
	}
void findcontact(contact* p) 查找联系人
{
	char name[20] = { 0 };
	printf("请输入你要查找的姓名\n");
	scanf("%s", name);
	int ret = Find_by_name(p, name);
	if (ret == -1)
	{
		printf("没有找到该联系人\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-20s\t%-12s\n", "姓名", "年龄", "性别", "地址", "电话");
		printf("%-20s\t%-5d\t%-5s\t%-20s\t%-12s\n", p->date[ret].name, p->date[ret].age, p->date[ret].sex, p->date[ret].add, p->date[ret].tell);
	}
}
void freecapacity(contact* p)  销毁通讯录
{
	free(p->date);
	p->date = NULL;
	p->sz = 0;
	p->capacity = 0;
}
