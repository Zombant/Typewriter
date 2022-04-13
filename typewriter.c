#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#define DEVICE "/dev/input/event%d"

int findKeyboard(){
    int keyboard = -1;
    int i = 0;
    while(keyboard == -1){
        char buf[20];
        snprintf(buf, 20, DEVICE, i);
        keyboard = open(buf, O_RDONLY);
        printf("Trying device: %s\n", buf);
        i++;
    }

    return keyboard;
}

int main(int argc, char **argv) {
    struct input_event event;

    //Find event name in /proc/bus/input/devices

    int keyboard;
    if(argc == 2) {
        keyboard = open(argv[1], O_RDONLY);
    } else {
        keyboard = findKeyboard();
    }

    if(keyboard == -1) {
        fprintf(stderr, "Could not open keyboard\n");
        exit(1);
    }

    while(1) {
        read(keyboard, &event, sizeof(event));

        if((event.code == KEY_ENTER || event.code == KEY_KPENTER) && event.value == 1) {
            system("mpg123 /etc/typewriter/ding.mp3 &");
        }

        if((event.type == EV_KEY) && (event.value == 1)) {
            system("mpg123 /etc/typewriter/keydown.mp3 &");
        }

        if((event.type == EV_KEY) && (event.value == 0)) {
            system("mpg123 /etc/typewriter/keyup.mp3 &");
        }
    }

    close(keyboard);
}
