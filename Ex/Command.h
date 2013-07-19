#include<iostream>
#include<vector>
using namespace std;
//�����û������Ķ���
class Image
{
public:
	void resize()
	{
		cout<<"�ı�ͼƬ��С"<<endl;
	}
};
class Text
{
public:
	void changeColor()
	{
		cout<<"�ı�������ɫ"<<endl;
	}
};
//����
class Command
{
public:
	virtual void execute()=0;
	virtual void unExecute()=0;
	virtual ~Command(){};
};
class ResizeCommand:public Command
{
	Image img;
public:
	virtual void execute()
	{
		img.resize();
	}
	virtual void unExecute()
	{
		cout<<"�ָ�ͼƬ��С"<<endl;
	}
};
class ColorCommand:public Command
{
	Text txt;
public:
	virtual void execute()
	{
		txt.changeColor();
	}
	virtual void unExecute()
	{
		cout<<"�ָ�������ɫ"<<endl;
	}
};
//�������
class CmdList
{
	static const unsigned int maxLen=20;
	vector<Command*>cmds;
	int curPos;//ִ�е㡪����¼����ִ�������ڶ��е�λ��
public:
	CmdList()
	{
		curPos=-1;
	}
	void storeCmd(Command*cmd)
	{
		//��ִ�е������Ԫ����ɾ��
		int times=cmds.size()-curPos-1;//ִ�е���Ԫ�ظ���
		while(times--)
		{
			delete cmds.back();//����ڴ�
			cmds.pop_back();
		}
		//ѹ��������
		cmds.push_back(cmd);
		if(cmds.size()>maxLen)//������һ��Ԫ�أ�ɾ����һ��
		{
			cmds.erase(cmds.begin());
		}
		curPos=cmds.size()-1;//�����µ�Ԫ�ؼ���ִ�й�����¼λ��
	}
	void unDo()//����
	{
		if(curPos>=0)//��Чλ��
		{
			cmds[curPos--]->unExecute();
		}
	}
	void reDo()//�ָ�
	{
		if(curPos<(int)cmds.size()-1)//����нڵ���ָܻ�
		{
			cmds[++curPos]->execute();
		}
	}
	~CmdList()
	{
		for(vector<Command*>::iterator it=cmds.begin();it!=cmds.end();++it)
		{
			delete *it;
		}
		cmds.clear();
	}
};
//������
class Invoker
{
public:
	void operation(Command*cmd)
	{
		cmd->execute();
	}
};

void TestCommand()
{
	CmdList cmdList;//�������
	Invoker inv;//������
	//�ı�ͼƬ
	Command*rcmd=new ResizeCommand();//��������
	inv.operation(rcmd);//ִ������
	cmdList.storeCmd(rcmd);
	//����������
	cmdList.unDo();
	cmdList.reDo();
	//�ı�����
	Command*ccmd=new ColorCommand();
	inv.operation(ccmd);
	cmdList.storeCmd(ccmd);
	//����������
	cmdList.unDo();
	cmdList.unDo();
	cmdList.reDo();
}