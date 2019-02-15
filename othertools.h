#ifndef SIMS_OTHERTOOLS_H
#define SIMS_OTHERTOOLS_H


#include <iostream>
#include <vector>
double rdm(int N)
{
	srand((int)time(0)+rand());
	double r=rand()%(N)/(double)(N);
	return r;
}

void vini(std::vector<int> &v,int n)
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