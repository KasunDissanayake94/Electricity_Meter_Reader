#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int firstNumber=0, lastmonthreading=0, lastmonthbillamount=0,functionNo=0,thismonthreading = 0,monthlypowerconsumption = 0,payment = 0,thismonthpayment = 0,currdate = 0,currentamount=0;
    float calculateamount;
    int count = 0;
    count = count+1;
    payment = 0;
    int paymentcount = 0;
    
    if(count == 1){
    	printf("What is the last month reading  : ");
    scanf("%d",&lastmonthreading);
    printf("What is the last month bill amount  : ");
    scanf("%d",&lastmonthbillamount);
	}
    
printf("Last month reading : %d                          Last month bill amount : %d\r\n",lastmonthreading,lastmonthbillamount);
printf("\r\n");
printf("-----------------------------MAIN MENU------------------------------------\r\n");
printf("\r\n");
printf("Chose any number to run your function>>\r\n");
printf("Press 1 for Enter this month reading\r\n");
printf("Press 2 for Enter payment details\r\n");
printf("Press 3 for View payment history\r\n");
printf("Press 4 for View monthly power consumption\r\n");
printf("Press 5 for Exit\r\n");
while(1){
	//While user wants to exit this loop will run
	printf("\r\n");
	printf("Enter Number here --->");
	scanf("%d",&functionNo);
if(functionNo==1){
	//reading of this month
	printf("Enter this month reading --->");
	scanf("%d",&thismonthreading);
	if(thismonthreading < lastmonthreading){
		printf("Invalid Input!!!");
	}
	
	
}else if(functionNo==2){
	
	if(thismonthreading != 0){
		//Doing the payment
		
		int consumption = thismonthreading - lastmonthreading;
		if(consumption <=60){
			if(consumption <=30){
				calculateamount = 30+(consumption*2.50);
			}else{
				calculateamount = 30 * 2.5 + 60 +((consumption-30)*4.85);
			}
		}else{
			if(consumption <= 90 ){
				calculateamount = 90 + 60*7.85 + 10*consumption;
			}else if(consumption <=120){
				calculateamount = 480 + 60*7.85 + 10*30 + 27.75*(consumption-90);
			}else if(consumption <= 180){
				calculateamount = 480 + 60*7.85 + 10*30 + 27.75*30 + 32*(consumption-120);
			}else if(consumption > 180){
				calculateamount = 540 + 60*7.85 + 10*30 + 27.75*30 + 32*60 + 45*(consumption-180);
			}
		}
		

	printf("Your current payment amount is %f.\n",calculateamount);
	
	
	
	printf("Amount of Payment --->");
	scanf("%d",&thismonthpayment);
	printf("\r\n");
	//Check whether the payment is done or not
	if(thismonthpayment != 0){
		paymentcount++;
		if(paymentcount>1){
			printf("You have done your payment for this month...\r\n");
		}else{
			//Searching for Month 
			char key[] = "#"; // the string I am searching for
		    int wordcount = 0;	
		    wordcount = wc("test.txt", key);		
			//Write File
			FILE *out = fopen("test.txt", "a"); 
			int x = 10;
			fprintf(out,"\n| #%d           | %d           | %d     |  |  |",wordcount+1,thismonthreading,(thismonthpayment));  
			  fprintf(out, "%s", "\n+--------------+---------------+---------+--+--+");  
			  fclose(out);
		}
		
	}
	}else{
		printf("Please Enter this month reading !!!\r\n");
	}
	
	
}else if(functionNo==3){
	//Print readings on console
	int c;
	FILE *file;
	file = fopen("test.txt", "r");
	if (file) {
	    while ((c = getc(file)) != EOF)
	        putchar(c);
	    fclose(file);
	}
	
	printf("\r\n");
	printf("You due Payment---> %f\r\n",calculateamount-thismonthpayment);


}else if(functionNo==4){
	//Calculate Power Consumption here
	if(thismonthreading){
		monthlypowerconsumption = thismonthreading - lastmonthreading;
	printf("Your Monthly Power Consumption is ->%dkWh\r\n",monthlypowerconsumption);
	}else{
		printf("Please Enter this month reading to calculate monthly power consumption!!!");
	}
	
}else if(functionNo==5){
}else{
	printf("Invalid Number Pressed\r\n");
	exit(1);
}

}

    return 0;
}
//Function to find last Month
int wc(char* file_path, char* word){
    FILE *fp;
    int count = 0;
    int ch, len;

    if(NULL==(fp=fopen(file_path, "r")))
        return -1;
    len = strlen(word);
    for(;;){
        int i;
        if(EOF==(ch=fgetc(fp))) break;
        if((char)ch != *word) continue;
        for(i=1;i<len;++i){
            if(EOF==(ch = fgetc(fp))) goto end;
            if((char)ch != word[i]){
                fseek(fp, 1-i, SEEK_CUR);
                goto next;
            }
        }
        ++count;
        next: ;
    }
end:
    fclose(fp);
    return count;
}

int calculatePayment(int thismonthread){
	int r = thismonthread;

	return r;
	
}


