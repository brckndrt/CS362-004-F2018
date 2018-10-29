#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	//define list of characters that trigger state variable change
    char errChars[9] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
	
	//return a randomly selected character from array of error characters
    return errChars[rand() % sizeof(errChars)];
}

char *inputString()
{
	//declare integer variable for use in loop
    int i;
	
	//define list of legal characters used to create string
	char errString[5] = {'r', 'e', 's', 'e', 't'};
	
	//declare reusable temp variable to hold generated string with additional space for null terminator
	char *tempString = malloc(sizeof(char) * strlen(errString) + 1);
	
	//loop and create string of five characters
	for (i = 0; i < sizeof(errString); i++){
		tempString[i] = errString[rand() % sizeof(errString)];
	}
	
	//insert null terminator at end of string
	tempString[i] = '\0';
	
	
    return tempString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
