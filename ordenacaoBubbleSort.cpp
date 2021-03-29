#include <iostream>

using namespace std;

//Funcao de ordena��o "por bolha" (Bubble Sort)
void bubbleSort(int *V, int N){
    int aux, fim = N;
    bool continua = false;
    do
    {
        //Essa variavel � um flag.
        //Se nenhuma troca ocorrer, o loop while n�o ser� mais executado
        continua = false;
        for (int i = 0; i < fim -1; i++){
            if(V[i] > V[i+1]){//Testa se o anterior � menor que o pr�ximo
                    //Faz a troca dos valores
                    aux = V[i];
                    V[i] = V[i+1];
                    V[i+1] = aux;
                    //Marca "continua" como true, para prosseguir o loop while
                    continua = true;
            }
        }
        fim--;//Decrementa o fim, pois conforme o algorimo avan�a, o fim do vetor j� est� ordenado
    } while (continua != false);
}

int main(){

    //Definido o valor do array fora de ordem
    int valores[] = {90,72,13,1,2,45,3,4,89};

    //Calcula o tamanho do array
    int tam = sizeof(valores)/sizeof(valores[0]);

    //imprimir este array fora de ordem
    cout << "Valor do array antes ordena��o." << endl;
    for (int i = 0; i < tam; i++){
        cout << valores[i] << endl;
    }

    //Chama a funcao de bubble sort, passando o array e o seu tamanho
    bubbleSort(valores, tam);

    //imprime o array ap�s ser ordenado
    cout << "Valor do array ap�s ordena��o." << endl;
    for (int i = 0; i < tam; i++){
        cout << valores[i] << endl;
    }

    return 0;
}