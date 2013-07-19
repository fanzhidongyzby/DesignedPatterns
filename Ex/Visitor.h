#include<iostream>
#include<list>
using namespace std;
//Ԫ�ػ���
class Visitor;
class Element
{
public:
	virtual void accept(Visitor*)=0;
	virtual ~Element(){}
};
//�����߻���
class ConcreteElementA;
class ConcreteElementB;
class Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA*)=0;
	virtual void visitConcreteElementB(ConcreteElementB*)=0;
	virtual ~Visitor(){}
};
//����Ԫ��
class ConcreteElementA:public Element
{
public:
	virtual void accept(Visitor*v)
	{
		v->visitConcreteElementA(this);//˫�����
	}
	void operationA()
	{
		cout<<"��Ԫ��A�Ĵ���"<<endl;
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
		cout<<"��Ԫ��B�Ĵ���"<<endl;
	}
};
//����ķ�����
class ConcreteVisitor1:public Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA*ea)
	{
		cout<<"������1";
		ea->operationA();
	}
	virtual void visitConcreteElementB(ConcreteElementB*eb)
	{
		cout<<"������1";
		eb->operationB();
	}
};
class ConcreteVisitor2:public Visitor
{
public:
	virtual void visitConcreteElementA(ConcreteElementA*ea)
	{
		cout<<"������2";
		ea->operationA();
	}
	virtual void visitConcreteElementB(ConcreteElementB*eb)
	{
		cout<<"������2";
		eb->operationB();
	}
};
//����ͱ���Ԫ�ؼ��ϵĸ߲���
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
	ObjectStruct os;//��ʼ������
	os.addElement(new ConcreteElementA());
	os.addElement(new ConcreteElementB());
	os.addElement(new ConcreteElementB());
	os.addElement(new ConcreteElementA());
	Visitor*v1=new ConcreteVisitor1();//����������1
	Visitor*v2=new ConcreteVisitor2();
	os.dispaly(v1);//�÷�����1��Ԫ�ؽ��в�����˫����ɡ�
	os.dispaly(v2);
}