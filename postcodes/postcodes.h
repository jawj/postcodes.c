//
//  postcodes.h
//  GridPoint GB
//
//  Created by George MacKerron on 2019/01/03.
//  Copyright © 2019 George MacKerron. All rights reserved.
//

#ifndef postcodes_h
#define postcodes_h

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
  PostcodeNotFound = 0,
  PostcodeSectorMeanOnly = 1,
  PostcodeOK = 2
} PostcodeStatus;

typedef struct {
  unsigned char area0;
  unsigned char area1;
  unsigned char district0;
  unsigned char district1;
  unsigned char sector;
  unsigned char unit0;
  unsigned char unit1;
  bool valid;
} PostcodeComponents;

typedef struct {
  unsigned int e;
  unsigned int n;
  PostcodeStatus status;
} PostcodeEastingNorthing;


PostcodeEastingNorthing eastingNorthingFromPostcodeComponents(const PostcodeComponents pcc);
PostcodeComponents postcodeComponentsFromString(const char s[]);
char* stringFromPostcodeComponents(const PostcodeComponents pcc);  // be sure to free(result) after use
bool postcodeTest(const bool noisily);

#endif /* postcodes_h */