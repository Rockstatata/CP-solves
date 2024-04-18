#include<bits/stdc++.h>
 
using namespace std;

class priorityqueue{
    int *arr;
    int size;
public:
    priorityqueue(){
        arr = new int(0);
        size = 0;
    }
    void push(int x){
        preserveup();
        arr[size] = x;
        shiftup(size);
    }
    void preserveup(){
        int * temp = new int [size+1];
        for(int i = 0;i<=size;i++){
            temp[i] = arr[i];
        }
        size++;
        arr = new int[size+1];
        for(int i = 0;i<=size-1;i++){
            arr[i] = temp[i];
        }
        delete temp;
    }
    void preservedown(){
        int * temp = new int [size+1];
        for(int i = 2;i<=size;i++){
            temp[i] = arr[i];
        }
        temp[0] = 0;
        temp[1] = arr[size];
        size--;
        arr = new int[size+1];
        for(int i = 0;i<=size;i++){
            
            arr[i] = temp[i];
        }
        delete temp;
    }
    void shiftup(int x){
        int i = x;
        while(i>1 && arr[parent(i)] < arr[i]){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }

    }
    void shiftdown(int i){
        int maxi = i, l = leftchild(i), r = rightchild(i);
        int x = arr[maxi];
        if(l<=size && arr[l]>arr[maxi]){
            maxi = l;
        }
        if(r<=size && arr[r]>arr[maxi]){
            maxi = r;
        }
        if(i!=maxi){
            swap(arr[i],arr[maxi]);
            shiftdown(maxi);
        }
    }
    void pop(){
        preservedown();
        shiftdown(1);
    }
    int top(){
        if(size!=0)return arr[1];
        return -1;
    }
    void changepriority(int i,int p){
        int oldp = arr[i];
        arr[i] = p;
        if(p>oldp){
            shiftup(i);
        }
        else{
            shiftdown(i);
        }
    }
    int parent(int i){
        return (i/2);
    }
    int leftchild(int i){
        return ((2*i));
    }
    int rightchild(int i){
        return ((2*i)+1);
    }

    void display(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
 


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    priorityqueue p1;
    p1.push(45);
    p1.push(20);
    p1.push(14);
    p1.push(12);
    p1.push(31);
    p1.push(7);
    p1.push(11);
    p1.push(13);
    p1.push(7);
    p1.display();
    cout<<p1.top()<<endl;
    p1.changepriority(2,55);
    p1.display();
    p1.pop();
    p1.display();
}