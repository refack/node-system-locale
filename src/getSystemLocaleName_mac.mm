#include "getSystemLocaleName.h"

#import <Foundation/NSLocale.h>
#import <Foundation/NSString.h>

const char *getSystemLocaleName() {
  NSString *localeIdentifier = [[NSLocale currentLocale] localeIdentifier];

  const char *systemLocaleName = [localeIdentifier cStringUsingEncoding:NSUTF8StringEncoding];

  return systemLocaleName;
}
