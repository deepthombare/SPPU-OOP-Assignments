//============================================================================
// Name        : Templates.cpp
// Author      : Deep Thombare
// Assignment  : 8
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.*/
//============================================================================
#include <iostream>

using namespace std;
template<class T>
void selectionsort(T l[],int n){
    int i;
    int m;
    for(i=0;i<n;i++){
        m=i;
        for(int j=i+1;j<n;j++){
            if(l[m]>l[j]){
                m=j;
            }
        }
        swap(l[i],l[m]);
    }
}
int main()
{
    int e=0;
    int c;
    while(e==0){
        cout<<"--------------------------"<<endl<<"1.Integer Array"<<endl<<"2.Float Array"<<endl<<"3.Character array"<<endl<<"4.Exit"<<endl;
        cout<<"Enter Choice:-"<<endl;
        cin>>c;
        switch(c){
            case 1:{
                int n1;
                cout<<endl<<"Enter number of elements:-"<<endl;
                cin>>n1;
                int *arr = new int[n1];
                cout<<"Enter elements to be sorted:-"<<endl;
                for(int i=0;i<n1;i++){
                    cin>>*(arr+i);
                }
                selectionsort<int>(arr,n1);
                cout<<"Sorted array is:-"<<endl;
                for(int k=0;k<n1;k++){
                    cout<<*(arr+k)<<endl;
                }
                delete[] arr;
                break;

            }
            case 2:{
                int n2;
                cout<<"Enter size of float array:-"<<endl;
                cin>>n2;
                float *farr=new float[n2];
                cout<<"Enter elements to be sorted:-"<<endl;
                for(int i=0;i<n2;i++){
                    cin>>*(farr+i);
                }
                selectionsort<float>(farr,n2);
                cout<<"Sorted array is:-"<<endl;
                for(int k=0;k<n2;k++){
                    cout<<*(farr+k)<<endl;
                }
                delete[] farr;
                break;

            }
            case 3:{
                int n3;
                cout<<"Enter size of Character array:-"<<endl;
                cin>>n3;
                char *carr=new char[n3];
                cout<<"Enter elements to be sorted:-"<<endl;
                for(int i=0;i<n3;i++){
                    cin>>*(carr+i);
                }
                selectionsort<char>(carr,n3);
                cout<<"Sorted array is:-"<<endl;
                for(int k=0;k<n3;k++){
                    cout<<*(carr+k)<<endl;
                }
                delete [] carr;
                break;

            }
            default :{
               exit(0);
            }
        }
    }

    return 0;
}
