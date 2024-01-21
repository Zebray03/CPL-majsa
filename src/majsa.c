#include "majsa.h"

Result *majsa(Status *status) {
  Result *result = (Result *)malloc(sizeof(Result));
  Result example0 = {
      .type = TSUMO,
      .yaku = {Kokushijuusanmenmachi},
      .han = -2,
      .fu = -1, // -1 代表 OJ 不会测评该条目
      .point = {32000, 32000, 32000},
      .machi = -1, // -1 代表 OJ 不会测评该条目
      .shanten = -1, // -1 代表 OJ 不会测评该条目
  };
  Result example1 = {
      .type = RON,
      .yaku = {Riichi, Ippatsu, Tanyao},
      .han = 5,
      .fu = 40,
      .point = {8300, 0, 0},
      .machi = -1, // -1 代表 OJ 不会测评该条目
      .shanten = -1, // -1 代表 OJ 不会测评该条目
  };
  if (status->currentPlayer == JICHA) {
    memcpy(result, &example0, sizeof(Result));
  }
  if (status->currentPlayer == KAMICHA) {
    memcpy(result, &example1, sizeof(Result));
  }
  return result;
}