#include "YakuChecker.h"

#include <stdbool.h>
#include <stdlib.h>

#include "lib/AgariTilesStructureBuilder.h"
#include "util/concealed.h"
#include "yaku/Bakaze.h"
#include "yaku/Chinitsu.h"
#include "yaku/Chun.h"
#include "yaku/Haku.h"
#include "yaku/Hatsu.h"
#include "yaku/Honitsu.h"
#include "yaku/Jikaze.h"


Yaku *checkYaku(Status *status) {
    AgariTilesStructure tilesStructure = resolve(status);
    Yaku *yaku = (Yaku *) malloc(sizeof(Yaku) * 100);
    Yaku *operand_ptr = yaku;
    for (int i = 0; i < 100; i++) {
        yaku[i] = Unknown;
    }
    bool isYakuman = false;

    // 役满
    // todo

    // 非役满
    if (!isYakuman) {


        // 立直-一发-海底-白发中-门风-场风-三杠子-对对和-三暗刻-小三元-混老头-混一色-清一色-宝牌-里宝牌
        // 立直
        if (status->isRiichi) {
            *operand_ptr = Riichi;
            operand_ptr++;
        }

        // 两立直
        if (status->isDoubleRiichi) {
            *operand_ptr = doubleRiichi;
            operand_ptr++;
        }

        // 一发
        if (status->isIppatsu) {
            *operand_ptr = Ippatsu;
            operand_ptr++;
        }

        // 海底摸月 河底捞鱼
        if (status->remainTileCount == 0) {
            if (status->currentPlayer == JICHA) {
                *operand_ptr = Haiteiraoyue;
            } else {
                *operand_ptr = Houteiraoyui;
            }
            operand_ptr++;
        }

        // 白
        if (isHaku(tilesStructure)) {
            *operand_ptr = YakuhaiHaku;
            operand_ptr++;
        }

        // 发
        if (isHatsu(status)) {
            *operand_ptr = YakuhaiHatsu;
            operand_ptr++;
        }

        // 中
        if (isChun(status)) {
            *operand_ptr = YakuhaiChun;
            operand_ptr++;
        }

        // 门风
        if (isJikaze(status)) {
            *operand_ptr = YakuhaiJikaze;
            operand_ptr++;
        }

        // 场风
        if (isBakaze(status)) {
            *operand_ptr = YakuhaiBakaze;
            operand_ptr++;
        }

        // todo

        // 混一色
        if (isHonitsu(status)) {
            if (isConcealed(status)) {
                *operand_ptr = Honitsu;
            } else {
                *operand_ptr = HonitsuF;
            }
            operand_ptr++;
        }

        // 清一色
        if (isChinitsu(status)) {
            if (isConcealed(status)) {
                *operand_ptr = Chinitsu;
            } else {
                *operand_ptr = ChinitsuF;
            }
            operand_ptr++;
        }

        // 宝牌

        // 里宝牌

    }

    return yaku;
}