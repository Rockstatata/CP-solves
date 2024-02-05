// ROLL: 2107006
// NAME: SARWAD HASAN SIDDIQUI
// ASSIGNMENT 1
// ARRAY CLASS MAKING
// ADDITIONAL WORK DONE: ALL LAB TASK FOR DEMONSTRATING THE PROPER WORKING OF THE CLASS
                         
#include<bits/stdc++.h>
 
using namespace std;

template<class T>
class myarray{
    T *arr;
    int size;
public:
    myarray():
        size{0}
    {

    }

    myarray(int n){
        size = n;
        arr = new T[size];
        for(int i = 0;i<size;i++){
            arr[i]=0;
        }
    }

    myarray(int x,int n){
        size = n;
        arr = new T[size];
        for(int i = 0;i<size;i++){
            arr[i]=x;
        }
    }

    int& getsize(){
        return size;
    }

    T& getarr(){
        return arr;
    }
    
    void createarray(int n){
        size = n;
        arr = new T[size];
        for(int i = 0;i<size;i++){
            arr[i]=0;
        }
    }

    void insertElement(int index, int value){
        size++;
        T *temp = new T[size];
        for(int i = 0;i<size-1;i++){
            temp[i]=arr[i];
        }
        for(int i=size-2;i>=index;i--){
            temp[i+1]=temp[i];
        }
        temp[index]=value;
        arr = new T[size];
        for(int i = 0;i<size;i++){
            arr[i]=temp[i];
        }
        delete[] temp;
    }

    void deleteElement(int index){
        T *temp = new T[size];
        for(int i = 0;i<size;i++){
            temp[i]=arr[i];
        }
        for(int i=index;i<size-1;i++){
            temp[i]=temp[i+1];
        }
        size--;
        arr = new T[size];
        for(int i = 0;i<size;i++){
            arr[i]=temp[i];
        }
        delete[] temp;
    }

    void searchElement(int value){
        int ind = -1;
        for(int i = 0;i<size;i++){
            if(arr[i]==value){
                ind = i;
            }
        }
        if(ind!=-1){
            cout<<"Element found at "<<ind<<" index"<<endl;
        }
        else{
            cout<<"Element not found"<<endl;
        }
    }

    void traversearray(){
        cout<<*this;
    }

    void updateElement(int index,int value){
        arr[index]=value;
    }

    void resize(int n){
        if(size>n){
            size=n;
            T *temp = new T[size] {0};  
            for(int i = 0;i<size;i++){
                temp[i]=arr[i];
            }
            arr = new T[size] {0};
            for(int i = 0;i<size;i++){
                arr[i]=temp[i];
            }
            delete[] temp;
        }
        else{
            T *temp = new T[size] {0};
            for(int i = 0;i<size;i++){
                temp[i]=arr[i];
            }
            arr = new T[n] {0};
            for(int i = 0;i<size;i++){
                arr[i]=temp[i];
            }
            size = n;
            delete[] temp;
        }
    }

    T& operator[](int index){
        return arr[index];
    }

    T& operator=(T& m){
        if (this != &m) {
            size = m.size;
            arr = new T[size];
            for(int i = 0; i < size; i++) {
                arr[i] = m.arr[i];
            }
        }
        return *this;
    }

    void operator=(int n){
        size=0;
    }

    friend istream& operator>>(istream& in,myarray<T> &m){
        for(int i = 0;i<m.size;i++){
            in>>m.arr[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out,myarray<T> &m){
        out<<"Size: "<<m.size<<endl;
        for(int i = 0;i<m.size;i++){
            out<<m.arr[i]<<" ";
        }
        out<<endl;
        return out;
    }

// A1 TASK
    void rotateelement(int r){
        if(r>=0){
            T *temp = new T[size] {0};
            for(int i = 0;i<r;i++){
                temp[i]=arr[i];
            }
            for(int i = 0;i<r;i++){
                deleteElement(0);
            }
            for(int i=0;i<r;i++){
                insertElement(size,temp[i]);
            }
            delete[] temp;
        }
        else{
            int l=size-(-r);
            T *temp = new T[size] {0};
            for(int i = 0;i<l;i++){
                temp[i]=arr[i];
            }
            for(int i = 0;i<l;i++){
                deleteElement(0);
            }
            for(int i=0;i<l;i++){
                insertElement(size,temp[i]);
            }
            delete[] temp;
        }
    }

// B1 TASK

    void rowcolumnremove(string s){
        char c = s[0];
        int ind = s[1]-'0';
        if(c=='r'){
            int n = arr[ind].getsize();
            for(int i = 0;i<n;i++){
                arr[0].deleteElement(0);
            }
            for(int i = ind;i<size;i++){
                arr[i-1]=arr[i];
            }   
            size--;
        }
        else{
            for(int i = 0;i<size;i++){
                arr[i].deleteElement(ind);
            }
        }
    }

// B2 TASK

    void zeroremoval(){
        int cnt=0;
        for(int i = 0;i<size;i++){
            if(arr[i]==0){
                deleteElement(i);
                cnt++;
                i--;
            }
        }
        for(int i = 0;i<cnt;i++){
            insertElement(size,0);
        }
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int size,x;
    cin>>size;
    myarray<int>arr(size);
    for(int i = 0;i<size;i++){
        cin>>x;
        arr[i]=x;
    }
    arr.zeroremoval();
    arr.traversearray();
    myarray<int>arr2;
    arr2.createarray(size);
    for(int i = 0;i<size;i++){
        cin>>arr2[i];
    }
    arr2.traversearray();
    arr.traversearray();
    arr.insertElement(3,2);
    arr.traversearray();
    arr.deleteElement(3);
    arr.traversearray();
    arr.searchElement(5);
    arr.updateElement(2,5);
    arr.resize(10);
    arr.traversearray();
    //arr.resize(1);
    //arr.traversearray();
    arr.rotateelement(2);
    arr.traversearray();
    arr.rotateelement(-2);
    arr.traversearray();
    myarray<myarray<int>>d2arr;
    int n=3;
    d2arr.createarray(3);
    for(int i = 0;i<n;i++){
        d2arr[i].createarray(3);
        cin>>d2arr[i];
    }
    for(int i = 0;i<d2arr.getsize();i++){
        d2arr[i].traversearray();
    }
    cout<<"Which row/column would you want to remove?"<<endl;
    string s;
    cin>>s;
    d2arr.rowcolumnremove(s);
    for(int i = 0;i<d2arr.getsize();i++){
        d2arr[i].traversearray();
    }
}