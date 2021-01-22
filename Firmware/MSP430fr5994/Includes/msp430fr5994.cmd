/******************************************************************************
*
* Copyright (C) 2012 - 2020 Texas Instruments Incorporated - http://www.ti.com/
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
*  Redistributions of source code must retain the above copyright
*  notice, this list of conditions and the following disclaimer.
*
*  Redistributions in binary form must reproduce the above copyright
*  notice, this list of conditions and the following disclaimer in the
*  documentation and/or other materials provided with the
*  distribution.
*
*  Neither the name of Texas Instruments Incorporated nor the names of
*  its contributors may be used to endorse or promote products derived
*  from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
/***************************************************************/
/*    msp430fr5994.cmd                                        */
/*    - Linker Command File for defintions in the header file  */
/*    Please do not change !                                   */
/*                                                             */
/***************************************************************/
/* 1.210 */
/***************************************************************/

/****************************************************************
* PERIPHERAL FILE MAP
****************************************************************/


/*****************************************************************************
 ADC12_B
*****************************************************************************/
ADC12CTL0          = 0x0800;
ADC12CTL0_L        = 0x0800;
ADC12CTL0_H        = 0x0801;
ADC12CTL1          = 0x0802;
ADC12CTL1_L        = 0x0802;
ADC12CTL1_H        = 0x0803;
ADC12CTL2          = 0x0804;
ADC12CTL2_L        = 0x0804;
ADC12CTL2_H        = 0x0805;
ADC12CTL3          = 0x0806;
ADC12CTL3_L        = 0x0806;
ADC12CTL3_H        = 0x0807;
ADC12LO            = 0x0808;
ADC12LO_L          = 0x0808;
ADC12LO_H          = 0x0809;
ADC12HI            = 0x080A;
ADC12HI_L          = 0x080A;
ADC12HI_H          = 0x080B;
ADC12IFGR0         = 0x080C;
ADC12IFGR0_L       = 0x080C;
ADC12IFGR0_H       = 0x080D;
ADC12IFGR1         = 0x080E;
ADC12IFGR1_L       = 0x080E;
ADC12IFGR1_H       = 0x080F;
ADC12IFGR2         = 0x0810;
ADC12IFGR2_L       = 0x0810;
ADC12IFGR2_H       = 0x0811;
ADC12IER0          = 0x0812;
ADC12IER0_L        = 0x0812;
ADC12IER0_H        = 0x0813;
ADC12IER1          = 0x0814;
ADC12IER1_L        = 0x0814;
ADC12IER1_H        = 0x0815;
ADC12IER2          = 0x0816;
ADC12IER2_L        = 0x0816;
ADC12IER2_H        = 0x0817;
ADC12IV            = 0x0818;
ADC12IV_L          = 0x0818;
ADC12IV_H          = 0x0819;
ADC12MCTL0         = 0x0820;
ADC12MCTL0_L       = 0x0820;
ADC12MCTL0_H       = 0x0821;
ADC12MCTL1         = 0x0822;
ADC12MCTL1_L       = 0x0822;
ADC12MCTL1_H       = 0x0823;
ADC12MCTL2         = 0x0824;
ADC12MCTL2_L       = 0x0824;
ADC12MCTL2_H       = 0x0825;
ADC12MCTL3         = 0x0826;
ADC12MCTL3_L       = 0x0826;
ADC12MCTL3_H       = 0x0827;
ADC12MCTL4         = 0x0828;
ADC12MCTL4_L       = 0x0828;
ADC12MCTL4_H       = 0x0829;
ADC12MCTL5         = 0x082A;
ADC12MCTL5_L       = 0x082A;
ADC12MCTL5_H       = 0x082B;
ADC12MCTL6         = 0x082C;
ADC12MCTL6_L       = 0x082C;
ADC12MCTL6_H       = 0x082D;
ADC12MCTL7         = 0x082E;
ADC12MCTL7_L       = 0x082E;
ADC12MCTL7_H       = 0x082F;
ADC12MCTL8         = 0x0830;
ADC12MCTL8_L       = 0x0830;
ADC12MCTL8_H       = 0x0831;
ADC12MCTL9         = 0x0832;
ADC12MCTL9_L       = 0x0832;
ADC12MCTL9_H       = 0x0833;
ADC12MCTL10        = 0x0834;
ADC12MCTL10_L      = 0x0834;
ADC12MCTL10_H      = 0x0835;
ADC12MCTL11        = 0x0836;
ADC12MCTL11_L      = 0x0836;
ADC12MCTL11_H      = 0x0837;
ADC12MCTL12        = 0x0838;
ADC12MCTL12_L      = 0x0838;
ADC12MCTL12_H      = 0x0839;
ADC12MCTL13        = 0x083A;
ADC12MCTL13_L      = 0x083A;
ADC12MCTL13_H      = 0x083B;
ADC12MCTL14        = 0x083C;
ADC12MCTL14_L      = 0x083C;
ADC12MCTL14_H      = 0x083D;
ADC12MCTL15        = 0x083E;
ADC12MCTL15_L      = 0x083E;
ADC12MCTL15_H      = 0x083F;
ADC12MCTL16        = 0x0840;
ADC12MCTL16_L      = 0x0840;
ADC12MCTL16_H      = 0x0841;
ADC12MCTL17        = 0x0842;
ADC12MCTL17_L      = 0x0842;
ADC12MCTL17_H      = 0x0843;
ADC12MCTL18        = 0x0844;
ADC12MCTL18_L      = 0x0844;
ADC12MCTL18_H      = 0x0845;
ADC12MCTL19        = 0x0846;
ADC12MCTL19_L      = 0x0846;
ADC12MCTL19_H      = 0x0847;
ADC12MCTL20        = 0x0848;
ADC12MCTL20_L      = 0x0848;
ADC12MCTL20_H      = 0x0849;
ADC12MCTL21        = 0x084A;
ADC12MCTL21_L      = 0x084A;
ADC12MCTL21_H      = 0x084B;
ADC12MCTL22        = 0x084C;
ADC12MCTL22_L      = 0x084C;
ADC12MCTL22_H      = 0x084D;
ADC12MCTL23        = 0x084E;
ADC12MCTL23_L      = 0x084E;
ADC12MCTL23_H      = 0x084F;
ADC12MCTL24        = 0x0850;
ADC12MCTL24_L      = 0x0850;
ADC12MCTL24_H      = 0x0851;
ADC12MCTL25        = 0x0852;
ADC12MCTL25_L      = 0x0852;
ADC12MCTL25_H      = 0x0853;
ADC12MCTL26        = 0x0854;
ADC12MCTL26_L      = 0x0854;
ADC12MCTL26_H      = 0x0855;
ADC12MCTL27        = 0x0856;
ADC12MCTL27_L      = 0x0856;
ADC12MCTL27_H      = 0x0857;
ADC12MCTL28        = 0x0858;
ADC12MCTL28_L      = 0x0858;
ADC12MCTL28_H      = 0x0859;
ADC12MCTL29        = 0x085A;
ADC12MCTL29_L      = 0x085A;
ADC12MCTL29_H      = 0x085B;
ADC12MCTL30        = 0x085C;
ADC12MCTL30_L      = 0x085C;
ADC12MCTL30_H      = 0x085D;
ADC12MCTL31        = 0x085E;
ADC12MCTL31_L      = 0x085E;
ADC12MCTL31_H      = 0x085F;
ADC12MEM0          = 0x0860;
ADC12MEM0_L        = 0x0860;
ADC12MEM0_H        = 0x0861;
ADC12MEM1          = 0x0862;
ADC12MEM1_L        = 0x0862;
ADC12MEM1_H        = 0x0863;
ADC12MEM2          = 0x0864;
ADC12MEM2_L        = 0x0864;
ADC12MEM2_H        = 0x0865;
ADC12MEM3          = 0x0866;
ADC12MEM3_L        = 0x0866;
ADC12MEM3_H        = 0x0867;
ADC12MEM4          = 0x0868;
ADC12MEM4_L        = 0x0868;
ADC12MEM4_H        = 0x0869;
ADC12MEM5          = 0x086A;
ADC12MEM5_L        = 0x086A;
ADC12MEM5_H        = 0x086B;
ADC12MEM6          = 0x086C;
ADC12MEM6_L        = 0x086C;
ADC12MEM6_H        = 0x086D;
ADC12MEM7          = 0x086E;
ADC12MEM7_L        = 0x086E;
ADC12MEM7_H        = 0x086F;
ADC12MEM8          = 0x0870;
ADC12MEM8_L        = 0x0870;
ADC12MEM8_H        = 0x0871;
ADC12MEM9          = 0x0872;
ADC12MEM9_L        = 0x0872;
ADC12MEM9_H        = 0x0873;
ADC12MEM10         = 0x0874;
ADC12MEM10_L       = 0x0874;
ADC12MEM10_H       = 0x0875;
ADC12MEM11         = 0x0876;
ADC12MEM11_L       = 0x0876;
ADC12MEM11_H       = 0x0877;
ADC12MEM12         = 0x0878;
ADC12MEM12_L       = 0x0878;
ADC12MEM12_H       = 0x0879;
ADC12MEM13         = 0x087A;
ADC12MEM13_L       = 0x087A;
ADC12MEM13_H       = 0x087B;
ADC12MEM14         = 0x087C;
ADC12MEM14_L       = 0x087C;
ADC12MEM14_H       = 0x087D;
ADC12MEM15         = 0x087E;
ADC12MEM15_L       = 0x087E;
ADC12MEM15_H       = 0x087F;
ADC12MEM16         = 0x0880;
ADC12MEM16_L       = 0x0880;
ADC12MEM16_H       = 0x0881;
ADC12MEM17         = 0x0882;
ADC12MEM17_L       = 0x0882;
ADC12MEM17_H       = 0x0883;
ADC12MEM18         = 0x0884;
ADC12MEM18_L       = 0x0884;
ADC12MEM18_H       = 0x0885;
ADC12MEM19         = 0x0886;
ADC12MEM19_L       = 0x0886;
ADC12MEM19_H       = 0x0887;
ADC12MEM20         = 0x0888;
ADC12MEM20_L       = 0x0888;
ADC12MEM20_H       = 0x0889;
ADC12MEM21         = 0x088A;
ADC12MEM21_L       = 0x088A;
ADC12MEM21_H       = 0x088B;
ADC12MEM22         = 0x088C;
ADC12MEM22_L       = 0x088C;
ADC12MEM22_H       = 0x088D;
ADC12MEM23         = 0x088E;
ADC12MEM23_L       = 0x088E;
ADC12MEM23_H       = 0x088F;
ADC12MEM24         = 0x0890;
ADC12MEM24_L       = 0x0890;
ADC12MEM24_H       = 0x0891;
ADC12MEM25         = 0x0892;
ADC12MEM25_L       = 0x0892;
ADC12MEM25_H       = 0x0893;
ADC12MEM26         = 0x0894;
ADC12MEM26_L       = 0x0894;
ADC12MEM26_H       = 0x0895;
ADC12MEM27         = 0x0896;
ADC12MEM27_L       = 0x0896;
ADC12MEM27_H       = 0x0897;
ADC12MEM28         = 0x0898;
ADC12MEM28_L       = 0x0898;
ADC12MEM28_H       = 0x0899;
ADC12MEM29         = 0x089A;
ADC12MEM29_L       = 0x089A;
ADC12MEM29_H       = 0x089B;
ADC12MEM30         = 0x089C;
ADC12MEM30_L       = 0x089C;
ADC12MEM30_H       = 0x089D;
ADC12MEM31         = 0x089E;
ADC12MEM31_L       = 0x089E;
ADC12MEM31_H       = 0x089F;


