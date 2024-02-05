// ROLL: 2107006
// NAME: SARWAD HASAN SIDDIQUI
// ASSIGNMENT 2
// DIFFERENT VARIANTS OF BINARY SEARCH DEMONSTRATION


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
        cout<<"Size of the array: "<<size<<endl;
        for(int i = 0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
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

    int check_sort(){
        for(int i = 0;i<size-1;i++){
            if(arr[i]>arr[i+1]){
                return 0;
            }
        }
        return 1;
    }

    int binary_search(int value){
        try{
            if(!check_sort()){
                throw 0;
            }
        }
        catch(int x){
            cout<<"The array is not sorted. Binary Search not possible"<<endl;
            return -1;
        }
        int l = 0, r=size-1;
        int mid = (l+r)/2;
        while(l<=r){
            mid = (l+r)/2;
            int thing = arr[mid];
            if(thing == value){
                return mid;
            }
            else if(value<thing){
                r=mid-1;
            }
            else if(value>thing){
                l=mid+1;
            }  
        }
        return -1;
        
    }

    int lower_bound(int value){
        try{
            if(!check_sort()){
                throw 0;
            }
        }
        catch(int x){
            cout<<"The array is not sorted. Binary Search not possible"<<endl;
            return -1;
        }
        int l = 0, r=size-1;
        int mid = (l+r)/2;
        if(value<arr[l] || value>arr[r]){
            return -1;
        }
        while(l<=r){
            mid = (l+r)/2;
            int thing = arr[mid];
            if(value<=thing){
                r=mid-1;
            }
            else if(value>thing){
                l=mid+1;
            }  
        }
        return r;
    }

    int upper_bound(int value){
        try{
            if(!check_sort()){
                throw 0;
            }
        }
        catch(int x){
            cout<<"The array is not sorted. Binary Search not possible"<<endl;
            return -1;
        }
        int l = 0, r=size-1;
        int mid = (l+r)/2;
        if(value<arr[l] || value>arr[r]){
            return -1;
        }
        while(l<=r){
            mid = (l+r)/2;
            int thing = arr[mid];
            if(value<thing){
                r=mid-1;
            }
            else if(value>=thing){
                l=mid+1;
            }  
        }
        if(l>=size) return -1;
        return l;
    }

/*
    This variant of binary search was a bit confusing to understand, as 
    it involves bit level manipulation and also there aren't enough 
    contents available on the internet to explain this topic. Yet, from
    the small amount of contents that I found, I grasped an understanding
    of the topic, which implies that this search is basically divided into
    two pieces. There aren't any left or right pointer, instead we are
    determining steps from the length of the array size and then we 
    logarithimically decrement the value of new_position variable and check for 
    the given value and the array element. We also use the position variable
    to make use of that new_position variable according to the conditional
    which will be true if the element value is less than the given value 
    and it's within the range of the array. After the for loop ends we check 
    if we have got a position where the array element is equal to the given
    value and return the position, otherwise -1.
*/

    int meta_binary_search(int value){
        try{
            if(!check_sort()){
                throw 0;
            }
        }
        catch(int x){
            cout<<"The array is not sorted. Binary Search not possible"<<endl;
            return -1;
        }
        int steps = log2(size-1)+1; 
        int position = 0;
        for (int i = steps; i >= 0; i--) {
            if (arr[position] == value){
                return position;
            }
    
            int new_position = position | (1 << i);
    
            if ((new_position < size) && (arr[new_position] <= value)){
                position = new_position;
            }
        }
        return ((arr[position] == value) ? position : -1);
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int size,x,value;
    cin>>size;
    myarray<int>arr(size);
    cout<<"Enter the array elements:"<<endl;
    for(int i = 0;i<size;i++){
        cin>>x;
        arr[i]=x;
    }
    cout<<"Enter the value you would like to find: "<<endl;
    cin>>value;
    arr.traversearray();
    cout<<arr.binary_search(value)<<endl;
    cout<<arr.lower_bound(value)<<endl;
    cout<<arr.upper_bound(value)<<endl;
    cout<<arr.meta_binary_search(value)<<endl;
    
}