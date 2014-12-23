#include <p32xxxx.h>
char spi_send_recveive(char send){
    SPI2BUF=send;
    while (SPI2STATbits.SPIBUSY);
    return SPI2BUF;
}
void __attribute__((interrupt(IPL6))) __attribute__((vector(4)))
sendA(void){
    char received;
    received = spi_send_recveive('A');//A
    IFS0bits.T1IF = 0; // wyzerowanie flagi przerwania
    return;
}
void __attribute__ ((interrupt(IPL7))) __attribute__ ((vector(8)))
sendB(void){
    char received;
    received = spi_send_recveive('B');
    IFS0bits.T2IF = 0; // wyzerowanie flagi przerwania
    return;
}
void initspi(void){  //inicjalizacja trybu master
    char junk; //
    SPI2CONbits.ON = 0;//zerowanie spi
    junk = SPI2BUF; //czyszczenie bufora
    SPI2BRG = 7; //ustawienie Baud rate w rejestrze BRG
    SPI2CONbits.MSTEN = 1; //tryb master spi, 5bit
    SPI2CONbits.CKE = 1; //
    SPI2CONbits.ON = 1; // wlaczenie spi
}

void initTimer1Interrupt(void){  //  TIMER1 ##########################
    T1CONbits.ON=0; // timer wyl.
    TMR1 = 0; // reset timera1

    T1CONbits.TCKPS=3; //preskaler 1:256 -> 20MHz/256=78.125Khz
    PR1=39063/4; //zmiana co 0.5sek.

    INTCONbits.MVEC=1;// vector mode on
    IPC1=0x6 << 2 | 0x3;// priority 7, subpriority 3
    IFS0bits.T1IF=0; //czysc flage przerwania Tmr1
    IEC0bits.T1IE=1; //wl. przerwania Tmr1
    asm volatile("ei"); // wl. przerwan
    T1CONbits.ON=1;// wl. timer
}                                   //################################
void initTimer2Interrupt(void){  //  TIMER2 ##########################
    T2CONbits.ON=0; // timer wyl.
    TMR2 = 0; // reset timera2

    T2CONbits.TCKPS=3; //preskaler
    PR2=1000; //

    INTCONbits.MVEC=1;// vector mode on
    IPC2=0x7 << 2 | 0x3;// priority 7, subpriority 3
    IFS0bits.T2IF=0; //czysc flage przerwania Tmr2
    IEC0bits.T2IE=1; //wl. przerwania Tmr2
    asm volatile("ei"); // wl. przerwan
    T2CONbits.ON=1;// wl. timer2 %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%dodane TON zamiast ON
}                                   //################################
int main(void) {
    initspi();
    initTimer1Interrupt();
    initTimer2Interrupt();
    while(1); //dzialanie w petli nieskonczonej
    return (0);
}
