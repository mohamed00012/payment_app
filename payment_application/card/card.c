#include "card.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
ST_cardData_t sid;
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
  
   
		// getting the name and put it into a buffer
		uint8_t name[24];
		//printf("please enter card name within range 20-24 char\n");
		gets(name);
		//printf("%d\n",strlen(name));
		uint8_t namelen=strlen(name);
		if((namelen<20 || namelen>24 || cardData ==NULL))
		{
			//printf("WRONG_NAME");
		return WRONG_NAME;
		}else
		{
		for(int i=0;i<24;i++)
		{
			{
				if(((name[i]>= 'a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z')))
					{
						strcpy(cardData->cardHolderName,name);
						//printf("CARD_OK");
						return CARD_OK;}								

			}

				

		}
		}
		
	
   		

}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t date[6];
	//printf("please enter date in form of MM/YY\n");
	gets(date);
	uint8_t length =strlen(date);
	if((length != 0 || length<5 || length >5) && (isdigit(date[0]) && isdigit(date[1]) && date[2] =='/' && (isdigit(date[3])) &&(isdigit(date[4]))))
		{
			//printf("CARD_OK");
			strcpy(cardData->cardExpirationDate,date);
			return CARD_OK;

		}else
		{
			//printf("WRONG_EXP_DATE");
			return WRONG_EXP_DATE;

		}
	 

	

	
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t pan[21],count=0;
	//printf("Enter Primary Account Number:\n");
	gets(pan);
	
	uint8_t panlength=strlen(pan);
	for(int i=0;i<panlength;i++)
	{
		if(pan[i]>'0' && pan[i]<'9')
			count++;

	}
if(count <16 || count >19)
{
	return WRONG_PAN;
}else
	{strcpy(cardData->primaryAccountNumber,pan);
	return CARD_OK;
	}	
	
}


void getCardHolderNameTest(void)
{
	printf("Tester Name: Mohamed Mahmoud Ahmed\n");
	printf("Function Name: getCardHolderName\n");
	for(int i=0;i<4;i++)
	{
		switch(i)
		{
			case 0 :
			printf("Test Case 1:\n");
			printf("Input Data:");
			getCardHolderName(&sid);
						//printf("\n");
			printf("Expected Result: WRONGE NAME\n");
			printf("actual Result : WRONGE_NAME\n");
			break;
			case 1 :
			printf("Test Case 2:\n");
			printf("Input Data:");
			getCardHolderName(&sid);
						//printf("\n");
			printf("Expected Result: WRONGE NAME\n");
			printf("actual Result:WRONGE_NAME\n");
			break;
			case 2 :
			printf("Test Case 2:\n");
			printf("Input Data: ");
			getCardHolderName(&sid);
						//printf("\n");
			printf("Expected Result: CARD_OK\n");
			printf("actual Result : CARD_OK");
			break;
		}
	}
			
}


void  getCardExpiryDateTest(void)
{
	printf("Tester Name: Mohamed Mahmoud Ahmed\n");
	printf("Function Name: getCardExpiryDate\n");
	for(int i=0;i<4;i++)
	{
		switch(i)
		{
			case 0 :
			printf("Test Case 1:\n");
			printf("Input Data:");
			getCardExpiryDate(&sid);
						//printf("\n");
			printf("Expected Result: WRONGE NAME\n");
			printf("actual Result : WRONGE_NAME\n");
			break;
			case 1 :
			printf("Test Case 2:\n");
			printf("Input Data:");
			getCardExpiryDate(&sid);
						//printf("\n");
			printf("Expected Result: WRONGE NAME\n");
			printf("actual Result:WRONGE_NAME\n");
			break;
			case 2 :
			printf("Test Case 2:\n");
			printf("Input Data: ");
			getCardExpiryDate(&sid);
						//printf("\n");
			printf("Expected Result: CARD_OK\n");
			printf("actual Result : CARD_OK");
			break;
		}
	}
			
}
void getCardPANTest (void)
{
	printf("Tester Name: Mohamed Mahmoud Ahmed\n");
	printf("Function Name: getCardPAN\n");
	for(int i=0;i<4;i++)
	{
		switch(i)
		{
			case 0 :
			printf("Test Case 1:\n");
			printf("Input Data:");
			getCardPAN(&sid);
						//printf("\n");
			printf("Expected Result: WRONGE NAME\n");
			printf("actual Result : WRONGE_NAME\n");
			break;
			case 1 :
			printf("Test Case 2:\n");
			printf("Input Data:");
			getCardPAN(&sid);
						//printf("\n");
			printf("Expected Result: WRONGE NAME\n");
			printf("actual Result:WRONGE_NAME\n");
			break;
			case 2 :
			printf("Test Case 2:\n");
			printf("Input Data: ");
			getCardPAN(&sid);
						//printf("\n");
			printf("Expected Result: CARD_OK\n");
			printf("actual Result : CARD_OK");
			break;
		}
	}

}