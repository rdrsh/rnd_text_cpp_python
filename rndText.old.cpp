#include "Python.h"
#include <algorithm>
using namespace std;

//-------------
struct WordInfo {
    char* word;
    int nextIdsLen;
    int* nextIds;
};

struct TextInfo {
    WordInfo* wordInfo;
    char* punctuation;
    int endFlag;
};

int nextIds0[] = {1};
int nextIds1[] = {2, 17, 49, 70, 99, 110, 123, 143, 194, 216, 243, 274, 276, 282, 305, 323, 341, 344};
int nextIds2[] = {3};
int nextIds3[] = {4, 52, 183, 196, 260};
int nextIds4[] = {5};
int nextIds5[] = {6};
int nextIds6[] = {7};
int nextIds7[] = {8};
int nextIds8[] = {9};
int nextIds9[] = {10, 109};
int nextIds10[] = {11};
int nextIds11[] = {12, 28, 55, 61, 91, 93, 232};
int nextIds12[] = {13};
int nextIds13[] = {14, 135, 215};
int nextIds14[] = {15};
int nextIds15[] = {16};
int nextIds16[] = {18};
int nextIds17[] = {19, 72};
int nextIds18[] = {20};
int nextIds19[] = {21, 265};
int nextIds20[] = {22};
int nextIds21[] = {23};
int nextIds22[] = {24, 121, 125, 140, 220, 315};
int nextIds23[] = {25, 47, 103, 111, 114, 126, 147, 184, 218, 253, 257, 307, 349};
int nextIds24[] = {26};
int nextIds25[] = {27, 86};
int nextIds26[] = {29};
int nextIds27[] = {30, 32, 42, 69, 71, 83, 89, 96, 207, 239};
int nextIds28[] = {31, 41, 217};
int nextIds29[] = {33};
int nextIds30[] = {34};
int nextIds31[] = {35, 100};
int nextIds32[] = {36, 101};
int nextIds33[] = {37, 53, 201, 293};
int nextIds34[] = {38, 261};
int nextIds35[] = {39};
int nextIds36[] = {40};
int nextIds37[] = {43};
int nextIds38[] = {44};
int nextIds39[] = {45, 66, 149, 211, 237, 312, 329, 336};
int nextIds40[] = {46};
int nextIds41[] = {48};
int nextIds42[] = {50};
int nextIds43[] = {51};
int nextIds44[] = {54, 60};
int nextIds45[] = {56};
int nextIds46[] = {57};
int nextIds47[] = {58};
int nextIds48[] = {59, 228};
int nextIds49[] = {62};
int nextIds50[] = {63, 94, 208};
int nextIds51[] = {64, 209};
int nextIds52[] = {65};
int nextIds53[] = {67, 88, 90, 212};
int nextIds54[] = {68, 224, 306};
int nextIds55[] = {73, 77};
int nextIds56[] = {74, 78};
int nextIds57[] = {75, 79};
int nextIds58[] = {76};
int nextIds59[] = {80};
int nextIds60[] = {81};
int nextIds61[] = {82, 165, 204};
int nextIds62[] = {84};
int nextIds63[] = {85};
int nextIds64[] = {87};
int nextIds65[] = {92, 238};
int nextIds66[] = {95};
int nextIds67[] = {97};
int nextIds68[] = {98};
int nextIds69[] = {102};
int nextIds70[] = {104};
int nextIds71[] = {105};
int nextIds72[] = {106, 113, 146, 164};
int nextIds73[] = {107, 178, 192, 256, 292, 296, 321};
int nextIds74[] = {108};
int nextIds75[] = {112};
int nextIds76[] = {115};
int nextIds77[] = {116};
int nextIds78[] = {117, 154, 330};
int nextIds79[] = {118, 155, 331};
int nextIds80[] = {119, 246};
int nextIds81[] = {120};
int nextIds82[] = {122};
int nextIds83[] = {124};
int nextIds84[] = {127};
int nextIds85[] = {128};
int nextIds86[] = {129};
int nextIds87[] = {130};
int nextIds88[] = {131};
int nextIds89[] = {132};
int nextIds90[] = {133, 166};
int nextIds91[] = {134};
int nextIds92[] = {136};
int nextIds93[] = {137};
int nextIds94[] = {138, 158, 175, 197, 225, 249, 283, 313};
int nextIds95[] = {139, 314};
int nextIds96[] = {141};
int nextIds97[] = {142};
int nextIds98[] = {144, 316};
int nextIds99[] = {145, 317};
int nextIds100[] = {148};
int nextIds101[] = {150};
int nextIds102[] = {151, 324};
int nextIds103[] = {152, 187, 333, 337};
int nextIds104[] = {153, 262};
int nextIds105[] = {156, 157, 264, 277, 318};
int nextIds106[] = {159};
int nextIds107[] = {160};
int nextIds108[] = {161};
int nextIds109[] = {162};
int nextIds110[] = {163};
int nextIds111[] = {167};
int nextIds112[] = {168};
int nextIds113[] = {169};
int nextIds114[] = {170};
int nextIds115[] = {171, 172};
int nextIds116[] = {173};
int nextIds117[] = {174};
int nextIds118[] = {176};
int nextIds119[] = {177};
int nextIds120[] = {179};
int nextIds121[] = {180};
int nextIds122[] = {181};
int nextIds123[] = {182, 301};
int nextIds124[] = {185};
int nextIds125[] = {186};
int nextIds126[] = {188};
int nextIds127[] = {189};
int nextIds128[] = {190};
int nextIds129[] = {191};
int nextIds130[] = {193, 295};
int nextIds131[] = {195};
int nextIds132[] = {198};
int nextIds133[] = {199};
int nextIds134[] = {200};
int nextIds135[] = {202};
int nextIds136[] = {203};
int nextIds137[] = {205};
int nextIds138[] = {206};
int nextIds139[] = {210};
int nextIds140[] = {213};
int nextIds141[] = {214};
int nextIds142[] = {219};
int nextIds143[] = {221};
int nextIds144[] = {222, 268};
int nextIds145[] = {223};
int nextIds146[] = {226};
int nextIds147[] = {227};
int nextIds148[] = {229, 255, 300};
int nextIds149[] = {230};
int nextIds150[] = {231};
int nextIds151[] = {233};
int nextIds152[] = {234};
int nextIds153[] = {235};
int nextIds154[] = {236};
int nextIds155[] = {240};
int nextIds156[] = {241};
int nextIds157[] = {242};
int nextIds158[] = {244};
int nextIds159[] = {245};
int nextIds160[] = {247};
int nextIds161[] = {248};
int nextIds162[] = {250};
int nextIds163[] = {251};
int nextIds164[] = {252};
int nextIds165[] = {254};
int nextIds166[] = {258};
int nextIds167[] = {259};
int nextIds168[] = {263, 290, 326};
int nextIds169[] = {266};
int nextIds170[] = {267};
int nextIds171[] = {269};
int nextIds172[] = {270, 325};
int nextIds173[] = {271};
int nextIds174[] = {272};
int nextIds175[] = {273};
int nextIds176[] = {275};
int nextIds177[] = {278};
int nextIds178[] = {279, 286, 348};
int nextIds179[] = {280, 287, 338};
int nextIds180[] = {281};
int nextIds181[] = {284};
int nextIds182[] = {285};
int nextIds183[] = {288};
int nextIds184[] = {289};
int nextIds185[] = {291, 302};
int nextIds186[] = {294};
int nextIds187[] = {297};
int nextIds188[] = {298};
int nextIds189[] = {299};
int nextIds190[] = {303};
int nextIds191[] = {304};
int nextIds192[] = {308};
int nextIds193[] = {309};
int nextIds194[] = {310};
int nextIds195[] = {311};
int nextIds196[] = {319};
int nextIds197[] = {320};
int nextIds198[] = {322};
int nextIds199[] = {327};
int nextIds200[] = {328};
int nextIds201[] = {332};
int nextIds202[] = {334};
int nextIds203[] = {335};
int nextIds204[] = {339};
int nextIds205[] = {340};
int nextIds206[] = {342};
int nextIds207[] = {343};
int nextIds208[] = {345};
int nextIds209[] = {346};
int nextIds210[] = {347};

