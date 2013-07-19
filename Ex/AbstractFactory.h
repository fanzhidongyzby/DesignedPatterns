#include<iostream>
using namespace std;
//��Ʒ��̳в��
class Button
{
public:
	virtual void click()=0;
	virtual ~Button(){}
};
class WindowsButton:public Button
{
public:
	virtual void click()
	{
		cout<<"������Windows��ť"<<endl;
	}
};
class MacButton:public Button
{
public:
	virtual void click()
	{
		cout<<"������Mac��ť"<<endl;
	}
};
class Menu
{
public:
	virtual void select()=0;
	virtual ~Menu(){}
};
class WindowsMenu:public Menu
{
public:
	virtual void select()
	{
		cout<<"ѡ����Windows�˵�"<<endl;
	}
};
class MacMenu:public Menu
{
public:
	virtual void select()
	{
		cout<<"ѡ����Mac�˵�"<<endl;
	}
};
//���󹤳�
class GUIFactory
{
public:
	virtual Button*createButton()=0;
	virtual Menu*createMenu()=0;
	virtual ~GUIFactory(){}
};
//����Ĺ���
class WindowsGUIFactory:public GUIFactory
{
public:
	virtual Button*createButton()
	{
		return new WindowsButton();
	}
	virtual Menu*createMenu()
	{
		return new WindowsMenu();
	}
};
class MacGUIFactory:public GUIFactory
{
public:
	virtual Button*createButton()
	{
		return new MacButton();
	}
	virtual Menu*createMenu()
	{
		return new MacMenu();
	}
};
void TestAbstractFactory()
{
	GUIFactory*factory=new WindowsGUIFactory();//��������
	Button*btn=factory->createButton();//�������
	Menu*menu=factory->createMenu();
	btn->click();//�����������
	menu->select();
	delete btn;
	delete menu;
	delete factory;
}