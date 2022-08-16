#include <stdio.h>
#include <conio.h>

//Electronic Power Supply Calculator
int ch;
float Vin,Vout,Iin,Iout,Rl,Vz,Rs,Iz,Pz,Pin, Pout;;
clrscr();

void main()
{
    int choice;
    float C, ans;
    float time_contsant(float,float);
    float voltage_regulator();
    float regulation();
    float gain_per();
    printf("Hello\n");
    printf("What would you like to calculate?\n");
    printf("1. Time constant\n");
    printf("2. Voltage regulation\n  a.Line Regulation \t b.Load Regulation\n");
    printf("3. a. Output Resistance  b.Voltage Regulation\n");
    printf("4. a. Voltage Gain \t b.Current Gain \t c.Power Gain\n");
    scanf("%d",&choice);
    if(choice == 1 )
    {
        printf("Enter Resistance \n");
        scanf("%f",&Rl);
        printf("Enter Capacitance \n");
        scanf("%f",&C);
        ans = time_contsant(Rl,C);
    }
    else if(choice == 2 )
        ans=voltage_regulator();
    else if(choice == 3 )
        ans=regulation();
    else if(choice == 4 )
        ans=gain_per();
    else
        printf("\n Oops! Invalid entry");
    printf("\n Answer = %f",ans);

}

float time_contsant(float rl,float c)
{
    float t;
    t=rl*c;
    return t;
}
float voltage_regulator()
{
    int c1;
    printf("\n What do you want to calculate?");
    printf("\n Press");
    printf("\n 1.Line Regulation");
    printf("\n 2.Load Regulation\n");
    scanf("\n %d",&ch);
    if (ch==1)
    {
        printf("\n To calculate input current ");
        printf("\n Enter input voltage: ");
        scanf("%f",&Vin);
        printf("\n Enter zener voltage: ");
        scanf("%f",&Vz);
        printf("\n Enter series resistance: ");
        scanf("%f",&Rs);
        Iin = (Vin-Vz)/Rs;
        return Iin;
    }
     else if(ch==2)
    {
      printf("\n To calculate Zener voltage press 1 ");
      printf("\n To calculate Series resistance press 2");
      printf("\n To calculate Zener power press 3\n");
      scanf("%d",&c1);
      switch(c1)
      {
          case 1: printf("\n Enter input voltage:");
                  scanf("%f",&Vin);
                  printf("\n Enter line resistance");
                  scanf("%f",&Rl);
                  printf("\n Enter series resistance");
                  scanf("%f",&Rs);
                  Vz = Vin*(Rl/(Rs+Rl));
                  return Vz;
                  break;

          case 2: printf("\n Enter input voltage:");
                  scanf("%f",&Vin);
                  printf("\n Enter line resistance");
                  scanf("%f",&Rl);
                  printf("\n Enter series resistance");
                  scanf("%f",&Rs);
                  Rs=Rl*((Vin/Vz)-1);
                  return Rs;
                  break;

          case 3: printf("\n Enter zener voltage:");
                  scanf("%f",&Vz);
                  printf("\n Enter Zener current");
                  scanf("%f",&Iz);
                  Pz=Vz*Iz;
                  return Pz;
                  break;

        default:  printf("\n Invalid choice!");
                  break;
      }
    }
    else
        printf("\n Invalid choice");
}


float regulation()
{
    printf("\n To calculate Output resistance press 1 \n To calculate Voltage regulation press 2 \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\n Enter change in output voltage and change in output current \n");
                scanf("%f %f",&Vout,&Iout);
                float Rout=Vout/Iout;
                return Rout;
                break;

        case 2: printf("\n Enter change in output voltage and change in input voltage \n");
                scanf("%f %f",&Vout,&Vin);
                float Vreg=(Vout/Vin)*100;
                return Vreg;
                break;

        default: printf("\n Invalid option\n");
                 break;
    }

}

float gain_per()
{
    printf("\n To calculate voltage gain press 1\nTo calculate current gain press 2\nTo calculate power gain press 3\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\n Enter output and input voltage\n");
                scanf("%f %f",&Vout,&Vin);
                float Av= Vout/Vin;
                return Av;
                break;

        case 2: printf("\n Enter output and input current\n");
                scanf("%f %f",&Iout,&Iin);
                float Ai=Iout/Iin;
                return Ai;
                break;

        case 3: printf("\n Enter output and input power \n");
                scanf("%f %f",&Pout,&Pin);
                float Ap=Pout/Pin;
                return Ap;
                break;

        default: printf("\n Invalid option");
                 break;
    }
    getch();
}