WordInfo wordInfo[] = {
    {"War", 1, nextIds0},
    {"and", 18, nextIds1},
    {"Peace", 1, nextIds2},
    {"by", 5, nextIds3},
    {"Leo", 1, nextIds4},
    {"Tolstoy", 1, nextIds5},
    {"Tolstoi", 1, nextIds6},
    {"BOOK", 1, nextIds7},
    {"ONE", 1, nextIds8},
    {"1805", 2, nextIds9},
    {"CHAPTER", 1, nextIds10},
    {"I", 7, nextIds11},
    {"Well", 1, nextIds12},
    {"Prince", 3, nextIds13},
    {"so", 1, nextIds14},
    {"Genoa", 1, nextIds15},
    {"Lucca", 1, nextIds16},
    {"are", 2, nextIds17},
    {"now", 1, nextIds18},
    {"just", 2, nextIds19},
    {"family", 1, nextIds20},
    {"estates", 1, nextIds21},
    {"of", 6, nextIds22},
    {"the", 13, nextIds23},
    {"Buonapartes", 1, nextIds24},
    {"But", 2, nextIds25},
    {"warn", 1, nextIds26},
    {"you", 10, nextIds27},
    {"if", 3, nextIds28},
    {"don", 1, nextIds29},
    {"t", 1, nextIds30},
    {"tell", 2, nextIds31},
    {"me", 2, nextIds32},
    {"that", 4, nextIds33},
    {"this", 2, nextIds34},
    {"means", 1, nextIds35},
    {"war", 1, nextIds36},
    {"still", 1, nextIds37},
    {"try", 1, nextIds38},
    {"to", 8, nextIds39},
    {"defend", 1, nextIds40},
    {"infamies", 1, nextIds41},
    {"horrors", 1, nextIds42},
    {"perpetrated", 1, nextIds43},
    {"Antichrist", 2, nextIds44},
    {"really", 1, nextIds45},
    {"believe", 1, nextIds46},
    {"he", 1, nextIds47},
    {"is", 2, nextIds48},
    {"will", 1, nextIds49},
    {"have", 3, nextIds50},
    {"nothing", 2, nextIds51},
    {"more", 1, nextIds52},
    {"do", 4, nextIds53},
    {"with", 3, nextIds54},
    {"no", 2, nextIds55},
    {"longer", 2, nextIds56},
    {"my", 2, nextIds57},
    {"friend", 1, nextIds58},
    {"faithful", 1, nextIds59},
    {"slave", 1, nextIds60},
    {"as", 3, nextIds61},
    {"call", 1, nextIds62},
    {"yourself", 1, nextIds63},
    {"how", 1, nextIds64},
    {"see", 2, nextIds65},
    {"frightened", 1, nextIds66},
    {"sit", 1, nextIds67},
    {"down", 1, nextIds68},
    {"all", 1, nextIds69},
    {"news", 1, nextIds70},
    {"It", 1, nextIds71},
    {"was", 4, nextIds72},
    {"in", 7, nextIds73},
    {"July", 1, nextIds74},
    {"speaker", 1, nextIds75},
    {"well", 1, nextIds76},
    {"known", 1, nextIds77},
    {"Anna", 3, nextIds78},
    {"Pavlovna", 3, nextIds79},
    {"Scherer", 2, nextIds80},
    {"maid", 1, nextIds81},
    {"honor", 1, nextIds82},
    {"favorite", 1, nextIds83},
    {"Empress", 1, nextIds84},
    {"Marya", 1, nextIds85},
    {"Fedorovna", 1, nextIds86},
    {"With", 1, nextIds87},
    {"these", 1, nextIds88},
    {"words", 1, nextIds89},
    {"she", 2, nextIds90},
    {"greeted", 1, nextIds91},
    {"Vasili", 1, nextIds92},
    {"Kuragin", 1, nextIds93},
    {"a", 8, nextIds94},
    {"man", 2, nextIds95},
    {"high", 1, nextIds96},
    {"rank", 1, nextIds97},
    {"importance", 2, nextIds98},
    {"who", 2, nextIds99},
    {"first", 1, nextIds100},
    {"arrive", 1, nextIds101},
    {"at", 2, nextIds102},
    {"her", 4, nextIds103},
    {"reception", 2, nextIds104},
    {"had", 5, nextIds105},
    {"cough", 1, nextIds106},
    {"for", 1, nextIds107},
    {"some", 1, nextIds108},
    {"days", 1, nextIds109},
    {"She", 1, nextIds110},
    {"said", 1, nextIds111},
    {"suffering", 1, nextIds112},
    {"from", 1, nextIds113},
    {"la", 1, nextIds114},
    {"grippe", 2, nextIds115},
    {"being", 1, nextIds116},
    {"then", 1, nextIds117},
    {"new", 1, nextIds118},
    {"word", 1, nextIds119},
    {"St", 1, nextIds120},
    {"Petersburg", 1, nextIds121},
    {"used", 1, nextIds122},
    {"only", 2, nextIds123},
    {"elite", 1, nextIds124},
    {"All", 1, nextIds125},
    {"invitations", 1, nextIds126},
    {"without", 1, nextIds127},
    {"exception", 1, nextIds128},
    {"written", 1, nextIds129},
    {"French", 2, nextIds130},
    {"delivered", 1, nextIds131},
    {"scarlet", 1, nextIds132},
    {"liveried", 1, nextIds133},
    {"footman", 1, nextIds134},
    {"morning", 1, nextIds135},
    {"ran", 1, nextIds136},
    {"follows", 1, nextIds137},
    {"If", 1, nextIds138},
    {"better", 1, nextIds139},
    {"Count", 1, nextIds140},
    {"or", 1, nextIds141},
    {"prospect", 1, nextIds142},
    {"spending", 1, nextIds143},
    {"an", 2, nextIds144},
    {"evening", 1, nextIds145},
    {"poor", 1, nextIds146},
    {"invalid", 1, nextIds147},
    {"not", 3, nextIds148},
    {"too", 1, nextIds149},
    {"terrible", 1, nextIds150},
    {"shall", 1, nextIds151},
    {"be", 1, nextIds152},
    {"very", 1, nextIds153},
    {"charmed", 1, nextIds154},
    {"tonight", 1, nextIds155},
    {"between", 1, nextIds156},
    {"7", 1, nextIds157},
    {"10", 1, nextIds158},
    {"Annette", 1, nextIds159},
    {"Heavens", 1, nextIds160},
    {"what", 1, nextIds161},
    {"virulent", 1, nextIds162},
    {"attack", 1, nextIds163},
    {"replied", 1, nextIds164},
    {"prince", 1, nextIds165},
    {"least", 1, nextIds166},
    {"disconcerted", 1, nextIds167},
    {"He", 3, nextIds168},
    {"entered", 1, nextIds169},
    {"wearing", 1, nextIds170},
    {"embroidered", 1, nextIds171},
    {"court", 2, nextIds172},
    {"uniform", 1, nextIds173},
    {"knee", 1, nextIds174},
    {"breeches", 1, nextIds175},
    {"shoes", 1, nextIds176},
    {"stars", 1, nextIds177},
    {"on", 3, nextIds178},
    {"his", 3, nextIds179},
    {"breast", 1, nextIds180},
    {"serene", 1, nextIds181},
    {"expression", 1, nextIds182},
    {"flat", 1, nextIds183},
    {"face", 1, nextIds184},
    {"spoke", 2, nextIds185},
    {"refined", 1, nextIds186},
    {"which", 1, nextIds187},
    {"our", 1, nextIds188},
    {"grandfathers", 1, nextIds189},
    {"but", 1, nextIds190},
    {"thought", 1, nextIds191},
    {"gentle", 1, nextIds192},
    {"patronizing", 1, nextIds193},
    {"intonation", 1, nextIds194},
    {"natural", 1, nextIds195},
    {"grown", 1, nextIds196},
    {"old", 1, nextIds197},
    {"society", 1, nextIds198},
    {"went", 1, nextIds199},
    {"up", 1, nextIds200},
    {"kissed", 1, nextIds201},
    {"hand", 1, nextIds202},
    {"presenting", 1, nextIds203},
    {"bald", 1, nextIds204},
    {"scented", 1, nextIds205},
    {"shining", 1, nextIds206},
    {"head", 1, nextIds207},
    {"complacently", 1, nextIds208},
    {"seated", 1, nextIds209},
    {"himself", 1, nextIds210},
    {"sofa", 0, 0}
};

