#include "contact.h"
void Loadcontact(contact* p)
{
	FILE* pf = fopen("contact.dat", "r");
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
void Initcontact(contact* p)
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
void savecontact(contact* p)
{
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
int Find_by_name(contact* p, char* name)
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
void Addcontact(contact* p)
{
	if (p->sz == MAX)
	{
		printf("��ϵ���������޷����\n");
		return;
	}
	if (p->capacity > p->sz)
	{
		printf("����������\n");
		scanf("%s", p->date[p->sz].name);
		printf("�������Ա�\n");
		scanf("%s", p->date[p->sz].sex);
		printf("����������\n");
		scanf("%d", &(p->date[p->sz].age));
		printf("�������ַ\n");
		scanf("%s", p->date[p->sz].add);
		printf("������绰\n");
		scanf("%s", p->date[p->sz].tell);
		p->sz++;
		printf("��ӳɹ�\n");
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
	
void Delcontact(contact* p)
{
	char name[20] = { 0 };
	printf("��������Ҫɾ��������\n");
	scanf("%s", name);
	int ret=Find_by_name(p, name);
	if (ret == -1)
	{
		printf("û���ҵ�����ϵ��\n");
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
			printf("ɾ��ʧ��\n");
			return;
		}
		p->date = ptr;
		
	}
	printf("��ϵ���Ѿ�ɾ��\n");
}
void printcontact(contact* p)
{
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
	for (i = 0; i < p->sz; i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-20s\t%-12s\n", p->date[i].name, p->date[i].age, p->date[i].sex, p->date[i].add, p->date[i].tell);
	}
}
void modifycontact(contact* p)
{
	char name[20] = { 0 };
	printf("��������Ҫ�޸ĵ�����\n");
	scanf("%s", name);
	int ret = Find_by_name(p, name);
	if (ret == -1)
	{
		printf("û���ҵ�����ϵ��\n");
		return;
	}
	else
	{
		printf("����������\n");
		scanf("%s", p->date[ret].name);
		printf("�������Ա�\n");
		scanf("%s", p->date[ret].sex);
		printf("����������\n");
		scanf("%d", &(p->date[ret].age));
		printf("�������ַ\n");
		scanf("%s", p->date[ret].add);
		printf("������绰\n");
		scanf("%s", p->date[ret].tell);
		printf("�޸ĳɹ�\n");
		return;
	}
	}
void findcontact(contact* p)
{
	char name[20] = { 0 };
	printf("��������Ҫ���ҵ�����\n");
	scanf("%s", name);
	int ret = Find_by_name(p, name);
	if (ret == -1)
	{
		printf("û���ҵ�����ϵ��\n");
		return;
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-20s\t%-12s\n", "����", "����", "�Ա�", "��ַ", "�绰");
		printf("%-20s\t%-5d\t%-5s\t%-20s\t%-12s\n", p->date[ret].name, p->date[ret].age, p->date[ret].sex, p->date[ret].add, p->date[ret].tell);
	}
}
void freecapacity(contact* p)
{
	free(p->date);
	p->date = NULL;
	p->sz = 0;
	p->capacity = 0;
}