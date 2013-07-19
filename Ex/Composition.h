#include<iostream>
#include<list>
using namespace std;
class Component
{
public:
	virtual void operation()=0;
	virtual void add(Component*)=0;
	virtual void remove(Component*)=0;
	virtual Component* getChild(int i)=0;
	virtual ~Component(){}
};
class Composite:public Component
{
	list<Component*> children;
public:
	virtual void operation()
	{
		cout<<"组合对象(";
		for(list<Component*>::iterator it=children.begin();it!=children.end();++it)
		{
			(*it)->operation();
			cout<<" ";
		}
		cout<<")";
	}
	virtual void add(Component*pc)
	{
		children.push_back(pc);
	}
	virtual void remove(Component*pc)
	{
		children.remove(pc);
	}
	virtual Component* getChild(int i)
	{
		list<Component*>::iterator it;
		for(it=children.begin();it!=children.end()&&(i>0);++it,--i);
		return *it;
	}
	virtual ~Composite()
	{
		for(list<Component*>::iterator it=children.begin();it!=children.end();++it)
		{
			delete *it;
		}
	}
};
class Leaf:public Component
{
public:
	virtual void operation()
	{
		cout<<"基本对象";
	}
	virtual void add(Component*pc){}
	virtual void remove(Component*pc){}
	virtual Component* getChild(int i){return NULL;}
};
int TestComposition()
{
	Component*pc1=new Composite();
	pc1->add(new Leaf());
	Component*pc2=new Composite();
	pc2->add(new Leaf());
	pc1->add(pc2);
	pc1->operation();
	delete pc1;
}