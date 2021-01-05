#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char *GetFirstToken(char str[], char inputCopy[], const char delim[])
{
  strcpy(inputCopy, str);
  return strtok(inputCopy, delim);
}

char *GetSecondToken(char str[], char inputCopy[], const char delim[])
{
  strcpy(inputCopy, str);
  char *ptr = strtok(inputCopy, delim);
  return strtok(NULL, delim);
}

// Function to check if two words are similar, if so -- True , Else - False
bool checksim(char *tok, char *fword)
{
char helps[strlen(fword)];
  int e = 0;
  if (strlen(tok) - strlen(fword) == 1)
  {
    for (int i = 0; i < strlen(tok); i++)
    {
      memset(helps,0,strlen(helps));
      for (int j = 0; j < strlen(tok); j++)
      {
        if (i != j)
        {
          helps[e] = tok[j];
          e++;
        }
      }

      if (strcmp(helps, fword) == 0)
      {

        return true;
        break;
      }
      else
      {
        strcpy(helps, "");
        e = 0;
      }
    }
  }
  return false;
}

int main()
{
  char string[512];
  char *token;
  //Get First Line....
  fgets(string, 512, stdin);
  char *inputCopy = malloc(255 * sizeof(char));
  //Possible delimiters
  const char delim[] = " \t\r\n\v\f";
  //Get First Word
  char *first = GetFirstToken(string, inputCopy, delim);
  //Get Choice(a||b)
  char *second = GetSecondToken(string, inputCopy, delim);
  if (*second == 'a')
  {
    while (fgets(string, 512, stdin))
    {
      // Check if First Word is contained in the line
      if (strstr(string, first) != NULL)
      {
        printf("%s\n", string);
      }
    }
  }
  else
  {
    while (fgets(string, 512, stdin))
    {
      token = strtok(string, delim);
      while (token != NULL)
      {
        
        //first case - they are exactly equal
        if (strcmp(first, token) == 0)
        {
          printf("%s\n", token);
        }
        //second case: Similar Words
        if (checksim(token, first))
        {
          printf("%s\n", token);
        }
        token = strtok(NULL, delim);
      }
    }
  }
}
