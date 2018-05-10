#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned char byte;

// if needed to see results on console, change log_enabled to 1

int log_enabled = 0;

//descending order

bool comp(int i, int j){
    return i > j;
}

// count of 1 in array elements

size_t ones_counter(size_t n){
    bitset<sizeof(size_t)*CHAR_BIT>b(n);
    return b.count();
}

int main(){
    fstream file;
    file.open("Input.txt", ios::in);

    if(!file.good()){
        cout<<"Opening file failed...";
        return 0;
    }

    // filltered_numbers is a string witch stores all characters from the range 0-F

    string filltered_numbers="";
    char c;
    while (file.get(c)){
        if((c>=48 && c<=57)||(c>=65 && c<=70))
        filltered_numbers+=c;
    }

    file.close();
    //check last char - if is odd size is incremented

    int size_of_input=filltered_numbers.length();
    if(size_of_input%2==1)
        size_of_input=(size_of_input/2)+1;
    else
        size_of_input/=2;


    byte *byte_array=new byte[size_of_input];
    int counter=0;

    // pairs of characters from filltered_numbers are put into byte_array, (byte_array is byte array)
    // compares are made based by ASCII

    for(int i=0; i<filltered_numbers.length(); i+=2){
        if(filltered_numbers[i]>=48 && filltered_numbers[i]<=57){
            byte_array[counter]=16*(filltered_numbers[i]-48);
        }
        else if(filltered_numbers[i]>=65 && filltered_numbers[i]<=70){
            byte_array[counter]=16*(filltered_numbers[i]-55);
        }
        if(filltered_numbers[i+1]>=48 && filltered_numbers[i+1]<=57){
            byte_array[counter]+=(filltered_numbers[i+1]-48);
        }
        else if(filltered_numbers[i+1]>=65 && filltered_numbers[i+1]<=70){
            byte_array[counter]+=(filltered_numbers[i+1]-55);
        }
        counter++;
    }

    // last char

    if(filltered_numbers.length()%2)
        byte_array[counter-1]/=16;

    //divide table to even and uneven vectors

    vector<byte>even;
    vector<byte>uneven;

    for(int i=0; i<size_of_input; i++){
        if(ones_counter((int)byte_array[i])%2){
            uneven.push_back(byte_array[i]);
        }
        else{
            even.push_back(byte_array[i]);
        }
    }

    delete [] byte_array;

    //sort vectors


    sort( even.begin(), even.end() );
    sort( uneven.begin(), uneven.end(), comp);

    if(log_enabled){
        cout<<"Even:"<<endl<<endl;

         for( size_t i = 0; i < even.size(); i++ )
            cout<<hex<<(int)even[i]<<endl;

        cout<<endl<<endl;
        cout<<"Uneven:"<<endl<<endl;

        for( size_t i = 0; i < uneven.size(); i++ )
            cout<<hex<<(int)uneven[i]<<endl;
    }



    //write results to output file

    fstream results;
    results.open("Results.txt", ios::out);

    results<<"Even: "<<endl<<endl;
    for( size_t i = 0; i < even.size(); i++ )
     results<<hex<<(int)even[i]<<endl;

    results<<endl<<endl;
    results<<"Uneven: "<<endl<<endl;

    for( size_t i = 0; i < uneven.size(); i++ )
        results<<hex<<(int)uneven[i]<<endl;

    return 0;
}
