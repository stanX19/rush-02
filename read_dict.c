#include "header.h"

static char* get_val(char* str) {
	int len;
	int i;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	if (!str[i])
		return 0;
	i++;
	if (str[i] == ' ')
		i++;
	len = i;
	while (str[len] && str[len] != '\n' && str[len] != '\r')
		len++;
	return substr(str, i, len);
}

node* read_dict(int fd) {
	char*			line;
	node*			head;
	long long int	key;

	head = 0;

	line = get_next_line(fd);
	while (line) {
		key = ft_atoi(line);
		push_node(&head, key, get_val(line));
		free(line);
		line = get_next_line(fd);
	}

	return head;
}