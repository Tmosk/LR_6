#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <string.h>

typedef  struct node {
    int data;
    struct node *next;
}node;

void add(node **h,int data);
int del(node **h);
int equals(node *h1, node *h2);
int main() {
    node *h1,*h2;
    h1=h2=NULL;
    printf("enter number of elements:\n");
    int size;
    scanf_s("%d",&size);
    printf("enter first queue\n");
    for (int i = 0; i < size; ++i) {
        int buf;
        scanf_s("%d",&buf);
        add(&h1,buf);
    }
    printf("enter second queue\n");
    for (int i = 0; i < size; ++i) {
        int buf;
        scanf_s("%d",&buf);
        add(&h2,buf);
    }
    if(equals(h1,h2)){
        printf("Equal\n");
    } else printf("Not equal\n");
    printf("first queue\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", del(&h1));
    }
    printf("\nsecond queue\n");
    for (int i = 0; i < size; ++i) {
        printf("%d ", del(&h2));
    }
}

void add(node **h,int data) {
    node *n;
        if (!(n = (node *) calloc(1, sizeof(node)))) {
            return;
        }
        n->data=data;
        if (*h==NULL)
            *h = n;
        else {
            n->next = *h;
            *h = n;
        }
}

int del(node **h) {
    node *pr;
    if (h==NULL) {
        printf("---EROOR---\nQUEUE IS EMPTY\n");
        return 0;
    }
    if ((*h)->next==NULL)
    {
        int data=(*h)->data;
        free(*h);
        *h = NULL;
        return data;
    }
    pr = *h;
    while (pr->next->next)
        pr = pr->next;
    int data = pr->next->data;
    free(pr->next);
    pr->next = NULL;
    return data;
}

int equals(node *h1, node *h2) {
    if(h1==h2)
        return 1;
    while (h1 && h2){
        if(h1->data!=h2->data){
            return 0;
        }
        h1=h1->next;
        h2=h2->next;
    }
    if(h1==h2){
        return 1;
    } else return 0;
}


