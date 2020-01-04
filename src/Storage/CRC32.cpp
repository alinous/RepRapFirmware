#include "CRC32.h"

constexpr uint32_t CRC_32_TAB[256] =
{
	// CRC polynomial 0xedb88320
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 0x076dc419, 0x706af48f,
	0xe963a535, 0x9e6495a3, 0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988,
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 0x1db71064, 0x6ab020f2,
	0xf3b97148, 0x84be41de, 0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7,
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 0x14015c4f, 0x63066cd9,
	0xfa0f3d63, 0x8d080df5, 0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172,
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 0x35b5a8fa, 0x42b2986c,
	0xdbbbc9d6, 0xacbcf940, 0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59,
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 0x21b4f4b5, 0x56b3c423,
	0xcfba9599, 0xb8bda50f, 0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924,
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 0x76dc4190, 0x01db7106,
	0x98d220bc, 0xefd5102a, 0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433,
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 0x7f6a0dbb, 0x086d3d2d,
	0x91646c97, 0xe6635c01, 0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e,
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 0x65b0d9c6, 0x12b7e950,
	0x8bbeb8ea, 0xfcb9887c, 0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65,
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 0x4adfa541, 0x3dd895d7,
	0xa4d1c46d, 0xd3d6f4fb, 0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0,
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 0x5005713c, 0x270241aa,
	0xbe0b1010, 0xc90c2086, 0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f,
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 0x59b33d17, 0x2eb40d81,
	0xb7bd5c3b, 0xc0ba6cad, 0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a,
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 0xe3630b12, 0x94643b84,
	0x0d6d6a3e, 0x7a6a5aa8, 0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1,
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 0xf762575d, 0x806567cb,
	0x196c3671, 0x6e6b06e7, 0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc,
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 0xd6d6a3e8, 0xa1d1937e,
	0x38d8c2c4, 0x4fdff252, 0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b,
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 0xdf60efc3, 0xa867df55,
	0x316e8eef, 0x4669be79, 0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236,
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 0xc5ba3bbe, 0xb2bd0b28,
	0x2bb45a92, 0x5cb36a04, 0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d,
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 0x9c0906a9, 0xeb0e363f,
	0x72076785, 0x05005713, 0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38,
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 0x86d3d2d4, 0xf1d4e242,
	0x68ddb3f8, 0x1fda836e, 0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777,
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 0x8f659eff, 0xf862ae69,
	0x616bffd3, 0x166ccf45, 0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2,
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 0xaed16a4a, 0xd9d65adc,
	0x40df0b66, 0x37d83bf0, 0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9,
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 0xbad03605, 0xcdd70693,
	0x54de5729, 0x23d967bf, 0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94,
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d
};

#if SAME70

