#include <iostream>
#include <string>
#include<string.h>
using namespace std;
//菜单界面
void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****1、添加联系人*****" << endl;
	cout << "*****2、显示联系人*****" << endl;
	cout << "*****3、删除联系人*****" << endl;
	cout << "*****4、查找联系人*****" << endl;
	cout << "*****5、修改联系人*****" << endl;
	cout << "*****6、清空联系人*****" << endl;
	cout << "*****0、退出联系人*****" << endl;
	cout << "***********************" << endl;
}

struct Person
{
	string m_Name;//姓名
	int m_Sex;//性别
	int m_Age;//年龄
	string m_Phone;//联系电话
	string m__Addr;//家庭住址

};
#define MAX 1000
struct Addressbooks
{
	struct Person personArray[MAX];//通讯录中保存的联系人的数组
	int m_Size;//通讯录中人员个数
};
// 添加通讯录成员
void addPerson(Addressbooks *abs)
{
	//判断通讯录是否已满
	if (abs->m_Size==MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;

    }
	else
	{
		
		//姓名
		string name;
	    cout << "请输入要添加的联系人姓名：" << endl;
		
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
			//性别
		int sex = 0;
		cout << "请输入联系人性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
		 cout << "请输入数字1或者2" << endl;
			
		}
					//年龄
		int age;
		cout << "请输入联系人年龄："<<endl;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

			//电话
		string phone;
		cout << "请输入联系人的电话号码：/n" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

			//住址
		cout << "请输入联系人住址：/n" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m__Addr = address;
		++abs->m_Size;
		cout << "添加成功！" << endl;
		system("pause");
		system("cls");
			
	}
	
};
 //显示通讯录成员
 //void displayPerson(Addressbooks *abs)
 //{
 //	if (abs->m_Size==0)
 //	{
 //		cout << "未保存联系人" << endl;
 //	}
 //	else
 //	{
 //	 for (int i = 0; i < abs->m_Size; i++)
 //	 {
 //		cout << "姓名：" << abs->personArray[abs->m_Size].m_Name << endl;
 //		cout << "性别：" << abs->personArray[abs->m_Size].m_Sex << endl;
 //		cout << "年龄：" << abs->personArray[abs->m_Size].m_Age << endl;
 //		cout << "电话：" << abs->personArray[abs->m_Size].m_Phone << endl;
 //		cout << "住址：" << abs->personArray[abs->m_Size].m__Addr << endl;
 //	 }
 //	}
 //};
