#include <bits/stdc++.h>
#include "fenwick.cpp"

using namespace std;

vector<int> vectorGenerate(int n){
	vector<int> v;
	
    for (int i = 0; i < n; i++){
    	// gera valores aleatorios entre 1 e 100
        v.push_back(rand() % 100 + 1);
 	}
    
    return v;	
}

int main(){
    for (int i = 0; i < 20; i++){
        cout << "Iter: " << i << "\n";

        int n = pow(2, i);
        
        vector<int> fenwickTree = vectorGenerate(n);
        
        chrono::steady_clock::time_point begin1 = chrono::steady_clock::now();
        build(fenwickTree);
        chrono::steady_clock::time_point end1 = chrono::steady_clock::now();

        cout << "Time build = " << chrono::duration_cast<chrono::microseconds>(end1 - begin1).count() << "[µs]" << endl; 
    }
}
