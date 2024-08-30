#include<bits/stdc++.h>
 
using namespace std;

template<class T>
class min_heap{
    pair<T,int> *arr;
    int size;
public:
    min_heap(){
        arr = new pair<T,int>({0,0});
        size = 0;
    }

    void insert(T key, int value){
        preserveup();
        arr[size].first = key;
        arr[size].second = value;
        shiftup(size);
    }

    void preserveup(){
        pair<T,int> *temp = new pair<T,int>[size+1];
        for(int i = 0;i<=size;i++){
            temp[i] = arr[i];
        }
        size++;
        arr = new pair<T,int>[size+1];
        for(int i = 0;i<=size-1;i++){
            arr[i] = temp[i];
        }
        delete temp;
    }
    
    void preservedown(){
        pair<T,int> * temp = new pair<T,int> [size+1];
        for(int i = 2;i<=size;i++){
            temp[i] = arr[i];
        }
        temp[0] = {0,0};
        temp[1] = arr[size];
        size--;
        arr = new pair<T,int>[size+1];
        for(int i = 0;i<=size;i++){
            arr[i] = temp[i];
        }
        delete temp;
    }
    void shiftup(int x){
        int i = x;
        while(i>1 && arr[parent(i)].second > arr[i].second){
            swap(arr[parent(i)],arr[i]);
            i = parent(i);
        }

    }
    void shiftdown(int i){
        int maxi = i, l = leftchild(i), r = rightchild(i);
        if(l<=size && arr[l]<arr[maxi]){
            maxi = l;
        }
        if(r<=size && arr[r]<arr[maxi]){
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
    pair<T,int> extract_min(){
        if(!is_empty()){
            pair<T,int> x = arr[1];
            pop();
            return x;
        }
        return {-1,-1};
    }
    void decrease_key(T key,int new_value){
        int ind = -1;
        for(int i = 1;i<=size;i++){
            if(arr[i].first==key){
                ind = i;
            }
        }
        int value = arr[ind].second;
        arr[ind].second = new_value;
        if(new_value<value){
            shiftup(ind);
        }
        else{
            shiftdown(ind);
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

    bool is_empty(){
        if(size==0) return true;
        return false;
    }

    void display(){
        for(int i = 1;i<=size;i++){
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }
    }

};

int main(){
    min_heap<int> pq;
    pq.insert(1,3);
    pq.display();
    pq.decrease_key(1,5);
    pq.display();
    
}

