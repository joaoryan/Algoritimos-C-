#include <iostream>

using namespace std;

//Essa fun��o � respons�vel por calcular o piv�, e garantir que os elementos a esquerda 
//s�o menores que o piv�, e a direita maior.
//Assim, duas parti��es s�o criadas. E de forma recursiva o algoritmo 
//ser� executado para ambas as parti��es.
int particiona(int *V, int inicio, int fim){
   int esq,dir,pivo,aux;
   esq = inicio; //Por padr�o a esq come�a no in�cio da parti��o
   dir = fim; //E a direta no final
   
   //O piv� � calculado como sendo o primeiro valor da parti��o. 
   //Ap�s a execu��o, o algoritmo ir� coloca-lo na posi��o mais adequada,
   // garantindo que todos a esquerda s�o menor. 
   //E a direita maior.
   pivo = V[inicio]; 

    //A valor da esquerda � menor que a direita? 
    //Se sim, ent�o continuamos a percorrer o vetor
    while (esq < dir){
        
        //O valor vetor na posi��o "esq" � maior que o piv�?
        //(Lembre-se que estamos fazendo decrescente) 
        //Se sim, continuamos andando. (incrementa a esq)
        while (V[esq] <= pivo && esq < fim){ //!!!aqui muda de a forma de ordena�ao
            esq++;
        }
        //O valor do vetor na posi��o da direita � menor que o pivo? 
        //(Lembre-se que estamos fazendo decrescente)
        //Se sim, continuamos descendo a posi��o dir (dir --)
        while(V[dir] > pivo){ //aqui muda a fprma de ordena�ao
            dir--;
        }
        //Se a esq for menor que a direita,significa que o valor na posi��o dir � menor
        // que o da posi��o esq, por isso trocamos.
        if(esq < dir){ 
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];//Depois que encontrarmos a posi��o adequada para o piv�, colocamos o piv� nessa posi��o
    V[dir] = pivo;
    return dir;//O piv� � a posi��o da direita
}

//Chamado pela fun��o com o vetor a ser ordenado
void quickSort(int *V, int inicio, int fim){
    int pivo;
    if(fim > inicio){ //Verifica se parti��o possui ao menos dois elementos
        pivo = particiona(V, inicio, fim); //Calcula o pivo e reorganiza o vetor
        quickSort(V, inicio, pivo-1); //Agora faz o quick sort para a parti��o a esquerda do piv�
        quickSort(V, pivo+1, fim); //Faz o quick sort para a parti��o a direita do piv�.
    }
}

int main(){
    
    //Definido o valor do array fora de ordem
    int valores[] = {23,4,67,-8,90,54,21};

    //Calcula o tamanho do array
    int tam = sizeof(valores)/sizeof(valores[0]);
    
    cout << "Valor do array antes da ordenacao." << endl;
    for (int i = 0; i < tam; i++){
        cout << valores[i] << " ";
    }
    cout << endl;

    //Chama a funcao de quick sort, passando o array e o seu tamanho
    quickSort(valores,0, tam-1);

    cout << "Valor do array apos a ordenacao." << endl;
    for (int i = 0; i < tam; i++){
        cout << valores[i] << " ";
    }
    cout << endl;
    
    return 0;
}