//Train Sorting
//Yanwu Tong

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//helper function
//return the maximum of two value
int max(int a, int b){
	if (a > b){
		return a;
	}
	return b;
}

//initialize the array a
int a[2009];


int findMax(int n){
	//initialize result, longest increasing substring, longest decreasing substring
	int result = 0;
	int LIS[2009];
	int LDS[2009];

	for(int i = n - 1; i > -1; i--){
		//initialize 
		LIS[i] = LDS[i] = 1;
		for(int j = n - 1; j > i; j--){
			if(a[i] > a[j]){
				LDS[i] = max(LDS[i], LDS[j]+1);
			}
			else if(a[i] < a[j]){
				LIS[i] = max(LIS[i], LIS[j]+1);
			}
		}
		result = max(result, LIS[i] + LDS[i] - 1);
	}
	return result;
}

int main(){
	int n;
	while(scanf("%d", &n) != EOF){         //run until reach the end of the file, update n
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);            //update current array
		}
		cout << findMax(n) << endl;
	}
	return 0;
}