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
	struct _node* head;
	struct _node* tail;
} DLL;

void init_DLL(DLL* s)
{
	s->head = NULL;
	s->tail = NULL;
}

void add_Node(DLL* s, int _data)
{
	Node* _new = (Node*)malloc(sizeof(Node));
	_new->data = _data;
	_new->next = NULL;
    _new->prev = NULL;

	if (s->head == NULL)
	{
		s->head = _new;
		s->tail = _new;
		return;
	}
	else
	{
		s->tail->next = _new;
		_new->prev = s->tail;
		
		s->tail = _new;
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
	}
	else if (cur == s->tail)
	{
		printf("You delete the tail\n");
		s->tail = cur->prev;
		cur->prev->next = NULL;
		free(cur);
	}
	else
	{
		printf("Delete Complete!\n");
		cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
		free(cur);

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

	if (cur == s->tail)
		s->tail = _new;
	else
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

void show_reverse_DLL(DLL *s)
{
	Node* cur = (Node*)malloc(sizeof(Node));
	cur = s->tail;
	while(cur != NULL)
	{
		printf("%d ", cur->data);
		cur = cur->prev;
	}
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
	show_reverse_DLL(s);

}