#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n; //numero de foco de dengue
	int x; //casa de joao

	//cout << "numero de foco de dengue :";
	cin >> n;
	int custo[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			//cout << "ponto :" << i << " casa :" << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j];
		}
	}
	cin >> x;
	int v[100];
	int p;
	int menor_custo;
	int custo_caminho;

	p = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i != x)
		{
			v[p] = i;
			p++;
		}
	}
	menor_custo = INT_MAX;
	do
	{
		custo_caminho = custo[x][v[0]];
		for(int i = 0; i < n - 2; i++)
		{
			custo_caminho += custo[v[i]][v[i + 1]];
		}
		custo_caminho += custo[v[n - 2]][x];
		menor_custo = min(menor_custo, custo_caminho);
	}
	while(next_permutation(v, v + (n - 1)));

	cout << menor_custo << endl;
	return 0;
}



