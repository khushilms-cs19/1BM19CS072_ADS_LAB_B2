#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node {
    int data;
    struct node *link[4];
};
typedef struct node* NODE;

NODE getnode(){
    printf("here allocating memory");
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("The memory is full\n");
        return NULL;
    }
    return temp;
}


int createRandom(){
    int randNum;
    randNum=rand()%4;
    return randNum;
}

NODE insertNode(NODE header, int num){
    NODE prevLinks[4];
    int randNum=createRandom();
    int rn=randNum,i;
    NODE cur,temp,prev,prevv;
    temp=getnode();
    temp->data=num;
    cur=header->link[randNum];
    if(header->link[0]==NULL){
        printf("here");
        for(i=0;i<randNum;i++){
            header->link[i]=temp;
        }
        return header;
    }
    while(cur!=NULL){
        if(cur->data<num){
            prev=cur;
            cur=cur->link[randNum];
        }else{
            if(randNum==0){
                cur=prev;
                break;
            }
            prevLinks[randNum]=prev;
            cur=prev;
            randNum--;
        }
    }
    for(i=0;i<rn;i++){
        temp->link[i]=prevLinks[i]->link[i];
        prevLinks[i]->link[i]=temp;
    }
    return header;
}

int main(){
    NODE header=getnode();
    int i;
    printf("here started the execution");
    header->data=0;
    for(i=0;i<4;i++){
        header->link[i]=NULL;
    }
    header = insertNode(header, 1);
}