// On SAME70 we have more flash memory available, so use 4K table instead of 1K and the faster slicing-by-4 algorithm
constexpr uint32_t CRC_32_TAB1[256] =
{
	0x00000000,0x191B3141,0x32366282,0x2B2D53C3,0x646CC504,0x7D77F445,0x565AA786,0x4F4196C7,
	0xC8D98A08,0xD1C2BB49,0xFAEFE88A,0xE3F4D9CB,0xACB54F0C,0xB5AE7E4D,0x9E832D8E,0x87981CCF,
	0x4AC21251,0x53D92310,0x78F470D3,0x61EF4192,0x2EAED755,0x37B5E614,0x1C98B5D7,0x05838496,
	0x821B9859,0x9B00A918,0xB02DFADB,0xA936CB9A,0xE6775D5D,0xFF6C6C1C,0xD4413FDF,0xCD5A0E9E,
	0x958424A2,0x8C9F15E3,0xA7B24620,0xBEA97761,0xF1E8E1A6,0xE8F3D0E7,0xC3DE8324,0xDAC5B265,
	0x5D5DAEAA,0x44469FEB,0x6F6BCC28,0x7670FD69,0x39316BAE,0x202A5AEF,0x0B07092C,0x121C386D,
	0xDF4636F3,0xC65D07B2,0xED705471,0xF46B6530,0xBB2AF3F7,0xA231C2B6,0x891C9175,0x9007A034,
	0x179FBCFB,0x0E848DBA,0x25A9DE79,0x3CB2EF38,0x73F379FF,0x6AE848BE,0x41C51B7D,0x58DE2A3C,
	0xF0794F05,0xE9627E44,0xC24F2D87,0xDB541CC6,0x94158A01,0x8D0EBB40,0xA623E883,0xBF38D9C2,
	0x38A0C50D,0x21BBF44C,0x0A96A78F,0x138D96CE,0x5CCC0009,0x45D73148,0x6EFA628B,0x77E153CA,
	0xBABB5D54,0xA3A06C15,0x888D3FD6,0x91960E97,0xDED79850,0xC7CCA911,0xECE1FAD2,0xF5FACB93,
	0x7262D75C,0x6B79E61D,0x4054B5DE,0x594F849F,0x160E1258,0x0F152319,0x243870DA,0x3D23419B,
	0x65FD6BA7,0x7CE65AE6,0x57CB0925,0x4ED03864,0x0191AEA3,0x188A9FE2,0x33A7CC21,0x2ABCFD60,
	0xAD24E1AF,0xB43FD0EE,0x9F12832D,0x8609B26C,0xC94824AB,0xD05315EA,0xFB7E4629,0xE2657768,
	0x2F3F79F6,0x362448B7,0x1D091B74,0x04122A35,0x4B53BCF2,0x52488DB3,0x7965DE70,0x607EEF31,
	0xE7E6F3FE,0xFEFDC2BF,0xD5D0917C,0xCCCBA03D,0x838A36FA,0x9A9107BB,0xB1BC5478,0xA8A76539,
	0x3B83984B,0x2298A90A,0x09B5FAC9,0x10AECB88,0x5FEF5D4F,0x46F46C0E,0x6DD93FCD,0x74C20E8C,
	0xF35A1243,0xEA412302,0xC16C70C1,0xD8774180,0x9736D747,0x8E2DE606,0xA500B5C5,0xBC1B8484,
	0x71418A1A,0x685ABB5B,0x4377E898,0x5A6CD9D9,0x152D4F1E,0x0C367E5F,0x271B2D9C,0x3E001CDD,
	0xB9980012,0xA0833153,0x8BAE6290,0x92B553D1,0xDDF4C516,0xC4EFF457,0xEFC2A794,0xF6D996D5,
	0xAE07BCE9,0xB71C8DA8,0x9C31DE6B,0x852AEF2A,0xCA6B79ED,0xD37048AC,0xF85D1B6F,0xE1462A2E,
	0x66DE36E1,0x7FC507A0,0x54E85463,0x4DF36522,0x02B2F3E5,0x1BA9C2A4,0x30849167,0x299FA026,
	0xE4C5AEB8,0xFDDE9FF9,0xD6F3CC3A,0xCFE8FD7B,0x80A96BBC,0x99B25AFD,0xB29F093E,0xAB84387F,
	0x2C1C24B0,0x350715F1,0x1E2A4632,0x07317773,0x4870E1B4,0x516BD0F5,0x7A468336,0x635DB277,
	0xCBFAD74E,0xD2E1E60F,0xF9CCB5CC,0xE0D7848D,0xAF96124A,0xB68D230B,0x9DA070C8,0x84BB4189,
	0x03235D46,0x1A386C07,0x31153FC4,0x280E0E85,0x674F9842,0x7E54A903,0x5579FAC0,0x4C62CB81,
	0x8138C51F,0x9823F45E,0xB30EA79D,0xAA1596DC,0xE554001B,0xFC4F315A,0xD7626299,0xCE7953D8,
	0x49E14F17,0x50FA7E56,0x7BD72D95,0x62CC1CD4,0x2D8D8A13,0x3496BB52,0x1FBBE891,0x06A0D9D0,
	0x5E7EF3EC,0x4765C2AD,0x6C48916E,0x7553A02F,0x3A1236E8,0x230907A9,0x0824546A,0x113F652B,
	0x96A779E4,0x8FBC48A5,0xA4911B66,0xBD8A2A27,0xF2CBBCE0,0xEBD08DA1,0xC0FDDE62,0xD9E6EF23,
	0x14BCE1BD,0x0DA7D0FC,0x268A833F,0x3F91B27E,0x70D024B9,0x69CB15F8,0x42E6463B,0x5BFD777A,
	0xDC656BB5,0xC57E5AF4,0xEE530937,0xF7483876,0xB809AEB1,0xA1129FF0,0x8A3FCC33,0x9324FD72,
};

