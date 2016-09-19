#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_FOSC_X2	25000001

int crystal []={  32768,
		1000000,
		1834200,
		2000000,
		2457600,
		3000000,
		3276800,
		3579545,
		3686400,
		4000000,
		4194304,
		4433619,
		4915200,
		5000000,
		6000000,
		7372800,
		8000000,
	       10000000,
	       11059200,
	       12000000,
	       14318100,
	       14745600,
	       16000000,
	       18432000,
	       19660800,
	       20000000,
	       22118400,
	       24000000,
	       24000140,
	       25000000,
	       30875000,
	       32000000,
	       40000000,
	       60000000,
	       	      0 };

int baudrate[]={  110,
		  300,
		 1200,
		 2400,
		 4800,
		 9600,
		19200,
		28800,
		38400,
		57600,
	       115200,
	       230400,
	       460800,
	       921600,
	      1843200,
	            0 };

unsigned int	fosc;

int bdr (int prescaler, int max, int val)
{
return (val>=max || val<0 || !prescaler)?0:(fosc/prescaler/(max-val));
}

int val (int prescaler, int max, int bdr)
{
return (!prescaler || !bdr)?-1:(max-fosc/prescaler/bdr);
}

int main (void)
{
int		i,ii,j,n;
int		std_timer8,true_baudrate_std_timer8,smod1_timer8,true_baudrate_smod1_timer8;
int		std_timer16,true_baudrate_std_timer16;
int		this_baudrate;
char		use_smod1_timer8,use_std_timer8,use_x2_mode;
char		use_std_timer16;
char		sz0[256];
char		sz1[256];
char		sz2[256];
char		sz_temp[10];

int		bdr0,bdr1,bdr2,val0,val1,val2,delta0,delta1,delta2,type0,type1,type2;
char		bdr_supported;

printf("// <== Using generator script/bdr.c c5131-usb-cdc-1_2_1 $Id: c51_bdr.c,v 1.7 2003/08/19 11:51:23 apache Exp $\r\n\
// BRG-0 refers to standard Atmel Internal Baudrate Generator peripheral (if available)\r\n\
// BRG-1 refers to standard C51 Timer 1 peripheral used as Baudrate Generator\r\n\
// BRG-2 refers to standard C52 Timer 2 peripheral used as Baudrate Generator (if available)\r\n\
\r\n#ifndef FOSC\r\n#error You must define FOSC in config.h\r\n");
for (ii=0;crystal[ii];ii++)
for (i=0;i<=ii;i++)
  {
  if (!(i==ii  || (i<ii && crystal[i]*2>crystal[(ii?(ii-1):0)] && crystal[i]*2<crystal[ii]))) continue;
    fosc=crystal[i];
    if (i!=ii) fosc*=2;
  printf("#elif   FOSC     ==         %6u // Fosc = %6u.%03u kHz\r\n",fosc/1000,fosc/1000,fosc%1000);
  for (j=0,n=0,sz0[0]=0,sz1[0]=0,sz2[0]=0;this_baudrate=baudrate[j];j++)
    {
    bdr_supported=0;

    use_x2_mode=0;
    fosc=crystal[i];
    if (i!=ii) fosc*=2;
    LABEL_X2_MODE_0:
    val0=val(384,256,this_baudrate);
    bdr0=bdr(384,256,val0);
    delta0=abs(this_baudrate-bdr0);
    type0=0;

    if (delta0>abs(this_baudrate-bdr(384,256,val0-1)))
      { // Round pb
      val0--;
      bdr0=bdr(384,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (delta0>abs(this_baudrate-bdr(192,256,val(192,256,this_baudrate))))
      { // Better value
      type0=1;
      val0=val(192,256,this_baudrate);
      bdr0=bdr(192,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (delta0>abs(this_baudrate-bdr(192,256,val(192,256,this_baudrate)-1)))
      { // Round pb
      type0=1;
      val0=val(192,256,this_baudrate)-1;
      bdr0=bdr(192,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (delta0>abs(this_baudrate-bdr(64,256,val(64,256,this_baudrate))))
      { // Better value
      type0=2;
      val0=val(64,256,this_baudrate);
      bdr0=bdr(64,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (delta0>abs(this_baudrate-bdr(64,256,val(64,256,this_baudrate)-1)))
      { // Round pb
      type0=2;
      val0=val(64,256,this_baudrate)-1;
      bdr0=bdr(64,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (delta0>abs(this_baudrate-bdr(32,256,val(32,256,this_baudrate))))
      { // Better value
      type0=3;
      val0=val(32,256,this_baudrate);
      bdr0=bdr(32,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (delta0>abs(this_baudrate-bdr(32,256,val(32,256,this_baudrate)-1)))
      { // Round pb
      type0=3;
      val0=val(32,256,this_baudrate)-1;
      bdr0=bdr(32,256,val0);
      delta0=abs(this_baudrate-bdr0);
      }

    if (!use_x2_mode && fosc<MAX_FOSC_X2 && abs(this_baudrate-bdr0)*100/this_baudrate>5)
      {
      use_x2_mode=1;
      fosc*=2;
      goto LABEL_X2_MODE_0;
      }

    if (abs(this_baudrate-bdr0)*100/this_baudrate<=5)
      {
      if (!bdr_supported)
        {
	if (n++) printf("  #elif"); else printf("  #if  "); // #if or #elif ?
	printf(" BAUDRATE ==         %6u // %6u bps Serial Speed\r\n",this_baudrate,this_baudrate);
	}
      if (use_x2_mode) strcat(sz0,"*");
      sprintf(sz_temp,"%u ",this_baudrate);
      strcat(sz0,sz_temp);
                       printf("    #define BRG0_INIT          %3u // %6u bps (delta=%u.%02u%%)\r\n",val0,bdr0,delta0*100/this_baudrate,delta0*10000/this_baudrate%100);
      if (type0&1)     printf("    #define BRG0_REQUIRE_SMOD1\r\n");
      if (type0&2)     printf("    #define BRG0_REQUIRE_SPD\r\n");
      if (use_x2_mode) printf("    #define BRG0_REQUIRE_X2_MODE\r\n");
      bdr_supported=1;
      }
    use_x2_mode=0;
    fosc=crystal[i];
    if (i!=ii) fosc*=2;
    LABEL_X2_MODE_1:

    val1=val(384,256,this_baudrate);
    bdr1=bdr(384,256,val1);
    delta1=abs(this_baudrate-bdr1);
    type1=0;

    if (delta1>abs(this_baudrate-bdr(384,256,val1-1)))
      { // Round pb
      val1--;
      bdr1=bdr(384,256,val1);
      delta1=abs(this_baudrate-bdr1);
      }

    if (delta1>abs(this_baudrate-bdr(192,256,val(192,256,this_baudrate))))
      { // Better value
      type1=1;
      val1=val(192,256,this_baudrate);
      bdr1=bdr(192,256,val1);
      delta1=abs(this_baudrate-bdr1);
      }

    if (delta1>abs(this_baudrate-bdr(192,256,val(192,256,this_baudrate)-1)))
      { // Round pb
      type1=1;
      val1=val(192,256,this_baudrate)-1;
      bdr1=bdr(192,256,val1);
      delta1=abs(this_baudrate-bdr1);
      }

    if (!use_x2_mode && fosc<MAX_FOSC_X2 && abs(this_baudrate-bdr1)*100/this_baudrate>5)
      {
      use_x2_mode=1;
      fosc*=2;
      goto LABEL_X2_MODE_1;
      }

    if (abs(this_baudrate-bdr1)*100/this_baudrate<=5)
      {
      if (!bdr_supported)
        {
	if (n++) printf("  #elif"); else printf("  #if  "); // #if or #elif ?
	printf(" BAUDRATE ==         %6u // %6u bps Serial Speed\r\n",this_baudrate,this_baudrate);
	}
      if (use_x2_mode) strcat(sz1,"*");
      sprintf(sz_temp,"%u ",this_baudrate);
      strcat(sz1,sz_temp);
                       printf("    #define BRG1_INIT          %3u // %6u bps (delta=%u.%02u%%)\r\n",val1,bdr1,delta1*100/this_baudrate,delta1*10000/this_baudrate%100);
      if (type1==1)    printf("    #define BRG1_REQUIRE_SMOD1\r\n");
      if (use_x2_mode) printf("    #define BRG1_REQUIRE_X2_MODE\r\n");
      bdr_supported=1;
      }
    use_x2_mode=0;
    fosc=crystal[i];
    if (i!=ii) fosc*=2;
    LABEL_X2_MODE_2:

    val2=val(32,65536,this_baudrate);
    bdr2=bdr(32,65536,val2);
    delta2=abs(this_baudrate-bdr2);
    type2=0;

    if (delta2>abs(this_baudrate-bdr(32,65536,val2-1)))
      { // Round pb
      val2--;
      bdr2=bdr(32,65536,val2);
      delta2=abs(this_baudrate-bdr2);
      }

    if (!use_x2_mode && fosc<MAX_FOSC_X2 && abs(this_baudrate-bdr2)*100/this_baudrate>5)
      {
      use_x2_mode=1;
      fosc*=2;
      goto LABEL_X2_MODE_2;
      }

    if (abs(this_baudrate-bdr2)*100/this_baudrate<=5)
      {
      if (!bdr_supported)
        {
	if (n++) printf("  #elif"); else printf("  #if  "); // #if or #elif ?
	printf(" BAUDRATE ==         %6u // %6u bps Serial Speed\r\n",this_baudrate,this_baudrate);
	}
      if (use_x2_mode) strcat(sz2,"*");
      sprintf(sz_temp,"%u ",this_baudrate);
      strcat(sz2,sz_temp);
                       printf("    #define BRG2_INIT        %5u // %6u bps (delta=%u.%02u%%)\r\n",val2,bdr2,delta2*100/this_baudrate,delta2*10000/this_baudrate%100);
      if (use_x2_mode) printf("    #define BRG2_REQUIRE_X2_MODE\r\n");
      bdr_supported=1;
      }
    }
  printf ("  #else\r\n    #error Only these baudrates are available (*=x2 mode only):\r\n    #error BRG-0 %s\r\n    #error BRG-1 %s\r\n    #error BRG-2 %s\r\n  #endif\r\n",sz0,sz1,sz2);
  }
printf("#endif\r\n// ==> End of generator $Id: c51_bdr.c,v 1.7 2003/08/19 11:51:23 apache Exp $\r\n");
return 0;
}
