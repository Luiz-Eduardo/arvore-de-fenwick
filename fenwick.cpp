#include <bits/stdc++.h>
#define MAXN 1000001

using namespace std;

int bit[MAXN];

int query(int index){
	int answer(0);
	
	index++; //BIT é 1-indexada, tem que incrementar já que o array é 0-indexado.
	
	while(index > 0){
		answer += bit[index];
		index -= index & (-index);
	}
	
	return answer;
}

void update(int index, int value){
	index++; //BIT é 1-indexada.
	
	while(index <= MAXN){ //Enquanto eu puder subir na BIT.
		bit[index] += value; //Atualizo o valor dos ancestrais.
		index += index & (-index); //Subo para o pai.
	}
}

void build(vector <int> &v){
	int *fenwickTree = new int[v.size() + 1];
	
	for(int i = 0; i < v.size(); i++){
		update(i, v[i]);
	}
	
}
