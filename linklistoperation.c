#include <stdio.h>
#include <stdlib.h>

//basic structure of a node
struct node
{
    int data;
    struct node *next;
};
//linklist traversal
void linklistTraversal(struct node *head){
    printf("elements of the linklist are: \n");
    while (head!=NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
//linklist traversal in reverse order
void linklistTraversalReverse(struct node *head){
    if (head == NULL) {
        return;
    }
    // Recursively traverse the rest of the list
    linklistTraversalReverse(head->next);
    // Print the current node's data
    printf("%d ", head->data);
}
//insert operation
//insert before head
struct node *insertBefore(struct node *head, int data){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    head = head->next;
    return ptr;
}
//insert at the end of list
void insertEnd(struct node *head, int data){
     struct node *p = head;
     struct node *ptr = (struct node *) malloc(sizeof(struct node));
     ptr->data = data;
     while (p->next!=NULL){
        p = p->next;
     }
     p->next = ptr;
     ptr->next = NULL;   
}
//insert ith position of the list
void insertAtposition(struct node *head, int data, int index){
    struct node *p = head;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
}
//insert inbetween nodes
void insertInbetweenNodes(struct node *prev_node, int data){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prev_node->next;
    prev_node->next = ptr;
}
//delete operations
//delete first node
struct node *deleteFirstNode(struct node *head){
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}
//delete last node
void deleteLast(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
//delete i-th position node
void deleteAtposition(struct node *head, int index){
    struct node *p = head;
    struct node *q;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);
}
//delete node in-between
void deletenodeInbetween(struct node *prev_node){
    struct node *p = prev_node->next;
    prev_node->next = p->next;
    free(p);
}

//search node
//linear search
int linearearch(struct node *head, int item){
    struct node *p = head;
    int i = 0;
    while (p!=NULL)
    {
        if (p->data == item)
        {
            return i;
        }
        p = p->next;
        i++;
    }
    return -1;
}
//binary search
int binarySearch(struct node *head, int item){
    int low= 0, high = 0, mid;
    // finding the total length of the linklist
    struct node *p = head;
    while (p!=NULL)
    {
        p = p->next;
        high++;
    }
    //to balance the node as size-1 = high--;
    high--;
    while (low<=high)
    {
        mid = low + (high-low)/2;
        struct node *midNode = head;
        //finding mid node
        for (int i = 0; i < mid; i++)
        {
            midNode = midNode->next;
        }
        if (midNode->data == item)
        {
            return mid;
        }else if (midNode->data > item)
        {
            high = mid-1;
        }else{
            low = mid+1;
        }  
    }
    return -1;
}
//delete duplicate node from a linklist
// 1 2 2 3 4 -> 1 2 3 4 
void deleteDuplicate(struct node *head){
    struct node *p = head;
    struct node *q = head->next;
    while (p!=NULL && q!=NULL)
    {
        if ( p->data == q->data)
        {
            struct node *ptr = q;
            p->next = q->next;
            free(ptr);
        }else{
            p = p->next;
            q = q->next;
        }
    }
}

//create node
struct node *createNode(){
    int data;
    printf("enter data\n");
    scanf("%d", &data);
    if (data == -1)
    {
        return NULL;
    }
    
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = createNode();
    return ptr;
}

int main()
{
    printf("enter the data of head node\n");
    struct node *head = createNode();
    //linklist traversal   
    linklistTraversal(head);
    //linklist reversal reverse
    linklistTraversalReverse(head);

    //delete duplicate node
    printf("delete duplicate node\n");
    deleteDuplicate(head);
    linklistTraversal(head);

    //insertion operation 
    //insert before
    printf("insert before\n");
    int data;
    printf("enter the data of the node\n");
    scanf("%d", &data);
    head = insertBefore(head, data);
    linklistTraversal(head);
    //insert end of the list
    printf("insert end of the list\n");
    int data_end;
    printf("enter the data of the node\n");
    scanf("%d", &data_end);
    insertEnd(head,data_end);
    linklistTraversal(head);
    //insert at i-th position
    int i_data, index;
    printf("enter the index where you want to insert a node\n");
    scanf("%d", &index);
    printf("enter the data of the node\n");
    scanf("%d", &i_data);
    insertAtposition(head,i_data,index);
    linklistTraversal(head);
    //insert inbetween nodes
    printf("insert in-between nodes\n");
    int ib_data;
    printf("enter data of the node\n");
    scanf("%d", &ib_data);
    insertInbetweenNodes(head->next, ib_data);
    linklistTraversal(head);

    //delete operation
    //delete first node
    printf("delete first node\n");
    head = deleteFirstNode(head);
    linklistTraversal(head);
    //delete last node
    printf("delete last node\n");
    deleteLast(head);
    linklistTraversal(head);
    //delete i-th position node
    printf("delete ith position node\n");
    int d_index;
    printf("enter the index of the node you want to delete \n");
    scanf("%d", &d_index);
    deleteAtposition(head,d_index);
    linklistTraversal(head);
    //delete node inbetween
    printf("delete node inbetween\n");
    deletenodeInbetween(head->next);
    linklistTraversal(head);

    //search
    //linear search
    printf("linear search\n");
    int item;
    printf("enter the data you want to search\n");
    scanf("%d", &item);
    int l_res = linearearch(head,item);
    if (l_res == -1)
    {
        printf("item not found in linear search\n");
    }else{
        printf("item found at %d index node\n", l_res);
    }
    //binary search
    printf("binary search\n");
    int key;
    printf("enter the data you want to search\n");
    scanf("%d", &key);
    int b_res = binarySearch(head, key);
    if (b_res == -1)
    {
        printf("item not found in binary search\n");
    }else{
        printf("item found at %dth index position in binary search\n", b_res);
    }

    return 0;
}
