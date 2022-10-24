#include "terminal.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "card.h"

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
    uint8_t date[11],datelength;
    printf("Enter the transactionDate in form of DD/MM/YY :\n");
    gets(date);
    datelength=strlen(date);

  if(termData == NULL || datelength<10 || date[2] !='/' || date[5] !='/') 
        {
          

                
          return WRONG_DATE; 
        }else 
        {

          time_t t = time(NULL);
                struct tm tm = *localtime(&t);
                uint16_t day,month,year;
                year=tm.tm_year + 1900;
                month=tm.tm_mon+  1;
                day = tm.tm_mday;
                  termData->transactionDate[0]=day/10 + '0';
                  termData->transactionDate[1]=day%10 + '0';
                  termData->transactionDate[2]='/';
                  termData->transactionDate[3]=month/10 + '0';
                  termData->transactionDate[4]=month%10 + '0';
                  termData->transactionDate[5]='/';
                  termData->transactionDate[6]=year/1000  + '0';
                  termData->transactionDate[7]=(year%1000)/100 + '0';
                  termData->transactionDate[8]=(year%1000)/10 +   '0';
                  termData->transactionDate[9]=year%10  + '0';
                  termData->transactionDate[10]='\0';
                  printf("%s\n",termData->transactionDate);
                  return TERMINAL_OK;
  }


}



EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
  uint8_t  yearexpire=((cardData->cardExpirationDate[3]-'0') *10 + (cardData->cardExpirationDate[4]-'0'));
  uint8_t yeartransaction=((termData->transactionDate[8]-'0') *10 + (termData->transactionDate[9]-'0'));
  uint8_t monthexpire=((cardData->cardExpirationDate[0]-'0')*10 +(cardData->cardExpirationDate[1]-'0'));
  uint8_t monthtransation=((termData->transactionDate[3]-'0')*10 + (termData->transactionDate[4]-'0'));
  if(yearexpire<yeartransaction)
  {
    return EXPIRED_CARD;
  }else if( yearexpire == yeartransaction)
  {
    if(monthexpire<monthtransation)
      {
        return EXPIRED_CARD;
      }else
      {
        return TERMINAL_OK;
      }
  }else 
  {
    return TERMINAL_OK;
  }



}



EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
  float amount;
  printf("Enter the transaction amount :\n");
  scanf("%f",&amount);
  if(amount<= 0)
  {
    return INVALID_AMOUNT;
  }else
  {
    termData->transAmount=amount;
    return TERMINAL_OK;
    
  }


}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
  if(termData->transAmount>termData->maxTransAmount)
  {
    return EXCEED_MAX_AMOUNT;
  }else
    return TERMINAL_OK;

}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
  
  if(maxAmount<=0)
  {
    return INVALID_MAX_AMOUNT;
  }else
  {
      termData->maxTransAmount=maxAmount;
    return TERMINAL_OK;
  }


}