TextInfo textInfo[] = {
    {wordInfo+0, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+2, ".", 1},
    {wordInfo+3, "", 0},
    {wordInfo+4, "", 0},
    {wordInfo+5, "/", 0},
    {wordInfo+6, ".", 1},
    {wordInfo+7, "", 0},
    {wordInfo+8, ":", 0},
    {wordInfo+9, ".", 1},
    {wordInfo+10, "", 0},
    {wordInfo+11, ". \"", 1},
    {wordInfo+12, ",", 0},
    {wordInfo+13, ",", 0},
    {wordInfo+14, "", 0},
    {wordInfo+15, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+16, "", 0},
    {wordInfo+17, "", 0},
    {wordInfo+18, "", 0},
    {wordInfo+19, "", 0},
    {wordInfo+20, "", 0},
    {wordInfo+21, "", 0},
    {wordInfo+22, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+24, ".", 1},
    {wordInfo+25, "", 0},
    {wordInfo+11, "", 0},
    {wordInfo+26, "", 0},
    {wordInfo+27, ",", 0},
    {wordInfo+28, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+29, "'", 0},
    {wordInfo+30, "", 0},
    {wordInfo+31, "", 0},
    {wordInfo+32, "", 0},
    {wordInfo+33, "", 0},
    {wordInfo+34, "", 0},
    {wordInfo+35, "", 0},
    {wordInfo+36, ",", 0},
    {wordInfo+28, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+37, "", 0},
    {wordInfo+38, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+40, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+41, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+42, "", 0},
    {wordInfo+43, "", 0},
    {wordInfo+3, "", 0},
    {wordInfo+33, "", 0},
    {wordInfo+44, "-", 0},
    {wordInfo+11, "", 0},
    {wordInfo+45, "", 0},
    {wordInfo+46, "", 0},
    {wordInfo+47, "", 0},
    {wordInfo+48, "", 0},
    {wordInfo+44, "-", 0},
    {wordInfo+11, "", 0},
    {wordInfo+49, "", 0},
    {wordInfo+50, "", 0},
    {wordInfo+51, "", 0},
    {wordInfo+52, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+53, "", 0},
    {wordInfo+54, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+17, "", 0},
    {wordInfo+55, "", 0},
    {wordInfo+56, "", 0},
    {wordInfo+57, "", 0},
    {wordInfo+58, ",", 0},
    {wordInfo+55, "", 0},
    {wordInfo+56, "", 0},
    {wordInfo+57, "'", 0},
    {wordInfo+59, "", 0},
    {wordInfo+60, ",'", 0},
    {wordInfo+61, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+62, "", 0},
    {wordInfo+63, "!", 1},
    {wordInfo+25, "", 0},
    {wordInfo+64, "", 0},
    {wordInfo+53, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+53, "?", 1},
    {wordInfo+11, "", 0},
    {wordInfo+65, "", 0},
    {wordInfo+11, "", 0},
    {wordInfo+50, "", 0},
    {wordInfo+66, "", 0},
    {wordInfo+27, "-", 0},
    {wordInfo+67, "", 0},
    {wordInfo+68, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+31, "", 0},
    {wordInfo+32, "", 0},
    {wordInfo+69, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+70, ".\"", 1},
    {wordInfo+71, "", 0},
    {wordInfo+72, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+74, ",", 0},
    {wordInfo+9, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+75, "", 0},
    {wordInfo+72, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+76, "-", 0},
    {wordInfo+77, "", 0},
    {wordInfo+78, "", 0},
    {wordInfo+79, "", 0},
    {wordInfo+80, ",", 0},
    {wordInfo+81, "", 0},
    {wordInfo+22, "", 0},
    {wordInfo+82, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+83, "", 0},
    {wordInfo+22, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+84, "", 0},
    {wordInfo+85, "", 0},
    {wordInfo+86, ".", 1},
    {wordInfo+87, "", 0},
    {wordInfo+88, "", 0},
    {wordInfo+89, "", 0},
    {wordInfo+90, "", 0},
    {wordInfo+91, "", 0},
    {wordInfo+13, "", 0},
    {wordInfo+92, "", 0},
    {wordInfo+93, ",", 0},
    {wordInfo+94, "", 0},
    {wordInfo+95, "", 0},
    {wordInfo+22, "", 0},
    {wordInfo+96, "", 0},
    {wordInfo+97, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+98, ",", 0},
    {wordInfo+99, "", 0},
    {wordInfo+72, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+100, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+101, "", 0},
    {wordInfo+102, "", 0},
    {wordInfo+103, "", 0},
    {wordInfo+104, ".", 1},
    {wordInfo+78, "", 0},
    {wordInfo+79, "", 0},
    {wordInfo+105, "", 0},
    {wordInfo+105, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+106, "", 0},
    {wordInfo+107, "", 0},
    {wordInfo+108, "", 0},
    {wordInfo+109, ".", 1},
    {wordInfo+110, "", 0},
    {wordInfo+72, ",", 0},
    {wordInfo+61, "", 0},
    {wordInfo+90, "", 0},
    {wordInfo+111, ",", 0},
    {wordInfo+112, "", 0},
    {wordInfo+113, "", 0},
    {wordInfo+114, "", 0},
    {wordInfo+115, ";", 0},
    {wordInfo+115, "", 0},
    {wordInfo+116, "", 0},
    {wordInfo+117, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+118, "", 0},
    {wordInfo+119, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+120, ".", 1},
    {wordInfo+121, ",", 0},
    {wordInfo+122, "", 0},
    {wordInfo+123, "", 0},
    {wordInfo+3, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+124, ".", 1},
    {wordInfo+125, "", 0},
    {wordInfo+103, "", 0},
    {wordInfo+126, "", 0},
    {wordInfo+127, "", 0},
    {wordInfo+128, ",", 0},
    {wordInfo+129, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+130, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+131, "", 0},
    {wordInfo+3, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+132, "-", 0},
    {wordInfo+133, "", 0},
    {wordInfo+134, "", 0},
    {wordInfo+33, "", 0},
    {wordInfo+135, ",", 0},
    {wordInfo+136, "", 0},
    {wordInfo+61, "", 0},
    {wordInfo+137, ": \"", 0},
    {wordInfo+138, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+50, "", 0},
    {wordInfo+51, "", 0},
    {wordInfo+139, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+53, ",", 0},
    {wordInfo+140, "[", 0},
    {wordInfo+141, "", 0},
    {wordInfo+13, "],", 0},
    {wordInfo+1, "", 0},
    {wordInfo+28, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+142, "", 0},
    {wordInfo+22, "", 0},
    {wordInfo+143, "", 0},
    {wordInfo+144, "", 0},
    {wordInfo+145, "", 0},
    {wordInfo+54, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+146, "", 0},
    {wordInfo+147, "", 0},
    {wordInfo+48, "", 0},
    {wordInfo+148, "", 0},
    {wordInfo+149, "", 0},
    {wordInfo+150, ",", 0},
    {wordInfo+11, "", 0},
    {wordInfo+151, "", 0},
    {wordInfo+152, "", 0},
    {wordInfo+153, "", 0},
    {wordInfo+154, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+65, "", 0},
    {wordInfo+27, "", 0},
    {wordInfo+155, "", 0},
    {wordInfo+156, "", 0},
    {wordInfo+157, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+158, "-", 0},
    {wordInfo+159, "", 0},
    {wordInfo+80, ".\" \"", 1},
    {wordInfo+160, "!", 1},
    {wordInfo+161, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+162, "", 0},
    {wordInfo+163, "!\"", 1},
    {wordInfo+164, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+165, ",", 0},
    {wordInfo+148, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+166, "", 0},
    {wordInfo+167, "", 0},
    {wordInfo+3, "", 0},
    {wordInfo+34, "", 0},
    {wordInfo+104, ".", 1},
    {wordInfo+168, "", 0},
    {wordInfo+105, "", 0},
    {wordInfo+19, "", 0},
    {wordInfo+169, ",", 0},
    {wordInfo+170, "", 0},
    {wordInfo+144, "", 0},
    {wordInfo+171, "", 0},
    {wordInfo+172, "", 0},
    {wordInfo+173, ",", 0},
    {wordInfo+174, "", 0},
    {wordInfo+175, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+176, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+105, "", 0},
    {wordInfo+177, "", 0},
    {wordInfo+178, "", 0},
    {wordInfo+179, "", 0},
    {wordInfo+180, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+181, "", 0},
    {wordInfo+182, "", 0},
    {wordInfo+178, "", 0},
    {wordInfo+179, "", 0},
    {wordInfo+183, "", 0},
    {wordInfo+184, ".", 1},
    {wordInfo+168, "", 0},
    {wordInfo+185, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+33, "", 0},
    {wordInfo+186, "", 0},
    {wordInfo+130, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+187, "", 0},
    {wordInfo+188, "", 0},
    {wordInfo+189, "", 0},
    {wordInfo+148, "", 0},
    {wordInfo+123, "", 0},
    {wordInfo+185, "", 0},
    {wordInfo+190, "", 0},
    {wordInfo+191, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+54, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+192, ",", 0},
    {wordInfo+193, "", 0},
    {wordInfo+194, "", 0},
    {wordInfo+195, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+94, "", 0},
    {wordInfo+95, "", 0},
    {wordInfo+22, "", 0},
    {wordInfo+98, "", 0},
    {wordInfo+99, "", 0},
    {wordInfo+105, "", 0},
    {wordInfo+196, "", 0},
    {wordInfo+197, "", 0},
    {wordInfo+73, "", 0},
    {wordInfo+198, "", 0},
    {wordInfo+1, "", 0},
    {wordInfo+102, "", 0},
    {wordInfo+172, ".", 1},
    {wordInfo+168, "", 0},
    {wordInfo+199, "", 0},
    {wordInfo+200, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+78, "", 0},
    {wordInfo+79, ",", 0},
    {wordInfo+201, "", 0},
    {wordInfo+103, "", 0},
    {wordInfo+202, ",", 0},
    {wordInfo+203, "", 0},
    {wordInfo+39, "", 0},
    {wordInfo+103, "", 0},
    {wordInfo+179, "", 0},
    {wordInfo+204, ",", 0},
    {wordInfo+205, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+206, "", 0},
    {wordInfo+207, ",", 0},
    {wordInfo+1, "", 0},
    {wordInfo+208, "", 0},
    {wordInfo+209, "", 0},
    {wordInfo+210, "", 0},
    {wordInfo+178, "", 0},
    {wordInfo+23, "", 0},
    {wordInfo+211, ".", 1}
};


