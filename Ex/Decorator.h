#include<iostream>
using namespace std;
class AbstractComponent
{
public:
	virtual string operation()=0;
	virtual ~AbstractComponent(){}
};
class ConcreteComponent:public AbstractComponent
{
public:
	virtual string operation()
	{
		return "基本对象";
	}
};
class Decorator:public AbstractComponent
{
protected:
	AbstractComponent*pAbsComponent;
public:
	Decorator(AbstractComponent*pac):pAbsComponent(pac){}
	virtual~Decorator()
	{
		delete pAbsComponent;
	}
};
class ConcreteDecorator:public Decorator
{
public:
	ConcreteDecorator(AbstractComponent*pac):Decorator(pac){}
	virtual string operation()
	{
		string str="装饰后的";
		str+=pAbsComponent->operation();
		return str;
	}
};
void TestDecorator()
{
	AbstractComponent*pac=
		new ConcreteDecorator(
			new ConcreteDecorator(
				new ConcreteComponent()
		));
	cout<<pac->operation().c_str()<<endl;
	delete pac;
}