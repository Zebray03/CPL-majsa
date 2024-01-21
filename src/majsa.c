#include "majsa.h"

Result *majsa(Status *status) {
  Result *result = (Result *)malloc(sizeof(Result));
  Result example = {
      .type = TSUMO,
      .yaku = {Kokushijuusanmenmachi},
      .han = 26,
      .fu = 30,
      .point = {32000, 32000, 32000},
      .machi = 13,
      .shanten = 0,
  };
  memcpy(result, &example, sizeof(Result));
  return result;
}