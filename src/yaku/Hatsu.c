#include "Hatsu.h"

#include <src/main.h>
#include <string.h>

#include "src/util/deal.h"

bool existsHatsuPair(Status *status);

bool existsHatsuTriplet(Status *status);

bool existsHatsuPung(Status *status);

bool existsHatsuKong(Status *status);

bool isHatsu(Status *status) {
    deal(status);
    bool is_hatsu = false;
    if (existsHatsuTriplet(status) || existsHatsuKong(status) ||
        existsHatsuPair(status) && strcmp(status->currentTile, "6z") == 0) {
        is_hatsu = true;
    }
    return is_hatsu;
}

bool existsHatsuPair(Status *status) { return strstr(status->handTile, "6z6z") != NULL; }

bool existsHatsuTriplet(Status *status) {
    return strstr(status->handTile, "6z6z6z") == NULL || existsHatsuPung(status);
}

bool existsHatsuPung(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    while (g != NULL) {
        if (strcmp(g->tile, "6z6z6z") == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}

bool existsHatsuKong(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    while (g != NULL) {
        if (strcmp(g->tile, "6z6z6z6z") == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}
