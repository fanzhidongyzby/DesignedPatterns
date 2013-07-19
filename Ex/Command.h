#include<iostream>
#include<vector>
using namespace std;
//具体用户操作的对象
class Image
{
public:
	void resize()
	{
		cout<<"改变图片大小"<<endl;
	}
};
class Text
{
public:
	void changeColor()
	{
		cout<<"改变文字颜色"<<endl;
	}
};
//命令
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
		cout<<"恢复图片大小"<<endl;
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
		cout<<"恢复文字颜色"<<endl;
	}
};
//命令队列
class CmdList
{
	static const unsigned int maxLen=20;
	vector<Command*>cmds;
	int curPos;//执行点——记录卡刚执行命令在队列的位置
public:
	CmdList()
	{
		curPos=-1;
	}
	void storeCmd(Command*cmd)
	{
		//从执行点往后的元素先删除
		int times=cmds.size()-curPos-1;//执行点后边元素个数
		while(times--)
		{
			delete cmds.back();//清除内存
			cmds.pop_back();
		}
		//压入新命令
		cmds.push_back(cmd);
		if(cmds.size()>maxLen)//超过了一个元素，删除第一个
		{
			cmds.erase(cmds.begin());
		}
		curPos=cmds.size()-1;//插入新的元素即刚执行过，记录位置
	}
	void unDo()//撤销
	{
		if(curPos>=0)//有效位置
		{
			cmds[curPos--]->unExecute();
		}
	}
	void reDo()//恢复
	{
		if(curPos<(int)cmds.size()-1)//后边有节点才能恢复
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
//调用者
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
	CmdList cmdList;//命令队列
	Invoker inv;//调用者
	//改变图片
	Command*rcmd=new ResizeCommand();//生成命令
	inv.operation(rcmd);//执行命令
	cmdList.storeCmd(rcmd);
	//撤销和重做
	cmdList.unDo();
	cmdList.reDo();
	//改变文字
	Command*ccmd=new ColorCommand();
	inv.operation(ccmd);
	cmdList.storeCmd(ccmd);
	//撤销和重做
	cmdList.unDo();
	cmdList.unDo();
	cmdList.reDo();
}