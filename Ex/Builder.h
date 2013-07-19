#include<iostream>
using namespace std;
//�������ӿ�
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
//�����﷨��
class Tree
{
public:
	void addNode(char*p)
	{
		cout<<"�����һ��"<<p<<"�ڵ�"<<endl;
	}
	void display()
	{
		cout<<"һ���������﷨��"<<endl;
	}
};
//�����﷨��������
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
		tree.addNode("<��ʶ��>");
	}
	virtual void addSemiconToken()
	{
		tree.addNode("<�ֺ�>");
	}
	Tree getTree()
	{
		return tree;
	}
};
//��ʶ������������
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
//�ʷ�������
class Parser
{
public:
	//ʹ�����������ɶ���
	void Conctruct(Builder*builder)
	{
		builder->addIntToken();
		builder->addIdentToken();
		builder->addSemiconToken();
	}
};
void TestBuilder()
{
	Parser par;//�ʷ�������
	SemanticTreeBuilder treeBuilder;//�﷨��������
	par.Conctruct(&treeBuilder);//�����﷨��
	Tree tree=treeBuilder.getTree();//��ȡ������﷨��
	tree.display();//��ʾ�﷨��
	IdentCountBuilder idBuilder;//��ʶ������������
	par.Conctruct(&idBuilder);//��ȡ��ʶ������
	cout<<"��ʶ������="<<idBuilder.getIdCount()<<endl;//�������
}