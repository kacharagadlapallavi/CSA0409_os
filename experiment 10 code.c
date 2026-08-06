#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msg {
    long type;
    char text[100];
} message;

int main() {
    key_t key = 1234;
    int msgid = msgget(key, 0666 | IPC_CREAT);

    message.type = 1;
    printf("Enter message: ");
    fgets(message.text, 100, stdin);

    msgsnd(msgid, &message, sizeof(message), 0);
    printf("Message sent\n");

    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("Received: %s\n", message.text);

    return 0;
}