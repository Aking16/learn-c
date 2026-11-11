#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <inttypes.h>

/*
 * Every printf / scanf format specifier in C.
 *
 * printf grammar:  %[flags][width][.precision][length]specifier
 * scanf  grammar:  %[*][width][length]specifier
 */

int main(void)
{
  /* ---------- integer specifiers ---------- */
  int i = -42;
  unsigned int u = 42u;
  printf("%d\n", i); /* signed decimal int           */
  printf("%i\n", i); /* signed decimal int (same)    */
  printf("%u\n", u); /* unsigned decimal             */
  printf("%o\n", u); /* unsigned octal               */
  printf("%x\n", u); /* unsigned hex, lowercase      */
  printf("%X\n", u); /* unsigned hex, uppercase      */

  /* ---------- floating-point specifiers ---------- */
  double d = 3.14159265358979;
  printf("%f\n", d); /* fixed decimal                */
  printf("%F\n", d); /* fixed decimal, uppercase     */
  printf("%e\n", d); /* scientific, lowercase        */
  printf("%E\n", d); /* scientific, uppercase        */
  printf("%g\n", d); /* shortest of %e / %f          */
  printf("%G\n", d); /* shortest, uppercase          */
  printf("%a\n", d); /* hex float, lowercase         */
  printf("%A\n", d); /* hex float, uppercase         */

  /* ---------- character / string specifiers ---------- */
  char c = 'A';
  char s[] = "hello";
  printf("%c\n", c); /* single character             */
  printf("%s\n", s); /* string                       */

  /* ---------- pointer specifier ---------- */
  int value = 0;
  printf("%p\n", (void *)&value); /* pointer address          */

  /* ---------- %n : stores chars written so far ---------- */
  int count = 0;
  printf("abc%n\n", &count); /* count == 3 after the call    */
  printf("count = %d\n", count);

  /* ---------- literal percent ---------- */
  printf("%%\n"); /* prints a single '%'          */

  /* ---------- length modifiers ---------- */
  printf("%hhd\n", (signed char)1);        /* char            */
  printf("%hhu\n", (unsigned char)1);      /* unsigned char   */
  printf("%hd\n", (short)1);               /* short           */
  printf("%hu\n", (unsigned short)1);      /* unsigned short  */
  printf("%ld\n", (long)1);                /* long            */
  printf("%lu\n", (unsigned long)1);       /* unsigned long   */
  printf("%lld\n", (long long)1);          /* long long       */
  printf("%llu\n", (unsigned long long)1); /* unsigned long long */
  printf("%jd\n", (intmax_t)1);            /* intmax_t        */
  printf("%ju\n", (uintmax_t)1);           /* uintmax_t       */
  printf("%zu\n", (size_t)1);              /* size_t          */
  printf("%td\n", (ptrdiff_t)1);           /* ptrdiff_t       */
  printf("%Lf\n", (long double)1.5L);      /* long double     */

  /* ---------- flags / width / precision ---------- */
  printf("%-10d|\n", i);  /* left-justify in width 10     */
  printf("%+d\n", i);     /* always show sign             */
  printf("% d\n", i);     /* space for positive sign      */
  printf("%010d\n", i);   /* zero-pad to width 10         */
  printf("%#o\n", u);     /* octal prefix 0               */
  printf("%#x\n", u);     /* hex prefix 0x                */
  printf("%8.3f\n", d);   /* width 8, 3 decimals          */
  printf("%.2s\n", s);    /* at most 2 chars              */
  printf("%*d\n", 5, i);  /* width from argument          */
  printf("%.*f\n", 2, d); /* precision from argument      */

  /* ---------- scanf specifiers (reference) ---------- */
  /*
   * %d  int              %i  int (auto base)
   * %u  unsigned int     %o  octal
   * %x  hex              %f / %e / %g / %a  float
   * %lf double           %Lf long double
   * %c  char             %s  string (whitespace-delimited)
   * %p  pointer          %n  chars consumed so far
   * %%  literal percent
   * %[...]  scanset      %*...  suppress assignment
   * length: hh h l ll j z t L
   */

  return 0;

  // 10 - 11
}
