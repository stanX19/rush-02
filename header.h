#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef MAX_FD
#  define MAX_FD 50
# endif

typedef struct s_dict
{
	long long int	key;
	char* val;
	struct s_dict*	next;
} node;

node* new_node(long long int key, char* val);
node* push_node(node** start, long long int key, char* val);
void free_list(node* start);
node* last_node(node* head);

char* get_next_line(int fd);
char* substr(char* str, int start, int end);
void* ft_memset(void* b, int c, size_t len);
int	  find(char* str, int start, int end, char target);
void* ft_memcpy(char* dst, const char* src, int n);
long long int	ft_atoi(char* str);
int ft_strlen(char* str);
char* ft_strcat(char* dest, char* src);

node* read_dict(int fd);
#endif