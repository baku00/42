#include "server.h"

void my_handler(int signum)
{
	static t_transmition transmition;

	transmition.c[1] = 0;
	if (!transmition.message)
	{
		transmition.message = ft_calloc(1, sizeof(char));
		if (!transmition.message)
			return;
	}
	if (!transmition.state)
	{
		transmition.state = 128;
		transmition.c[0] = 0;
	}
	if (signum == SIGUSR2)
		transmition.c[0] += transmition.state;
	transmition.state /= 2;
	if (!transmition.state)
	{
		transmition.message = ft_strjoin(transmition.message, transmition.c);
		if (!transmition.c[0])
		{
			printf("Message: %s\n\n\n\n", transmition.message);
			free(transmition.message);
			transmition.message = NULL;
		}
	}
}

void handler(int signo, siginfo_t *info, void *context)
{
    struct sigaction oldact;
    if (sigaction(SIGSEGV, NULL, &oldact) == -1) {
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_transmition	transmition;
	struct sigaction act = { 0 };

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &handler;
	if (sigaction(SIGSEGV, &act, NULL) == -1){
		printf("Sigaction error\n");
		exit(EXIT_FAILURE);
	}
	// raise(SIGSEGV);
	// t_transmition	transmition;
	// struct sigaction act = { 0 };
	printf("%d\n", getpid());
	// act.sa_flags = SA_SIGINFO;
    // act.sa_sigaction = &handler;
	// if (sigaction(SIGSEGV, &act, NULL) == -1) {
    //     perror("sigaction");
    //     exit(EXIT_FAILURE);
    // }
	// signal(SIGUSR1, my_handler);
	// signal(SIGUSR2, my_handler);
	while (1)
	pause();
	return (0);
}
