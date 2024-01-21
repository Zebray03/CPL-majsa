#include "main.h"
#include "majsa.h"

int main() {
  Status status[] = {
      {
          .bakaze = TON,
          .jikaze = TON,
          .honbaCount = 0,
          .dora = "1m",
          .uradora = "3s",
          .handTile = "1m9m1p9p1s9s1z2z3z4z5z6z7z",
          .groupTile = {},
          .discardTile = "2m3m4m5m3p4p5p6p2s3s4s5s",
          .currentPlayer = JICHA,
          .currentTile = "1z",
          .remainTileCount = 18,
          .isRiichi = false,
          .isDoubleRiichi = false,
          .isIppatsu = false,
          .isRinshan = false,
      },
      {
          .bakaze = TON,
          .jikaze = NANN,
          .honbaCount = 1,
          .dora = "9p",
          .uradora = "5m",
          .handTile = "4m0m6m7m7m8m8m5s6s6s7s7s8s",
          .groupTile = {},
          .discardTile = "3z5z1z2m3p2m3s7s",
          .currentPlayer = KAMICHA,
          .currentTile = "8m",
          .remainTileCount = 37,
          .isRiichi = true,
          .isDoubleRiichi = false,
          .isIppatsu = true,
          .isRinshan = false,
      },
  };
  Result const *result = majsa(&status[0]); // 更改这里的参数来切换测试用例
  if (result != NULL)
    outputResultJson(*result);
  // OJ 会对比输出结果和标准结果，按照对比结果给出评分
  return 0;
}

void outputResultJson(Result result) {
  FILE *f = fopen("result.json", "w");
  fprintf(f, "{\"Type\":%d,\"Yaku\":[", result.type);
  for (int i = 0; i < 20; i++) {
    fprintf(f, "%d", result.yaku[i]);
    if (i < 19) {
      fprintf(f, ",");
    }
  }
  fprintf(f, "],\"Han\":%d,\"Fu\":%d,\"Point\":[%d,%d,%d],\"Machi\":%d,\"Shanten\":%d}", result.han, result.fu, result.point[0], result.point[1], result.point[2], result.machi, result.shanten);
  fclose(f);
}