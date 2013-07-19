#include<iostream>
using namespace std;
class Singleton
{
protected://禁用构造、拷贝、复制
	Singleton(){}
	Singleton(const Singleton&){}
	Singleton&operator=(const Singleton&){}
public://返回单例引用
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}
	void operation()
	{
		cout<<"单例"<<endl;
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