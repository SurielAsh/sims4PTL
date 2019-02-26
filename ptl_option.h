#ifndef SIMS_PTL_OPTION_H
#define SIMS_PTL_OPTION_H
//SIMS_PTL_OPTION_H

#include <vector>
#include<thread>
#include <iostream>
#include "othertools.h"

struct ptl
{
	std::vector<int> p;
	std::vector<double> v;
	std::vector<int> pbest;
	std::vector<std::vector<int>> map;
	void update(int e1,int e2,int n,double w,std::vector<int> gbest);
	void spini(int n);
	void ini(int n);
	bool valid(std::vector<int> &p,int n);
	int fit(std::vector<int> &p,int n);
};

void ptl::update(int e1,int e2,int n,double w,std::vector<int> gbest)
{
	if(fit(p,n)<fit(pbest,n))
		pbest=p;
	for(int i=0;i<n;i++)
	{
		//InitRand();
		double r1,r2;
		r1=rdm(99,i);
		r2=rdm(99,i);
		v[i]=w*v[i]+e1*r1*(pbest[i]-p[i])+e2*r2*(gbest[i]-p[i]);
		p[i]=p[i]+v[i];
	}
	if(valid(p,n)==0)
		ini(n);
}

void ptl::spini(int n)
{
	vini(p,n);
	vini(v,n);
	vini(pbest,n);
}

void ptl::ini(int n)
{
	do {
		for (int i=0; i < n; i++) {
			do{
				InitRand();
				p[i]=rand()%n;
				v[i]=rand()%n;}
				//v[i]=rand()%(n-p[i]);}
			while(map[i][p[i]]==1);
		}
	}while(valid(p,n)==0);
}

bool ptl::valid(std::vector<int> &p,int n)
{
	for(int i=0;i<n;i++)
	{
		if(p[i]>=n||p[i]<0)
			return 0;
		else if(map[i][p[i]]==1)
			return 0;
	}
	int temp=0;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			int t=0;
			for(int k=0;k<p[i];k++)
				t+=map[i][k];
			if(t!=0)
				return 0;
		}
		else{
			for (int t = p[i - 1]; t < p[i]; t++)
				temp += map[i - 1][t];
			for (int t = p[i - 1]; t > p[i]; t--)
				temp += map[i - 1][t];
			if (temp != 0)
				return 0;
			if (map[i][p[i]-1] == 1 && map[i - 1][p[i]] == 1)
				return 0;
			if(i==n-1){
			int sum=0;
			for(int c=p[n-1];c<n;c++)
				sum+=map[n-1][c];
			if(sum!=0)
				return 0;
			}
		}
	}
	return 1;
}

/*int ptl::fit(std::vector<int> &p,int n)
{
	int f=0,t=0,temp=0;
	for(int i=0;i<n-1;i++)
	{
		f=i-p[i];
		if(f<0)
			f=-f;
		bool b=0;
		if(i<n-2)
			b=(p[i]==p[i+2]);
		if(p[i+1]>p[i]&&(map[i+1][p[i+1]-1]==0||map[i][p[i]+1]==0)&&b==0)
			f-=3;
		t+=f;
		temp=p[i+1]-p[i];
		if(temp<0)
			temp=-temp;
		t+=temp;
	}
	t+=n-1-p[n-1];
	t+=p[0];
	return t;
}*/
int ptl::fit(std::vector<int> &p,int n)
{
	int sum=0;
	int route=0,reg=0,cut=0,temp=0;
 	for(int i=0;i<n-1;i++)
 	{
 		temp=p[i+1]-p[i];
		if(temp<0)
			temp=-temp;
 		route+=temp;
		temp=0;
 		temp=i-p[i];
		if(temp<0)
			temp=-temp;
		reg+=temp;

		if(p[i+1]>p[i]&&(map[i+1][p[i+1]-1]==0||map[i][p[i]+1]==0))
		{
			route-=2;

		if(p[i+1]-p[i]==1)
			cut-=1;
		}
 	}
 	reg+=n-1-p[n-1];
 	route+=p[0]+n-1-p[n-1];
 	sum=route+2*reg+3*cut;
 	return sum;
}

#endif