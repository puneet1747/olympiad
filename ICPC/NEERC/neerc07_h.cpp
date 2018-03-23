#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<lint, lint> pi;

string l[6] = {"AB", "AC", "BA", "BC", "CA", "CB"};
int G1[180] = {181448,174280,88264,173832,87816,80648,181336,174168,88152,180888,170136,55448,172824,86808,169240,54552,72472,43800,173664,87648,80480,172768,86752,169184,54496,72416,43744,78688,71520,42848,153217,146049,117377,144705,116033,108865,153105,145937,117265,151761,133841,19153,143697,115025,132945,18257,100689,14673,144425,115753,108585,143529,114857,132777,18089,100521,14505,106793,99625,13609,153098,145930,117258,151754,133834,19146,143690,115018,132938,18250,100682,14666,151642,133722,19034,131930,17242,6490,143466,114794,132714,18026,100458,14442,131818,17130,6378,99114,13098,5930,181315,174147,88131,180867,170115,55427,172803,86787,169219,54531,72451,43779,180755,170003,55315,168211,53523,35603,172579,86563,168995,54307,72227,43555,168099,53411,35491,69987,41315,34147,173636,87620,80452,172740,86724,169156,54468,72388,43716,78660,71492,42820,172572,86556,168988,54300,72220,43548,168092,53404,35484,69980,41308,34140,78380,71212,42540,69868,41196,34028,144397,115725,108557,143501,114829,132749,18061,100493,14477,106765,99597,13581,143445,114773,132693,18005,100437,14421,131797,17109,6357,99093,13077,5909,106597,99429,13413,98981,12965,5797};
int G2[360] = {181896,153224,178312,120968,146056,117384,177416,120072,109320,144712,116040,108872,181840,153168,178256,120912,146000,117328,180944,152272,170192,55504,137936,51920,176912,119568,169744,55056,105232,47888,144208,115536,137040,51024,104784,47440,177248,119904,109152,176800,119456,169632,54944,105120,47776,107360,103776,46432,144488,115816,108648,144040,115368,136872,50856,104616,47272,107304,103720,46376,181889,178305,120961,181441,174273,88257,177409,120065,173825,87809,109313,80641,181777,178193,120849,180433,166097,22737,176401,119057,165649,22289,101137,15121,181273,174105,88089,180377,166041,22681,172313,86297,165145,21785,68377,11033,177185,119841,173601,87585,109089,80417,176289,118945,165537,22177,101025,15009,172257,86241,165089,21729,68321,10977,106849,78177,99681,13665,67425,10081,181826,153154,178242,120898,145986,117314,180930,152258,170178,55490,137922,51906,176898,119554,169730,55042,105218,47874,144194,115522,137026,51010,104770,47426,181770,178186,120842,180426,166090,22730,176394,119050,165642,22282,101130,15114,180762,152090,170010,55322,137754,51738,180314,165978,22618,168218,53530,164634,21274,35610,6938,135514,49498,35162,176674,119330,169506,54818,104994,47650,176226,118882,165474,22114,100962,14946,168162,53474,164578,21218,35554,6882,102754,45410,99170,13154,34658,5986,143914,115242,136746,50730,104490,47146,135402,49386,35050,102698,45354,34602,181259,174091,88075,180363,166027,22667,172299,86283,165131,21771,68363,11019,180307,165971,22611,164627,21267,6931,172131,86115,164963,21603,68195,10851,164515,21155,6819,66403,9059,5475,177220,119876,109124,176772,119428,169604,54916,105092,47748,107332,103748,46404,177164,119820,173580,87564,109068,80396,176268,118924,165516,22156,101004,14988,172236,86220,165068,21708,68300,10956,106828,78156,99660,13644,67404,10060,176660,119316,169492,54804,104980,47636,176212,118868,165460,22100,100948,14932,168148,53460,164564,21204,35540,6868,102740,45396,99156,13140,34644,5972,172124,86108,164956,21596,68188,10844,164508,21148,6812,66396,9052,5468,107052,103468,46124,106604,77932,99436,13420,67180,9836,102572,45228,98988,12972,34476,5804,66284,8940,5356,144453,115781,108613,144005,115333,136837,50821,104581,47237,107269,103685,46341,143893,115221,136725,50709,104469,47125,135381,49365,35029,102677,45333,34581,107045,103461,46117,102565,45221,34469};

int hsh(){
    int ret = 0;
    for(int i=0; i<6; i++){
        int p = 0;
        if(l[i] == "AB") p = 0;
        if(l[i] == "AC") p = 1;
        if(l[i] == "BA") p = 2;
        if(l[i] == "BC") p = 3;
        if(l[i] == "CA") p = 4;
        if(l[i] == "CB") p = 5;
        ret += (p << (3*i));
    }
    return ret;
}

lint ipow(int x, int p){
    if(p == 0) return 1;
    return ipow(x, p-1) * x;
}

// G1 = 2 ^ n - 1
// G2 = 2 * (3 ^ (n - 1)) - 1;
// G3 = 3 ^ (n-1)

int main(){
    int n;
    cin >> n;
    for(int i=0; i<6; i++) cin >> l[i];
    if(n == 1){
        cout << 1;
    }
    if(n == 2){
        if(find(G2, G2 + 360, hsh()) != G2 + 360){
            cout << 2 * ipow(3, n-1) - 1;
        }
        else{
            cout << ipow(2, n) - 1;
        }
    }
    if(n > 2){
        if(find(G1, G1 + 180, hsh()) != G1 + 180){
            cout << ipow(2, n) - 1;
        }
        else if(find(G2, G2 + 360, hsh()) != G2 + 360){
            cout << 2 * ipow(3, n-1) - 1;
        }
        else{
            cout << ipow(3, n-1);
        }
    }
    cout << endl;
}