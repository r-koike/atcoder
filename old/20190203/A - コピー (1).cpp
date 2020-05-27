#include<iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	/* ====================================== */
	int N;
	vector<int> A(N);
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	int res = 0;
	for(int i = 0; i < N; i++){
		bool end = false;
		if(A[i]%res == 0){
			A[i] /= res;
		}else{
			end = true;
		}
		while(!end){
			if(A[i]%2 == 0){
				A[i] = A[i]/2;
				res++;
			}else{
				end = true;
			}
		}
	}


	cout << res;
	/* ====================================== */
	return 0;
}