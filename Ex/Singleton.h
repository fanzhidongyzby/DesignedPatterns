#include<iostream>
using namespace std;
class Singleton
{
protected://���ù��졢����������
	Singleton(){}
	Singleton(const Singleton&){}
	Singleton&operator=(const Singleton&){}
public://���ص�������
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}
	void operation()
	{
		cout<<"����"<<endl;
	}
};

void TestSingleton()
{
	Singleton*ps=&Singleton::getInstance();
	Singleton&s=Singleton::getInstance();
	Singleton::getInstance().operation();
	ps->operation();
	s.operation();
}