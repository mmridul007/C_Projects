#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define s 100
struct node{
    char name[s];
    int age;
    double salary;
    char date[s];
    int id;
    struct node *next;
}*head;

void insert(char *name, int age, double salary, char *date, int id){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    strcpy(temp->name,name);
    temp->age=age;
    temp->salary=salary;
    strcpy(temp->date,date);
    temp->id=id;
    if(head==NULL){
        head=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}
void search(int id){
    struct node *temp=head;
    while(temp!=NULL){
        if(temp->id==id){
            printf("\nName: %s\n", temp->name);
            printf("Age: %d\n", temp->age);
            printf("Salary: %.2lf\n", temp->salary);
            printf("Joining Date: %s\n",temp->date);
            printf("ID: %d\n", temp->id);

            temp=temp->next;
        }
    }
    printf("\n\n ID:%d not found\n\n",id);
}
void delete(int id){
    struct node *temp1=head;
    struct node *temp2=head;
    while(temp1!=NULL){
        if(temp1->id==id){
            printf("\n\nID:%d found!!\n\n",id);
            if(temp1==temp2){
                head= head->next;
                free(temp1);
            }
            else{
                temp2->next=temp1->next;
                free(temp1);
            }
            printf("\n Delete Successfully\n\n");
            return;
        }
        temp2=temp1;
        temp1=temp1->next;
    }
    printf("\n\nID:%d not found\n\n",id);
    
}

void update(int id){
    struct node *temp=head;
    while(temp!=NULL){
        if(temp->id==id){
            printf("Enter name: ");
            getchar();
            gets(temp->name);

            printf("Enter age: ");
            scanf("%d",&temp->age);

            printf("Enter salary: ");
            scanf("%lf",&temp->salary);

            printf("Enter joining date: ");
            getchar();
            gets(temp->date);

            printf("Enter ID: ");
            scanf("%d",&temp->id);

            return;
        }
        temp=temp->next;
    }
}
void display(){
    struct node *temp;
    if(head==NULL){
        printf("List is empty.\n");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("\nName: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Salary: %.2lf\n",temp->salary);
        printf("Joining date: %s\n",temp->date);
        printf("ID: %d\n",temp->id);
        temp=temp->next;
    }
}

int main(){
    int n,age,id;
    char name[s];
    double salary;
    char date[s];
    printf("\n\n~~~~~~Welcome to Salary Management System~~~~~~\n\n");
    do{
        printf("\n1. Add Record\n2. View Record\n3. Search Record\n4. Delete Record\n5. Update Record\n6. Exit\n");
        printf("\nChoose an option: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            printf(" ");

            printf("\nEnter name: ");
            getchar();
            gets(name);

            printf("Enter age: ");
            scanf("%d", &age);

            printf("Enter salary: ");
            scanf("%lf", &salary);

            printf("Enter joining date: ");
            getchar();
            gets(date);

            printf("Enter ID: ");
            scanf("%d", &id);

            insert(name, age, salary, date, id);
            break;

        case 2:
            
            display();
            break;

        case 3:
            printf(" ");
            printf("\nEnter ID: ");
            scanf("%d", &id);

            search(id);
            break;

        case 4:
            printf(" ");
            printf("\nEnter ID: ");
            scanf("%d", &id);

            delete(id);
            break;

        case 5:
            printf(" ");
            printf("\nEnter ID: ");
            scanf("%d", &id);

            update(id);
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nWrong option select!!\n");
            break;
        }
    }
    while(n!=6);
    return 0;
}

