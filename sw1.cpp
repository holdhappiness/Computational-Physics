#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include<ctime>

using namespace std;

ofstream out("isingdata.dat");
const int L = 10000;                //number of sites.
const int MCS = 5000;           //number of MC steps.
const double P = 1;             //Probability for reconnection.
const double K = 0.003;


void LinkMaker(int Link[L])
{
	double pros[L]; /* = {P};*/
	for(int i=0;i<L;i++) pros[i]=P;
	double r;
	for(int i = 0; i < L; i++)
	{	
		r = 1.0*rand()/RAND_MAX;
		if(r < pros[i])
		{
			int j;
			while(true)
			{
				j = rand()%L;
				if(!((j==i)||(j==(i+1)%L)||(j==(i-1+L)%L)));
				{
					break;
				}	//生成的第一个满足条件的j
			}
			Link[i] = j;
			Link[j] = i;
			pros[j] = 0;
		}
		else
		{
			Link[i] = i;
		}
		
	}
	//cout<<Link[40]<<'\n';
}
void LinkMaker_1(int *Link)
{
	Link=(int*)malloc(L*sizeof(int));
	double pros[L]; /* = {P};*/
	for(int i=0;i<L;i++) pros[i]=P;
	double r;
	for(int i = 0; i < L; i++)
	{	
		r = 1.0*rand()/RAND_MAX;
		if(r < pros[i])
		{
			int j;
			while(true)
			{
				j = rand()%L;
				if(!((j==i)||(j==(i+1)%L)||(j==(i-1+L)%L)));
				{
					break;
				}	//生成的第一个满足条件的j
			}
			*(Link+i) = j;
			*(Link+j) = i;
			pros[j] = 0;
		}
		else
		{
			*(Link+i) = i;
		}
	}
	//cout<<Link[18]<<'\n';
}


double InitialSpin(int s[L])
{
	for(int i = 0; i < L; i++)
	{
		s[i] = 1;
		//s[i][j]= 2 * (rand() % 2) - 1;
	
	}
	return 0;
}
//随机初始化自旋分布
//----------------------------------------

double ExchangeEnergy(int Spin[L], int Link[L])
{
	double e = 0;
	for(int i = 0; i < L; i++)
	{
		if(Link[i] == i)
		{
			e = -Spin[i]*(Spin[(i+1)%L]+Spin[(i-1+L)%L]);
		}
		else
		{
			e = -Spin[i]*(Spin[(i+1)%L]+Spin[(i-1+L)%L]) + Spin[i]*Spin[Link[i]];
		}
		
	
	}
	return e;
}
// 计算体系的总能量

//计算格点的局域能量
double Magnetization(int s[L])
{
	double m = 0;
	for (int i = 0; i < L; i++)
	{
        m += s[i];
	}
	return m;
}
//输出体系的磁性
void MonteCarlo(int Spin[L], int Link[L], double T)
{
    double Mag[MCS];
    for(int t = 0; t < MCS ; t++ )
    {
        int Eu, Ed;
        int E1, E2;
        double r, p;
		double m = 0.0;
        for(int i = 0; i < L; i++)
        {
            p = 0.5;
            r = 1.0*rand()/RAND_MAX;
            if(r < p)
            {   
                if(Link[i] == i)
                {
                    Eu = -Spin[(i+1)%L]-Spin[(i-1+L)%L];
                    Ed = Spin[(i+1)%L]+Spin[(i-1+L)%L];
                }
                else
                {
                    Eu = -(Spin[(i+1)%L]+Spin[(i-1+L)%L]) + Spin[Link[i]];
                    Ed = Spin[(i+1)%L]+Spin[(i-1+L)%L] - Spin[Link[i]];
                }
                if(Spin[i] == 1)
                {
                    E1 = Eu;
                    E2 = Ed;
                }
                else
                {
                    E1 = Eu;
                    E2 = Ed;
                }
				if(E1 <= E2)
				{
					r = 1.0*rand()/RAND_MAX;
					p = exp(-(E2-E1)/(K*T));
					//cout<<p<<'\n'<<endl;
					if(r < p)
					{
						Spin[i] = -Spin[i];
					}
					
				}
				else
				{
					Spin[i] = -Spin[i];
				}
                
            }
			m += Spin[i];    
        }
		//cout<<m<<'\n';
		Mag[t] = (double) (m/L);
    }
	double sum = 0;
	for(int i=0; i<MCS; i++ )
	{
		sum = sum + Mag[i];
	}
	double avr = sum/MCS; 
	//cout<<Mag[800]<<'\n'<<Link[86]<<endl;
	//cout<<sum<<'\n'<<Link[87]<<endl;
	cout<<Mag[MCS-1]<<'\n'<<endl;
}
int main()
{
	srand((unsigned)time(NULL));
	int s[L] = { 0 };
	int l[L] = { 0 };
	InitialSpin(s);
	LinkMaker(l);
	double T;
	int i=0;
	for (T = 0.1; T <1.1; T += 0.05)
	{

		MonteCarlo(s,l,T);
		//printf("%f\n",T);
	} 
	out.close();
	system("pause");
	return 0;
}

