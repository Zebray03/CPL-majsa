#include "AgariTilesStructureBuilder.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void deal(Status *status);

int maj_strcmp(char *maj1, char *maj2);

bool isChiitoitsu(Status *status);

AgariTilesStructure resolve(Status *status) {
    AgariTilesStructure result;
    char *tile_list[30]; // 手牌+当前控牌
    strcat(tile_list, status->handTile);
    strcat(tile_list, status->currentTile);
    deal(tile_list);
    result.is_chiitoitsu = isChiitoitsu(tile_list);
    if (result.is_chiitoitsu) {
        for (int i = 0; i < 7; i++) {
            strncpy(result.split.ChitoitsuStructure.pairs[i], status->handTile + (i << 1), 2);
        }
    } else {
        // 处理副露
        Group *opr_tri = result.split.GeneralStructure.triplets;
        Group *g = status->groupTile;
        while (g->tile[0] != '\0') {
            result.is_chiitoitsu = false;
            *opr_tri = *g;
            opr_tri++;
            g++;
        }

        if (strlen(status->handTile) >> 1 == 2) {
            strcpy(result.split.GeneralStructure.pair, status->handTile);
        }
        else {
            //todo
        }
    }
}

void deal(char *tiles) {
    int tiles_num = strlen(tiles) >> 1;
    char **tiles_list = malloc(sizeof(char *) * tiles_num);
    char *ptr = tiles;
    for (int i = 0; i < tiles_num; i++) {
        tiles_list[i] = malloc(sizeof(char) * 3);
        strcpy(tiles_list[i], ptr);
        ptr += 2;
    }
    qsort(tiles_list, tiles_num, sizeof(char *), maj_strcmp);
    tiles[0] = '\0';
    for (int i = 0; i < tiles_num; i++) {
        strcat(tiles, tiles_list[i]);
    }
}

int maj_strcmp(char *maj1, char *maj2) {
    int result = 0;
    if (maj1[1] > maj2[1]) {
        result = 1;
    } else if (maj1[1] < maj2[1]) {
        result = -1;
    } else {
        if (maj1[0] > maj2[0]) {
            result = 1;
        } else if (maj1[0] < maj2[0]) {
            result = -1;
        }
    }
    return result;
}

bool isChiitoitsu(Status *status) {
    return status->handTile[0] != status->handTile[2] &&
           status->handTile[strlen(status->handTile) - 3] == status->handTile[strlen(status->handTile) - 1];
}
