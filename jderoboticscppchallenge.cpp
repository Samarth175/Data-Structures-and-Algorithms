#include <iostream>

#define MAX 10

using namespace std;

char arr[10][10];

int main() {
	int r=5,c=7;
	for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        char ch;
	        cin>>ch;
	        arr[i][j] = ch;
	    }
	}
	for(int i=0;i<r;i++){
	    for(int j=0;j<c;j++){
	        cout<<arr[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}



//Sample Input
// ##.##.#
// #..##.#
// #.#####
// #..####
// #######