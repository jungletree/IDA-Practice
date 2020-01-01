#include "idc.idc"

static main() {
  auto x,FBin,ProcRange;

HideJunkCode();

PatchJunkCode();

AnalyzeArea (MinEA(),MaxEA());
		}

static PatchJunkCode() {
  auto x,FBin,ProcRange;

FBin = "E8 0A 00 00 00 E8 EB 0C 00 00 E8 F6 FF FF FF";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){

x = x +5;
PatchByte (x,0x90);
x = x + 3 ;
PatchByte (x,0x90);
x++;
PatchWord (x,0x9090);
x =x +2 ;
PatchDword (x,0x90909090);

										}

FBin = "74 04 75 02 EB 02 EB 01 81";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){

x = x + 4;
PatchWord (x,0x9090);
x = x + 4;
PatchByte (x,0x90);

										}

FBin = "50 E8 02 00 00 00 29 5A 58 6B C0 03 E8 02 00 00 00 29 5A 83 C4 04";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){

x = x + 6;
PatchWord (x,0x9090);
x = x + 11;
PatchWord (x,0x9090);
										}

FBin = "EB 01 68 EB 02 CD 20 EB 01 E8";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){

x = x+2;
PatchByte (x,0x90);
x = x+3;
PatchWord (x,0x9090);
x = x+4;
PatchByte (x,0x90);
										}
		}

static HideJunkCode() {
  auto x,y,FBin;

FBin = "E8 0A 00 00 00 E8 EB 0C 00 00 E8 F6 FF FF FF";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){
MakeUnknown (x,0x17,1);
y = x + 0x17;
HideArea (x,y,atoa(x),atoa(x),atoa(y),-1);

										}

FBin = "74 04 75 02 EB 02 EB 01 81";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){
MakeUnknown (x,0x09,1);
y = x + 0x09;
HideArea (x,y,atoa(x),atoa(x),atoa(y),-1);

										}

FBin = "50 E8 02 00 00 00 29 5A 58 6B C0 03 E8 02 00 00 00 29 5A 83 C4 04";

for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){
MakeUnknown (x,0x17,1);
y = x + 0x17;
HideArea (x,y,atoa(x),atoa(x),atoa(y),-1);

										}


FBin = "EB 01 68 EB 02 CD 20 EB 01 E8";
for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin)){
MakeUnknown (x,0x0a,1);
y = x + 0x0a;
HideArea (x,y,atoa(x),atoa(x),atoa(y),-1);
										}
}

