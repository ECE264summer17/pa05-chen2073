#include <stdlib.h>
#include "utility.h"
#include "answer05.h"

// recursive implementation of long_int_to_string conversion
// this code should print only the magnitude of the number
// the sign is taken care of by the long_int_to_string function
// 
void rec_magnitude_long_int_to_string(long int number, int base,
                                      char *intstring, int *stringlen)
{
   // increment the counter for counting the number of recursive calls
   // do not remove this line

   Increment_counter(&number);

   // put your code here



  // Last statement
   Decrement_counter();
}

char *long_int_to_string(long int number, int base)
{
   // the real function for long_int_to_string

   char intstring[65];  // 65 because the largest length needed is 
                        // for base 2, 1 byte for the negative sign,
                        // 63 bytes for the magnitude, and 1 byte for null char
   int stringlen = 0;

   if ((base < 2) || (base > 36)) {
      return NULL;
   }
   if (number < 0) {
      intstring[0] = '-';
      // place the number at location 1 of intstring
      stringlen = 1;
   }
   rec_magnitude_long_int_to_string(number, base, intstring, &stringlen);

   // allocate enough space for null character
   char *ret_string = (char *)malloc(sizeof(char) * (stringlen + 1));
   int i;
   for (i = 0; i < stringlen; i++) {
      ret_string[i] = intstring[i];
   }
   ret_string[i] = '\0';
   return ret_string;
}
