#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define GREEN_LED_PATH "/sys/class/leds/ACT/brightness"
#define RED_LED_PATH "/sys/class/leds/PWR/brightness"

void write_brightness(const char *path, int brightness) {
    int fd = open(path, O_WRONLY);
    if (fd == -1) return;

    char buffer[4];
    int len = snprintf(buffer, sizeof(buffer), "%d", brightness);
    if(write(fd, buffer, len)<0){
        close(fd);
        return;
    }
    close(fd);
}

int main() {
    while (1) {
        printf("Green: off  Red: on\n");
        write_brightness(GREEN_LED_PATH, 0);
        write_brightness(RED_LED_PATH, 0);
        sleep(1);

        printf("Green: on   Red: off\n");
        write_brightness(GREEN_LED_PATH, 255);
        write_brightness(RED_LED_PATH, 255);
        sleep(1);
    }
    return 0;
}