/*****************************************************************************
 AES256
*****************************************************************************/
AESACTL0           = 0x09C0;
AESACTL0_L         = 0x09C0;
AESACTL0_H         = 0x09C1;
AESACTL1           = 0x09C2;
AESACTL1_L         = 0x09C2;
AESACTL1_H         = 0x09C3;
AESASTAT           = 0x09C4;
AESASTAT_L         = 0x09C4;
AESASTAT_H         = 0x09C5;
AESAKEY            = 0x09C6;
AESAKEY_L          = 0x09C6;
AESAKEY_H          = 0x09C7;
AESADIN            = 0x09C8;
AESADIN_L          = 0x09C8;
AESADIN_H          = 0x09C9;
AESADOUT           = 0x09CA;
AESADOUT_L         = 0x09CA;
AESADOUT_H         = 0x09CB;
AESAXDIN           = 0x09CC;
AESAXDIN_L         = 0x09CC;
AESAXDIN_H         = 0x09CD;
AESAXIN            = 0x09CE;
AESAXIN_L          = 0x09CE;
AESAXIN_H          = 0x09CF;


/*****************************************************************************
 CAPTIO0
*****************************************************************************/
CAPTIO0CTL         = 0x043E;
CAPTIO0CTL_L       = 0x043E;
CAPTIO0CTL_H       = 0x043F;


/*****************************************************************************
 CAPTIO1
*****************************************************************************/
CAPTIO1CTL         = 0x047E;
CAPTIO1CTL_L       = 0x047E;
CAPTIO1CTL_H       = 0x047F;


/*****************************************************************************
 COMP_E
*****************************************************************************/
CECTL0             = 0x08C0;
CECTL0_L           = 0x08C0;
CECTL0_H           = 0x08C1;
CECTL1             = 0x08C2;
CECTL1_L           = 0x08C2;
CECTL1_H           = 0x08C3;
CECTL2             = 0x08C4;
CECTL2_L           = 0x08C4;
CECTL2_H           = 0x08C5;
CECTL3             = 0x08C6;
CECTL3_L           = 0x08C6;
CECTL3_H           = 0x08C7;
CEINT              = 0x08CC;
CEINT_L            = 0x08CC;
CEINT_H            = 0x08CD;
CEIV               = 0x08CE;
CEIV_L             = 0x08CE;
CEIV_H             = 0x08CF;


/*****************************************************************************
 CRC
*****************************************************************************/
CRCDI              = 0x0150;
CRCDI_L            = 0x0150;
CRCDI_H            = 0x0151;
CRCDIRB            = 0x0152;
CRCDIRB_L          = 0x0152;
CRCDIRB_H          = 0x0153;
CRCINIRES          = 0x0154;
CRCINIRES_L        = 0x0154;
CRCINIRES_H        = 0x0155;
CRCRESR            = 0x0156;
CRCRESR_L          = 0x0156;
CRCRESR_H          = 0x0157;


/*****************************************************************************
 CRC32
*****************************************************************************/
CRC32DIW0          = 0x0980;
CRC32DIW0_L        = 0x0980;
CRC32DIW0_H        = 0x0981;
CRC32DIW1          = 0x0982;
CRC32DIW1_L        = 0x0982;
CRC32DIW1_H        = 0x0983;
CRC32DIRBW1        = 0x0984;
CRC32DIRBW1_L      = 0x0984;
CRC32DIRBW1_H      = 0x0985;
CRC32DIRBW0        = 0x0986;
CRC32DIRBW0_L      = 0x0986;
CRC32DIRBW0_H      = 0x0987;
CRC32INIRESW0      = 0x0988;
CRC32INIRESW0_L    = 0x0988;
CRC32INIRESW0_H    = 0x0989;
CRC32INIRESW1      = 0x098A;
CRC32INIRESW1_L    = 0x098A;
CRC32INIRESW1_H    = 0x098B;
CRC32RESRW1        = 0x098C;
CRC32RESRW1_L      = 0x098C;
CRC32RESRW1_H      = 0x098D;
CRC32RESRW0        = 0x098E;
CRC32RESRW0_L      = 0x098E;
CRC32RESRW0_H      = 0x098F;
CRC16DIW0          = 0x0990;
CRC16DIW0_L        = 0x0990;
CRC16DIW0_H        = 0x0991;
CRC16DIRBW0        = 0x0996;
CRC16DIRBW0_L      = 0x0996;
CRC16DIRBW0_H      = 0x0997;
CRC16INIRESW0      = 0x0998;
CRC16INIRESW0_L    = 0x0998;
CRC16INIRESW0_H    = 0x0999;
CRC16RESRW0        = 0x099E;
CRC16RESRW0_L      = 0x099E;
CRC16RESRW0_H      = 0x099F;


/*****************************************************************************
 CS
*****************************************************************************/
CSCTL0             = 0x0160;
CSCTL0_L           = 0x0160;
CSCTL0_H           = 0x0161;
CSCTL1             = 0x0162;
CSCTL1_L           = 0x0162;
CSCTL1_H           = 0x0163;
CSCTL2             = 0x0164;
CSCTL2_L           = 0x0164;
CSCTL2_H           = 0x0165;
CSCTL3             = 0x0166;
CSCTL3_L           = 0x0166;
CSCTL3_H           = 0x0167;
CSCTL4             = 0x0168;
CSCTL4_L           = 0x0168;
CSCTL4_H           = 0x0169;
CSCTL5             = 0x016A;
CSCTL5_L           = 0x016A;
CSCTL5_H           = 0x016B;
CSCTL6             = 0x016C;
CSCTL6_L           = 0x016C;
CSCTL6_H           = 0x016D;


