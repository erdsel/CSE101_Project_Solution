/*Hocam sadece ilk üc secenek dogru calisiyor. Dorduncu secenegi yapmaya vaktim yetmedi fakat eger dogru bilgi yollayabilseydim olmasi gereken islemler arduino kodunda yazmaktadır. Besinci secenegin de dogru olup olmadigindan emin degilim. Kaynakca olarak kullandıgim siteleri buraya ekliyorum. Kodda hata almamak amacli bu siteleri kullandim, bilginize.
https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/
https://www.arduino.cc/en/Reference/Sq
https://www.mobilhanem.com/arduino-dersleri-serial-port-ve-fonksiyonlari/#parse
 */


// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
// C library headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit()
int main () {
int serial_port = open("/dev/ttyUSB0", O_RDWR);
int counter=0;
// Check for errors
if (serial_port < 0) {
    printf("Error %i from open: %s\n", errno, strerror(errno));
}
struct termios tty;
if(tcgetattr(serial_port, &tty) != 0) {
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
}
struct termios {
	tcflag_t c_iflag;		/* input mode flags */
	tcflag_t c_oflag;		/* output mode flags */
	tcflag_t c_cflag;		/* control mode flags */
	tcflag_t c_lflag;		/* local mode flags */
	cc_t c_line;			/* line discipline */
	cc_t c_cc[NCCS];		/* control characters */
};

while(1){
printf("## WELCOME TO GTU ARDUINO LAB ##\n## STUDENT NAME: SELEN ERDOGAN ##\n## PLEASE SELECT FROM THE FOLLOWING ##\n## MENU : ##\n(1) TURN ON LED ON ARDUINO\n(2) TURN OFF LED ON ARDUINO\n(3) FLASH ARDUINO LED 3 TIMES\n(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO\n(5) Button press counter (bonus item)\n(0) EXIT\nPLEASE SELECT:");
	int secim;
	scanf("%d", &secim);
	if (secim == 1){
char num[] = "1";
		
	write(serial_port, num, 1);
	printf("%s\n",num);
	counter++;

}
else if (secim == 2){
char num2[] = "2";
		
	write(serial_port, num2, 1);
	printf("%s\n",num2);
	counter++;

}
else if (secim == 3){
char num3[] = "3";
		
	write(serial_port, num3, 1);
	printf("%s\n",num3);
	counter++;

}
else if (secim == 4){
char num4[] = "4";
        write(serial_port, num4, 1);
	printf("%s\n",num4);
	printf("Enter the number you want to square");	
	int x;
	scanf("%d" , &x);//Hocam bu kisim calismiyor.
	counter++;

}
else if (secim == 5){
char num5[] = "5";
		
	write(serial_port, num5, 1);
	printf("%s\n",num5);
	//Bu kisim dogru olmayabilir.
	printf("%d kez islem yapildi.", counter);

}
else if (secim == 0){
exit(0);

}
else {
printf("That's not an option.\n Try again\n");

}


}
close(serial_port);
return 0;
}
