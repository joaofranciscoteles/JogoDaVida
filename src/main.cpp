#include <iostream>
#include "JogoDaVida.hpp"

using namespace std;

int main(){

    JogoDaVida jogo;

    int geracoes;
    int **matriz_original;
    int **matriz_copia;
    int linhas,colunas;
    int num_inicial=0;
    string titulo="Geração ";
    
    
    ifstream arq;

    arq.open("datasets/input.mps");

    if(arq.is_open()){
        arq>>linhas>>colunas;
        
        matriz_original= new int*[linhas];
        for (int i = 0; i < linhas; i++){
        matriz_original[i] = new int[colunas];
        }

        jogo.le_matriz(arq,matriz_original,linhas,colunas);
    }

    matriz_copia= new int*[linhas];
    for (int i = 0; i < linhas; i++) {
        matriz_copia[i] = new int[colunas];
    }

    arq.close();

    ofstream saida;

    saida.open("geracoes.mps",fstream::out);

    jogo.escreve_matriz(saida,matriz_original,linhas,colunas,titulo,num_inicial);
    
    cout<<"Digite o número de gerações que deseja:"<<endl;
    cin>>geracoes;

    for(int i=0;i<geracoes;i++){
    
    cout<<"Iniciando Geração:"<<i+1<<endl;

    
    jogo.processa_matriz(matriz_original,matriz_copia,linhas,colunas);

    jogo.copia_matriz(matriz_original,matriz_copia,linhas,colunas);

    jogo.escreve_matriz(saida,matriz_original,linhas,colunas,titulo,i+1);

    if(jogo.verifica_zerou(matriz_copia,linhas,colunas)){
        cout<<"Extinção da civilização"<<endl;
        break;
    }

    cout<<"Finalizando Geração:"<<i+1<<endl;
     
    }

    saida.close();
 
 return 0;
}