/*****************************************************************************
 DIO
*****************************************************************************/
PAIN               = 0x0200;
PAIN_L             = 0x0200;
PAIN_H             = 0x0201;
PAOUT              = 0x0202;
PAOUT_L            = 0x0202;
PAOUT_H            = 0x0203;
PADIR              = 0x0204;
PADIR_L            = 0x0204;
PADIR_H            = 0x0205;
PAREN              = 0x0206;
PAREN_L            = 0x0206;
PAREN_H            = 0x0207;
PASEL0             = 0x020A;
PASEL0_L           = 0x020A;
PASEL0_H           = 0x020B;
PASEL1             = 0x020C;
PASEL1_L           = 0x020C;
PASEL1_H           = 0x020D;
P1IV               = 0x020E;
P1IV_L             = 0x020E;
P1IV_H             = 0x020F;
PASELC             = 0x0216;
PASELC_L           = 0x0216;
PASELC_H           = 0x0217;
PAIES              = 0x0218;
PAIES_L            = 0x0218;
PAIES_H            = 0x0219;
PAIE               = 0x021A;
PAIE_L             = 0x021A;
PAIE_H             = 0x021B;
PAIFG              = 0x021C;
PAIFG_L            = 0x021C;
PAIFG_H            = 0x021D;
P2IV               = 0x021E;
P2IV_L             = 0x021E;
P2IV_H             = 0x021F;
PBIN               = 0x0220;
PBIN_L             = 0x0220;
PBIN_H             = 0x0221;
PBOUT              = 0x0222;
PBOUT_L            = 0x0222;
PBOUT_H            = 0x0223;
PBDIR              = 0x0224;
PBDIR_L            = 0x0224;
PBDIR_H            = 0x0225;
PBREN              = 0x0226;
PBREN_L            = 0x0226;
PBREN_H            = 0x0227;
PBSEL0             = 0x022A;
PBSEL0_L           = 0x022A;
PBSEL0_H           = 0x022B;
PBSEL1             = 0x022C;
PBSEL1_L           = 0x022C;
PBSEL1_H           = 0x022D;
P3IV               = 0x022E;
P3IV_L             = 0x022E;
P3IV_H             = 0x022F;
PBSELC             = 0x0236;
PBSELC_L           = 0x0236;
PBSELC_H           = 0x0237;
PBIES              = 0x0238;
PBIES_L            = 0x0238;
PBIES_H            = 0x0239;
PBIE               = 0x023A;
PBIE_L             = 0x023A;
PBIE_H             = 0x023B;
PBIFG              = 0x023C;
PBIFG_L            = 0x023C;
PBIFG_H            = 0x023D;
P4IV               = 0x023E;
P4IV_L             = 0x023E;
P4IV_H             = 0x023F;
PCIN               = 0x0240;
PCIN_L             = 0x0240;
PCIN_H             = 0x0241;
PCOUT              = 0x0242;
PCOUT_L            = 0x0242;
PCOUT_H            = 0x0243;
PCDIR              = 0x0244;
PCDIR_L            = 0x0244;
PCDIR_H            = 0x0245;
PCREN              = 0x0246;
PCREN_L            = 0x0246;
PCREN_H            = 0x0247;
PCSEL0             = 0x024A;
PCSEL0_L           = 0x024A;
PCSEL0_H           = 0x024B;
PCSEL1             = 0x024C;
PCSEL1_L           = 0x024C;
PCSEL1_H           = 0x024D;
P5IV               = 0x024E;
P5IV_L             = 0x024E;
P5IV_H             = 0x024F;
PCSELC             = 0x0256;
PCSELC_L           = 0x0256;
PCSELC_H           = 0x0257;
PCIES              = 0x0258;
PCIES_L            = 0x0258;
PCIES_H            = 0x0259;
PCIE               = 0x025A;
PCIE_L             = 0x025A;
PCIE_H             = 0x025B;
PCIFG              = 0x025C;
PCIFG_L            = 0x025C;
PCIFG_H            = 0x025D;
P6IV               = 0x025E;
P6IV_L             = 0x025E;
P6IV_H             = 0x025F;
PDIN               = 0x0260;
PDIN_L             = 0x0260;
PDIN_H             = 0x0261;
PDOUT              = 0x0262;
PDOUT_L            = 0x0262;
PDOUT_H            = 0x0263;
PDDIR              = 0x0264;
PDDIR_L            = 0x0264;
PDDIR_H            = 0x0265;
PDREN              = 0x0266;
PDREN_L            = 0x0266;
PDREN_H            = 0x0267;
PDSEL0             = 0x026A;
PDSEL0_L           = 0x026A;
PDSEL0_H           = 0x026B;
PDSEL1             = 0x026C;
PDSEL1_L           = 0x026C;
PDSEL1_H           = 0x026D;
P7IV               = 0x026E;
P7IV_L             = 0x026E;
P7IV_H             = 0x026F;
PDSELC             = 0x0276;
PDSELC_L           = 0x0276;
PDSELC_H           = 0x0277;
PDIES              = 0x0278;
PDIES_L            = 0x0278;
PDIES_H            = 0x0279;
PDIE               = 0x027A;
PDIE_L             = 0x027A;
PDIE_H             = 0x027B;
PDIFG              = 0x027C;
PDIFG_L            = 0x027C;
PDIFG_H            = 0x027D;
P8IV               = 0x027E;
P8IV_L             = 0x027E;
P8IV_H             = 0x027F;
PJIN               = 0x0320;
PJIN_L             = 0x0320;
PJIN_H             = 0x0321;
PJOUT              = 0x0322;
PJOUT_L            = 0x0322;
PJOUT_H            = 0x0323;
PJDIR              = 0x0324;
PJDIR_L            = 0x0324;
PJDIR_H            = 0x0325;
PJREN              = 0x0326;
PJREN_L            = 0x0326;
PJREN_H            = 0x0327;
PJSEL0             = 0x032A;
PJSEL0_L           = 0x032A;
PJSEL0_H           = 0x032B;
PJSEL1             = 0x032C;
PJSEL1_L           = 0x032C;
PJSEL1_H           = 0x032D;
PJSELC             = 0x0336;
PJSELC_L           = 0x0336;
PJSELC_H           = 0x0337;
P1IN               = 0x0200;

P2IN               = 0x0201;

P2OUT              = 0x0203;

P1OUT              = 0x0202;

P1DIR              = 0x0204;

P2DIR              = 0x0205;

P1REN              = 0x0206;

P2REN              = 0x0207;

P1SEL0             = 0x020A;

P2SEL0             = 0x020B;

P1SEL1             = 0x020C;

P2SEL1             = 0x020D;

P1SELC             = 0x0216;

P2SELC             = 0x0217;

P1IES              = 0x0218;

P2IES              = 0x0219;

P1IE               = 0x021A;

P2IE               = 0x021B;

P1IFG              = 0x021C;

P2IFG              = 0x021D;

P3IN               = 0x0220;

P4IN               = 0x0221;

P3OUT              = 0x0222;

P4OUT              = 0x0223;

P3DIR              = 0x0224;

P4DIR              = 0x0225;

P3REN              = 0x0226;

P4REN              = 0x0227;

P4SEL0             = 0x022B;

P3SEL0             = 0x022A;

P3SEL1             = 0x022C;

P4SEL1             = 0x022D;

P3SELC             = 0x0236;

P4SELC             = 0x0237;

P3IES              = 0x0238;

P4IES              = 0x0239;

P3IE               = 0x023A;

P4IE               = 0x023B;

P3IFG              = 0x023C;

P4IFG              = 0x023D;

P5IN               = 0x0240;

P6IN               = 0x0241;

P5OUT              = 0x0242;

P6OUT              = 0x0243;

P5DIR              = 0x0244;

P6DIR              = 0x0245;

P5REN              = 0x0246;

P6REN              = 0x0247;

P5SEL0             = 0x024A;

P6SEL0             = 0x024B;

P5SEL1             = 0x024C;

P6SEL1             = 0x024D;

P5SELC             = 0x0256;

P6SELC             = 0x0257;

P5IES              = 0x0258;

P6IES              = 0x0259;

P5IE               = 0x025A;

P6IE               = 0x025B;

P5IFG              = 0x025C;

P6IFG              = 0x025D;

P7IN               = 0x0260;

