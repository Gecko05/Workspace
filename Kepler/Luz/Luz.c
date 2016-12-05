#include <Luz.h>
#use rs232(baud=9600,parity=N,xmit=PIN_C6,rcv=PIN_C7,bits=8)
unsigned long luzAdc;
int conversion = 2;
int constante = 0;
int16 lumens;
void main()
{
   setup_adc_ports(AN0);
   setup_adc(ADC_CLOCK_DIV_4);
   setup_timer_2(T2_DIV_BY_4,249,1);      //1.0 ms overflow, 1.0 ms interrupt

   setup_ccp1(CCP_PWM);
   set_pwm1_duty((int16)100);

   while(TRUE)
   {
      //TODO: User Code
      set_adc_channel(0);//set the pic to read from AN0
      luzAdc = read_adc();
      lumens = ((((float)luzAdc)/65536)*conversion) + constante;
      printf("%lu\r\n",luzAdc);
   }

}
