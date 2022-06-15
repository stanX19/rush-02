#include "header.h"
#include <stdio.h>

int main(int argc, char** argv) {
	node* head;
	int fd;
	int val;
	char* path;

	if (argc < 2 || argc > 3) {
		write(1, "Error\n", 6);
		return 0;
	}
	if (argc == 2) {
		val = ft_atoi(argv[1]);
		path = "english.dict";
	}
	else {
		val = ft_atoi(argv[2]);
		path = argv[1];
	}
	fd = open(path, O_RDONLY);
	head = read_dict(fd);
	node* temp = head;
	while (temp) {
		printf("%lli: %s\n", temp->key, temp->val);
		temp = temp->next;
	}
	(void)val;
	free_list(head);
}