P8IN               = 0x0261;

P7OUT              = 0x0262;

P8OUT              = 0x0263;

P7DIR              = 0x0264;

P8DIR              = 0x0265;

P7REN              = 0x0266;

P8REN              = 0x0267;

P7SEL0             = 0x026A;

P8SEL0             = 0x026B;

P7SEL1             = 0x026C;

P8SEL1             = 0x026D;

P7SELC             = 0x0276;

P8SELC             = 0x0277;

P7IES              = 0x0278;

P8IES              = 0x0279;

P7IE               = 0x027A;

P8IE               = 0x027B;

P7IFG              = 0x027C;

P8IFG              = 0x027D;



/*****************************************************************************
 DMA
*****************************************************************************/
DMACTL0            = 0x0500;
DMACTL0_L          = 0x0500;
DMACTL0_H          = 0x0501;
DMACTL1            = 0x0502;
DMACTL1_L          = 0x0502;
DMACTL1_H          = 0x0503;
DMACTL2            = 0x0504;
DMACTL2_L          = 0x0504;
DMACTL2_H          = 0x0505;
DMACTL4            = 0x0508;
DMACTL4_L          = 0x0508;
DMACTL4_H          = 0x0509;
DMAIV              = 0x050E;
DMAIV_L            = 0x050E;
DMAIV_H            = 0x050F;
DMA0CTL            = 0x0510;
DMA0CTL_L          = 0x0510;
DMA0CTL_H          = 0x0511;
DMA0SA             = 0x0512;
DMA0SAL            = 0x0512;
DMA0SAH            = 0x0514;
DMA0DA             = 0x0516;
DMA0DAL            = 0x0516;
DMA0DAH            = 0x0518;
DMA0SZ             = 0x051A;
DMA0SZ_L           = 0x051A;
DMA0SZ_H           = 0x051B;
DMA1CTL            = 0x0520;
DMA1CTL_L          = 0x0520;
DMA1CTL_H          = 0x0521;
DMA1SA             = 0x0522;
DMA1SAL            = 0x0522;
DMA1SAH            = 0x0524;
DMA1DA             = 0x0526;
DMA1DAL            = 0x0526;
DMA1DAH            = 0x0528;
DMA1SZ             = 0x052A;
DMA1SZ_L           = 0x052A;
DMA1SZ_H           = 0x052B;
DMA2CTL            = 0x0530;
DMA2CTL_L          = 0x0530;
DMA2CTL_H          = 0x0531;
DMA2SA             = 0x0532;
DMA2SAL            = 0x0532;
DMA2SAH            = 0x0534;
DMA2DA             = 0x0536;
DMA2DAL            = 0x0536;
DMA2DAH            = 0x0538;
DMA2SZ             = 0x053A;
DMA2SZ_L           = 0x053A;
DMA2SZ_H           = 0x053B;
DMA3CTL            = 0x0540;
DMA3CTL_L          = 0x0540;
DMA3CTL_H          = 0x0541;
DMA3SA             = 0x0542;
DMA3SAL            = 0x0542;
DMA3SAH            = 0x0544;
DMA3DA             = 0x0546;
DMA3DAL            = 0x0546;
DMA3DAH            = 0x0548;
DMA3SZ             = 0x054A;
DMA3SZ_L           = 0x054A;
DMA3SZ_H           = 0x054B;
DMA4CTL            = 0x0550;
DMA4CTL_L          = 0x0550;
DMA4CTL_H          = 0x0551;
DMA4SA             = 0x0552;
DMA4SAL            = 0x0552;
DMA4SAH            = 0x0554;
DMA4DA             = 0x0556;
DMA4DAL            = 0x0556;
DMA4DAH            = 0x0558;
DMA4SZ             = 0x055A;
DMA4SZ_L           = 0x055A;
DMA4SZ_H           = 0x055B;
DMA5CTL            = 0x0560;
DMA5CTL_L          = 0x0560;
DMA5CTL_H          = 0x0561;
DMA5SA             = 0x0562;
DMA5SAL            = 0x0562;
DMA5SAH            = 0x0564;
DMA5DA             = 0x0566;
DMA5DAL            = 0x0566;
DMA5DAH            = 0x0568;
DMA5SZ             = 0x056A;
DMA5SZ_L           = 0x056A;
DMA5SZ_H           = 0x056B;


/*****************************************************************************
 FRCTL_A
*****************************************************************************/
FRCTL0             = 0x0140;
FRCTL0_L           = 0x0140;
FRCTL0_H           = 0x0141;
GCCTL0             = 0x0144;
GCCTL0_L           = 0x0144;
GCCTL0_H           = 0x0145;
GCCTL1             = 0x0146;
GCCTL1_L           = 0x0146;
GCCTL1_H           = 0x0147;


/*****************************************************************************
 LEA
*****************************************************************************/
LEACAP             = 0x0A80;
LEACAPL            = 0x0A80;
LEACAPH            = 0x0A82;

LEACNF0            = 0x0A84;
LEACNF0L           = 0x0A84;
LEACNF0H           = 0x0A86;

LEACNF1            = 0x0A88;
LEACNF1L           = 0x0A88;
LEACNF1H           = 0x0A8A;

LEACNF2            = 0x0A8C;
LEACNF2L           = 0x0A8C;
LEACNF2H           = 0x0A8E;

LEAMB              = 0x0A90;
LEAMBL             = 0x0A90;
LEAMBH             = 0x0A92;

LEAMT              = 0x0A94;
LEAMTL             = 0x0A94;
LEAMTH             = 0x0A96;

LEACMA             = 0x0A98;
LEACMAL            = 0x0A98;
LEACMAH            = 0x0A9A;

LEACMCTL           = 0x0A9C;
LEACMCTLL          = 0x0A9C;
LEACMCTLH          = 0x0A9E;

LEACMDSTAT         = 0x0AA8;
LEACMDSTATL        = 0x0AA8;
LEACMDSTATH        = 0x0AAA;

LEAS1STAT          = 0x0AAC;
LEAS1STATL         = 0x0AAC;
LEAS1STATH         = 0x0AAE;

LEAS0STAT          = 0x0AB0;
LEAS0STATL         = 0x0AB0;
LEAS0STATH         = 0x0AB2;

LEADSTSTAT         = 0x0AB4;
LEADSTSTATL        = 0x0AB4;
LEADSTSTATH        = 0x0AB6;

LEAPMCTL           = 0x0AC0;
LEAPMCTLL          = 0x0AC0;
LEAPMCTLH          = 0x0AC2;

LEAPMDST           = 0x0AC4;
LEAPMDSTL          = 0x0AC4;
LEAPMDSTH          = 0x0AC6;

LEAPMS1            = 0x0AC8;
LEAPMS1L           = 0x0AC8;
LEAPMS1H           = 0x0ACA;

LEAPMS0            = 0x0ACC;
LEAPMS0L           = 0x0ACC;
LEAPMS0H           = 0x0ACE;

LEAPMCB            = 0x0AD0;
LEAPMCBL           = 0x0AD0;
LEAPMCBH           = 0x0AD2;

LEAIFGSET          = 0x0AF0;
LEAIFGSETL         = 0x0AF0;
LEAIFGSETH         = 0x0AF2;

LEAIE              = 0x0AF4;
LEAIEL             = 0x0AF4;
LEAIEH             = 0x0AF6;

LEAIFG             = 0x0AF8;
LEAIFGL            = 0x0AF8;
LEAIFGH            = 0x0AFA;

LEAIV              = 0x0AFC;
LEAIVL             = 0x0AFC;
LEAIVH             = 0x0AFE;



/*****************************************************************************
 MPU
*****************************************************************************/
MPUCTL0            = 0x05A0;
MPUCTL0_L          = 0x05A0;
MPUCTL0_H          = 0x05A1;
MPUCTL1            = 0x05A2;
MPUCTL1_L          = 0x05A2;
MPUCTL1_H          = 0x05A3;
MPUSEGB2           = 0x05A4;
MPUSEGB2_L         = 0x05A4;
MPUSEGB2_H         = 0x05A5;
MPUSEGB1           = 0x05A6;
MPUSEGB1_L         = 0x05A6;
MPUSEGB1_H         = 0x05A7;
MPUSAM             = 0x05A8;
MPUSAM_L           = 0x05A8;
MPUSAM_H           = 0x05A9;
MPUIPC0            = 0x05AA;
MPUIPC0_L          = 0x05AA;
MPUIPC0_H          = 0x05AB;
MPUIPSEGB2         = 0x05AC;
MPUIPSEGB2_L       = 0x05AC;
MPUIPSEGB2_H       = 0x05AD;
MPUIPSEGB1         = 0x05AE;
MPUIPSEGB1_L       = 0x05AE;
MPUIPSEGB1_H       = 0x05AF;


