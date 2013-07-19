#include<iostream>
using namespace std;
//生成器接口
class Builder
{
protected:
	Builder(){}
public:
	virtual void addIntToken(){}
	virtual void addIdentToken(){}
	virtual void addSemiconToken(){}
	virtual ~Builder(){}
};
//抽象语法树
class Tree
{
public:
	void addNode(char*p)
	{
		cout<<"添加了一个"<<p<<"节点"<<endl;
	}
	void display()
	{
		cout<<"一颗完整的语法树"<<endl;
	}
};
//抽象语法树生成器
class SemanticTreeBuilder:public Builder
{
	Tree tree;
public:
	SemanticTreeBuilder(){}
	virtual void addIntToken()
	{
		tree.addNode("<Int>");
	}	
	virtual void addIdentToken()
	{
		tree.addNode("<标识符>");
	}
	virtual void addSemiconToken()
	{
		tree.addNode("<分号>");
	}
	Tree getTree()
	{
		return tree;
	}
};
//标识符个数生成器
class IdentCountBuilder:public Builder
{
	int num;
public:
	IdentCountBuilder():num(0){}
	virtual void addIdentToken()
	{
		num++;
	}
	int getIdCount()
	{
		return num;
	}
};
//词法分析器
class Parser
{
public:
	//使用生成器生成对象
	void Conctruct(Builder*builder)
	{
		builder->addIntToken();
		builder->addIdentToken();
		builder->addSemiconToken();
	}
};
void TestBuilder()
{
	Parser par;//词法分析器
	SemanticTreeBuilder treeBuilder;//语法树生成器
	par.Conctruct(&treeBuilder);//构造语法树
	Tree tree=treeBuilder.getTree();//获取构造的语法树
	tree.display();//显示语法树
	IdentCountBuilder idBuilder;//标识符个数生成器
	par.Conctruct(&idBuilder);//获取标识符个数
	cout<<"标识符个数="<<idBuilder.getIdCount()<<endl;//输出个数
}