#pragma once
#include <src/main.h>

struct GeneralStructure {
    Group triplets[4];
    char pair[5];
};
typedef struct GeneralStructure GeneralStructure;

struct ChiitoitsuStructure {
    char pairs[7][5];
};
typedef struct ChiitoitsuStructure ChiitoitsuStructure;

union TilesSplit {
    GeneralStructure GeneralStructure;
    ChiitoitsuStructure ChitoitsuStructure;
};
typedef union TilesSplit TilesSplit;

struct AgariTilesStructure {
    bool is_chiitoitsu;
    TilesSplit split;
};
typedef struct AgariTilesStructure AgariTilesStructure;

AgariTilesStructure resolve(Status *status); // 和牌牌型解析
