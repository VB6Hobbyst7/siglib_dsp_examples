// Siglib Word Length Increase / Decrease Example

// Include files
#include <stdio.h>
#include <siglib.h>                                 // SigLib DSP library
#include "dpchar.h"

// Define constants
#define ENABLE_DEBUG_LOG        0       // Set to '1' to enable debug logging and '0' to disable

#define NUMBER_OF_SAMPLES       40
#define LONG_WORD_LENGTH        8
#define SHORT_WORD_LENGTH       3

// Declare global variables and arrays
// Test sequences - uncomment which ever one you would like to use

const unsigned char InputSequence[] = "Hello World - abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//static const unsigned char InputSequence[] = {
//  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
//  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
//  };
//static const unsigned char InputSequence[] = {
//  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//  };
//static const unsigned char InputSequence[] = {
//  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
//  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
//  0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
//  0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f
//  };
//static const unsigned char InputSequence[] = {             // Bit reversed
//  0x00, 0x80, 0x40, 0xc0, 0x20, 0xa0, 0x60, 0xe0, 0x10, 0x90, 0x50, 0xd0, 0x30, 0xb0, 0x70, 0xf0,
//  0x08, 0x88, 0x48, 0xc8, 0x28, 0xa8, 0x68, 0xe8, 0x18, 0x98, 0x58, 0xd8, 0x38, 0xb8, 0x78, 0xf8,
//  0x04, 0x84, 0x44, 0xc4, 0x24, 0xa4, 0x64, 0xe4, 0x14, 0x94, 0x54, 0xd4, 0x34, 0xb4, 0x74, 0xf4,
//  0x0c, 0x8c, 0x4c, 0xcc, 0x2c, 0xac, 0x6c, 0xec, 0x1c, 0x9c, 0x5c, 0xdc, 0x3c, 0xbc, 0x7c, 0xfc
//  };


static unsigned char    OutputSequence[160];
static unsigned char    RegeneratedSequence[80];

void main (void)
{
    SLArrayIndex_t  NumberOfBytesConverted;
    SLArrayIndex_t  i;
    SLFixData_t     ValidationCheckFlag = 0;

#if ENABLE_DEBUG_LOG
    SUF_ClearDebugfprintf();
#endif

    NumberOfBytesConverted =
        SDA_DecreaseWordLength (InputSequence,      // Pointer to source data
                                OutputSequence,     // Pointer to destination data
                                LONG_WORD_LENGTH,   // Input word length
                                SHORT_WORD_LENGTH,  // Output word length
                                NUMBER_OF_SAMPLES); // Source array length

    printf ("SDA_DecreaseWordLength - number of bytes converted = %d\n", NumberOfBytesConverted);

#if ENABLE_DEBUG_LOG
    for (i = 0; i < NumberOfBytesConverted; i++) {
        SUF_Debugfprintf ("OutputSequence[%d]", i);
        dpchar (OutputSequence[i]);
    }
#endif

    NumberOfBytesConverted =
        SDA_IncreaseWordLength (OutputSequence,             // Pointer to source data
                                RegeneratedSequence,        // Pointer to destination data
                                SHORT_WORD_LENGTH,          // Input word length
                                LONG_WORD_LENGTH,           // Output word length
                                NumberOfBytesConverted);    // Source array length

    printf ("SDA_IncreaseWordLength - number of bytes converted = %d\n", NumberOfBytesConverted);

#if ENABLE_DEBUG_LOG
    SUF_Debugfprintf ("\n", i);
    for (i = 0; i < NumberOfBytesConverted; i++) {
        SUF_Debugfprintf ("RegeneratedSequence[%d]", i);
        dpchar (RegeneratedSequence[i]);
    }
#endif

    RegeneratedSequence[NumberOfBytesConverted] = '\0';     // Add trailing NULL to end of string
    printf ("ReAsync string = %s\n", RegeneratedSequence);

    for (i = 0; i < NUMBER_OF_SAMPLES; i++) {
        if (RegeneratedSequence[i] != InputSequence[i]) {
            printf ("RegeneratedSequence[%d] (%x) != InputSequence[%d] (%x)\n", i, RegeneratedSequence[i], i, InputSequence[i]);
            ValidationCheckFlag = 1;
        }
    }

    if (ValidationCheckFlag == 0) {
        printf ("\n\nThe output sequence was correct\n\n");
    }
}


