#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    if(my_pid <= 2500)
    printf("This is the new Pid:\t");
    printf("%u\n", my_pid);

    return (0);
}
