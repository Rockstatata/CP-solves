#include<bits/stdc++.h>
 
using namespace std;

struct student{
    int roll;
    student* next;
};

class Linked_list{
public:
    student* head;
public:
    Linked_list(){
        head = NULL;
    }

    void insertlast(int roll){
        student* news = new student();
        student* tail = new student();
        news->roll = roll;
        if(head==NULL){
            head = news;
            head->next = NULL;
            return;
        }
        else{
            tail = head;
            while(tail->next!=NULL){
                tail = tail->next;
            }
            tail->next = news;
            news->next = NULL;
            return;
        }
    }

    void insertatposition(int roll,int pos){
        int count = 1;
        student *st = new student;
        st->roll = roll;
        student* current = new student;
        current = head;
        while(count!=pos-1){
            current= current->next;
            if(current==NULL){
                return;
            }
            count++;
        }
        st->next = current->next;
        current->next = st;
        return;
    }

    void insertfirst(int roll){
        student *st = new student;
        st->roll = roll;
        if(head==NULL){
            head = st;
            head->next = NULL;
            return;
        }
        st->next = head;
        head = st;
        return;
    }

    void display(){
        student* current = new student;
        current = head;
        while(current!=NULL){
            cout<<"Roll: "<<current->roll<<endl;
            current = current->next;
        }
        return;
    }

    int get_length(){
        student* current = new student;
        current = head;
        int count = 0;
        while(current!=NULL){
            current = current->next;
            count++;
        }
        return count;
    }

    void sum(Linked_list& list1, Linked_list& list2){
        int len1 = list1.get_length(),len2 = list2.get_length();
        student* current1 = new student();
        student* current2 = new student();
        int carry = 0;
        while(len1 && len2){
            current1 = list1.head;
            current2 = list2.head;
            int count1 = 1, count2 = 1;
            while(count1!=len1){
                current1 = current1->next;
                count1++;
            }
            while(count2!=len2){
                current2 = current2->next;
                count2++;
            }
            int sum = current1->roll + current2->roll;
            if(carry==1){
                sum++;
                carry = 0;
            }

            if(sum>=10){
                carry = 1;
                sum-=10;
            }

            insertfirst(sum);
            len1--;
            len2--;
        }

        if(carry!=0){
            insertfirst(carry);
        }
        int len3 = get_length();
        len1= list1.get_length();
        len2= list2.get_length();
        if(len1!=0 && len3<len1){
            int len4 = len1-len3;
            int count4 = 1;
            while(len4){
                current1 = list1.head;
                while(count4!=len4){
                    current1 = current1->next;
                    count4++;
                }
                int cc = current1->roll;
                insertfirst(cc);
                count4=1;
                len4--;
            }
        }
        else if(len2!=0 && len3<len2){
            int len4 = len2-len3;
            int count4 = 1;
            while(len4){
                current2 = list2.head;
                while(count4!=len4){
                    current2 = current2->next;
                    count4++;
                }
                int cc = current2->roll;
                insertfirst(cc);
                count4=1;
                len4--;
            }
        }
    }

    student* mergeTwoLists(student* list1, student* list2) {
        student *current1 = list1;
        student *current2 = list2;
        //student *head = new student();
        int flag;
        head = NULL;
        student *current;
        while(current1!=NULL){
            if(head == NULL){
                student *news = new student();
                news->roll = current1->roll;
                head = news;
                head->next=NULL;
            }
            else{
            student *previous = NULL;
            current = head;
            while(current!=NULL){
                flag = 0;
                if(current->roll > current1->roll){
                    if(current == head){
                        student *news = new student();
                        news->roll = current1->roll;
                        news->next = head;
                        head = news;
                        head->next = current;
                    }
                    else{
                        student *news = new student();
                        news->roll = current1->roll;
                        news->next = current->next;
                        previous->next = news;                       
                    } 
                    flag = 1;
                    break;                   
                }
                previous=current;
                current=current->next;
            }
            if(flag==0){
                student *news = new student();
                news->roll = current1->roll;
                previous->next = news;
                current = news;
                current->next = NULL;  
                }
            }
            current1=current1->next;
            current = head;
        }
        while(current2!=NULL){
            if(head == NULL){
                student *news = new student();
                news->roll = current2->roll;
                head = news;
                head->next=NULL;
            }
            else{
                current = head;
            student *previous = NULL;
            while(current!=NULL){
                flag = 0;
                if(current->roll > current2->roll){
                    if(current == head){
                        student *news = new student();
                        news->roll = current2->roll;
                        news->next = head;
                        head = news;
                    }
                    else{
                        student *news = new student();
                        news->roll = current2->roll;
                        news->next = current->next;
                        previous->next = news;                      
                    }  
                    flag= 1;
                    break;                
                }
                previous=current;
                current=current->next;
            }
            if(flag==0){
                student *news = new student();
                news->roll = current2->roll;
                previous->next = news;
                current = news;
                current->next = NULL;  
                }
            }
            current2=current2->next;
            current = head;
        }
        return head;
    }
};
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Linked_list list1,list2,sumlist,mergelist;
    list1.insertlast(6);
    list1.insertlast(2);
    list1.insertlast(7);
    list1.insertlast(1);

    list2.insertlast(9);
    list2.insertlast(9);
    list2.insertlast(5);

    //sumlist.sum(list1,list2);
    //sumlist.display();
    mergelist.mergeTwoLists(list1.head,list2.head);
    mergelist.display();
    return 0;
}