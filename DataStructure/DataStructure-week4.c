#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} NODE;

void add_node(NODE **start, int value) {
	NODE *new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = value;
	new_node->next = NULL;
	
	if(*start == NULL) {
		*start = new_node;
		return;
	}
	else {
		NODE *current;	
		current = *start;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
		return;
	}
}

void insert_node(NODE **start, int value, int insert_after_value) {
	NODE *current = *start; 
	
	while(current != NULL) {
		if(insert_after_value == current->data) {
			NODE *new_node = (NODE*)malloc(sizeof(NODE));	
			new_node->data = value;
			new_node->next = NULL;
			if(current->next == NULL) {
				current->next = new_node;
				break;
			}
			else {
				new_node->next = current->next;
				current->next = new_node;
				break;
			}
		}
		current = current->next;
	}
}

void delete_node(NODE **start, int value) {
	NODE *current = *start;
	NODE *temp;

	if(value == current->data) {
		*start = current->next;
		free(current);
		return;
	}
	
	while(current != NULL) {
		if(current->next->data == value) {
			temp = current->next;
			current->next = current->next->next;
			free(temp);
			return;
		}
		current = current->next;
	}
}

void print_list(NODE *node) {
	while(node != NULL) {
		printf("%d ", node->data); 
		node = node->next;
	}
	printf("\n");
}

void free_list(NODE *node) {
	NODE *current, *temp;
	current = node;
	while(current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
}

int main() {
    int selection,newdata,insertlocation,deletedata;
    NODE *head = NULL;
    while(1) {
        printf("�ثe��C���e: ");
        print_list(head);
        printf("\n(1) �s�W�`�I\n(2) ���J�`�I\n(3) �R���`�I\n(0) ����\n... ");
        scanf("%d",&selection);
        switch (selection) {
            case 0:
                printf("�w�h�X...");
                free_list(head);
                return 0;
            case 1:
                printf("�п�J�s�����... ");
                scanf("%d",&newdata);
                add_node(&head,newdata);
                break;
            case 2:
                printf("�п�J�n���J�����... ");
                scanf("%d",&newdata);
                printf("�п�J�n���J����m... ");
                scanf("%d",&insertlocation);
                insert_node(&head,newdata,insertlocation-1);
                break;
            case 3:
                printf("�п�J�n�R�������... ");
                scanf("%d",&deletedata);
                delete_node(&head,deletedata);
                break;
            default:
                printf("��J���~\n�Э��s��J");
                break;
        }
    }
}