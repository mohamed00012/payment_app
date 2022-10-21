#include "card.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	// getting the name and put it into a buffer
	uint8_t name[24];
	printf("please enter card name within range 20-24 char\n");
	gets(name);

	uint8_t namelen=strlen(name);
	if(namelen<20 &&	 namelen>24)
	{
		return WRONG_NAME;
	}else
	{
		for(int i=0;i<24;i++)
		{
			if(name[i] != ' ')
			{
				if(!((name[i]>= 'a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z')))
					{return WRONG_NAME;}								

			}
			continue;
				

		}
	}
	strcpy(cardData->cardHolderName,name);
	return CARD_OK;
		

}


EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t date[5];
	printf("please enter date in form of MM/YY\n");





	
}



