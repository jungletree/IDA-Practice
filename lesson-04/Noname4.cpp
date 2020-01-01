static PatchJunkCode() 
{
    auto x,FBin,ProcRange;

	FBin = "E8 0A 00 00 00 E8 EB 0C 00 00 E8 F6 FF FF FF";
	//花指令1的特征码
	for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin))
	{
		x=x+5; //E8
		PatchByte (x,0x90);
		x = x + 3; //00
		PatchByte (x,0x90);
		x++;  //00 E8
		PatchWord (x,0x9090);
		x =x +2 ; //F6 FF FF FF
		PatchDword (x,0x90909090);
	}

	FBin = "74 04 75 02 EB 02 EB 01 81";
	// 花指令2的特征码
	for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin))
	{
		x = x + 4; //EB 02
		PatchWord (x,0x9090);
		x = x + 4; //81
		PatchByte (x,0x90);
	}

	FBin = "50 E8 02 00 00 00 29 5A 58 6B C0 03 E8 02 00 00 00 29 5A 83 C4 04";
	// 花指令3的特征码
	for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin))
	{
		x = x + 6;//29 5A
		PatchWord (x,0x9090);
		x = x + 11; //29 5A
		PatchWord (x,0x9090);
	}

	FBin = "EB 01 68 EB 02 CD 20 EB 01 E8";
	for (x = FindBinary(MinEA(),0x03,FBin);x != BADADDR;x = FindBinary(x,0x03,FBin))
	{
		x = x+2; //68
		PathByte (x,0x90);
		x = x+3;  //CD 20
		PatchWord (x,0x9090);
		x = x+4;  //E8
		PatchByte (x,0x90);
	}
}