/*****************************************************************************
 MPY32
*****************************************************************************/
MPY                = 0x04C0;
MPY_L              = 0x04C0;
MPY_H              = 0x04C1;
MPYS               = 0x04C2;
MPYS_L             = 0x04C2;
MPYS_H             = 0x04C3;
MAC                = 0x04C4;
MAC_L              = 0x04C4;
MAC_H              = 0x04C5;
MACS               = 0x04C6;
MACS_L             = 0x04C6;
MACS_H             = 0x04C7;
OP2                = 0x04C8;
OP2_L              = 0x04C8;
OP2_H              = 0x04C9;
RESLO              = 0x04CA;
RESLO_L            = 0x04CA;
RESLO_H            = 0x04CB;
RESHI              = 0x04CC;
RESHI_L            = 0x04CC;
RESHI_H            = 0x04CD;
SUMEXT             = 0x04CE;
SUMEXT_L           = 0x04CE;
SUMEXT_H           = 0x04CF;
MPY32L             = 0x04D0;
MPY32L_L           = 0x04D0;
MPY32L_H           = 0x04D1;
MPY32H             = 0x04D2;
MPY32H_L           = 0x04D2;
MPY32H_H           = 0x04D3;
MPYS32L            = 0x04D4;
MPYS32L_L          = 0x04D4;
MPYS32L_H          = 0x04D5;
MPYS32H            = 0x04D6;
MPYS32H_L          = 0x04D6;
MPYS32H_H          = 0x04D7;
MAC32L             = 0x04D8;
MAC32L_L           = 0x04D8;
MAC32L_H           = 0x04D9;
MAC32H             = 0x04DA;
MAC32H_L           = 0x04DA;
MAC32H_H           = 0x04DB;
MACS32L            = 0x04DC;
MACS32L_L          = 0x04DC;
MACS32L_H          = 0x04DD;
MACS32H            = 0x04DE;
MACS32H_L          = 0x04DE;
MACS32H_H          = 0x04DF;
OP2L               = 0x04E0;
OP2L_L             = 0x04E0;
OP2L_H             = 0x04E1;
OP2H               = 0x04E2;
OP2H_L             = 0x04E2;
OP2H_H             = 0x04E3;
RES0               = 0x04E4;
RES0_L             = 0x04E4;
RES0_H             = 0x04E5;
RES1               = 0x04E6;
RES1_L             = 0x04E6;
RES1_H             = 0x04E7;
RES2               = 0x04E8;
RES2_L             = 0x04E8;
RES2_H             = 0x04E9;
RES3               = 0x04EA;
RES3_L             = 0x04EA;
RES3_H             = 0x04EB;
MPY32CTL0          = 0x04EC;
MPY32CTL0_L        = 0x04EC;
MPY32CTL0_H        = 0x04ED;


/*****************************************************************************
 PMM
*****************************************************************************/
PMMCTL0            = 0x0120;
PMMCTL0_L          = 0x0120;
PMMCTL0_H          = 0x0121;
PMMIFG             = 0x012A;
PMMIFG_L           = 0x012A;
PMMIFG_H           = 0x012B;
PM5CTL0            = 0x0130;
PM5CTL0_L          = 0x0130;
PM5CTL0_H          = 0x0131;


/*****************************************************************************
 RAMCTL
*****************************************************************************/
RCCTL0             = 0x0158;
RCCTL0_L           = 0x0158;
RCCTL0_H           = 0x0159;


/*****************************************************************************
 REF_A
*****************************************************************************/
REFCTL0            = 0x01B0;
REFCTL0_L          = 0x01B0;
REFCTL0_H          = 0x01B1;


/*****************************************************************************
 RTC_C
*****************************************************************************/
RTCCTL0            = 0x04A0;
RTCCTL0_L          = 0x04A0;
RTCCTL0_H          = 0x04A1;
RTCCTL13           = 0x04A2;
RTCCTL13_L         = 0x04A2;
RTCCTL13_H         = 0x04A3;
RTCOCAL            = 0x04A4;
RTCOCAL_L          = 0x04A4;
RTCOCAL_H          = 0x04A5;
RTCTCMP            = 0x04A6;
RTCTCMP_L          = 0x04A6;
RTCTCMP_H          = 0x04A7;
RTCPS0CTL          = 0x04A8;
RTCPS0CTL_L        = 0x04A8;
RTCPS0CTL_H        = 0x04A9;
RTCPS1CTL          = 0x04AA;
RTCPS1CTL_L        = 0x04AA;
RTCPS1CTL_H        = 0x04AB;
RTCPS              = 0x04AC;
RTCPS_L            = 0x04AC;
RTCPS_H            = 0x04AD;
RTCIV              = 0x04AE;
RTCIV_L            = 0x04AE;
RTCIV_H            = 0x04AF;
RTCTIM0            = 0x04B0;
RTCTIM0_L          = 0x04B0;
RTCTIM0_H          = 0x04B1;
RTCCNT12           = 0x04B0;
RTCCNT12_L         = 0x04B0;
RTCCNT12_H         = 0x04B1;
RTCTIM1            = 0x04B2;
RTCTIM1_L          = 0x04B2;
RTCTIM1_H          = 0x04B3;
RTCCNT34           = 0x04B2;
RTCCNT34_L         = 0x04B2;
RTCCNT34_H         = 0x04B3;
RTCDATE            = 0x04B4;
RTCDATE_L          = 0x04B4;
RTCDATE_H          = 0x04B5;
RTCYEAR            = 0x04B6;
RTCYEAR_L          = 0x04B6;
RTCYEAR_H          = 0x04B7;
RTCAMINHR          = 0x04B8;
RTCAMINHR_L        = 0x04B8;
RTCAMINHR_H        = 0x04B9;
RTCADOWDAY         = 0x04BA;
RTCADOWDAY_L       = 0x04BA;
RTCADOWDAY_H       = 0x04BB;
BIN2BCD            = 0x04BC;
BIN2BCD_L          = 0x04BC;
BIN2BCD_H          = 0x04BD;
BCD2BIN            = 0x04BE;
BCD2BIN_L          = 0x04BE;
BCD2BIN_H          = 0x04BF;
RT0PS              = 0x04AC;

RT1PS              = 0x04AD;

RTCCNT1            = 0x04B0;

RTCCNT2            = 0x04B1;

RTCCNT3            = 0x04B2;

RTCCNT4            = 0x04B3;



/*****************************************************************************
 SFR
*****************************************************************************/
SFRIE1             = 0x0100;
SFRIE1_L           = 0x0100;
SFRIE1_H           = 0x0101;
SFRIFG1            = 0x0102;
SFRIFG1_L          = 0x0102;
SFRIFG1_H          = 0x0103;
SFRRPCR            = 0x0104;
SFRRPCR_L          = 0x0104;
SFRRPCR_H          = 0x0105;


/*****************************************************************************
 SYS
*****************************************************************************/
SYSCTL             = 0x0180;
SYSCTL_L           = 0x0180;
SYSCTL_H           = 0x0181;
SYSJMBC            = 0x0186;
SYSJMBC_L          = 0x0186;
SYSJMBC_H          = 0x0187;
SYSJMBI0           = 0x0188;
SYSJMBI0_L         = 0x0188;
SYSJMBI0_H         = 0x0189;
SYSJMBI1           = 0x018A;
SYSJMBI1_L         = 0x018A;
SYSJMBI1_H         = 0x018B;
SYSJMBO0           = 0x018C;
SYSJMBO0_L         = 0x018C;
SYSJMBO0_H         = 0x018D;
SYSJMBO1           = 0x018E;
SYSJMBO1_L         = 0x018E;
SYSJMBO1_H         = 0x018F;
SYSUNIV            = 0x019A;
SYSUNIV_L          = 0x019A;
SYSUNIV_H          = 0x019B;
SYSSNIV            = 0x019C;
SYSSNIV_L          = 0x019C;
SYSSNIV_H          = 0x019D;
SYSRSTIV           = 0x019E;
SYSRSTIV_L         = 0x019E;
SYSRSTIV_H         = 0x019F;


