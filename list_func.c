#include "header.h"

node* new_node(long long int key, char*val) {
	node* new;
	
	new = malloc(sizeof(node));
	if (new)
	{
		new->key = key;
		new->val = val;
		new->next = 0;
	}
	return new;
}

node* push_node(node**start, long long int key, char* val) {
	node* new;

	new = new_node(key, val);
	if (new)
	{
		new->next = *start;
		*start = new;
	}
	return new;
}

node* last_node(node* head) {
	if (head->next)
		return last_node(head->next);
	return head;
}

void free_list(node* start) {
	node* temp;

	while (start)
	{
		temp = start;
		start = start->next;
		free(temp->val);
		free(temp);
	}
}