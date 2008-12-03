#include <iostream>
#include <vector>

#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(int argv, char **argc)
{
	vector <double> timeArray;
	vector <double> phaseArray;
	long double time, phase;
	long unsigned int numPoints;

	while(!feof(stdin))
	{
		cin >> time >> phase;
		if(feof(stdin)) break;
		timeArray.push_back(time);
		phaseArray.push_back(phase);
	}
	
	numPoints = phaseArray.size();
	

	long unsigned int N;
	double Tau0;

	N = numPoints;
	if(N > 1) Tau0 = timeArray[1] - timeArray[0];
	else
	{
		cout << "Not Enough Points to Calculate Tau0" << endl;
		Tau0;
	}

	long unsigned int n, k, m, Nw, ns;

	if(argv > 2)
	{
		Nw = atoi(argc[1]);
		ns = atoi(argc[2]);
	}
	else if(argv > 1)
	{
		Nw = atoi(argc[1]);
		ns = Nw/10;
	}
	else
	{
		Nw = N/10;
		ns = Nw/10;
	}

	double sum;

	for(n = Nw; n <= N-Nw; n += ns)
	{
	
		for(k = 1; k <= Nw/3; k++)
		{
			sum = 0.0;
			for(m = n-Nw/2+k; m < n+Nw/2-k-1; m++)
			{
				sum += (phaseArray[m+k]-2.0*phaseArray[m]+phaseArray[m-k])*
				       (phaseArray[m+k]-2.0*phaseArray[m]+phaseArray[m-k]);
			}
			sum = sum / (2.0*k*k*Tau0*Tau0) / (N-2.0*k);
			printf("%i %i %.4e\n", (n-Nw)/ns+1, k, sum);
		}
		printf("\n");
	}
	
	return(0);
}