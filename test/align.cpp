#include <iostream>
#include <vector>

using namespace std;

void Munge8( void *data, uint32_t size ) {
    uint8_t *data8 = (uint8_t*) data;
    uint8_t *data8End = data8 + size;
    
    while( data8 != data8End ) {
        *data8 = -*data8;
        // cout << uint32_t(*data8) << endl;
        data8++;
    }
}

void Munge16( void *data, uint32_t size ) {
    uint16_t *data16 = (uint16_t*) data;
    uint16_t *data16End = data16 + (size >> 1); /* Divide size by 2. */
    uint8_t *data8 = (uint8_t*) data16End;
    uint8_t *data8End = data8 + (size & 0x00000001); /* Strip upper 31 bits. */
    
    while( data16 != data16End ) {
        *data16 = -*data16;
        data16++;
    }
    while( data8 != data8End ) {
        *data8 = -*data8;
        data8++;
    }
}

void Munge32( void *data, uint32_t size ) {
    uint32_t *data32 = (uint32_t*) data;
    uint32_t *data32End = data32 + (size >> 2); /* Divide size by 4. */
    uint8_t *data8 = (uint8_t*) data32End;
    uint8_t *data8End = data8 + (size & 0x00000003); /* Strip upper 30 bits. */
    
    while( data32 != data32End ) {
        *data32 = -*data32;
        data32++;
    }
    while( data8 != data8End ) {
        *data8 = -*data8;
        data8++;
    }
}

#include <stdio.h>
 
// Alignment requirements
// (typical 32 bit machine)
 
// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes
 
// structure A
typedef struct structa_tag
{
    char        c;
    char        cc;
    short int   s;
    int         i;
} structa_t;
 
// structure B
typedef struct structb_tag
{
    short int   s;
    char        c;
    int         i;
} structb_t;
 
// structure C
typedef struct structc_tag
{
    char        c;
    double      d;
    int         s;
} structc_t;
 
// structure D
typedef struct structd_tag
{
    double      d;
    int         i;
    char        c;
} structd_t;
 
void alignment_check(void* p1, void* p2)
{
   // Considering downward stack
   // (on upward stack the output will be negative)
    printf("Displacement = %llu - %llu = %llu\n",
           (uint64_t)p2, (uint64_t)p1,
           (uint64_t)p2 - (uint64_t)p1);
}

int main(int argc, char ** argv)
{
    printf("sizeof(structa_t) = %lu\n", sizeof(structa_t));
    printf("sizeof(structb_t) = %lu\n", sizeof(structb_t));
    printf("sizeof(structc_t) = %lu\n", sizeof(structc_t));
    printf("sizeof(structd_t) = %lu\n", sizeof(structd_t));

    structa_t sa;
    structb_t sb;
    structc_t sc;
    structd_t sd;
    sd.d = 99.1234;
    sd.i = 1;
    sd.c = 'A';

    for (size_t p = 0; p < sizeof(int); ++p)
        printf( "p=%lu, v=%.2x\n", p,  *((char*)&sd.i + p));

    printf("sa (%p, %p, %p)\n", &sa.cc, &sa.s, &sa.i);
    printf("sb (%p, %p, %p)\n", &sb.s, &sb.c, &sb.i);
    printf("sc (%p, %p, %p)\n", &sc.c, &sc.d, &sc.s);
    printf("sd (%p, %p, %p)\n", &sd.d, &sd.i, &sd.c);

    cout << "sizeof(void*) = " << sizeof(void*) << endl;
    alignment_check(&sa.c, &sa.s);
    alignment_check(&sd.d, &sd.i);

    const char *ptr = "hello, world";
    printf("ptr = %p\n", ptr);
    
    const uint32_t L = 4000000;
    uint8_t x[L];
    // for (int i = 0; i < L; ++i) {
    //     cout << unsigned(x[i]) << endl;
    // }
    Munge8((void*)x, L);
    return 0;
}
