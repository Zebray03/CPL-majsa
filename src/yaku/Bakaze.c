#include "Bakaze.h"

#include <string.h>

bool existsBakazePair(Status *status);

bool existsBakazeTriplet(Status *status);

bool existsBakazePung(Status *status);

bool existsBakazeKong(Status *status);

char hash_map[4][2] = {"1z", "2z", "3z", "4z"};

char *getNKazehai(Status *status, int N);

bool isBakaze(Status *status) {
    bool is_bakaze = false;
    if (existsBakazeTriplet(status) || existsBakazeKong(status) ||
        existsBakazePair(status) && strcmp(status->currentTile, hash_map[status->bakaze - TON]) == 0) {
        is_bakaze = true;
        }
    return is_bakaze;
}

bool existsBakazePair(Status *status) { return strstr(status->handTile, getNKazehai(status, 2)) != NULL; }

bool existsBakazeTriplet(Status *status) {
    return strstr(status->handTile, getNKazehai(status, 3)) == NULL || existsBakazePung(status);
}

bool existsBakazePung(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    char *pung = getNKazehai(status, 3);
    while (g != NULL) {
        if (strcmp(g->tile, pung) == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}

bool existsBakazeKong(Status *status) {
    bool is_exist = false;
    Group *g = status->groupTile;
    char *quad = getNKazehai(status, 3);
    while (g != NULL) {
        if (strcmp(g->tile, quad) == 0) {
            is_exist = true;
            break;
        }
        g++;
    }
    return is_exist;
}