constexpr uint32_t CRC_32_TAB2[256] =
{
	0x00000000,0x01C26A37,0x0384D46E,0x0246BE59,0x0709A8DC,0x06CBC2EB,0x048D7CB2,0x054F1685,
	0x0E1351B8,0x0FD13B8F,0x0D9785D6,0x0C55EFE1,0x091AF964,0x08D89353,0x0A9E2D0A,0x0B5C473D,
	0x1C26A370,0x1DE4C947,0x1FA2771E,0x1E601D29,0x1B2F0BAC,0x1AED619B,0x18ABDFC2,0x1969B5F5,
	0x1235F2C8,0x13F798FF,0x11B126A6,0x10734C91,0x153C5A14,0x14FE3023,0x16B88E7A,0x177AE44D,
	0x384D46E0,0x398F2CD7,0x3BC9928E,0x3A0BF8B9,0x3F44EE3C,0x3E86840B,0x3CC03A52,0x3D025065,
	0x365E1758,0x379C7D6F,0x35DAC336,0x3418A901,0x3157BF84,0x3095D5B3,0x32D36BEA,0x331101DD,
	0x246BE590,0x25A98FA7,0x27EF31FE,0x262D5BC9,0x23624D4C,0x22A0277B,0x20E69922,0x2124F315,
	0x2A78B428,0x2BBADE1F,0x29FC6046,0x283E0A71,0x2D711CF4,0x2CB376C3,0x2EF5C89A,0x2F37A2AD,
	0x709A8DC0,0x7158E7F7,0x731E59AE,0x72DC3399,0x7793251C,0x76514F2B,0x7417F172,0x75D59B45,
	0x7E89DC78,0x7F4BB64F,0x7D0D0816,0x7CCF6221,0x798074A4,0x78421E93,0x7A04A0CA,0x7BC6CAFD,
	0x6CBC2EB0,0x6D7E4487,0x6F38FADE,0x6EFA90E9,0x6BB5866C,0x6A77EC5B,0x68315202,0x69F33835,
	0x62AF7F08,0x636D153F,0x612BAB66,0x60E9C151,0x65A6D7D4,0x6464BDE3,0x662203BA,0x67E0698D,
	0x48D7CB20,0x4915A117,0x4B531F4E,0x4A917579,0x4FDE63FC,0x4E1C09CB,0x4C5AB792,0x4D98DDA5,
	0x46C49A98,0x4706F0AF,0x45404EF6,0x448224C1,0x41CD3244,0x400F5873,0x4249E62A,0x438B8C1D,
	0x54F16850,0x55330267,0x5775BC3E,0x56B7D609,0x53F8C08C,0x523AAABB,0x507C14E2,0x51BE7ED5,
	0x5AE239E8,0x5B2053DF,0x5966ED86,0x58A487B1,0x5DEB9134,0x5C29FB03,0x5E6F455A,0x5FAD2F6D,
	0xE1351B80,0xE0F771B7,0xE2B1CFEE,0xE373A5D9,0xE63CB35C,0xE7FED96B,0xE5B86732,0xE47A0D05,
	0xEF264A38,0xEEE4200F,0xECA29E56,0xED60F461,0xE82FE2E4,0xE9ED88D3,0xEBAB368A,0xEA695CBD,
	0xFD13B8F0,0xFCD1D2C7,0xFE976C9E,0xFF5506A9,0xFA1A102C,0xFBD87A1B,0xF99EC442,0xF85CAE75,
	0xF300E948,0xF2C2837F,0xF0843D26,0xF1465711,0xF4094194,0xF5CB2BA3,0xF78D95FA,0xF64FFFCD,
	0xD9785D60,0xD8BA3757,0xDAFC890E,0xDB3EE339,0xDE71F5BC,0xDFB39F8B,0xDDF521D2,0xDC374BE5,
	0xD76B0CD8,0xD6A966EF,0xD4EFD8B6,0xD52DB281,0xD062A404,0xD1A0CE33,0xD3E6706A,0xD2241A5D,
	0xC55EFE10,0xC49C9427,0xC6DA2A7E,0xC7184049,0xC25756CC,0xC3953CFB,0xC1D382A2,0xC011E895,
	0xCB4DAFA8,0xCA8FC59F,0xC8C97BC6,0xC90B11F1,0xCC440774,0xCD866D43,0xCFC0D31A,0xCE02B92D,
	0x91AF9640,0x906DFC77,0x922B422E,0x93E92819,0x96A63E9C,0x976454AB,0x9522EAF2,0x94E080C5,
	0x9FBCC7F8,0x9E7EADCF,0x9C381396,0x9DFA79A1,0x98B56F24,0x99770513,0x9B31BB4A,0x9AF3D17D,
	0x8D893530,0x8C4B5F07,0x8E0DE15E,0x8FCF8B69,0x8A809DEC,0x8B42F7DB,0x89044982,0x88C623B5,
	0x839A6488,0x82580EBF,0x801EB0E6,0x81DCDAD1,0x8493CC54,0x8551A663,0x8717183A,0x86D5720D,
	0xA9E2D0A0,0xA820BA97,0xAA6604CE,0xABA46EF9,0xAEEB787C,0xAF29124B,0xAD6FAC12,0xACADC625,
	0xA7F18118,0xA633EB2F,0xA4755576,0xA5B73F41,0xA0F829C4,0xA13A43F3,0xA37CFDAA,0xA2BE979D,
	0xB5C473D0,0xB40619E7,0xB640A7BE,0xB782CD89,0xB2CDDB0C,0xB30FB13B,0xB1490F62,0xB08B6555,
	0xBBD72268,0xBA15485F,0xB853F606,0xB9919C31,0xBCDE8AB4,0xBD1CE083,0xBF5A5EDA,0xBE9834ED,
};

