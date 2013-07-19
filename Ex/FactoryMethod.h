#include<iostream>
using namespace std;
//产品类
class Car
{
public:
	virtual void beep()=0;
	virtual ~Car(){}
};
class BenziCar:public Car
{
public:
	virtual void beep()
	{
		cout<<"奔驰汽车"<<endl;
	}
};
class BMWCar:public Car
{
public:
	virtual void beep()
	{
		cout<<"宝马汽车"<<endl;
	}
};
//工厂接口
class Factory
{
public:
	virtual Car*createCar()=0;
	virtual ~Factory(){}
};
class BenziFactory:public Factory
{
public:
	virtual Car*createCar()
	{
		return new BenziCar();
	}
};
class BMWFactory:public Factory
{
public:
	virtual Car*createCar()
	{
		return new BMWCar();
	}
};
void TestFactoryMethod()
{
	Factory*factory=new BenziFactory();
	Car*car=factory->createCar();
	car->beep();
	delete car;
	delete factory;
}