/*****************************************************************************
 TA0
*****************************************************************************/
TA0CTL             = 0x0340;
TA0CTL_L           = 0x0340;
TA0CTL_H           = 0x0341;
TA0CCTL0           = 0x0342;
TA0CCTL0_L         = 0x0342;
TA0CCTL0_H         = 0x0343;
TA0CCTL1           = 0x0344;
TA0CCTL1_L         = 0x0344;
TA0CCTL1_H         = 0x0345;
TA0CCTL2           = 0x0346;
TA0CCTL2_L         = 0x0346;
TA0CCTL2_H         = 0x0347;
TA0R               = 0x0350;
TA0R_L             = 0x0350;
TA0R_H             = 0x0351;
TA0CCR0            = 0x0352;
TA0CCR0_L          = 0x0352;
TA0CCR0_H          = 0x0353;
TA0CCR1            = 0x0354;
TA0CCR1_L          = 0x0354;
TA0CCR1_H          = 0x0355;
TA0CCR2            = 0x0356;
TA0CCR2_L          = 0x0356;
TA0CCR2_H          = 0x0357;
TA0EX0             = 0x0360;
TA0EX0_L           = 0x0360;
TA0EX0_H           = 0x0361;
TA0IV              = 0x036E;
TA0IV_L            = 0x036E;
TA0IV_H            = 0x036F;


/*****************************************************************************
 TA1
*****************************************************************************/
TA1CTL             = 0x0380;
TA1CTL_L           = 0x0380;
TA1CTL_H           = 0x0381;
TA1CCTL0           = 0x0382;
TA1CCTL0_L         = 0x0382;
TA1CCTL0_H         = 0x0383;
TA1CCTL1           = 0x0384;
TA1CCTL1_L         = 0x0384;
TA1CCTL1_H         = 0x0385;
TA1CCTL2           = 0x0386;
TA1CCTL2_L         = 0x0386;
TA1CCTL2_H         = 0x0387;
TA1R               = 0x0390;
TA1R_L             = 0x0390;
TA1R_H             = 0x0391;
TA1CCR0            = 0x0392;
TA1CCR0_L          = 0x0392;
TA1CCR0_H          = 0x0393;
TA1CCR1            = 0x0394;
TA1CCR1_L          = 0x0394;
TA1CCR1_H          = 0x0395;
TA1CCR2            = 0x0396;
TA1CCR2_L          = 0x0396;
TA1CCR2_H          = 0x0397;
TA1EX0             = 0x03A0;
TA1EX0_L           = 0x03A0;
TA1EX0_H           = 0x03A1;
TA1IV              = 0x03AE;
TA1IV_L            = 0x03AE;
TA1IV_H            = 0x03AF;


/*****************************************************************************
 TA2
*****************************************************************************/
TA2CTL             = 0x0400;
TA2CTL_L           = 0x0400;
TA2CTL_H           = 0x0401;
TA2CCTL0           = 0x0402;
TA2CCTL0_L         = 0x0402;
TA2CCTL0_H         = 0x0403;
TA2CCTL1           = 0x0404;
TA2CCTL1_L         = 0x0404;
TA2CCTL1_H         = 0x0405;
TA2R               = 0x0410;
TA2R_L             = 0x0410;
TA2R_H             = 0x0411;
TA2CCR0            = 0x0412;
TA2CCR0_L          = 0x0412;
TA2CCR0_H          = 0x0413;
TA2CCR1            = 0x0414;
TA2CCR1_L          = 0x0414;
TA2CCR1_H          = 0x0415;
TA2EX0             = 0x0420;
TA2EX0_L           = 0x0420;
TA2EX0_H           = 0x0421;
TA2IV              = 0x042E;
TA2IV_L            = 0x042E;
TA2IV_H            = 0x042F;


/*****************************************************************************
 TA3
*****************************************************************************/
TA3CTL             = 0x0440;
TA3CTL_L           = 0x0440;
TA3CTL_H           = 0x0441;
TA3CCTL0           = 0x0442;
TA3CCTL0_L         = 0x0442;
TA3CCTL0_H         = 0x0443;
TA3CCTL1           = 0x0444;
TA3CCTL1_L         = 0x0444;
TA3CCTL1_H         = 0x0445;
TA3R               = 0x0450;
TA3R_L             = 0x0450;
TA3R_H             = 0x0451;
TA3CCR0            = 0x0452;
TA3CCR0_L          = 0x0452;
TA3CCR0_H          = 0x0453;
TA3CCR1            = 0x0454;
TA3CCR1_L          = 0x0454;
TA3CCR1_H          = 0x0455;
TA3EX0             = 0x0460;
TA3EX0_L           = 0x0460;
TA3EX0_H           = 0x0461;
TA3IV              = 0x046E;
TA3IV_L            = 0x046E;
TA3IV_H            = 0x046F;


/*****************************************************************************
 TA4
*****************************************************************************/
TA4CTL             = 0x07C0;
TA4CTL_L           = 0x07C0;
TA4CTL_H           = 0x07C1;
TA4CCTL0           = 0x07C2;
TA4CCTL0_L         = 0x07C2;
TA4CCTL0_H         = 0x07C3;
TA4CCTL1           = 0x07C4;
TA4CCTL1_L         = 0x07C4;
TA4CCTL1_H         = 0x07C5;
TA4CCTL2           = 0x07C6;
TA4CCTL2_L         = 0x07C6;
TA4CCTL2_H         = 0x07C7;
TA4R               = 0x07D0;
TA4R_L             = 0x07D0;
TA4R_H             = 0x07D1;
TA4CCR0            = 0x07D2;
TA4CCR0_L          = 0x07D2;
TA4CCR0_H          = 0x07D3;
TA4CCR1            = 0x07D4;
TA4CCR1_L          = 0x07D4;
TA4CCR1_H          = 0x07D5;
TA4CCR2            = 0x07D6;
TA4CCR2_L          = 0x07D6;
TA4CCR2_H          = 0x07D7;
TA4EX0             = 0x07E0;
TA4EX0_L           = 0x07E0;
TA4EX0_H           = 0x07E1;
TA4IV              = 0x07EE;
TA4IV_L            = 0x07EE;
TA4IV_H            = 0x07EF;


/*****************************************************************************
 TB0
*****************************************************************************/
TB0CTL             = 0x03C0;
TB0CTL_L           = 0x03C0;
TB0CTL_H           = 0x03C1;
TB0CCTL0           = 0x03C2;
TB0CCTL0_L         = 0x03C2;
TB0CCTL0_H         = 0x03C3;
TB0CCTL1           = 0x03C4;
TB0CCTL1_L         = 0x03C4;
TB0CCTL1_H         = 0x03C5;
TB0CCTL2           = 0x03C6;
TB0CCTL2_L         = 0x03C6;
TB0CCTL2_H         = 0x03C7;
TB0CCTL3           = 0x03C8;
TB0CCTL3_L         = 0x03C8;
TB0CCTL3_H         = 0x03C9;
TB0CCTL4           = 0x03CA;
TB0CCTL4_L         = 0x03CA;
TB0CCTL4_H         = 0x03CB;
TB0CCTL5           = 0x03CC;
TB0CCTL5_L         = 0x03CC;
TB0CCTL5_H         = 0x03CD;
TB0CCTL6           = 0x03CE;
TB0CCTL6_L         = 0x03CE;
TB0CCTL6_H         = 0x03CF;
TB0R               = 0x03D0;
TB0R_L             = 0x03D0;
TB0R_H             = 0x03D1;
TB0CCR0            = 0x03D2;
TB0CCR0_L          = 0x03D2;
TB0CCR0_H          = 0x03D3;
TB0CCR1            = 0x03D4;
TB0CCR1_L          = 0x03D4;
TB0CCR1_H          = 0x03D5;
TB0CCR2            = 0x03D6;
TB0CCR2_L          = 0x03D6;
TB0CCR2_H          = 0x03D7;
TB0CCR3            = 0x03D8;
TB0CCR3_L          = 0x03D8;
TB0CCR3_H          = 0x03D9;
TB0CCR4            = 0x03DA;
TB0CCR4_L          = 0x03DA;
TB0CCR4_H          = 0x03DB;
TB0CCR5            = 0x03DC;
TB0CCR5_L          = 0x03DC;
TB0CCR5_H          = 0x03DD;
TB0CCR6            = 0x03DE;
TB0CCR6_L          = 0x03DE;
TB0CCR6_H          = 0x03DF;
TB0EX0             = 0x03E0;
TB0EX0_L           = 0x03E0;
TB0EX0_H           = 0x03E1;
TB0IV              = 0x03EE;
TB0IV_L            = 0x03EE;
TB0IV_H            = 0x03EF;


/*****************************************************************************
 WDT_A
*****************************************************************************/
WDTCTL             = 0x015C;
WDTCTL_L           = 0x015C;
WDTCTL_H           = 0x015D;


