/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//eXtended INI Processor Test Filterscript
//
//Version:1.0
//
//License:Public Domain
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define FILTERSCRIPT
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <a_samp>

#define INI_DISABLE_CASE_SENSITIVITY
#include <eINI>
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
public OnFilterScriptInit()
{
	print("\n--------------------------------------");
	print(" eINI Test Filterscript");
	print("--------------------------------------\n");
	new INI:handle1=INI::OpenINI("Small.ini",INI_READ);
	if(INI::IsValidHandle(handle1))
	{
	    INI::ParseINI(handle1,"Load_%s",true);
		INI::WriteBuffer(handle1);
		INI::CloseINI(handle1,false); //False because we have already saved
	}
	else
	{
	    print("COULD NOT LOAD Small.ini");
	}
	
	new INI:handle2 = INI::OpenINI("Medium.ini",INI_READ);
	if(INI::IsValidHandle(handle2))
	{
		INI::DumpINI(handle2);
		INI::CloseINI(handle2);
	}
	
	handle1 = INI::CreateINI("NewFile.ini");
	if(INI::IsValidHandle(handle1))
	{
	    new arr[5] = {1,2,3,4,5};
		INI::WriteString(handle1,"MyValue","MyKey","MySection");
		INI::WriteBool(handle1,true,"MyBool","BoolSection");
		INI::WriteInteger(handle1,123,"MyInt","IntSection");
		INI::WriteFloat(handle1,2.333,"MyFloat","FloatSection");
		INI::WriteHex(handle1,15,"MyHex","HexSection");
		INI::WriteBinary(handle1,25,"MyBin","BinSection");
		INI::WriteArray(handle1,arr,"MyArr","ArrSection");
		INI::WriteFormat(handle1,0,"iTs",123,"FKey1int",true,"FKeyBool","eINI","FKeyStr");
	}
	handle2=INI::OpenINI("Large.ini",INI_READ);
	if(INI::IsValidHandle(handle2))
	{
	    new result[64],Int,Int2,Int3,Int4,Float:flt,Float:flt2,bool:bl,arr[100],dest[100];
	    INI::ReadString(handle2,result,"key1","Large1");
	    INI::ReadBool(handle2,bl,"tru","Bools");
	    INI::ReadInteger(handle2,Int,"","",4);
	    INI::ReadFloat(handle2,flt,"keyflt","",-1,1);
	    INI::ReadHex(handle2,Int2,"keyL");
	    INI::ReadBinary(handle2,Int3,"bin");
	    INI::ReadArray(handle2,arr,"IntArray","ARRAY");
	    INI::ReadFormat(handle2,6,"fis",flt2,"float",Int4,"int",arr,"replace");
	    INI::Replace(arr,dest,"ReplaceFunc");
	    printf("key1 of Large1 has value: %s",result);
	    printf("tru of Large1 has value: %d",bl);
	    printf("KeyID 4 of Large.ini has value: %d",Int);
	    printf("keyflt of section id 1 has value: %f",flt);
	    printf("keyL of global section has value: %d",Int2);
	    printf("bin of global section has value: %d",Int3);
	    printf("int of section id 6 has value: %d",Int4);
	    printf("float of section id 6 has value: %f",flt2);
	    printf("replace of section id 6 has value after replacement: %s",dest);
	}
	INI::CloseINI(handle1);
	INI::CloseINI(handle2);
	handle2=INI::OpenINI("Large2.ini",INI_WRITE);
	if(INI::IsValidHandle(handle2))
	{
		INI::DeleteSection(handle2,"BOOLS");
		INI::DeleteKey(handle2,"key2","MED1");
		new res[32],id =	INI::GetSectionID(handle2,"LARGE1");
		INI::GetSectionName(handle2,res,id);
		printf("LARGE1 Section Name: %s",res);
		
		INI::WriteString(handle1,"This key was edited by eINI","key1","",-1,5);
		
		id =	INI::GetKeyID(handle2,"key5","LARGE1");
		INI::GetKeyName(handle2,res,id);
		printf("LARGE1 key5 Key Name: %s",res);
		
	}
	INI::CloseINI(handle2);
	return 1;
}
forward ReplaceFunc(const text[]);
forward Load_(const key[],const value[]);
forward Load_SMALL1(const key[],const value[]);
forward Load_SMALL2(const key[],const value[]);
public ReplaceFunc(const text[])
{
	return 50;
}
public Load_(const key[],const value[]) //Global Section of SMALL.INI
{
	printf("Global Key from Small.ini Key:%s Value:%s",key,value);
	return 1;
}
public Load_SMALL1(const key[],const value[]) 
{
    printf("Key from small.ini Key:%s Value:%s",key,value);
	return 1;
}
public Load_SMALL2(const key[],const value[]) 
{
    printf("Key from small.ini Key:%s Value:%s",key,value);
	return 1;
}

