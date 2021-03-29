#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	int n; //numero de foco de dengue
	int x; //casa de joao

	cout << "numero de foco de dengue : ";
	cin >> n;
	int vet[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			cout << "ponto :" << i << " casa : " << j <<" = ";
			cin >> vet[i][j];
		    vet[j][i] = vet[i][j];
		}
	}
	cout<<"casa de joao : ";
	cin>>x;
	
	bool foco[100];
	int menor_custo;
	int custo_at;
	int foco_atual;
	int proximo_foco;

	for(int i = 0; i < n; i++)
	{
		foco[i] = false;
	}
	
	menor_custo = 0;
	foco_atual = x;
	for(int i = 0; i < n-1; i++)
	{
		foco[foco_atual] = true;
		custo_at = INT_MAX;
		for(int j = 0; j < n; j++)
		{
			if(!foco[j] && custo_at > vet[foco_atual][j])
			{
				proximo_foco = j;
				custo_at = vet[foco_atual][j];
			}
		}
		menor_custo += custo_at;
		foco_atual = proximo_foco;
	}

	menor_custo += vet[foco_atual][x];
	
	cout <<"menor custo : "<< menor_custo << endl;

	return 0;
}