/*****************************************************************************
 eUSCI_A0
*****************************************************************************/
UCA0CTLW0          = 0x05C0;
UCA0CTLW0_L        = 0x05C0;
UCA0CTLW0_H        = 0x05C1;
UCA0CTLW1          = 0x05C2;
UCA0CTLW1_L        = 0x05C2;
UCA0CTLW1_H        = 0x05C3;
UCA0BRW            = 0x05C6;
UCA0BRW_L          = 0x05C6;
UCA0BRW_H          = 0x05C7;
UCA0MCTLW          = 0x05C8;
UCA0MCTLW_L        = 0x05C8;
UCA0MCTLW_H        = 0x05C9;
UCA0STATW          = 0x05CA;
UCA0STATW_L        = 0x05CA;
UCA0STATW_H        = 0x05CB;
UCA0RXBUF          = 0x05CC;
UCA0RXBUF_L        = 0x05CC;
UCA0RXBUF_H        = 0x05CD;
UCA0TXBUF          = 0x05CE;
UCA0TXBUF_L        = 0x05CE;
UCA0TXBUF_H        = 0x05CF;
UCA0ABCTL          = 0x05D0;
UCA0ABCTL_L        = 0x05D0;
UCA0ABCTL_H        = 0x05D1;
UCA0IRCTL          = 0x05D2;
UCA0IRCTL_L        = 0x05D2;
UCA0IRCTL_H        = 0x05D3;
UCA0IE             = 0x05DA;
UCA0IE_L           = 0x05DA;
UCA0IE_H           = 0x05DB;
UCA0IFG            = 0x05DC;
UCA0IFG_L          = 0x05DC;
UCA0IFG_H          = 0x05DD;
UCA0IV             = 0x05DE;
UCA0IV_L           = 0x05DE;
UCA0IV_H           = 0x05DF;


/*****************************************************************************
 eUSCI_A1
*****************************************************************************/
UCA1CTLW0          = 0x05E0;
UCA1CTLW0_L        = 0x05E0;
UCA1CTLW0_H        = 0x05E1;
UCA1CTLW1          = 0x05E2;
UCA1CTLW1_L        = 0x05E2;
UCA1CTLW1_H        = 0x05E3;
UCA1BRW            = 0x05E6;
UCA1BRW_L          = 0x05E6;
UCA1BRW_H          = 0x05E7;
UCA1MCTLW          = 0x05E8;
UCA1MCTLW_L        = 0x05E8;
UCA1MCTLW_H        = 0x05E9;
UCA1STATW          = 0x05EA;
UCA1STATW_L        = 0x05EA;
UCA1STATW_H        = 0x05EB;
UCA1RXBUF          = 0x05EC;
UCA1RXBUF_L        = 0x05EC;
UCA1RXBUF_H        = 0x05ED;
UCA1TXBUF          = 0x05EE;
UCA1TXBUF_L        = 0x05EE;
UCA1TXBUF_H        = 0x05EF;
UCA1ABCTL          = 0x05F0;
UCA1ABCTL_L        = 0x05F0;
UCA1ABCTL_H        = 0x05F1;
UCA1IRCTL          = 0x05F2;
UCA1IRCTL_L        = 0x05F2;
UCA1IRCTL_H        = 0x05F3;
UCA1IE             = 0x05FA;
UCA1IE_L           = 0x05FA;
UCA1IE_H           = 0x05FB;
UCA1IFG            = 0x05FC;
UCA1IFG_L          = 0x05FC;
UCA1IFG_H          = 0x05FD;
UCA1IV             = 0x05FE;
UCA1IV_L           = 0x05FE;
UCA1IV_H           = 0x05FF;


/*****************************************************************************
 eUSCI_A2
*****************************************************************************/
UCA2CTLW0          = 0x0600;
UCA2CTLW0_L        = 0x0600;
UCA2CTLW0_H        = 0x0601;
UCA2CTLW1          = 0x0602;
UCA2CTLW1_L        = 0x0602;
UCA2CTLW1_H        = 0x0603;
UCA2BRW            = 0x0606;
UCA2BRW_L          = 0x0606;
UCA2BRW_H          = 0x0607;
UCA2MCTLW          = 0x0608;
UCA2MCTLW_L        = 0x0608;
UCA2MCTLW_H        = 0x0609;
UCA2STATW          = 0x060A;
UCA2STATW_L        = 0x060A;
UCA2STATW_H        = 0x060B;
UCA2RXBUF          = 0x060C;
UCA2RXBUF_L        = 0x060C;
UCA2RXBUF_H        = 0x060D;
UCA2TXBUF          = 0x060E;
UCA2TXBUF_L        = 0x060E;
UCA2TXBUF_H        = 0x060F;
UCA2ABCTL          = 0x0610;
UCA2ABCTL_L        = 0x0610;
UCA2ABCTL_H        = 0x0611;
UCA2IRCTL          = 0x0612;
UCA2IRCTL_L        = 0x0612;
UCA2IRCTL_H        = 0x0613;
UCA2IE             = 0x061A;
UCA2IE_L           = 0x061A;
UCA2IE_H           = 0x061B;
UCA2IFG            = 0x061C;
UCA2IFG_L          = 0x061C;
UCA2IFG_H          = 0x061D;
UCA2IV             = 0x061E;
UCA2IV_L           = 0x061E;
UCA2IV_H           = 0x061F;


/*****************************************************************************
 eUSCI_A3
*****************************************************************************/
UCA3CTLW0          = 0x0620;
UCA3CTLW0_L        = 0x0620;
UCA3CTLW0_H        = 0x0621;
UCA3CTLW1          = 0x0622;
UCA3CTLW1_L        = 0x0622;
UCA3CTLW1_H        = 0x0623;
UCA3BRW            = 0x0626;
UCA3BRW_L          = 0x0626;
UCA3BRW_H          = 0x0627;
UCA3MCTLW          = 0x0628;
UCA3MCTLW_L        = 0x0628;
UCA3MCTLW_H        = 0x0629;
UCA3STATW          = 0x062A;
UCA3STATW_L        = 0x062A;
UCA3STATW_H        = 0x062B;
UCA3RXBUF          = 0x062C;
UCA3RXBUF_L        = 0x062C;
UCA3RXBUF_H        = 0x062D;
UCA3TXBUF          = 0x062E;
UCA3TXBUF_L        = 0x062E;
UCA3TXBUF_H        = 0x062F;
UCA3ABCTL          = 0x0630;
UCA3ABCTL_L        = 0x0630;
UCA3ABCTL_H        = 0x0631;
UCA3IRCTL          = 0x0632;
UCA3IRCTL_L        = 0x0632;
UCA3IRCTL_H        = 0x0633;
UCA3IE             = 0x063A;
UCA3IE_L           = 0x063A;
UCA3IE_H           = 0x063B;
UCA3IFG            = 0x063C;
UCA3IFG_L          = 0x063C;
UCA3IFG_H          = 0x063D;
UCA3IV             = 0x063E;
UCA3IV_L           = 0x063E;
UCA3IV_H           = 0x063F;


/*****************************************************************************
 eUSCI_B0
*****************************************************************************/
UCB0CTLW0          = 0x0640;
UCB0CTLW0_L        = 0x0640;
UCB0CTLW0_H        = 0x0641;
UCB0CTLW1          = 0x0642;
UCB0CTLW1_L        = 0x0642;
UCB0CTLW1_H        = 0x0643;
UCB0BRW            = 0x0646;
UCB0BRW_L          = 0x0646;
UCB0BRW_H          = 0x0647;
UCB0STATW          = 0x0648;
UCB0STATW_L        = 0x0648;
UCB0STATW_H        = 0x0649;
UCB0TBCNT          = 0x064A;
UCB0TBCNT_L        = 0x064A;
UCB0TBCNT_H        = 0x064B;
UCB0RXBUF          = 0x064C;
UCB0RXBUF_L        = 0x064C;
UCB0RXBUF_H        = 0x064D;
UCB0TXBUF          = 0x064E;
UCB0TXBUF_L        = 0x064E;
UCB0TXBUF_H        = 0x064F;
UCB0I2COA0         = 0x0654;
UCB0I2COA0_L       = 0x0654;
UCB0I2COA0_H       = 0x0655;
UCB0I2COA1         = 0x0656;
UCB0I2COA1_L       = 0x0656;
UCB0I2COA1_H       = 0x0657;
UCB0I2COA2         = 0x0658;
UCB0I2COA2_L       = 0x0658;
UCB0I2COA2_H       = 0x0659;
UCB0I2COA3         = 0x065A;
UCB0I2COA3_L       = 0x065A;
UCB0I2COA3_H       = 0x065B;
UCB0ADDRX          = 0x065C;
UCB0ADDRX_L        = 0x065C;
UCB0ADDRX_H        = 0x065D;
UCB0ADDMASK        = 0x065E;
UCB0ADDMASK_L      = 0x065E;
UCB0ADDMASK_H      = 0x065F;
UCB0I2CSA          = 0x0660;
UCB0I2CSA_L        = 0x0660;
UCB0I2CSA_H        = 0x0661;
UCB0IE             = 0x066A;
UCB0IE_L           = 0x066A;
UCB0IE_H           = 0x066B;
UCB0IFG            = 0x066C;
UCB0IFG_L          = 0x066C;
UCB0IFG_H          = 0x066D;
UCB0IV             = 0x066E;
UCB0IV_L           = 0x066E;
UCB0IV_H           = 0x066F;


