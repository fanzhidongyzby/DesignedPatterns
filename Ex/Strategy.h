#include<iostream>
using namespace std;
class Strategy
{
public:
	virtual bool algorithmInterface(int x,int y)=0;
	virtual ~Strategy(){}
};
class UpStrategy:public Strategy
{
public:
	virtual bool algorithmInterface(int x,int y)
	{
		return x<y;
	}
};
class DownStrategy:public Strategy
{
public:
	virtual bool algorithmInterface(int x,int y)
	{
		return x>y;
	}
};
class Context
{
	Strategy*pStrategy;
public:
	Context(Strategy*ps):pStrategy(ps){}
	void sort()
	{
		if(pStrategy->algorithmInterface(1,2))
		{
			cout<<"1£¬2ÓÐÐò"<<endl;
		}
		else
		{
			cout<<"1£¬2·´Ðò"<<endl;
		}
	}
	~Context()
	{
		delete pStrategy;
	}
};
void TestStrategy()
{
	Context c1(new UpStrategy());
	c1.sort();
	Context c2(new DownStrategy());
	c2.sort();
}