constexpr uint32_t CRC_32_TAB3[256] =
{
	0x00000000,0xB8BC6765,0xAA09C88B,0x12B5AFEE,0x8F629757,0x37DEF032,0x256B5FDC,0x9DD738B9,
	0xC5B428EF,0x7D084F8A,0x6FBDE064,0xD7018701,0x4AD6BFB8,0xF26AD8DD,0xE0DF7733,0x58631056,
	0x5019579F,0xE8A530FA,0xFA109F14,0x42ACF871,0xDF7BC0C8,0x67C7A7AD,0x75720843,0xCDCE6F26,
	0x95AD7F70,0x2D111815,0x3FA4B7FB,0x8718D09E,0x1ACFE827,0xA2738F42,0xB0C620AC,0x087A47C9,
	0xA032AF3E,0x188EC85B,0x0A3B67B5,0xB28700D0,0x2F503869,0x97EC5F0C,0x8559F0E2,0x3DE59787,
	0x658687D1,0xDD3AE0B4,0xCF8F4F5A,0x7733283F,0xEAE41086,0x525877E3,0x40EDD80D,0xF851BF68,
	0xF02BF8A1,0x48979FC4,0x5A22302A,0xE29E574F,0x7F496FF6,0xC7F50893,0xD540A77D,0x6DFCC018,
	0x359FD04E,0x8D23B72B,0x9F9618C5,0x272A7FA0,0xBAFD4719,0x0241207C,0x10F48F92,0xA848E8F7,
	0x9B14583D,0x23A83F58,0x311D90B6,0x89A1F7D3,0x1476CF6A,0xACCAA80F,0xBE7F07E1,0x06C36084,
	0x5EA070D2,0xE61C17B7,0xF4A9B859,0x4C15DF3C,0xD1C2E785,0x697E80E0,0x7BCB2F0E,0xC377486B,
	0xCB0D0FA2,0x73B168C7,0x6104C729,0xD9B8A04C,0x446F98F5,0xFCD3FF90,0xEE66507E,0x56DA371B,
	0x0EB9274D,0xB6054028,0xA4B0EFC6,0x1C0C88A3,0x81DBB01A,0x3967D77F,0x2BD27891,0x936E1FF4,
	0x3B26F703,0x839A9066,0x912F3F88,0x299358ED,0xB4446054,0x0CF80731,0x1E4DA8DF,0xA6F1CFBA,
	0xFE92DFEC,0x462EB889,0x549B1767,0xEC277002,0x71F048BB,0xC94C2FDE,0xDBF98030,0x6345E755,
	0x6B3FA09C,0xD383C7F9,0xC1366817,0x798A0F72,0xE45D37CB,0x5CE150AE,0x4E54FF40,0xF6E89825,
	0xAE8B8873,0x1637EF16,0x048240F8,0xBC3E279D,0x21E91F24,0x99557841,0x8BE0D7AF,0x335CB0CA,
	0xED59B63B,0x55E5D15E,0x47507EB0,0xFFEC19D5,0x623B216C,0xDA874609,0xC832E9E7,0x708E8E82,
	0x28ED9ED4,0x9051F9B1,0x82E4565F,0x3A58313A,0xA78F0983,0x1F336EE6,0x0D86C108,0xB53AA66D,
	0xBD40E1A4,0x05FC86C1,0x1749292F,0xAFF54E4A,0x322276F3,0x8A9E1196,0x982BBE78,0x2097D91D,
	0x78F4C94B,0xC048AE2E,0xD2FD01C0,0x6A4166A5,0xF7965E1C,0x4F2A3979,0x5D9F9697,0xE523F1F2,
	0x4D6B1905,0xF5D77E60,0xE762D18E,0x5FDEB6EB,0xC2098E52,0x7AB5E937,0x680046D9,0xD0BC21BC,
	0x88DF31EA,0x3063568F,0x22D6F961,0x9A6A9E04,0x07BDA6BD,0xBF01C1D8,0xADB46E36,0x15080953,
	0x1D724E9A,0xA5CE29FF,0xB77B8611,0x0FC7E174,0x9210D9CD,0x2AACBEA8,0x38191146,0x80A57623,
	0xD8C66675,0x607A0110,0x72CFAEFE,0xCA73C99B,0x57A4F122,0xEF189647,0xFDAD39A9,0x45115ECC,
	0x764DEE06,0xCEF18963,0xDC44268D,0x64F841E8,0xF92F7951,0x41931E34,0x5326B1DA,0xEB9AD6BF,
	0xB3F9C6E9,0x0B45A18C,0x19F00E62,0xA14C6907,0x3C9B51BE,0x842736DB,0x96929935,0x2E2EFE50,
	0x2654B999,0x9EE8DEFC,0x8C5D7112,0x34E11677,0xA9362ECE,0x118A49AB,0x033FE645,0xBB838120,
	0xE3E09176,0x5B5CF613,0x49E959FD,0xF1553E98,0x6C820621,0xD43E6144,0xC68BCEAA,0x7E37A9CF,
	0xD67F4138,0x6EC3265D,0x7C7689B3,0xC4CAEED6,0x591DD66F,0xE1A1B10A,0xF3141EE4,0x4BA87981,
	0x13CB69D7,0xAB770EB2,0xB9C2A15C,0x017EC639,0x9CA9FE80,0x241599E5,0x36A0360B,0x8E1C516E,
	0x866616A7,0x3EDA71C2,0x2C6FDE2C,0x94D3B949,0x090481F0,0xB1B8E695,0xA30D497B,0x1BB12E1E,
	0x43D23E48,0xFB6E592D,0xE9DBF6C3,0x516791A6,0xCCB0A91F,0x740CCE7A,0x66B96194,0xDE0506F1,
};