int startIds[] = {0, 3, 7, 10, 12, 26, 85, 90, 104, 129, 153, 162, 179, 185, 246, 247, 251, 262, 289, 325};

#define TEXT_INFO_SIZE (sizeof(textInfo)/sizeof(TextInfo))
#define WORD_INFO_SIZE (sizeof(wordInfo)/sizeof(WordInfo))
#define START_IDS_SIZE (sizeof(startIds)/sizeof(int))

//-------------

template <class T> inline int round(T x) {
    return int(x+0.5);
}

///////////////////////////////////////////////////////////////////////////////
// rnd utils
///////////////////////////////////////////////////////////////////////////////

int rndRange(const int a, const int b) {
    //	return rand()%(b-a+1)+a;
    double r = (double)rand()/RAND_MAX*(b-a)+a;
    return round(r);
}

int rndRange(const int a) {
    double r = (double)rand()/RAND_MAX*a;
    return round(r);
}

template <class T> T rndArrayValue(T* array, int arraySize) {
    return array[rndRange(arraySize)];
}

template <class T> T* rndSequence(const int count, const T* fromArr, const int fromArrSize) {
    T* result = new T[count];
    T* fromArrCopy = new T[fromArrSize];

    for (int i = 0, j = 0; i < count; i++, j++) {
        if (fromArrSize == j) {
            j = 0;
        }
        if (0 == j) {
            memcpy(fromArrCopy, fromArr, sizeof(T)*fromArrSize);
        }

        int r = rndRange(j, fromArrSize-1);
        result[i] = fromArrCopy[r];
        swap(fromArrCopy[j], fromArrCopy[r]);
    }

    delete[] fromArrCopy;

    return result;
}

