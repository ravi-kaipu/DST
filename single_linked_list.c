#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}slist;

slist *alloc_node(int value) {
	slist *tmp = (slist *)malloc(sizeof(slist));
	tmp->data = value;
	tmp->next = NULL;
	return tmp;
}

void add_entry(slist **head, int value) {
	slist **walk = head;

	while (*walk != NULL)
		walk = &(*walk)->next;

	*walk = alloc_node(value);
	printf("Added %d to list\n", value);
}

slist * search_element(slist *head, int value) {
    slist *walk = head;
    while ((walk != NULL) && (walk->data != value))
        walk = walk->next;
    return walk;
}
void remove_entry(slist **head, int value) {
	slist **walk = head;
    slist *entry = search_element(*head, value);
    if (entry == NULL)
        return;

	while (*walk != entry) {
		walk = &(*walk)->next;
    }

	*walk = entry->next;
    printf("Remove %d from list\n", value);

}

void print_list(slist *head) {
	if (head == NULL)
		return;

    printf("\nSingle linked list:\n   ");
	while (head->next != NULL) {
		printf("%d ->", head->data);
		head = head->next;
	}
	printf("%d\n\n", head->data);
}

int main(){
	slist *list = NULL;
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
