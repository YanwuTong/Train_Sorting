//Ascending Photo
//Yanwu Tong

#include <bits/stdc++.h>

using namespace std;

int findIndex(int a[], int x, int i, int f){
	int temp = (i + f) / 2;
	if(a[temp] == x){
		return temp;
	}
	else if(a[temp] > x){
		return findIndex(a, x, i, temp);
	}
	else{
		return findIndex(a, x, temp + 1, f);
	}
}

int main(){

	vector<int> a;
	string line;
	string get;
	int n;
	int result;

	getline(cin,line);

	getline(cin, line);
	istringstream ss(line);
	while(getline(ss, get, ' ')){
		int temp = stoi(get);
		if(a.empty() || a.back() != temp){
			a.push_back(temp);
		}
	}

	n = (int) a.size();

	//test the input part

	// cout << n << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << a[i] << " ";
	// }
	// cout << endl;

//--------------------------------------------------------------------------------------
	//this is for the easier version

	// initialize the maximum of cut we need to do
	result = n -1;

	int b[n];
	for(int i = 0; i < n; i++){
		b[i] = a[i];
	}

	sort(b,b+n);
	
	// test the array b
	
	// for(int i = 0; i < n; i++){
	// 	cout << b[i] << " ";
	// }
	// cout << endl;

	// remove all cut that are unnecessary
	for(int i = 0; i < n - 1; i++){
		if(a[i+1] - a[i] == 1){
			result -= 1;
	//		cout << result << endl;
		}
		else if(a[i+1] > a[i]){
			if(findIndex(b, a[i+1], 0, n) - findIndex(b, a[i], 0, n) == 1){
				result -= 1;
	//			cout << result << endl;
			}
		}
	}
//--------------------------------------------------------------------------------------









	cout << result << endl;

	return 0;
}