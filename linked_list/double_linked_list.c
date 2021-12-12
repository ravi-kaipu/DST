#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *prev;
}dlist;

dlist *alloc_node(int value) {
	dlist *tmp = (dlist *)malloc(sizeof(dlist));
	tmp->data = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	return tmp;
}

void add_entry(dlist **head, int value) {
	dlist **walk = head;
	dlist *parent = NULL;

	while (*walk != NULL) {
		parent = *walk;
		walk = &(*walk)->next;
	}

	*walk = alloc_node(value);
	(*walk)->prev = parent;
	printf("Added %d to list\n", value);
}

dlist * search_element(dlist *head, int value) {
	dlist *walk = head;
    	while ((walk != NULL) && (walk->data != value))
        	walk = walk->next;
    	return walk;
}

void remove_entry(dlist **head, int value) {
	dlist **walk = head;
    	dlist *entry = search_element(*head, value);
    	if (entry == NULL)
        	return;

	while (*walk != entry)
		walk = &(*walk)->next;
	
	*walk = entry->next;
	(*walk)->prev = entry->prev;
    	printf("Remove %d from list\n", value);
}

void print_list(dlist *head) {
	if (head == NULL)
		return;

	printf("\nDouble linked list:\n   ");
	while (head->next != NULL) {
		printf("%d ->", head->data);
		head = head->next;
	}
	printf("%d\n\n", head->data);
}

int main(){
	dlist *list = NULL;
	int option;
	int value;

	for(;;) {
        	printf("\nOptions:\n");
        	printf("1. Insert element to list\n");
        	printf("2. Remove element to list\n");
        	printf("3. Exit\n");

        	printf("Enter Option: ");
        	scanf("%d", &option);

        	switch(option) {
            		case 1:
                		printf("Enter value: ");
                		scanf("%d", &value);
                		add_entry(&list, value);
                		print_list(list);
                		break;
            		case 2:
                		printf("Enter value: ");
                		scanf("%d", &value);
                		remove_entry(&list, value);
                		print_list(list);
                		break;
            		case 3:
                		exit(0);
        	}
	}

	return 0;
}
