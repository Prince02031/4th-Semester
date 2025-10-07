#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

#define INTERVAL 10000

int main()
{

	int interval,i;
	double or_dist, pi;
	int circ_p=0, sq_p=0;

	mt19937 mt(time(nullptr));

	for(int i=0;i<100000000;i++)
	{
		double rand_x = static_cast<double>(mt() % (INTERVAL + 1)) / INTERVAL;
        double rand_y = static_cast<double>(mt() % (INTERVAL + 1)) / INTERVAL;

		
		or_dist= rand_x*rand_x + rand_y*rand_y;

		if(or_dist<=1)
		{
			circ_p++;
		}
		sq_p++;
		//interval++;

		pi= 4.0 * circ_p/sq_p;
		

		if(i>1000)
			break;

	}


	//cout<<mt() <<endl;
	cout<<pi<<endl;


	return 0;
}