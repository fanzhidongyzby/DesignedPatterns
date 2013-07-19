#include<iostream>
using namespace std;
//目标接口
class Target
{
public:
	virtual void request()=0;
	virtual ~Target(){}
};
//被适配的接口
class Adaptee
{
public:
	virtual void specificRequest()
	{
		cout<<"特殊的接口"<<endl;
	}
};
//适配器
class Adapter:public Target
{
	Adaptee *adaptee;
public:
	Adapter(Adaptee*ad):adaptee(ad){}
	virtual void request()
	{
		adaptee->specificRequest();//适配请求
	}
	virtual ~Adapter()
	{
		delete adaptee;
	}
};

void TestAdapter()
{
	Target* target=new Adapter(new Adaptee);
	target->request();//一般请求
	delete target;
}