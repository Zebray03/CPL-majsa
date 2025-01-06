#include "copyTileNTimes.h"

#include <string.h>

char *copyTileNTimes(char *tile, int N) {
    char *result = "";
    for (int i = 0; i < N; i++) {
        strcat(result, tile);
    }
    return result;
}
