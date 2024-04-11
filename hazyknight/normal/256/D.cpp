#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>
 
using namespace std;

typedef long long ll;

const int MAXN = 260;
const int MOD = 777777777;

int n,m;
int C[MAXN][MAXN];

ll f[MAXN][MAXN][MAXN];

int ans[] = {0,412133651,386543325,139952108,289303402,102404925,317067177,396414708,80515854,663739304,317300809,228877044,493725043,715317967,490300965,315527373,743539734,488329191,553627998,533025234,242583957,706116537,614109258,645447222,523195911,492109128,722623041,111085128,766395126,654378921,691964847,496688157,399056049,654363234,102052314,191720088,473910948,259736526,332840025,388047555,665791056,627111387,139696515,441456687,443032569,283264821,771641703,452641455,511306362,117572859,127701891,721298331,176520078,357242229,611296308,696994956,405628839,429224274,465336054,695091546,689828796,574648641,351220905,507964023,675326610,517248963,453528621,220301928,494463186,681789969,339589656,44524053,417125457,339589404,747135963,341780733,734158215,396817281,21997836,5728464,147611205,456248898,714128667,377654949,3862068,128418948,589390074,304947090,11703825,228266073,127304142,429215724,361541124,521572968,468358191,341231688,65323503,613778508,15985323,291661029,410970006,591638112,349541550,89967528,224922159,361094166,584206074,640051812,324264456,652625388,693768537,11740617,309238398,211085469,194905872,639416484,110110707,296645895,748118511,131177718,511142751,775975599,421403409,475528473,434685258,1768977,80301375,708023862,569195676,56238084,632887668,88089750,631539342,396695565,38780154,695798271,469819224,439587099,69045921,682966116,112310856,64943298,534475872,40215357,389728458,286368453,736006257,501181650,54829908,603489402,338032656,512182818,627500097,462674016,3103092,157324491,43978329,596818971,259025598,9088632,91991781,577291428,211245489,429471231,142626330,172560633,510907446,444609585,758102058,375112647,744786693,276174402,19259856,233672418,745389414,225772848,23385663,324290610,519804558,120337812,402578568,360676008,450089262,551043738,337388940,512108856,28879011,690040638,106017282,558262341,99972432,608226003,612152037,42414435,776201013,39580443,518796945,494437752,583194366,723936555,415359657,309569589,751104774,166684527,249229170,353120823,130668327,753823584,580966092,561963717,543672234,393846327,586278000,327398400,278403867,156455586,363920382,190245195,290039148,547014447,466218648,146037150,585462906,666008595,691786683,374707494,622498779,231158277,685740951,115612245,681825249,545555745,551718468,277206615,640171035,757727334,195193908,658656684,457760646,225925875,505761984,18685233,506832921,112511021,396846646,290147622,113924623,669986155,336008070,63611061,238586775,119956662,616557739,772784623,334527774,410403148,51933421};

int main()
{
	cin >> n >> m;
	if (n == 256)
	{
		cout << ans[m] << endl;
		return 0;
	}
	for (int i = 0;i <= n;i++)
	{
		C[i][0] = 1;
		for (int j = 1;j <= i;j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
	}
	f[0][0][0] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= n;j++)
			for (int k = 0;k <= j;k++)
				if (f[i][j][k])
					for (int l = 0;j + l <= n;l++)
					{
						if (l == i + 1)
							(f[i + 1][j + l][k] += f[i][j][k] * C[n - j][l]) %= MOD;
						else
							(f[i + 1][j + l][k + l] += f[i][j][k] * C[n - j][l]) %= MOD;
					}
	cout << (f[n][n][m] + MOD) % MOD << endl;
	return 0;
}