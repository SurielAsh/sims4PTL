#ifndef SIMS_MAP_OPTION_H
#define SIMS_MAP_OPTION_H


#include <vector>
#include <iostream>


void mkmap(std::vector<std::vector<int>> &map,int n)
{
	for(int x=0;x!=n;x++)
	{
		for(int y=0;y!=n;y++)
		{
			double r=rdm(99,1);
			if(r>0.87)
				map[x][y]=1;
			else
				map[x][y]=0;
		}
	}
	map[0][0]=0;
	map[n-1][n-1]=0;

	/*map[1][1]=1;
	map[1][2]=1;
	map[1][3]=1;*/

}

void shwmap(std::vector<std::vector<int>> &map,int n)
{
	for(int x=0;x!=n;x++)
	{
		for(int y=0;y!=n;y++)
		{
			if(map[x][y]==1)
				std::cout<<"▇|";
			else if(map[x][y]==-1)
				std::cout<<"$|";
			else
				std::cout<<"_|";
		}
		std::cout<<std::endl;
	}
}
#endif