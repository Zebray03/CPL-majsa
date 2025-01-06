#include "concealed.h"

bool isConcealed(Status *status) {
    bool flag = true;
    Group *g = status->groupTile;
    while (g->tile[0] != '\0') {
        if (g->type != Ankan) {
            flag = false;
            break;
        }
        g++;
    }
    return flag;
}