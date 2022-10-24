#include "card.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
  if(cardData !=NULL)
   {
		// getting the name and put it into a buffer
		uint8_t name[24];
		printf("please enter card name within range 20-24 char\n");
		gets(name);
		//printf("%d\n",strlen(name));
		uint8_t namelen=strlen(name);
		if((namelen<20 || namelen>24 || namelen == 0))
		{
		return WRONG_NAME;
		}else
		{
		for(int i=0;i<24;i++)
		{
			{
				if(((name[i]>= 'a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z')))
					{
					strcpy(cardData->cardHolderName,name);
					return CARD_OK;}								

			}

				

		}
		}
		
	
   	}	

}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t date[6];
	printf("please enter date in form of MM/YY\n");
	gets(date);
	uint8_t length =strlen(date);
	if((length != 0 || length<5 || length >5) && (isdigit(date[0]) && isdigit(date[1]) && date[2] =='/' && (isdigit(date[3])) &&(isdigit(date[4]))))
		{
			
			strcpy(cardData->cardExpirationDate,date);

			return CARD_OK;

		}else
		{
			return WRONG_EXP_DATE;

		}
	 

	
	
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t pan[21],count=0;
	printf("Enter Primary Account Number:\n");
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
	strcpy(cardData->primaryAccountNumber,pan);
	return CARD_OK;
		
	
}



