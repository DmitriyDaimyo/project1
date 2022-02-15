#include <user/user.h>


int main()
{
	int buf1[2];
	int buf2[2];
	pipe(buf1);
	pipe(buf2);
	if (fork() == 0)
	{
		char a;
		close(buf1[1]);
		close(buf2[0]);
		read(buf1[0], &a, 1);
		printf("%d: recieved ping\n", getpid());
		write(buf2[1], &a, 1);
		exit(0);
	}
	else
	{
		char x = 'a';
		char b;
		close(buf1[0]);
		close(buf2[1]);
		write(buf1[1], &x, 1);
		read(buf2[0], &b, 1);
		printf("%d: recieved pong\n", getpid());
		exit(0);
	}
}
