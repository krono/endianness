/*
  endianness.c
  because I always mix up how that works.

 */
#include <stdio.h>
#include <inttypes.h>

int main(int argc,char** argv)
{
  uint8_t real_8 = UINT8_C(0xAB);
  printf(" 8: %#0.2" PRIx8 "\n", real_8);

  uint16_t real_16 = UINT16_C(0xABCD);
  printf("16: %#0.2" PRIx16 "\n", real_16);
  uint8_t* bytes_16 = (uint8_t*)&real_16;
  printf("    %#0.2" PRIx8 " %#0.2" PRIx8 "\n", bytes_16[0], bytes_16[1]);

  uint32_t real_32 = UINT32_C(0xABCD0123);
  printf("32: %#0.2" PRIx32 "\n", real_32);
  uint8_t* bytes_32 = (uint8_t*)&real_32;
  printf("    %#0.2" PRIx8 " %#0.2" PRIx8 " %#0.2" PRIx8" %#0.2" PRIx8 "\n",
         bytes_32[0], bytes_32[1], bytes_32[3], bytes_32[3]);

  uint64_t real_64 = UINT64_C(0xABCDEF0123456789);
  printf("64: %#0.2" PRIx64 "\n", real_64);
  uint8_t* bytes_64 = (uint8_t*)&real_64;
  printf("   "
         " %#0.2" PRIx8 " %#0.2" PRIx8 " %#0.2" PRIx8" %#0.2" PRIx8
         " %#0.2" PRIx8 " %#0.2" PRIx8 " %#0.2" PRIx8" %#0.2" PRIx8 "\n",
         bytes_64[0], bytes_64[1], bytes_64[3], bytes_64[3],
         bytes_64[4], bytes_64[5], bytes_64[6], bytes_64[7]);

  if (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
    printf("Little ");
  } else if (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) {
    printf("Big ");
  } else {
    printf("Other ");
  }
  printf("endian (%d)\n", __BYTE_ORDER__);
  return 0;
}
