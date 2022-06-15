#include "header.h"
#include <stdio.h>

char* to_words(node* head, long long int val)
{
	char* ret;
	node* cur;
	char buf[10000];

	buf[0] = 0;
	cur = head;
	while (cur && val > 0) {
		if (val / cur->key) {
			if (val / cur->key > 1) {
				ret = to_words(head, val / cur->key);
				ft_strcat(buf, ret);
				free(ret);
			}
			ft_strcat(buf, cur->val);
			ft_strcat(buf, " ");
		}
		val %= cur->key;
		cur = cur->next;
	}
	if (*buf == 0) {
		cur = last_node(head);
		ft_strcat(buf, cur->val);
	}
	ret = substr(buf, 0, ft_strlen(buf));
	return ret;
}

int main(int argc, char** argv) {
	node* head;
	char* ret;
	int fd;
	long long int val;
	char* path;

	if (argc < 2 || argc > 3) {
		write(1, "Error\n", 6);
		return 0;
	}
	if (argc == 2) {
		val = ft_atoi(argv[1]);
		path = "english.txt";
	}
	else {
		val = ft_atoi(argv[2]);
		path = argv[1];
	}
	fd = open(path, O_RDONLY);
	head = read_dict(fd);
	ret = to_words(head, val);
	write(1, ret, ft_strlen(ret));
	write(1, "\n", 1);
	free(ret);
	free_list(head);
}