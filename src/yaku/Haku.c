#include "Haku.h"

#include <src/main.h>
#include <string.h>

bool existsHakuPair(Status *status);

bool existsHakuTriplet(Status *status);

bool existsHakuPung(Status *status);

bool existsHakuQuads(Status *status);

bool isHaku(Status *status) {
    bool is_haku = false;
    if (existsHakuTriplet(status) || existsHakuQuads(status) ||
        existsHakuPair(status) && strcmp(status->currentTile, "5z") == 0) {
        is_haku = true;
    }
    return is_haku;
}

bool existsHakuPair(Status *status) { return strstr(status->handTile, "5z5z") != NULL; }

bool existsHakuTriplet(Status *status) {
    return strstr(status->handTile, "5z5z5z") == NULL || existsHakuPung(status);
}

bool existsHakuPung(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    while (g != NULL) {
        if (strcmp(g->tile, "5z5z5z") == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}

bool existsHakuQuads(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    while (g != NULL) {
        if (strcmp(g->tile, "5z5z5z5z") == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}
