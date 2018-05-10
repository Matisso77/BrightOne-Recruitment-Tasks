#include <iostream>

using namespace std;

//if needed to see input tasks change log_enabled to 1 

int log_enabled = 0; 

// return sum of array

int find_sum(int n, int* array){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=array[i];

    }
    return sum;
}

/*
Computational complexity is only O(n) - it's necessary to go through array only twice
First time we are looking for sum of array, then compares left and right sum
Ever iteration we are update left and right sum
*/

bool check_sums(int n, int* array){

    int max_sum, left_sum=0, right_sum;
    max_sum=find_sum(n, array);
    right_sum=max_sum;
    for(int i=0; i<n; i++){
        right_sum-=array[i];
        if(right_sum==left_sum){
            return true;
        }
        left_sum+=array[i];
    }
    return false;
}
int main()
{

    int number_tests;
	if(log_enabled)		
		cout << "Enter number of tests" << endl;
	
    cin>>number_tests;
    int tests[number_tests];
    bool results[number_tests];

    for(int i=0; i<number_tests; i++){
        if(log_enabled)
			cout<<"Enter number of elements for "<< i+1 << " test"<<endl;

        cin>>tests[i];
        if(log_enabled)
			cout<<"Enter number sequence for "<< i +1  << " test"<<endl;
		
        int numbers[tests[i]];
        for(int j=0; j<tests[i]; j++){
            cin>>numbers[j];
        }

        results[i]=check_sums(tests[i], numbers);
    }

    // output

    cout<<endl<<endl;
    for(int i=0; i<number_tests; i++){
        if(results[i]==true)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }

    return 0;
}
