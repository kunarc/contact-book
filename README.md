# contact-book
这是一个简单的通讯录，可以进行动态的存储联系人信息。实现了通讯录增删查改的功能，并使用了文件存储将信息存储在文件中，当再次执行代码时，通讯录将读取文件中存储好的联系人信息。实现了信息的存储。  

通讯录由人的信息、通讯录的空间大小和存储的人数构成，故可以声明一个结构体类型来定义此通讯录。除此之外，人的信息也能由结构体来声明，其中包含了年龄、性别、电话等等.  
`struct people`  
{  
	char name[20];  
	char sex[5];  
	char add[20];  
	char tell[12];  
	int age;  
};  
`typedef struct contact` 
{  
	struct people* date;  
	int sz;  
	int capacity;  
}contact;  
在声明通讯录过后，为了使内存不会浪费，该通讯录使用动态内存来开辟，每当增加一个联系人时，就在内存的堆区开辟一块内存共通讯录使用。每当删除一个联系人就free一块空间。防止内存的浪费。与此同时，存储的人数相应的增加和减少。

然后就是为通讯录实现增、删、查、改的功能了。每一个功能通过分装成一个函数来实现。  
void Initcontact(contact* p);  
void Addcontact(contact* p);  
void Delcontact(contact*p);  
void printcontact(contact* p);  
void modifycontact(contact* p);  
void findcontact(contact* p);  
void freecapacity(contact*p);  
void savecontact(contact*p);  
void Loadcontact(contact* p);  
最后利用文件相关的函数，将信息存储起来。实现信息的永久保存。
