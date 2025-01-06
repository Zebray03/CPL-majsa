#include "Chun.h"

#include <src/main.h>
#include <string.h>

#include "src/util/deal.h"

bool existsChunPair(Status *status);

bool existsChunTriplet(Status *status);

bool existsChunPung(Status *status);

bool existsChunQuads(Status *status);

bool isChun(Status *status) {
    deal(status);
    bool is_chun = false;
    if (existsChunTriplet(status) || existsChunQuads(status) ||
        existsChunPair(status) && strcmp(status->currentTile, "7z") == 0) {
        is_chun = true;
        }
    return is_chun;
}

bool existsChunPair(Status *status) { return strstr(status->handTile, "7z7z") != NULL; }

bool existsChunTriplet(Status *status) {
    return strstr(status->handTile, "7z7z7z") == NULL || existsChunPung(status);
}

bool existsChunPung(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    while (g != NULL) {
        if (strcmp(g->tile, "7z7z7z") == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}

bool existsChunQuads(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    while (g != NULL) {
        if (strcmp(g->tile, "7z7z7z7z") == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}
