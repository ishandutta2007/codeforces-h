#include<iostream>
#include<cstdio>

using namespace std;
const int MAXN = 300;
int ans[MAXN]={1,2,3,4,5,6,7,8,9,10,12,14,16,18,21,24,27,28,32,36,40,45,48,54,56,63,64,72,81,90,96,108,112,126,128,144,162,168,189,192,216,243,252,256,288,324,360,405,432,486,504,567,576,648,729,810,864,972,1008,1134,1152,1296,1458,1512,1701,1728,1944,2187,2268,2304,2592,2916,3240,3645,3888,4374,4536,5103,5184,5832,6561,7290,7776,8748,9072,10206,10368,11664,13122,13608,15309,15552,17496,19683,20412,20736,23328,26244,29160,32805,34992,39366,40824,45927,46656,52488,59049,65610,69984,78732,81648,91854,93312,104976,118098,122472,137781
,139968,157464,177147,183708,186624,209952,236196,262440,295245,314928,354294,367416,413343,419904,472392,531441,590490,629856,708588,734832,826686,839808,944784,1062882,1102248,1240029,1259712,1417176,1594323,1653372,1679616,1889568,2125764,2361960,2657205,2834352,3188646,3306744,3720087,3779136,4251528,4782969,5314410,5668704,6377292,6613488,7440174,7558272,8503056,9565938,9920232,11160261,11337408,12754584,14348907,14880348,15116544,17006112,19131876,21257640,23914845,25509168,28697814,29760696,33480783,34012224,38263752,43046721,47829690,51018336,57395628,59521392,66961566,68024448,76527504,86093442,89282088,100442349,102036672,114791256,129140163,133923132,136048896,153055008,172186884,191318760,215233605,229582512,258280326,267846264,301327047,306110016,344373768,387420489};

int index[MAXN]={1,2,3,4,5,6,7,8,9,25,26,27,28,29,37,38,39,47,48,49,58,59,68,69,78,79,88,89,99,259,268,269,278,279,288,289,299,378,379,388,389,399,479,488,489,499,589,599,689,699,789,799,889,
899,999,2599,2689,2699,2789,2799,2889,2899,2999,3789,3799,3889,3899,3999,4799,4889,4899,4999,5899,5999,6899,6999,7899,7999,8899,8999,9999,25999,26899,26999,27899,27999,28899,
28999,29999,37899,37999,38899,38999,39999,47999,48899,48999,49999,58999,59999,68999,69999,78999,79999,88999,89999,99999,259999,268999,269999,278999,279999,288999,289999,299999,378999,379999,388999,389999,399999,479999,488999,489999,499999,589999,599999,689999,699999,789999,799999,889999,899999,999999,2599999,2689999,2699999,2789999,2799999,2889999,2899999,2999999,3789999,3799999,3889999,3899999,3999999,4799999,4889999,4899999,4999999,5899999,5999999,6899999,6999999,7899999,7999999,8899999,8999999,9999999,25999999,26899999,26999999,27899999,27999999,28899999,28999999,29999999,37899999,37999999,38899999,38999999,39999999,47999999,48899999,48999999,49999999,58999999,59999999,68999999,69999999,78999999,79999999,88999999,89999999,99999999,259999999,268999999,269999999,278999999,279999999,288999999,289999999,299999999,378999999,379999999,388999999,389999999,399999999,479999999,488999999,489999999,499999999,589999999,599999999,689999999,699999999,789999999,799999999,889999999,899999999,999999999};
int main()
{
    int n;
    scanf("%d",&n);
    int i = 0;
    while(i<210)
    {
        if(n<index[i])
        {
            i--;
            break;
        }
        if(n==index[i])
        {
            break;
        }
        i++;
    }
    if(index[i]>n)
    {
        i--;
    }
    //cout<<"i = "<<i<<"index[i] = "<<index[i]<<" ans[i] = "<<ans[i]<<endl;
    cout<<ans[i]<<endl;
    return 0;
}