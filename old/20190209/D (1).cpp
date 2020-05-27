#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	cin.tie(0);ios::sync_with_stdio(false);
	/* ====================================== */
	int L;
	cin >> L;
	vector<int> A(L);
	vector<int> B(L);
	for(int i = 0; i < L; i++){
		cin >> A[i];
		if(A[i] == 0){
			B[i] = 0;
		}else if(A[i] != 0 && A[i]%2 == 0){
			B[i] = 2;
		}else if(A[i]%2 == 1){
			B[i] = 1;
		}
	}

	int min = 1000000000;
	for(int i = 0; i < L+1; i++){
		for(int j = 0; j < L - i + 1; j++){
			int sum = 0;
			int sum0 = 0;
			int sum1 = 0;
			bool isZeroPre = true;
			int numZeroPost = 0;
			for(int k = 0; k < L; k++){
				if(k < i){
					if(B[k] == 0){
						if(!isZeroPre){
							sum0 += 2;
						}
					}else if(B[k] == 1){
						sum0 += 1;
						isZeroPre = false;
					}else{
						isZeroPre = false;
					}
				}else if(i <= k  && k < j){
					if(B[k] == 0 || B[k] == 2){
						sum += 1;
					}
				}else if(j <= k){
					if(B[k] == 0){
						sum1 += 2;
						numZeroPost++;
					}else if(B[k] == 1){
						sum1 += 1;
						numZeroPost = 0;
					}else{
						numZeroPost = 0;
					}
				}
			}
			sum1 -= numZeroPost * 2;

			sum0 = min(sum0, std::accumulate(A.begin(), A.end(), 0));

			sum += sum0 + sum1;

			if(sum < min){
				min = sum;
				cout << i << ',' << j << endl;
			}
		}
	}




	cout << min;
	/* ====================================== */
	return 0;
}