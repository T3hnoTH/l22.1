#pragma once
#include <iostream>
using namespace std;

template<typename Type>
class Vector {
	Type* arr;
	int size;

public:
	Vector(){
        size =  0;
        arr = nullptr;
    }
	Vector(int size, Type value){
        this->size = size;
        this->arr = new Type[size];
        for (int i = 0; i < size; i++){
            this->arr[i] = value;
        }
        
    }
	~Vector(){
        if (size > 0){
            delete[] arr;
            arr = nullptr;
            size = 0;
        }
        
    }

	int getSize() const{return size;}
	void print()const{
        if (size == 0){
            cout << "..." <<  endl;
        }else{
            for (int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }cout << endl;
        }
    };
	
	void push_back(Type item){
        Type* tmp = new Type[size + 1];
        for (int i = 0; i < size; i++){        
            tmp[i] = arr[i];}
        tmp[size] = item;
        if(arr != nullptr) delete[] arr;
            arr = tmp;
        size++;

    }
    Type& operator[](int number){return arr[number];} 

	Type find_max()const{
        Type max = arr[0];
        for (int i = 1; i < size; i++){
            if (arr[i] > max){
                max = arr[i];
            }
        }return max;
    }
	Type find_min()const{
        Type min = arr[0];
        for (int i = 1; i < size; i++){
            if (arr[i] < min){
                min = arr[i];
            }
        }return min;
    }

};