/*****************************************************************************
 eUSCI_B1
*****************************************************************************/
UCB1CTLW0          = 0x0680;
UCB1CTLW0_L        = 0x0680;
UCB1CTLW0_H        = 0x0681;
UCB1CTLW1          = 0x0682;
UCB1CTLW1_L        = 0x0682;
UCB1CTLW1_H        = 0x0683;
UCB1BRW            = 0x0686;
UCB1BRW_L          = 0x0686;
UCB1BRW_H          = 0x0687;
UCB1STATW          = 0x0688;
UCB1STATW_L        = 0x0688;
UCB1STATW_H        = 0x0689;
UCB1TBCNT          = 0x068A;
UCB1TBCNT_L        = 0x068A;
UCB1TBCNT_H        = 0x068B;
UCB1RXBUF          = 0x068C;
UCB1RXBUF_L        = 0x068C;
UCB1RXBUF_H        = 0x068D;
UCB1TXBUF          = 0x068E;
UCB1TXBUF_L        = 0x068E;
UCB1TXBUF_H        = 0x068F;
UCB1I2COA0         = 0x0694;
UCB1I2COA0_L       = 0x0694;
UCB1I2COA0_H       = 0x0695;
UCB1I2COA1         = 0x0696;
UCB1I2COA1_L       = 0x0696;
UCB1I2COA1_H       = 0x0697;
UCB1I2COA2         = 0x0698;
UCB1I2COA2_L       = 0x0698;
UCB1I2COA2_H       = 0x0699;
UCB1I2COA3         = 0x069A;
UCB1I2COA3_L       = 0x069A;
UCB1I2COA3_H       = 0x069B;
UCB1ADDRX          = 0x069C;
UCB1ADDRX_L        = 0x069C;
UCB1ADDRX_H        = 0x069D;
UCB1ADDMASK        = 0x069E;
UCB1ADDMASK_L      = 0x069E;
UCB1ADDMASK_H      = 0x069F;
UCB1I2CSA          = 0x06A0;
UCB1I2CSA_L        = 0x06A0;
UCB1I2CSA_H        = 0x06A1;
UCB1IE             = 0x06AA;
UCB1IE_L           = 0x06AA;
UCB1IE_H           = 0x06AB;
UCB1IFG            = 0x06AC;
UCB1IFG_L          = 0x06AC;
UCB1IFG_H          = 0x06AD;
UCB1IV             = 0x06AE;
UCB1IV_L           = 0x06AE;
UCB1IV_H           = 0x06AF;


/*****************************************************************************
 eUSCI_B2
*****************************************************************************/
UCB2CTLW0          = 0x06C0;
UCB2CTLW0_L        = 0x06C0;
UCB2CTLW0_H        = 0x06C1;
UCB2CTLW1          = 0x06C2;
UCB2CTLW1_L        = 0x06C2;
UCB2CTLW1_H        = 0x06C3;
UCB2BRW            = 0x06C6;
UCB2BRW_L          = 0x06C6;
UCB2BRW_H          = 0x06C7;
UCB2STATW          = 0x06C8;
UCB2STATW_L        = 0x06C8;
UCB2STATW_H        = 0x06C9;
UCB2TBCNT          = 0x06CA;
UCB2TBCNT_L        = 0x06CA;
UCB2TBCNT_H        = 0x06CB;
UCB2RXBUF          = 0x06CC;
UCB2RXBUF_L        = 0x06CC;
UCB2RXBUF_H        = 0x06CD;
UCB2TXBUF          = 0x06CE;
UCB2TXBUF_L        = 0x06CE;
UCB2TXBUF_H        = 0x06CF;
UCB2I2COA0         = 0x06D4;
UCB2I2COA0_L       = 0x06D4;
UCB2I2COA0_H       = 0x06D5;
UCB2I2COA1         = 0x06D6;
UCB2I2COA1_L       = 0x06D6;
UCB2I2COA1_H       = 0x06D7;
UCB2I2COA2         = 0x06D8;
UCB2I2COA2_L       = 0x06D8;
UCB2I2COA2_H       = 0x06D9;
UCB2I2COA3         = 0x06DA;
UCB2I2COA3_L       = 0x06DA;
UCB2I2COA3_H       = 0x06DB;
UCB2ADDRX          = 0x06DC;
UCB2ADDRX_L        = 0x06DC;
UCB2ADDRX_H        = 0x06DD;
UCB2ADDMASK        = 0x06DE;
UCB2ADDMASK_L      = 0x06DE;
UCB2ADDMASK_H      = 0x06DF;
UCB2I2CSA          = 0x06E0;
UCB2I2CSA_L        = 0x06E0;
UCB2I2CSA_H        = 0x06E1;
UCB2IE             = 0x06EA;
UCB2IE_L           = 0x06EA;
UCB2IE_H           = 0x06EB;
UCB2IFG            = 0x06EC;
UCB2IFG_L          = 0x06EC;
UCB2IFG_H          = 0x06ED;
UCB2IV             = 0x06EE;
UCB2IV_L           = 0x06EE;
UCB2IV_H           = 0x06EF;


/*****************************************************************************
 eUSCI_B3
*****************************************************************************/
UCB3CTLW0          = 0x0700;
UCB3CTLW0_L        = 0x0700;
UCB3CTLW0_H        = 0x0701;
UCB3CTLW1          = 0x0702;
UCB3CTLW1_L        = 0x0702;
UCB3CTLW1_H        = 0x0703;
UCB3BRW            = 0x0706;
UCB3BRW_L          = 0x0706;
UCB3BRW_H          = 0x0707;
UCB3STATW          = 0x0708;
UCB3STATW_L        = 0x0708;
UCB3STATW_H        = 0x0709;
UCB3TBCNT          = 0x070A;
UCB3TBCNT_L        = 0x070A;
UCB3TBCNT_H        = 0x070B;
UCB3RXBUF          = 0x070C;
UCB3RXBUF_L        = 0x070C;
UCB3RXBUF_H        = 0x070D;
UCB3TXBUF          = 0x070E;
UCB3TXBUF_L        = 0x070E;
UCB3TXBUF_H        = 0x070F;
UCB3I2COA0         = 0x0714;
UCB3I2COA0_L       = 0x0714;
UCB3I2COA0_H       = 0x0715;
UCB3I2COA1         = 0x0716;
UCB3I2COA1_L       = 0x0716;
UCB3I2COA1_H       = 0x0717;
UCB3I2COA2         = 0x0718;
UCB3I2COA2_L       = 0x0718;
UCB3I2COA2_H       = 0x0719;
UCB3I2COA3         = 0x071A;
UCB3I2COA3_L       = 0x071A;
UCB3I2COA3_H       = 0x071B;
UCB3ADDRX          = 0x071C;
UCB3ADDRX_L        = 0x071C;
UCB3ADDRX_H        = 0x071D;
UCB3ADDMASK        = 0x071E;
UCB3ADDMASK_L      = 0x071E;
UCB3ADDMASK_H      = 0x071F;
UCB3I2CSA          = 0x0720;
UCB3I2CSA_L        = 0x0720;
UCB3I2CSA_H        = 0x0721;
UCB3IE             = 0x072A;
UCB3IE_L           = 0x072A;
UCB3IE_H           = 0x072B;
UCB3IFG            = 0x072C;
UCB3IFG_L          = 0x072C;
UCB3IFG_H          = 0x072D;
UCB3IV             = 0x072E;
UCB3IV_L           = 0x072E;
UCB3IV_H           = 0x072F;


/****************************************************************
* End of Modules
****************************************************************/

