#include<bits/stdc++.h>
 
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *current1 = list1;
        ListNode *current2 = list2;
        ListNode *head = new ListNode();
        int flag;
        head = NULL;
        ListNode *current;
        while(current1!=NULL){
            if(head == NULL){
                ListNode *news = new ListNode();
                news->val = current1->val;
                head = news;
                head->next=NULL;
            }
            else{
                ListNode *previous = NULL;
                current = head;
                while(current!=NULL){
                    flag = 0;
                    if(current->val > current1->val){
                        if(current == head){
                            ListNode *news = new ListNode();
                            news->val = current1->val;
                            news->next = head;
                            head = news;
                            head->next = current;
                        }
                        else{
                            ListNode *news = new ListNode();
                            news->val = current1->val;
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
                    ListNode *news = new ListNode();
                    news->val = current1->val;
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
                ListNode *news = new ListNode();
                news->val = current2->val;
                head = news;
                head->next=NULL;
            }
            else{
                current = head;
            ListNode *previous = NULL;
            while(current!=NULL){
                flag = 0;
                if(current->val > current2->val){
                    if(current == head){
                        ListNode *news = new ListNode();
                        news->val = current2->val;
                        news->next = head;
                        head = news;
                    }
                    else{
                        ListNode *news = new ListNode();
                        news->val = current2->val;
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
                ListNode *news = new ListNode();
                news->val = current2->val;
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
    
}