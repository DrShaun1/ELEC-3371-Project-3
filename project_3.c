//Names: Aidan Stoner, Marc Santacapita, Erin Cardino, and Shaunessy Reynolds
//Date: 10/16/13
//Course: ELEC-3371
//Description: PE13 and PE15 need to be high in order for the 7-segments to display a number. PE11 switch which
//             7-segment is being displayed, PE8, PE10, PE12, & PE14 are data pins which will display the
//             decimal version of their binary value 0-9.
//******************************************************************************
//Global Variables:
int num1 = 0xA500; //Variables for 7-seg display
int prevPA0 = 0; //holds previous value of PA0 for falling/rising edge purposes
//******************************************************************************
//Main Function
void main() {
//Initializations
     RCC_APB2ENR |= 1 << 2;  //enables clock for PortA
     RCC_APB2ENR |= 1 << 5;  //enables clock for PortD
     RCC_APB2ENR |= 1 << 6;  //enables clock for PortD    need to choose output port and enable it
     
     GPIOA_CRL = 0x44444444; //Set PortA as an input
     GPIOA_CRH = 0x44444444;
     GPIOD_CRL = 0x44444444; //Set PortD as an input
     GPIOD_CRH = 0x44444444;
     GPIOE_CRL = 0x33333333; //Set PortE as an output for LEDS
     GPIOE_CRH = 0x33333333;
//******************************************************************************
//Objective 2
          GPIOE_ODR = num1;   //sets GPIOE equal to num1 variable which will then be displayed on the MET1155
//******************************************************************************
     while(1){
//Objective 3
          if(GPIOA_IDR.B0 == 1){
               prevPA0 = 1;
          }
          if(GPIOA_IDR.B0 == 0 & prevPA0 == 1){
               GPIOE_ODR.B11 = ~GPIOE_ODR.B11;
               prevPA0 = 0;
          }
     }
}