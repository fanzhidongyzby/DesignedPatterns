#include<iostream>
using namespace std;
//�ײ�ʵ�ֲ���
class WindowImp
{
public:
	virtual void devDrawText()=0;
	virtual void devDrawLine()=0;
	virtual ~WindowImp(){}
};
class XWindowImp:public WindowImp
{
public:
	virtual void devDrawText()
	{
		cout<<"XWindow--Text"<<endl;
	}
	virtual void devDrawLine()
	{
		cout<<"XWindow--Line"<<endl;
	}
};
class PMWindowImp:public WindowImp
{
public:
	virtual void devDrawText()
	{
		cout<<"PMWindow--Text"<<endl;
	}
	virtual void devDrawLine()
	{
		cout<<"PMWindow--Line"<<endl;
	}
};
//�߲���󲿷�
class Window
{
	WindowImp*imp;//�ײ�ʵ��
public:
	Window(WindowImp*i):imp(i){}
	virtual void drawText()
	{
		imp->devDrawText();
	}
	virtual void drawRect()
	{
		imp->devDrawLine();
		imp->devDrawLine();
		imp->devDrawLine();
		imp->devDrawLine();
	}
	virtual ~Window()
	{
		delete imp;
	}
};
class IconWindow:public Window
{
public:
	IconWindow(WindowImp*i):Window(i){}
	virtual void drawBoard()
	{
		drawRect();
		drawText();
	}
};
class TrasientWindow:public Window
{
public:
	TrasientWindow(WindowImp*i):Window(i){}
	virtual void drawCloseBox()
	{
		drawRect();
	}
};

void TestBridge()
{
	WindowImp*imp=new XWindowImp();
	Window w(imp);
	w.drawText();
	w.drawRect();
	imp=new PMWindowImp();
	IconWindow iw(imp);
	iw.drawBoard();
}