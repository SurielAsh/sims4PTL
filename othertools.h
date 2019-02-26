#ifndef SIMS_OTHERTOOLS_H
#define SIMS_OTHERTOOLS_H


#include <iostream>
#include <vector>
#include <sys/time.h>
/* 初始化随机种子 */
void InitRand()
{
	//struct timeval tv;
	//gettimeofday(&tv,NULL);
	//unsigned t=tv.tv_usec;
	//srand(t+rand());
	srand(clock()+rand());
	//std::cout<<rand()<<std::endl;
}

double rdm(int N,int i)
{
	InitRand();
	double r=rand()%(N)/(double)(N);
	return r;
}

void vini(std::vector<int> &v,int n)
{
	for(int i=0;i<n;i++)
		v.push_back(0);
}

void vini(std::vector<double> &v,int n)
{
	for(int i=0;i<n;i++)
		v.push_back(0);
}

void fw(int Gmax,int gen,double &w)
{
	gen++;
	w=(1/gen);
}

#endif //SIMS_OTHERTOOLS_H