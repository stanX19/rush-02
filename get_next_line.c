#include "header.h"

static int read_to_buf(int fd, char*buf, int *idx, int*end)
{
	int ret;
	int temp;

	if (BUFFER_SIZE < 0)
		return -1;
	*end = *idx;
	temp = find(buf, 0, *end, '\n');
	ret = BUFFER_SIZE;
	while (temp == -1 && ret == BUFFER_SIZE) {
		ret = read(fd, buf + *end, BUFFER_SIZE);
		if (ret == -1)
			return -1;
		temp = find(buf, *end, *end + ret, '\n');
		*end += ret;
	}
	if (temp == -1)
		*idx = *end - 1;
	else
		*idx = temp;
	return 0;
}

char* get_next_line(int fd)
{
	static char buffers[MAX_FD + 1][10000000];
	int idx;
	int end;
	char* txt;

	if (fd < 0 || fd > MAX_FD)
		return 0;
	idx = ft_strlen(buffers[fd]);
	if (read_to_buf(fd, buffers[fd], &idx, &end) == -1 || idx == -1)
		return 0;
	end = end - idx - 1;
	txt = substr(buffers[fd], 0, idx + 1);
	ft_memcpy(buffers[fd], buffers[fd] + idx + 1, end);
	buffers[fd][end] = 0;
	return txt;
}