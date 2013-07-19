#include<iostream>
#include<hash_map>
using namespace std;
//基本原型接口——相当于Clonable
class Prototype
{
public:
	virtual Prototype* Clone()=0;
	virtual ~Prototype(){}
};
//原型管理器
class PrototypeMgr
{
	hash_map<char*,Prototype*>map;
public:
	void regProto(char* key,Prototype*p)
	{
		if(map.find(key)!=map.end())
		{
			delete map[key];
		}
		map[key]=p;
	}
	Prototype* const operator[](char* key)
	{
		if(map.find(key)!=map.end())
		{
			return map[key]->Clone();
		}
		else
			return NULL;
	}
	~PrototypeMgr()
	{
		for(hash_map<char*,Prototype*>::iterator it=map.begin();
			it!=map.end();++it)
		{
			delete it->second;
		}
	}
};
//浅拷贝
class ConcretePrototype1:public Prototype
{
	int * refMember;
	int member;
public:
	virtual Prototype* Clone()
	{
		cout<<"执行ConcretePrototype1的浅复制"<<endl;
		ConcretePrototype1*copy= new ConcretePrototype1;
		copy->member=member;
		copy->refMember=refMember;
		return copy;
	}
};
//深度拷贝
class ConcretePrototype2:public Prototype
{
	int * refMember;
	int member;
public:
	ConcretePrototype2():refMember(new int){}
	virtual Prototype* Clone()
	{
		cout<<"执行ConcretePrototype2的深复制"<<endl;
		ConcretePrototype2*copy= new ConcretePrototype2;
		copy->member=member;
		copy->refMember=new int;//指针引用数据也要拷贝
		*copy->refMember=*refMember;
		return copy;
	}
	virtual~ConcretePrototype2()
	{
		delete refMember;
	}
};

void TestPrototype()
{
	PrototypeMgr mgr;
	//注册原型
	mgr.regProto("浅复制",new ConcretePrototype1);
	mgr.regProto("深复制",new ConcretePrototype2);
	//请求原型
	Prototype*cp1=mgr["浅复制"];
	Prototype*cp2=mgr["深复制"];
	delete cp1;
	delete cp2;
}