#include<iostream>
using namespace std;
//产品类继承层次
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
		cout<<"单击了Windows按钮"<<endl;
	}
};
class MacButton:public Button
{
public:
	virtual void click()
	{
		cout<<"单击了Mac按钮"<<endl;
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
		cout<<"选择了Windows菜单"<<endl;
	}
};
class MacMenu:public Menu
{
public:
	virtual void select()
	{
		cout<<"选择了Mac菜单"<<endl;
	}
};
//抽象工厂
class GUIFactory
{
public:
	virtual Button*createButton()=0;
	virtual Menu*createMenu()=0;
	virtual ~GUIFactory(){}
};
//具体的工厂
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
	GUIFactory*factory=new WindowsGUIFactory();//创建工厂
	Button*btn=factory->createButton();//创建组件
	Menu*menu=factory->createMenu();
	btn->click();//调用组件函数
	menu->select();
	delete btn;
	delete menu;
	delete factory;
}