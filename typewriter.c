#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    struct input_event event;
    int keyboard = open("/dev/input/event5", O_RDONLY);

    while(1) {
        read(keyboard, &event, sizeof(event));

        if(event.code == KEY_ENTER && event.value == 1) {
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
