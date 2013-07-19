#include<iostream>
using namespace std;
//Ŀ��ӿ�
class Target
{
public:
	virtual void request()=0;
	virtual ~Target(){}
};
//������Ľӿ�
class Adaptee
{
public:
	virtual void specificRequest()
	{
		cout<<"����Ľӿ�"<<endl;
	}
};
//������
class Adapter:public Target
{
	Adaptee *adaptee;
public:
	Adapter(Adaptee*ad):adaptee(ad){}
	virtual void request()
	{
		adaptee->specificRequest();//��������
	}
	virtual ~Adapter()
	{
		delete adaptee;
	}
};

void TestAdapter()
{
	Target* target=new Adapter(new Adaptee);
	target->request();//һ������
	delete target;
}