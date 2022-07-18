#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
    struct _node* prev;
} Node;

typedef struct _DLL
{
	int n;
	struct _node* head;
} DLL;

void init_DLL(DLL* s)
{
	s->n = 0;
	s->head = NULL;
}

void add_Node(DLL* s, int _data)
{
	Node* _new = (Node*)malloc(sizeof(Node));
	_new->data = _data;
	_new->next = NULL;
    _new->prev = NULL;
	s->n++;

	if (s->head == NULL)
	{
		s->head = _new;
		return;
	}
	else
	{
		Node* temp = s->head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = _new;
        _new->prev = temp;
		return;
	}
}

Node* find_Node(DLL* s, int _data)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = s->head;

	while (cur != NULL)
	{
		if (cur->data == _data)
			return cur;

		cur = cur->next;
	}

	if (cur != NULL)
		return NULL;
	
}

void delete_Node(DLL* s, int _data)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = find_Node(s, _data);

	if (cur == NULL)
	{
		printf("Not Found!!\n");
		return;
	}

	if (cur == s->head)
	{
		printf("You delete the head!\n");
		s->head = cur->next;
        cur->next->prev = NULL;
		free(cur);
		return;
	}
	else
	{
		cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
		free(cur);

		printf("Delete Complete!\n");
	}
	return;
}

void insert_Node(DLL* s, int _num, int _data)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = find_Node(s, _num);

    if(cur == NULL)
    {
        printf("Not Found!!\n");
        return;
    }

    Node *_new = (Node *)malloc(sizeof(Node));
    _new->data = _data;
	_new->next = cur->next;
    _new->prev = cur;

    if (cur->next != NULL)
        cur->next->prev = _new;

	cur->next = _new;
    
	printf("Insert Complete!\n");
	return;
}

void show_DLL(DLL* s)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = s->head;
	while (cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

int main()
{
	DLL* s = (DLL*)malloc(sizeof(DLL));

	init_DLL(s);

	add_Node(s, 1);
	add_Node(s, 2);
	add_Node(s, 3);
	add_Node(s, 4);
	add_Node(s, 5);

	show_DLL(s);

	int number_find;
	printf("Enter number to find : ");
	scanf("%d", &number_find);
	Node* find = find_Node(s, number_find);
	if (find == NULL)
		printf("Not Found\n");
	
	else
		printf("Found %d!!\n",number_find);
	
	int number_delete;
	printf("Enter number to delete : ");
	scanf("%d", &number_delete);
	delete_Node(s, number_delete);
	show_DLL(s);

	int idx;
	printf("Enter number where you insert : ");
	scanf("%d", &idx);

	int number_insert;
	printf("Enter number to insert : ");
	scanf("%d", &number_insert);
	insert_Node(s, idx, number_insert);
	show_DLL(s);
}