#include<iostream>
#include<list>
using namespace std;
//元素基类
class Visitor;
class Element
{
public:
	virtual void accept(Visitor*)=0;
	virtual ~Element(){}
};
//访问者基类
class ConcreteElementA;
class ConcreteElementB;
class Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA*)=0;
	virtual void visitConcreteElementB(ConcreteElementB*)=0;
	virtual ~Visitor(){}
};
//具体元素
class ConcreteElementA:public Element
{
public:
	virtual void accept(Visitor*v)
	{
		v->visitConcreteElementA(this);//双向分派
	}
	void operationA()
	{
		cout<<"对元素A的处理"<<endl;
	}
};
class ConcreteElementB:public Element
{
public:
	virtual void accept(Visitor*v)
	{
		v->visitConcreteElementB(this);
	}
	void operationB()
	{
		cout<<"对元素B的处理"<<endl;
	}
};
//具体的访问者
class ConcreteVisitor1:public Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA*ea)
	{
		cout<<"访问者1";
		ea->operationA();
	}
	virtual void visitConcreteElementB(ConcreteElementB*eb)
	{
		cout<<"访问者1";
		eb->operationB();
	}
};
class ConcreteVisitor2:public Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA*ea)
	{
		cout<<"访问者2";
		ea->operationA();
	}
	virtual void visitConcreteElementB(ConcreteElementB*eb)
	{
		cout<<"访问者2";
		eb->operationB();
	}
};
//管理和遍历元素集合的高层类
class ObjectStruct
{
	list<Element*>data;
public:
	void addElement(Element*e)
	{
		data.push_back(e);
	}
	void delElement(Element*e)
	{
		data.remove(e);
	}
	void dispaly(Visitor*v)
	{
		for(list<Element*>::iterator it=data.begin();
			it!=data.end();++it)
		{
			(*it)->accept(v);
		}
	}
	~ObjectStruct()
	{
		for(list<Element*>::iterator it=data.begin();
			it!=data.end();++it)
		{
			delete (*it);
		}
	}
};
void TestVisitor()
{
	ObjectStruct os;//初始化集合
	os.addElement(new ConcreteElementA());
	os.addElement(new ConcreteElementB());
	os.addElement(new ConcreteElementB());
	os.addElement(new ConcreteElementA());
	Visitor*v1=new ConcreteVisitor1();//创建访问者1
	Visitor*v2=new ConcreteVisitor2();
	os.dispaly(v1);//用访问者1对元素进行操作【双向分派】
	os.dispaly(v2);
}