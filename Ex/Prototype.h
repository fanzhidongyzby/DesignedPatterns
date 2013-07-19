#include<iostream>
#include<hash_map>
using namespace std;
//����ԭ�ͽӿڡ����൱��Clonable
class Prototype
{
public:
	virtual Prototype* Clone()=0;
	virtual ~Prototype(){}
};
//ԭ�͹�����
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
//ǳ����
class ConcretePrototype1:public Prototype
{
	int * refMember;
	int member;
public:
	virtual Prototype* Clone()
	{
		cout<<"ִ��ConcretePrototype1��ǳ����"<<endl;
		ConcretePrototype1*copy= new ConcretePrototype1;
		copy->member=member;
		copy->refMember=refMember;
		return copy;
	}
};
//��ȿ���
class ConcretePrototype2:public Prototype
{
	int * refMember;
	int member;
public:
	ConcretePrototype2():refMember(new int){}
	virtual Prototype* Clone()
	{
		cout<<"ִ��ConcretePrototype2�����"<<endl;
		ConcretePrototype2*copy= new ConcretePrototype2;
		copy->member=member;
		copy->refMember=new int;//ָ����������ҲҪ����
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
	//ע��ԭ��
	mgr.regProto("ǳ����",new ConcretePrototype1);
	mgr.regProto("���",new ConcretePrototype2);
	//����ԭ��
	Prototype*cp1=mgr["ǳ����"];
	Prototype*cp2=mgr["���"];
	delete cp1;
	delete cp2;
}