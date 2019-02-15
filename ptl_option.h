#ifndef SIMS_PTL_OPTION_H
#define SIMS_PTL_OPTION_H
//SIMS_PTL_OPTION_H

#include <vector>
#include <iostream>


struct ptl
{
	std::vector<int> p;
	std::vector<int> v;
	std::vector<int> pbest;
	std::vector<std::vector<int>> map;
	void update(int e1,int e2,int n,int w,std::vector<int> gbest);
	void spini(int n);
	void ini(int n);
	bool valid(std::vector<int> &p,int n);
	double fit(std::vector<int> &p,int n);
};

void ptl::update(int e1,int e2,int n,int w,std::vector<int> gbest)
{
	if(fit(p,n)<fit(pbest,n))
		pbest=p;
	for(int i=0;i<n;i++)
	{
		double r1,r2;
		r1=rdm(99);
		r2=rdm(99);
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
			p[i]=rand()%n;
			v[i]=rand()%n;
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
			if (temp != 0)
				return 0;
			if (map[i][p[i]-1] == 1 && map[i - 1][p[i]] == 1)
				return 0;
			if(p[i]<p[i-1])
				return 0;
		}
	}
	return 1;
}

double ptl::fit(std::vector<int> &p,int n)
{
	int f=0,t=0;
	for(int i=0;i<n-1;i++)
	{
		f=i-p[i];
		if(f<0)
			f=-f;
		if(p[i+1]>p[i]&&(map[i+1][p[i+1]-1]==0||map[i][p[i]+1]==0))
			f-=2;
		t+=f;
	}
	t+=n-1-p[n-1];
	t+=p[0];
	return t;
}


#endif