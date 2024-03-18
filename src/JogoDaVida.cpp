#include "JogoDaVida.hpp"


void JogoDaVida::le_matriz(ifstream& arq,int **&matriz_original, int linhas, int colunas){

   for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
              arq>>matriz_original[i][j];
            }
        }

}


int JogoDaVida::conta_vizinhos(int **matriz_original,int pos_linha, int pos_coluna,int linhas, int colunas){

int contador=0,i=0,j=0;

for(i=pos_linha-1;i<=pos_linha+1;i++){
    for(j=pos_coluna-1;j<=pos_coluna+1;j++){
        if((i==pos_linha && j==pos_coluna)|| (i<0||j<0)||(i>=linhas ||j>=colunas)){
            continue;
        }
        else if(matriz_original[i][j]==1){
            contador++;
        }
    }
}

return contador;

}

void JogoDaVida::processa_matriz(int **matriz_original,int **&matriz_copia,int linhas,int colunas){

int vizinhos;

for(int i=0;i<linhas;i++){
    for(int j=0;j<colunas;j++){
    vizinhos=conta_vizinhos(matriz_original,i,j,linhas,colunas);
    if(matriz_original[i][j]==1 && (vizinhos==2 || vizinhos==3)){
      matriz_copia[i][j]=1;
    }
    else if(matriz_original[i][j]==0 && vizinhos==3){
        matriz_copia[i][j]=1;
    }
    else{
        matriz_copia[i][j]=0;
    }

    }
}


}

void JogoDaVida:: copia_matriz(int **&matriz_original,int **matriz_copia, int linhas, int colunas){
  for(int i=0;i<linhas;i++){
    for(int j=0;j<colunas;j++){
        matriz_original[i][j]=matriz_copia[i][j];
    }
  }
}

void JogoDaVida:: escreve_matriz(ofstream& arq, int **matriz, int linhas, int colunas,string titulo,int num_geracao){
    arq<<titulo<<num_geracao<<endl;
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            arq<<matriz[i][j];
        }
        arq<<endl;
    }
}


bool JogoDaVida::verifica_zerou(int **matriz_copia, int linhas, int colunas){

    int contador=0;

    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            if(matriz_copia[i][j]!=0){
                contador++;
            }
        }
    }

    if(contador==0){
        return true;
    }
    else{
        return false;
    }

}