#endif

CRC32::CRC32() noexcept
{
	Reset();
}

void CRC32::Update(char c) noexcept
{
	crc = (CRC_32_TAB[(crc ^ c) & 0xFF] ^ (crc >> 8));
}

// A note on CRC algorithms on ARM:
// Original algorithm (1 byte per loop iteration, 1K table): 7 instructions, 11 clocks (11 clocks/byte)
// Algorithm currently used on non-SAME70 processors (4 bytes per loop iteration, 1K table): 19 instructions, 26 clocks (6.5 clocks/byte)
// Slicing-by-4 using 1 dword per loop iteration: 15 instructions, 18 clocks (4.5 clocks/byte)
// Slicing-by-4 using 1 quadword per loop iteration: 28 instructions, 31 clocks (3.875 clocks/byte)
void CRC32::Update(const char *s, size_t len) noexcept
{
	// The speed of this function affects the speed of file uploads, so make it as fast as possible. Sadly the SAME70 doesn't do hardware CRC calculation.
	// Work on a local copy of the crc to avoid storing it all the time
	uint32_t locCrc = crc;
	const char * const end = s + len;

	// Process any bytes at the start until we reach a dword boundary
	while ((reinterpret_cast<uint32_t>(s) & 3) != 0 && s != end)
	{
		locCrc = (CRC_32_TAB[(locCrc ^ *s++) & 0xFF] ^ (locCrc >> 8));
	}

#if SAME70
	const char * const endAligned = s + ((end - s) & ~7);
	while (s != endAligned)
	{
		// Slicing-by-4 algorithm, 2 quadwords at a time
		const uint32_t data0 = *reinterpret_cast<const uint32_t*>(s) ^ locCrc;
	    locCrc = CRC_32_TAB[(data0 >> 24) & 0xFF] ^ CRC_32_TAB1[(data0 >> 16) & 0xFF] ^ CRC_32_TAB2[(data0 >> 8) & 0xFF] ^ CRC_32_TAB3[data0 & 0xFF];
		const uint32_t data1 = *reinterpret_cast<const uint32_t*>(s + 4) ^ locCrc;
	    locCrc = CRC_32_TAB[(data1 >> 24) & 0xFF] ^ CRC_32_TAB1[(data1 >> 16) & 0xFF] ^ CRC_32_TAB2[(data1 >> 8) & 0xFF] ^ CRC_32_TAB3[data1 & 0xFF];
		s += 8;
	}
#else
	const char * const endAligned = s + ((end - s) & ~3);
	while (s != endAligned)
	{
		const uint32_t data = *reinterpret_cast<const uint32_t*>(s);
		s += 4;
		locCrc = (CRC_32_TAB[(locCrc ^ data) & 0xFF] ^ (locCrc >> 8));
		locCrc = (CRC_32_TAB[(locCrc ^ (data >> 8)) & 0xFF] ^ (locCrc >> 8));
		locCrc = (CRC_32_TAB[(locCrc ^ (data >> 16)) & 0xFF] ^ (locCrc >> 8));
		locCrc = (CRC_32_TAB[(locCrc ^ (data >> 24)) & 0xFF] ^ (locCrc >> 8));
	}
#endif

	// Process up to 7 (SAME70) or 3 (others) bytes at the end
	while (s != end)
	{
		locCrc = (CRC_32_TAB[(locCrc ^ *s++) & 0xFF] ^ (locCrc >> 8));
	}

	crc = locCrc;
}

void CRC32::Reset() noexcept
{
	crc = 0xffffffff;
}
