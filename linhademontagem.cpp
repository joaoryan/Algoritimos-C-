#include<iostream>
#include<list>
using namespace std;

int main()
{

	int n;
	int a[2][100];
	int t[2][100];
	int e[2];
	int x[2];

	int f[2][100];
	int l[2][100];

	int f_;
	int l_;
//entrada de dados
	cin >> n;
	for(int i = 0; i < 2; i++)
	{
		cin >> e[i];
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < n  ; j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < n - 1 ; j++)
		{
			cin >> t[i][j];
		}
	}
	for(int i = 0; i < 2; i++)
	{
		cin >> x[i];
	}
//fim da entreda
	int custo1, custo2;
	f[0][0] = e[0] + a[0][0];
	f[1][0] = e[1] + a[1][0];
	l[0][0] = -1;
	l[1][0] = -1;

	for(int maq = 1; maq < n; maq++)
	{
		for(int linha = 0; linha < 2; linha++)
		{
			if(linha == 0)
			{
				custo1 = f[0][maq - 1] + a[0][maq];
				custo2 = f[1][maq - 1] + t[1][maq - 1] + a[0][maq];
			}
			else
			{
				custo1 = f[1][maq - 1] + a[1][maq];
				custo2 = f[0][maq - 1] + t[0][maq - 1] + a[1][maq];
			}
			if(custo1 < custo2)
			{
				f[linha][maq] = custo1;
				l[linha][maq] = linha;
			}
			else
			{
				f[linha][maq] = custo2;
				if(linha == 0)
					l[linha][maq] = 1;
				else
					l[linha][maq] = 0;
			}
		}

	}

	f[0][n] = f[0][n - 1] + x[0];
	l[0][n] = 0;
	f[1][n] = f[1][n - 1] + x[1];
	l[1][n] = 1;

	if(f[0][n] < f[1][n])
	{
		f_ = f[0][n];
		l_ = 0;
	}
	else
	{
		f_ = f[1][n];
		l_ = 1;
	}

int i=l_;
cout << "Linha " << i<< " estacao " << n-1 << endl;
for(int j = n - 1; j >=1; j--)
{
i=l[i][j];	
cout << "Linha " << i<< " estacao " << (j-1) << endl;	
}


	return 0;
}
