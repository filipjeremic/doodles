#include <stdio.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

#define MAX_GROUPS 2

int main()
{
   // Not const char/readonly memory to avoid copying later when printing
   char sample[] = "\
argentumbooks@cbn.net.id \
info@rasabali.com \
robertson.anya@gmail.com \
fk230581@gmail.com \
ziravazma@yahoo.com \
135arthouse@padmaubud.biz \
tagged_gathering@yahoo.com \
lataverna@gmail.com \
argentumbooks-subscribe@googlegroups.com \
meliabenoa@solmelia.com \
ceria@permatabank.co.id \
sinar@nerantimagsaysay.co.id \
adminbali@apvcasia.com \
bali_hrd-2008@yahoo.com \
ian@kutatownhouses.com \
personal@designelicious.com \
directjava@gmail.com \
knkb.bali@gmail.com \
tradiumcorp@gmail.com \
bali@galleria.co.id \
salvindo@ins.salvationarmy.org\
";

   // Match emails ending with "gmail.com"
   const char *const regexString = "[a-zA-Z][a-zA-Z_0-9\\.]*@gmail\\.com"; // [\\w\\d]* doesn't work, I didn't investigate why...

   regex_t regexCompiled;
   if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
   {
      printf("Could not compile the regular expression.\n");
      return 1;
   }

   char *current = sample;

   regmatch_t groupArray[MAX_GROUPS];

   while (true)
   {
      if (regexec(&regexCompiled, current, MAX_GROUPS, groupArray, 0) != 0)
      {
         break; // No more matches
      }

      const size_t startOffset = groupArray[0].rm_so;
      const size_t endOffset = groupArray[0].rm_eo;

      const char tempChar = current[endOffset];
      current[endOffset] = 0;
      printf("%s\n", current + startOffset);
      current[endOffset] = tempChar;

      current += endOffset;
   }

   regfree(&regexCompiled);

   return 0;
}