//显示联系人
void shouPerson(Addressbooks abs)
{
	if (abs.m_Size == 0)
	{
		cout << "未保存联系人" << endl;
	}
	else
	{


		for (int i = 0; i < abs.m_Size; i++)
		{
			//cout << "**************" << endl;
			cout << "序号：" << i << "\t";
			cout << "姓名：" << abs.personArray[i].m_Name << "\t";
			cout << "性别：" << abs.personArray[i].m_Sex << "\t";
			cout << "年龄：" << abs.personArray[i].m_Age << "\t";
			cout << "电话：" << abs.personArray[i].m_Phone << "\t";
			cout << "住址：" << abs.personArray[i].m__Addr << endl;
			//cout << "**************" << endl;

		}
		
	}
	system("pause");
	system("cls");

}
//查找输入的姓名
int checkperson(Addressbooks *abs,string name)
{
	
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name==name)
		{
			return i;
		}
		
	}
	return -1;
}
//删除联系人
void deletePerson(Addressbooks *abs)
{
    gg:
	cout << "请输入想要删除的序号或者姓名：" << endl;
	char ch;
	string name;
	//cin >> name;
	cin >> ch;
	name = ch;
	if (ch >= '0'&&ch <= '1000')
	{
	
		int x;
		cout << "删除该序号的联系人后，序号后的联系人的序号将会向前移一位！" << endl;
		cout << "你是否要执行？" << endl;
		cout << "1、是   2、否" << endl;
		cin >> x;
		if (x==2)
		{
			int b = 0;
			cout << "你是否要继续删除联系人：" << endl;
			cout << "1、是   2、否" << endl;
			cin >> b;
			if (b==1)
			{
				goto gg;//退出if语句 继续执行
			}
			else
			{

			}
		}
		else
		{
			int a;
			a = (int)(ch - '0');
			//删除联系人，并将后面的联系人前移
			for (a; a <= abs->m_Size; a++)
			{
				abs->personArray[a] = abs->personArray[a + 1];
			}
			//free(abs->personarray[abs->m_size]); //删除重复的最后一个联系人
			abs->m_Size--;
			cout << "删除成功" << endl;
		}
		
	}
	else 
	{
		//ret=-1 未查到
		//ret！=-1 查到了
		int ret = checkperson(abs, name);
		if (ret!=-1)
		{
			for (ret; ret < abs->m_Size;ret++)
			{
				//数据前移
				abs->personArray[ret] = abs->personArray[ret + 1];
			}
			abs->m_Size--;
			cout << "删除成功" << endl;

		}
		else
		{
			cout << "通讯录中没有此姓名" << endl;
		}
	}
		system("pause");
		system("cls");
}
//查找联系人
void findPerson(Addressbooks *abs)
{
	string name;
	cout << "请输入查找联系人的姓名：" << endl;
	cin >> name;
	int check = checkperson(abs, name);
	if (check==-1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout << "序号：" << check << "\t";
		cout << "姓名：" << abs->personArray[check].m_Name << "\t";
		cout << "性别：" << abs->personArray[check].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[check].m_Age << "\t";
		cout << "电话：" << abs->personArray[check].m_Phone << "\t";
		cout << "住址：" << abs->personArray[check].m__Addr << endl;
	}
	system("pause");
	system("cls");
	
}
//修改联系人
void  modifyPerson(Addressbooks *abs)
{
	cout << "请输入要修改的姓名：" << endl;
	string name;
	cin >> name;
	int check=checkperson(abs,name);
	if (check==-1)
	{
		cout << "查无此人" << endl;

	}
	else
	{
		kk:
		cout << "请输入要修改的选项：1、姓名  2、性别  3、年龄  4、联系电话  5、住址  6、不修改" << endl;
		mm:
		int i = 0;
		cin >> i;
		if (i == 1)
		{
			//姓名
			cout << "请输入修改后的姓名：" << endl;
			string name;
			cin >> name;
			abs->personArray[check].m_Name = name;
			cout << "修改完成" << endl;
			cout << "是否要修改其他选项？ 1、是  2、否" << endl;
			int a = 0;
			cin >> a;
			if (a==1)
			{
				goto kk;
			}
			else
			{

			}
		}
		else if (i == 2)
		{
			//性别
			int sex = 0;
			cout << "请输入联系人性别：" << endl;
			cout << "1---男" << endl;
			cout << "2---女" << endl;
			while (true)
			{
				cin >> sex;
				if (sex == 1 || sex == 2)
				{
					abs->personArray[check].m_Sex = sex;
					break;
				}
				cout << "请输入数字1或者2" << endl;

			}

			cout << "修改完成" << endl;
			cout << "是否要修改其他选项？ 1、是  2、否" << endl;
			int a = 0;
			cin >> a;
			if (a == 1)
			{
				goto kk;
			}
			else
			{

			}
		}
		else if (i == 3)
		{
			//年龄
			int age;
			cout << "请输入联系人年龄：" << endl;
			cin >> age;
			abs->personArray[check].m_Age = age;

			cout << "修改完成" << endl;
			cout << "是否要修改其他选项？ 1、是  2、否" << endl;
			int a = 0;
			cin >> a;
			if (a == 1)
			{
				goto kk;
			}
			else
			{

			}
		}
		else if (i == 4)
		{
			//联系电话
			string phone;
			cout << "请输入联系人的电话号码：/n" << endl;
			cin >> phone;
			abs->personArray[check].m_Phone = phone;
			cout << "修改完成" << endl;
			cout << "是否要修改其他选项？ 1、是  2、否" << endl;
			int a = 0;
			cin >> a;
			if (a == 1)
			{
				goto kk;
			}
			else
			{

			}
		}
		else if (i == 5)
		{
			//家庭住址
			cout << "请输入联系人住址：/n" << endl;
			string address;
			cin >> address;
			abs->personArray[check].m__Addr = address;
			cout << "修改完成" << endl;
			cout << "是否要修改其他选项？ 1、是  2、否" << endl;
			int a = 0;
			cin >> a;
			if (a == 1)
			{
				goto kk;
			}
			else
			{

			}
		}
		else if (i == 6)
		{
			cout << "修改完成" << endl;
			cout << "是否要修改其他选项？ 1、是  2、否" << endl;
			int a = 0;
			cin >> a;
			if (a == 1)
			{
				goto kk;
			}
			else
			{

			}
		}
		else
		{
			cout << "请输入数字1-6" << endl;
			goto mm;
		}

	}
	system("pause");
	system("cls");

	}
	//清空联系人
	void EmptyPerson(Addressbooks *abs)
	{
		cout << "清空后所有联系人数据将被删除，是否要执行？ 1、是   2、否" << endl;
		int a = 0;
		cin >> a;
		if (a==1)
		{
			abs->m_Size = 0;
			cout << "通讯录已被清空！" << endl;

		}
		else
		{

		}
		system("pause");
		system("cls");
	}
int main()
{
	//初始化通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录人员个数
	 abs.m_Size = 0;

	int select = 0;//创建用户选择输入的变量
		while (true)
	{ 
	 showMenu();
	  
	 cin >> select;
	  if (select == 0)
	  {
		cout << "欢迎下次使用" << endl;//退出菜单
		system("pause");
		return 0;
	  }
	  else if (select==1)
	  {
		  //添加联系人
		  addPerson(&abs);//利用地址传递，可以修饰实参
	  }
	  else if (select==2)
	  {
		  //显示联系人
		  //displayPerson(&abs);
		  
		  shouPerson(abs);
	
	  }
	  else if (select==3)
	  {
		  //删除联系人
		  deletePerson(&abs);
		 
	  }
	  else if (select==4)
	  {
		  //查找联系人
		  findPerson(&abs);
	  }
	  else if (select==5)
	  {
		  //修改联系人
		  modifyPerson(&abs);

	  }
	  else if (select==6)
	  {
		  //清空联系人
		  EmptyPerson(&abs);
	  }
	  else
	  {
		  cout << "请输入0到6的整数" << endl;

	  }
	}
	


}


