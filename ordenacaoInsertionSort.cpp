#include<iostream>
 
using namespace std;
 
//Funcao de ordenacao por insercao
void insertionSort(int *V, int N){
 
 //mantem salvo o valor que estamos buscando a posi��o correta para "inserir".
 int atual;
 //variavel auxiliar 
 int j; 
 
 //Percorrendo o array, iniciando pela segunda posi��o
 for (int i = 1; i < N; i++){
 atual = V[i]; //salva o valor que vamos "inserir" na posi��o correta
 
 //Enquanto os elementos a esquerda de "atual" for menor que ele deslocamos esses n�meros para a direita, 
 //at� que "atual" seja inserido na posi��o correta. Caso o vetor chegue no fim (j = 0) tamb�m paramos a busca. O que 
 //ocorrer primeiro
 for(j = i; (j > 0) && (atual < V[j-1]); j--){
 V[j] = V[j-1];//Deslocando os valores a esquerda de "atual" para a direita.
 }
 V[j] = atual; //Inserindo o "atual" na posi��o correta
 }
}
 
int main(){
 
 //Definido o valor do array fora de ordem
 int valores[] = {67,72,13,1,2,45,3,4,89};
 
 //Calcula o tamanho do array
 int tam = sizeof(valores)/sizeof(valores[0]);
 
 //imprimir este array fora de ordem
 cout << "Valor do array antes ordenacao." << endl;
 for (int i = 0; i < tam; i++){
 cout << valores[i] << endl;
 }
 
 //Chama a funcao de insertion sort, passando o array e o seu tamanho
 insertionSort(valores, tam);
 
 //imprime o array ap�s ser ordenado
 cout << "Valor do array apos ordenacao." << endl;
 for (int i = 0; i < tam; i++){
 cout << valores[i] << endl;
 }
 
 return 0;
}