///////////////////////////////////////////////////////////////////////////////
// arr utils
///////////////////////////////////////////////////////////////////////////////

int* arrRangeN(const int n) {
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    return arr;
}

template <class T> void arrSortAsc(T* arr, const int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) swap(arr[i], arr[j]);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
// python code
///////////////////////////////////////////////////////////////////////////////
//<time.h>
static PyObject* ex_seed(PyObject *self, PyObject *args) {
    int seed = 0;
    if (!PyArg_ParseTuple(args, "|i", &seed))
        return NULL;
    int argsLen = PySequence_Length(args);

    srand(argsLen ? seed : (unsigned)time(NULL));

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject* ex_printOriginal(PyObject *self, PyObject *args) {
    char* space = "";
    for (int i = 0; i < TEXT_INFO_SIZE; i++) {
        TextInfo* ti = textInfo+i;
        WordInfo* wi = ti->wordInfo;
        printf("%s%s%s", space, wi->word, ti->punctuation);
        space = " ";
    }
    Py_INCREF(Py_None);
    return Py_None;
}

void printWord(char* word, char* &space, int &endFlag, int charCase) {
    if (!word[0]) return;
    if (endFlag && !charCase) charCase = 3;
    switch (charCase) {
        case 0:
            printf("%s%s", space, word);
            break;
        case 1:
            printf("%s%c%s", space, toupper(word[0]), word+1);
            break;
        case 2:
            printf("%s%c%s", space, toupper(word[0]), word+1);
            break;
        case 3:
            printf("%s%c%s", space, toupper(word[0]), word+1);
            break;
    }
    space = " ";
    endFlag = 0;
}

static PyObject* ex_printText(PyObject *self, PyObject *args, PyObject *keywds) {
    int wordCount = 100;
    PyObject* insWords = NULL;
    int chainLen = 2;
    int isPunctuation = 1;
    int charCase = 0;

    static char *kwlist[] = {"wordCount", "insertions", "chainLen", "isPunctuation", "charCase", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "i|Oiii", kwlist, &wordCount, &insWords, &chainLen, &isPunctuation, &charCase)) {
        return NULL;
    }
    if (wordCount < 0) { PyErr_SetString(PyExc_TypeError, "wordCount must be 0 or greate"); return NULL; }
    if (chainLen < 1) { PyErr_SetString(PyExc_TypeError, "chainLen must be 1 or greate"); return NULL; }
    if (charCase < 0 || charCase > 3) { PyErr_SetString(PyExc_TypeError, "charCase must be in [0, 3] interval"); return NULL; }
    if (insWords && !PySequence_Check(insWords)) { PyErr_SetString(PyExc_TypeError, "insWords must be a sequence"); return NULL; }
    int insWordCount = insWords ? PySequence_Length(insWords) : 0;

    int chainStep = rndRange(chainLen-1);
    int endFlag = 1;
    char* space = "";
    int textId;

    int* allPosArr = arrRangeN(wordCount);
    int* insPosArr = rndSequence(insWordCount, allPosArr, wordCount);
    delete allPosArr;
    arrSortAsc(insPosArr, insWordCount);
    int insPosInd = 0;

    for (int i = 0; i < wordCount; i++) {
        if (endFlag) {
            textId = rndArrayValue(startIds, START_IDS_SIZE-1);
        }

        while (insPosInd < insWordCount && insPosArr[insPosInd] == i) {
            PyObject* pyWord = PySequence_Fast_GET_ITEM(insWords, insPosInd);
            if (!PyString_Check(pyWord)) { PyErr_SetString(PyExc_TypeError, "insWords must contains strings only"); return NULL; }
        printf("|%d|", textId);
            printWord(PyString_AsString(pyWord), space, endFlag, charCase);
            insPosInd++;
        }

        TextInfo* ti = textInfo+textId;
        WordInfo* wi = ti->wordInfo;

    printf("|%d|", textId);
        printWord(wi->word, space, endFlag, charCase);
        if (isPunctuation) printf("%s", ti->punctuation);
        endFlag = ti->endFlag;

        if (!endFlag) {
            if (chainStep < chainLen-1 && textId < TEXT_INFO_SIZE-1) {
                textId++;
            }
            else {
                textId = rndArrayValue(wi->nextIds, wi->nextIdsLen);
            }
        }
    }

    delete insPosArr;

    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef rndText_methods[] = {
    {"seed", ex_seed, 1, "seed"},
    {"printOriginal", ex_printOriginal, 1, "prints original text"},
    {"printText", (PyCFunction)ex_printText, METH_VARARGS | METH_KEYWORDS, "prints random generated text"},
    {NULL, NULL}
};

extern "C" void initrndText(void) {
    Py_InitModule("rndText", rndText_methods);
}
