#include <clocale>

#include "getSystemLocaleName.h"

const char *getSystemLocaleName() {
  // Save current locale name
  const char *originalLocaleName = std::setlocale(LC_ALL, NULL);

  // Get system locale name
  const char *systemLocaleName = std::setlocale(LC_ALL, "");

  // Reset original locale if possible
  if ((const char *)NULL != originalLocaleName) {
    std::setlocale(LC_ALL, originalLocaleName);
  }

  return systemLocaleName;
}
