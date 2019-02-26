#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include "mltrd.h"
#include "othertools.h"
#include "map_option.h"
#include "ptl_option.h"

using namespace std;

int main()
{
	int n,Gmax,e1,e2,num;
	double w;
//*******以下内容是相关参数
	n=12;//栅格维度
	Gmax=10000;//最大迭代
	e1=2;//加速度参量
	e2=2;
	num=20;//粒子数
	w=1;//不要改
//×××××××以下内容不要修改
	cout<<"粒子数为"<<num<<endl;

	vector<int> tempmap;
	vini(tempmap,n);
	vector<vector<int>> map;
	for(int i=0;i!=n;i++)
	{
		map.push_back(tempmap);
	}
	mkmap(map,n);
	shwmap(map,n);
	cout<<endl;
	//**************以下开始运算****************
	vector<vector<int>> tmap=map;
	clock_t start,ends;
	start=clock();
	//**************计时器就绪***************


	ptl gbest;
	gbest.map=map;
	gbest.spini(n);
	gbest.ini(n);

	vector<ptl> vptl;
	for(int i=0;i<num;i++) {
		vptl.push_back(gbest);
	}

	//for(int i=0;i<num;i++) {
	//	vptl[i].ini(n);
	//}
	Dprt0(vptl, n);

	for(int gen=0;gen<Gmax;gen++) {
		cout<<"第 "<<gen<<" 代,gbest适应度为"<<gbest.fit(gbest.p, n)<<endl;
		for (int i = 0; i < num; i++) {
			double v=vptl[i].fit(vptl[i].p, n);
			double g=gbest.fit(gbest.p, n);
			bool b;
			b=(v<=g);
			if (b==1)
				gbest.p = vptl[i].p;
			//vptl[i].update(e1,e2,n,w,gbest.p);
		}
		update0(vptl,e1,e2,n,w,gbest.p);
		fw(Gmax,gen,w);
	}
	for(int i=0;i<n;i++)
	{
		map[i][gbest.p[i]]=-1;
	}
	shwmap(map,n);
	//*************运算结束************
	ends=clock();
	cout<<"共用时： "<<(ends-start)/1000<<" 毫秒"<<endl;
	return 0;
}