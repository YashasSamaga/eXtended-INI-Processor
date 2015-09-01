/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//eXtended INI Processor
//
//Known as eINI in short, is an INI File Processor, which parses any INI File which follows the required
//standards and makes reading, writing and many other INI related manipulations easier.
//
//Version:1.1
//
//License:
//Copyright (C) <2015>  <Yashas Samaga>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//Credits:
//Yashas <yashas_2010@yahoo.com>
//
//Thanks to:
//Y_Less,Dracoblue,Slick,Neufox and everyone else for their INI Readers which helped me a lot
//Slice,Y_Less and many others who used to amaze me every time
//
//Special Thanks to:
//Y_Less a.k.a Alex "Y_Less" Cole
//Kye/Kalcor & the whole SA-MP Team
//Thiadmer for PAWN
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 native INI:INI::CreateINI(const fname[]);
 native INI:INI::OpenINI(const fname[],mode=INI_READ_WRITE);
 native _:INI::IsValidHandle(INI:handle);
 native _:INI::CloseINI(INI:filehandle,bool:savebuffer=true);
 native _:INI::WriteBuffer(INI:filehandle);
 native _:INI::ParseINI(INI:filehandle,const LoadFunction[] = "",bool:dynamic=false,extra=0,bool:pass_extra=false,bool:func_with_key=false);
 native
 native _:INI::ReadString(INI:filehandle,result[],const key[],const section[],keyid=-1,sectionid=-1,result_size=sizeof(result),section_size=sizeof(section),key_size=sizeof(key))
 native _:INI::ReadBool(INI:filehandle,&bool:variable,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadInteger(INI:filehandle,&variable,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadFloat(INI:filehandle,&Float:variable,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadHex(INI:filehandle,&variable,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadBinary(INI:filehandle,&variable,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadArray(INI:filehandle,array[],const key[]="",const section[]="",keyid=-1,sectionid=-1,array_size=sizeof(array),section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadEnum(INI:filehandle,enum_entity[],enum_size,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::ReadFormat(INI:filehandle,sectionid,const format[],{Float,_}:...);
 native _:INI::Replace(const src[],dest[],const ReplacementFunction[]="",extra=0,bool:pass_extra=false,sz=sizeof(src),sz_dest=sizeof(dest),sz_rf=sizeof(ReplacementFunction));
 native _:INI::SetReplacementString(src[]);
 native
 native _:INI::WriteString(INI:filehandle,const data[],const key[],const section[],keyid=-1,sectionid=-1,data_size=sizeof(data),section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteBool(INI:filehandle,bool:variable,const key[],const section[],keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteInteger(INI:filehandle,variable,const key[],const section[],keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteFloat(INI:filehandle,Float:variable,const key[],const section[],keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteHex(INI:filehandle,variable,const key[],const section[],keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteBinary(INI:filehandle,variable,const key[],const section[],keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteArray(INI:filehandle,array[],const key[]="",const section[]="",keyid=-1,sectionid=-1,array_size=sizeof(array),section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteEnum(INI:filehandle,enum_entity[],enum_size,const key[]="",const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::WriteFormat(INI:filehandle,sectionid,const format[],{Float,_}:...);
 native
 native _:INI::DeleteSection(INI:filehandle,const section[]="",sectionid=-1,section_size=sizeof(section));
 native _:INI::DeleteKey(INI:filehandle,const key[],const section[]="",keyid=-1,sectionid=-1,key_size=sizeof(key),section_size=sizeof(section));
 native _:INI::GetSectionID(INI:filehandle,const section[],section_size=sizeof(section));
 native _:INI::GetKeyID(INI:filehandle,const key[],const section[]="",sectionid=-1,section_size=sizeof(section),key_size=sizeof(key));
 native _:INI::GetSectionName(INI:filehandle,result[],sectionid,result_size=sizeof(result));
 native _:INI::GetKeyName(INI:filehandle,result[],keyid,result_size=sizeof(result));
 native _:INI::DumpINI(INI:filehandle);
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//#define INI_CAREFUL_MODE //define to enable Careful Mode
//#define INI_LIBERAL_MODE //define to enable liberal mode
//#define INI_ASSUME_FORMATTED_INI //define to enable assume formatted mode

//#define INI_DISABLE_CASE_SENSITIVITY

//#define INI_DISABLE_WARNINGS //define to disable warnings
//#define INI_DISABLE_ERRORS //define to disable warnings
//#define INI_DISABLE_NOTICES //define to disable warnings

//#define INI_ENABLE_WHITESPACE //define to enable whitespaces in names
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined __INCLUDED_EINI__
	#endinput
#endif
#define __INCLUDED_EINI__
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined INI::
	#undef INI
#endif
#define INI:: eINI_
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if !defined INI_MAX_MULTI_FILES
    #define INI_MAX_MULTI_FILES			2 //Maximum number of files that can be opened simultaneously
#else
	#assert (INI_MAX_MULTI_FILES > 0)
#endif
#if !defined INI_MAX_LINES
    #define INI_MAX_LINES					128  //Maximum number of lines per INI File
#else
    #assert (INI_MAX_LINES > 0)
#endif
#if !defined INI_MAX_SECTIONS
    #define INI_MAX_SECTIONS				32 //Maximum number of sections per INI File
#else
	#assert (INI_MAX_LINES > INI_MAX_SECTIONS > 0)
#endif
#if !defined INI_MAX_KEYS
    #define INI_MAX_KEYS 					INI_MAX_LINES	//Maximum number of keys per INI File
#else
	#assert (INI_MAX_LINES > INI_MAX_KEYS > 0)
#endif
#if !defined INI_NAME_VALUE_DELIMITER
	#define INI_NAME_VALUE_DELIMITER 		'=' //Key=Value delimiter (separator)
#else
    #assert (INI_NAME_VALUE_DELIMITER == '=' || INI_NAME_VALUE_DELIMITER == ':')
#endif
#if !defined INI_ESCAPE_CHARACTER   		//Escape Sequence delimiter (\n,\r,etc)
	#define INI_ESCAPE_CHARACTER 			'\\'
#else
	#assert (INI_ESCAPE_CHARACTER == '\\')
#endif
#if !defined INI_MAX_LINE_LENGTH
    #define INI_MAX_LINE_LENGTH 			256 //Maximum number of characters per INI Line
#else
	#assert (INI_MAX_LINE_LENGTH > 1)
#endif
#if !defined INI_MAX_FILE_NAME_LENGTH
	#define INI_MAX_FILE_NAME_LENGTH 		32 //INI File Name Length
#else
    #assert (INI_MAX_FILE_NAME_LENGTH > 0)
#endif
#if !defined INI_MAX_SECTION_NAME_LENGTH
	#define INI_MAX_SECTION_NAME_LENGTH 	32 //Length of Section Name
#else
    #assert (INI_MAX_SECTION_NAME_LENGTH > 0)
#endif
#if !defined INI_MAX_KEY_NAME_LENGTH
    #define INI_MAX_KEY_NAME_LENGTH 		64 //Maximum number of characters for a key name
#else
	#assert (INI_MAX_KEY_NAME_LENGTH > 0)
#endif
#if !defined INI_MAX_KEY_VALUE_LENGTH
    #define INI_MAX_KEY_VALUE_LENGTH		INI_MAX_LINE_LENGTH //Maximum number of characters for a key value
#else
	#assert (INI_MAX_KEY_VALUE_LENGTH > 0)
#endif
#if !defined INI_MAX_REPLACEMENT_TAG
	#define INI_MAX_REPLACEMENT_TAG 		24 //Maximum Length of Replacement Tag
#else
	#assert (INI_MAX_REPLACEMENT_TAG > 0)
#endif
#if !defined INI_MAX_REPLACEMENT_TEXT
	#define INI_MAX_REPLACEMENT_TEXT		64 //Maximum Length of Replacement Text
#else
	#assert (INI_MAX_REPLACEMENT_TEXT < INI_MAX_KEY_VALUE_LENGTH)
#endif
#if !defined INI_FLOATING_POINT_PRECISION
	#define INI_FLOATING_POINT_PRECISION	16 //Number of cells need to store the largest floating point number
#else
	#assert (24 > INI_FLOATING_POINT_PRECISION > 0)
#endif
#if !defined INI_INTEGER_DIGITS
	#define INI_INTEGER_DIGITS	10 //Number of cells in the longest integer + 1
#else
	#assert (17 > INI_INTEGER_DIGITS > 0)
#endif
#if !defined INI_HEX_DIGITS
	#define INI_HEX_DIGITS	8 //Number of cells need to store the largest hexadecimal number
#else
	#assert (16 > INI_HEX_DIGITS > 0)
#endif
#if !defined INI_BIN_DIGITS
	#define INI_BIN_DIGITS	32 //Number of cells need to store the largest binary number
#else
	#assert (33 > INI_BIN_DIGITS > 0)
#endif
#if !defined INI_MAX_FUNCTION_NAME_LENGTH
	#define INI_MAX_FUNCTION_NAME_LENGTH	32 //Length of Function Identifier that can be given to CallLocalFunction
#else
	#assert (128 > INI_MAX_FUNCTION_NAME_LENGTH > 0)
#endif
#if !defined INI_WRITE_FALSE_VALUE
	#define INI_WRITE_FALSE_VALUE	"false" //String to be saved when WriteBool is called
	#define INI_WRITE_FALSE_VALUE_SIZE	6 //Size of INI_WRITE_FALSE_VALUE
#endif
#if !defined INI_WRITE_TRUE_VALUE
	#define INI_WRITE_TRUE_VALUE	"true" 	//String to be saved when WriteBool is called
	#define INI_WRITE_TRUE_VALUE_SIZE 5 //Size of INI_WRITE_TRUE_VALUE
#endif
#if !defined INI_DISABLE_CASE_SENSITIVITY
	#define _INI_CS false
#else
    #define _INI_CS true
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Must be distinct negative numbers
#define INI_ERR_FAILED_TO_OPEN -1
#define INI_ERR_FILE_DOES_NOT_EXIST -2
#define INI_ERR_FILE_ALREADY_EXISTS -3
#define INI_ERR_FILE_CREATION_FAILED -4
#define INI_ERR_MAX_FILE_LIMIT -5
#define INI_ERR_INVALID_HANDLE -6
#define INI_ERR_SYNTAX -7
#define INI_ERR_INVALID_ID -8
#define INI_ERR_INVALID_BOOL -9
#define INI_ERR_PARSING_FAILED -17

#define INI_SECTION_NOT_FOUND -10
#define INI_KEY_CREATE_FAILED -11
#define INI_SECTION_CREATED -12
#define INI_SECTION_CREATE_FAILED -13
#define INI_KEY_CREATED -14
#define INI_KEY_NOT_FOUND -15
#define INI_KEY_FOUND -16
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INI_UNUSED 0 //Must be zero
#define INI_READ_WRITE 1
#define INI_READ 2
#define INI_WRITE 3
#define INI_WRITE_NEW 4
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INI_LINE_EMPTY 1
#define INI_LINE_COMMENT 2
#define INI_LINE_SECTION_KEY 3
#define INI_LINE_SECTION_TAG 4
#define INI_LINE_GLOBAL_KEY 5
#define INI_LINE_EOF 6

#define INI_LINE_RETAIN 1
#define INI_LINE_DELETE 2
#define INI_LINE_MODIFIED 3

#define INI_DEFAULT_FILL -1
#define INI_LINKED_LIST_NULL -1
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INI_LOG_FILE "eini_log.txt"
#define DEFAULT_INVALID_HANDLE INI:-4081998
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define eINI_IsValidHandle(%0) (INI:INI_MAX_MULTI_FILES > %0 > INI:-1)

#define IsFileHandleInUse(%0) (INI_File[%0][E_INI_FILE_mode])
#define InvalidateFileHandle(%0) (INI_File[%0][E_INI_FILE_mode] = INI_UNUSED)

#if defined INI_ENABLE_WHITESPACE
	#define IsValidNameChar(%0) (('A' <= %0 <= 'Z') || ('a' <= %0 <= 'z') || (%0 == '_') || ('0' <= %0 <= '9') || (%0 == ' '))
#else
    #define IsValidNameChar(%0) (('A' <= %0 <= 'Z') || ('a' <= %0 <= 'z') || (%0 == '_') || ('0' <= %0 <= '9'))
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined INI_USE_LOG_FILE
	#if !defined INI_DISABLE_ERRORS
		#define INI_Error(%0);  _INI_Log(%0);
	#else
		#define INI_Error(%0);
	#endif

	#if !defined INI_DISABLE_WARNINGS
	 	#define INI_Warning(%0);  _INI_Log(%0);
	#else
		#define INI_Warning(%0);
	#endif

	#if !defined INI_DISABLE_NOTICES
		#define INI_Notice(%0); _INI_Log(%0);
	#else
		#define INI_Notice(%0);
	#endif
#else
	#if !defined INI_DISABLE_ERRORS
		#define INI_Error(%0,%1); printf(%1);
	#else
		#define INI_Error(%0);
	#endif

	#if !defined INI_DISABLE_WARNINGS
	 	#define INI_Warning(%0,%1); printf(%1);
	#else
		#define INI_Warning(%0);
	#endif

	#if !defined INI_DISABLE_NOTICES
		#define INI_Notice(%0,%1); printf(%1);
	#else
		#define INI_Notice(%0);
	#endif
#endif
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
forward i_eINI_SYSREQ_FIX();
public i_eINI_SYSREQ_FIX()
{
	format("",0,"");
}

#define BYTES_PER_CELL 				4
stock _INI_Log(INI:handle, fstring[], {Float, _}:...)
{
	#pragma unused handle

    static const STATIC_ARGS = 2;
    new n = (numargs() - STATIC_ARGS) * BYTES_PER_CELL;

    new File:LogFile = fopen(INI_LOG_FILE,io_append);

    if(n)
    {
        new message[256],arg_start,arg_end;
        #emit CONST.alt        fstring
        #emit LCTRL          5
        #emit ADD
        #emit STOR.S.pri        arg_start

        #emit LOAD.S.alt        n
        #emit ADD
        #emit STOR.S.pri        arg_end
        do
        {
            #emit LOAD.I
            #emit PUSH.pri
            arg_end -= BYTES_PER_CELL;
            #emit LOAD.S.pri      arg_end
        }
        while(arg_end > arg_start);

        #emit PUSH.S          fstring
        #emit PUSH.C          256
        #emit PUSH.ADR         message

        n += BYTES_PER_CELL * 3;
        #emit PUSH.S          n
        #emit SYSREQ.C         format

        n += BYTES_PER_CELL;
        #emit LCTRL          4
        #emit LOAD.S.alt        n
        #emit ADD
        #emit SCTRL          4

        if(LogFile)
        {
            new str[256],hr,mins,sec,year,month,day;
            gettime(hr,mins,sec);
            getdate(year,month,day);
            format(str,sizeof(str),"[%i:%i:%i][%i:%i:%i]%s\r\n",day,month,year,hr,mins,sec,message);
            fwrite(LogFile,str);
            fclose(LogFile);
        }
        else
        {
            printf("Could not open log file");
            print(message);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
enum E_INI_FILE
{
    E_INI_FILE_filename[INI_MAX_FILE_NAME_LENGTH char],
    E_INI_FILE_LoadedSections,
    E_INI_FILE_LoadedKeys,
    E_INI_FILE_lines,
    E_INI_FILE_start_lineid,
    E_INI_FILE_end_lineid,
    E_INI_FILE_mode,
    bool:E_INI_FILE_parsed
}
enum E_INI_LINE
{
	E_INI_LINE_type,
	E_INI_LINE_id,
	E_INI_LINE_previous,
	E_INI_LINE_next,
	E_INI_LINE_Content[INI_MAX_LINE_LENGTH]
}
enum E_INI_SECTION
{
    E_INI_SECTION_name[INI_MAX_SECTION_NAME_LENGTH],
	E_INI_SECTION_sectionid,
	E_INI_SECTION_lineid,
	E_INI_SECTION_keystart
}
enum E_INI_KEY
{
    E_INI_KEY_name[INI_MAX_KEY_NAME_LENGTH],
    E_INI_KEY_value[INI_MAX_KEY_VALUE_LENGTH],
	E_INI_KEY_sectionid,
	E_INI_KEY_lineid,
	E_INI_KEY_previous,
	E_INI_KEY_next
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static stock INI_File[INI_MAX_MULTI_FILES][E_INI_FILE];
static stock INI_Line[INI_MAX_MULTI_FILES*INI_MAX_LINES][E_INI_LINE];
static stock INI_Section[INI_MAX_MULTI_FILES*INI_MAX_SECTIONS][E_INI_SECTION];
static stock INI_Key[INI_MAX_MULTI_FILES*INI_MAX_KEYS][E_INI_KEY];

new INI_ReplacementText[INI_MAX_REPLACEMENT_TEXT];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
stock intrl_EINI_BinaryToDecimal(const str[])
{
	new value = 0,i;
	if((str[0] | 0x20) == 'b' ) i = 1;
	for(;;)
	{
		switch(str[i++])
		{
			case '1': value = (value<<1) | 1;
			case '0': value <<= 1;
			case 'b','B',' ': continue;
			default: break;
		}
	}
	return value;
}
stock intrl_EINI_HexadecimalToDecimal(const str[])
{
    new value = 0,i = -1;
    if(str[0] == '0' && ((str[1] | 0x20) == 'x')) i = 1;

	for(;;)
    {
      	switch(str[++i])
        {
          	case '0'..'9': value = (value<<4) | (str[i] - '0');
            case 'a'..'f': value = (value<<4) | (str[i] - 'a' + 10);
            case 'A'..'F': value = (value<<4) | (str[i] - 'A' + 10);
            case ' ': continue;
            default: break;
        }
    }
    return value;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************************************************
	<summary>CreateINI</summary>
	<para>Creates an INI File</para>
	<param name="fname">Location where the file should be created</param>
	<returns>
		Returns INI Handle on success or an error code if failed
		(INI_ERR_FILE_ALREADY_EXISTS/INI_ERR_MAX_FILE_LIMIT)
	</returns>
	<remarks>
	    The location where the file should be created should be relative to the scriptfiles folder
	</remarks>
	<example>
	    <code>
	    	CreateFile("config\\new_file.ini"); //Creates a file in scriptfiles\config\new_file.ini
	    </code>
	</example>
*******************************************************************************************************************************/
stock INI:INI::CreateINI(const fname[])
{
	static j,tmp;
	if(fexist(fname))
	{
	    INI_Error(DEFAULT_INVALID_HANDLE,"[INI]CreateINI:File already exists(%s)",fname);
	    return INI:INI_ERR_FILE_ALREADY_EXISTS;
	}

	for(new i = 0;i < INI_MAX_MULTI_FILES;i++)
	{
		if(IsFileHandleInUse(i)) continue;

	    for(j = INI_MAX_KEYS*i,tmp = INI_MAX_KEYS*(i+1);j < tmp;j++)
			INI_Key[j][E_INI_KEY_sectionid] = INI_DEFAULT_FILL;

	    for(j = INI_MAX_SECTIONS*i,tmp = INI_MAX_SECTIONS*(i+1);j < tmp;j++)
	        INI_Section[j][E_INI_SECTION_sectionid] = INI_DEFAULT_FILL;

		for(j = INI_MAX_LINES*i,tmp = INI_MAX_LINES*(i+1);j < tmp;j++)
		{
	        INI_Line[j][E_INI_LINE_type] = INI_DEFAULT_FILL;
	        INI_Line[j][E_INI_LINE_previous] = INI_Line[j][E_INI_LINE_next] = INI_LINKED_LIST_NULL;
		}
				
		INI_File[i][E_INI_FILE_mode] = INI_WRITE_NEW;
		INI_File[i][E_INI_FILE_LoadedSections] = INI_File[i][E_INI_FILE_LoadedKeys] = 0;
		INI_File[i][E_INI_FILE_lines] = 1;
		INI_File[i][E_INI_FILE_end_lineid] = INI_File[i][E_INI_FILE_start_lineid] = INI_MAX_LINES*i;
		INI_Line[INI_MAX_LINES*i][E_INI_LINE_type] = INI_LINE_EOF;
        INI_File[i][E_INI_FILE_parsed] = true;
		strpack(INI_File[i][E_INI_FILE_filename],fname,INI_MAX_FILE_NAME_LENGTH);
		return INI:i;
	}
	INI_Error(DEFAULT_INVALID_HANDLE,"[INI]CreateINI:Maximum Open Files Limit Reached(%s)",fname);
    return INI:INI_ERR_MAX_FILE_LIMIT;
}
/*******************************************************************************************************************************
	<summary>OpenINI</summary>
	<para>Opens an INI</para>
	<param name="fname">Location of the file to open</param>
	<param name="mode">Depending on the file usage, the mode is set(INI_READ_WRITE/INI_WRITE/INI_READ)</param>
	<returns>
		Returns INI Handle on success or an error code if failed
		(INI_ERR_MAX_FILE_LIMIT/INI_ERR_FILE_DOES_NOT_EXIST)
	</returns>
	<remarks>
	    The location of the file to be opened should be relative to the scriptfiles folder
	</remarks>
	<example>
	    <code>
	    	OpenINI("config\\new_file.ini"); //Opens a file from scriptfiles\config\new_ini
		</code>
	</example>
*******************************************************************************************************************************/
stock INI:INI::OpenINI(const fname[],mode=INI_READ_WRITE)
{
	static j,tmp;
    if(!fexist(fname))
    {
     	INI_Error(INI:DEFAULT_INVALID_HANDLE,"[INI]OpenINI:File doesn't exist (%s)",fname);
        return INI:INI_ERR_FILE_DOES_NOT_EXIST;
    }

	#if !defined INI_DISABLE_WARNINGS
    for(new i = 0;i < INI_MAX_MULTI_FILES;i++)
    {
  		if(IsFileHandleInUse(i))
			if(!strcmp(fname,INI_File[i][E_INI_FILE_filename]))
            	INI_Warning(INI:DEFAULT_INVALID_HANDLE,"[INI]Warning:Creating another instance of the same file(%s)",fname);
   	}
   	#endif

   	for(new i = 0;i < INI_MAX_MULTI_FILES;i++)
   	{
    	if(!IsFileHandleInUse(i))
        {
        	for(j = INI_MAX_KEYS*i,tmp = INI_MAX_KEYS*(i+1);j < tmp;j++)
             	INI_Key[j][E_INI_KEY_sectionid] = INI_DEFAULT_FILL;

            for(j = INI_MAX_SECTIONS*i,tmp = INI_MAX_SECTIONS*(i+1);j < tmp;j++)
              	INI_Section[j][E_INI_SECTION_sectionid] = INI_DEFAULT_FILL;

            INI_File[i][E_INI_FILE_end_lineid] = INI_File[i][E_INI_FILE_start_lineid] = j = INI_MAX_LINES*i;
            INI_File[i][E_INI_FILE_mode] = mode;
            INI_File[i][E_INI_FILE_LoadedSections] = INI_File[i][E_INI_FILE_LoadedKeys] = INI_File[i][E_INI_FILE_lines] = 0;
            INI_File[i][E_INI_FILE_parsed] = false;

            for(tmp = INI_MAX_LINES*(i+1);j < tmp;j++)
            {
               	INI_Line[j][E_INI_LINE_type] = INI_DEFAULT_FILL;
                INI_Line[j][E_INI_LINE_previous] = INI_Line[j][E_INI_LINE_next] = INI_LINKED_LIST_NULL;
            }

            strpack(INI_File[i][E_INI_FILE_filename],fname,INI_MAX_FILE_NAME_LENGTH);
            return INI:i;
        }
   	}
  	INI_Error(INI:DEFAULT_INVALID_HANDLE,"[INI]OpenINI:Maximum Open Files Limit Reached(%s)",fname);
   	return INI:INI_ERR_MAX_FILE_LIMIT;
}
/*******************************************************************************************************************************
	<summary>CloseINI</summary>
	<para>Saves the file then invalidates the INI Handle</para>
	<param name="filehandle">INI Handle</param>
	<param name="savebuffer">Set to true to save the buffer to the file(true by default)</param>
	<returns>
		Returns 0 on success or an error code if failed
		(INI_ERR_INVALID_HANDLE/INI_ERR_PARSING_FAILED)
	</returns>
	<remarks>
	    The buffer can be manually saved by calling WriteBuffer.
	</remarks>
	<example>
		new INI:handle = INI::OpenINI("eINI.ini"); //Opens a file for read/write
		INI::WriteBuffer(handle); //Saves the file
		Close(handle,false); //Invalidates the handle without saving since its already saved
	</example>
	<seealso>INI::WriteBuffer<seealso>
*******************************************************************************************************************************/
stock INI::CloseINI(INI:filehandle,bool:savebuffer=true)
{
 	#if !defined INI_CAREFUL_MODE
		if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]CloseINI:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	    else { INI_Error(filehandle,"[INI]CloseINI:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
   	#endif
   	
	if(savebuffer)
		if(INI::WriteBuffer(filehandle) == INI_ERR_PARSING_FAILED)	return INI_ERR_PARSING_FAILED;
    InvalidateFileHandle(_:filehandle);
 	return 0;
}
/*******************************************************************************************************************************
	<summary>WriteBuffer</summary>
	<para>When any changes are made to the INI ,the file is not updated automatically until CloseINI is called.WriteBuffer
	forcefully updates the file.</para>
	<param name="filehandle">INI Handle</param>
	<returns>
		Returns 0 on success or an error code
		(INI_ERR_INVALID_HANDLE/INI_ERR_FILE_CREATION_FAILED/INI_ERR_PARSING_FAILED/INI_ERR_FAILED_TO_OPEN)
	</returns>
	<remarks>
	    The buffer is saved automatically when CloseINI is called until it is explicitly told not to save.
	</remarks>
	<example>
		new INI:handle = INI::OpenINI("eINI.ini"); //Opens a file for read/write
		INI::WriteBuffer(handle); //Saves the file
		INI::Close(handle,false); //Invalidates the handle without saving since its already saved
	</example>
*******************************************************************************************************************************/
stock INI::WriteBuffer(INI:filehandle)
{
	#if !defined INI_CAREFUL_MODE
		if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]WriteBuffer:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	    else { INI_Error(filehandle,"[INI]WriteBuffer:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif

 	new str[INI_MAX_FILE_NAME_LENGTH];
    new File:wfile;

    strunpack(str,INI_File[_:filehandle][E_INI_FILE_filename]);

    if(!INI_File[_:filehandle][E_INI_FILE_parsed])
		if(INI::ParseINI(filehandle))
		{
		    INI_Error(filehandle,"[INI]WriteBuffer:Failed to parse file(%s)>>Write Aborted",str);
			return INI_ERR_PARSING_FAILED;
		}

    switch(INI_File[_:filehandle][E_INI_FILE_mode])
    {
        case INI_READ:	return 0;
	    case INI_WRITE_NEW:
     	{
     	    if(fexist(str))
    			fremove(str);
     	    if(!(wfile = fopen(str,io_write)))
			{
                INI_Error(filehandle,"[INI]WriteBuffer:Failed to create file(%s)",str);
				return INI_ERR_FILE_CREATION_FAILED;
			}
	    }
	    default:
    	{
    	    if(fexist(str))
    			fremove(str);
			if(!(wfile = fopen(str,io_write)))
			{
                INI_Error(filehandle,"[INI]WriteBuffer:Failed to open file(%s) for writing.",str);
				return INI_ERR_FAILED_TO_OPEN;
			}
	   	}
	}
	for(new i = INI_File[_:filehandle][E_INI_FILE_start_lineid];INI_Line[i][E_INI_LINE_type] != INI_LINE_EOF;i = INI_Line[i][E_INI_LINE_next])
		fwrite(wfile,INI_Line[i][E_INI_LINE_Content]);

	fclose(wfile);
	return 0;
}
/*******************************************************************************************************************************
	<summary>ParseINI</summary>
	<para>Parses the whole file and stores all the data in a buffer for fast reading and writing</para>
	<param name="filehandle">INI Handle</param>
	<param name="LoadFunction>Function to be called if dynamic loading used(null by default)</param>
	<param name="dynamic">Set true to enable dynamic loading (false by default)</param>
	<param name="extra">Extra value to be passed to the dynamic loading function (0 by default)</param>
	<param name="pass_extra">Set to true if extra paramter is used (false by default)</param>
    <param name="func_with_key">If false,first occurrence of %s in LoadFunction will be replaced with section name only
									  If true,the first two occurrences of %s in LoadFunction will be replaced with section
									  name followed by key name respectively (false by default)</param>
	<param name="tradition_func">If true the section name and key name will be passed as arguments to the LoadFunction.
								 The LoadFunction will be called as it is without any moidifications. (false by default)</param>
    <param name="broadcast">If true the data will be sent to all running scripts.If set to false, only the local script
	                        callbacks will be called. (false by deafult)</param>

	<returns>
		Returns error code if INI syntax was unacceptable
		Returns 0 for normal execution
		It also returns 0 if file was not meant to be parsed(in case of a new file)
		INI_ERR_INVALID_HANDLE
		INI_ERR_SYNTAX

	</returns>
	<remarks>
	    The default value of extra paramter has no effect on the function
	</remarks>
	<example>
		INI::ParseINI(myhandle); //Normal Parsing
		INI::ParseINI(myhandle,"Load_%s",true); //Parsing with dynamic loading.The %s will be replaced with the section name
		INI::ParseINI(myhandle,"Load_%s",true,playerid,true); //Parsing with dynamic loading with extra parameter
		INI::ParseINI(myhandle,"Load_%s_%s",true,random_number,false,true); //Parsing with dynamic loading.The %s will be replaced with section and
		                                 //key name
		INI::ParseINI(myhandle,"Load_%s_%s",true,playerid,true,true); //Parsing with dynamic loading with extra paramter
		INI::ParseINI(myhandle,"LoadFunction",true,playerid,true,false,true); //Parsing with traditional dynamic loading with extra paramter
        INI::ParseINI(myhandle,"LoadFunction",true,playerid,true,false,true,true); //Parsing with traditional dynamic loading and broadcast accross all scripts
	</example>
*******************************************************************************************************************************/
stock INI::ParseINI(INI:filehandle,const LoadFunction[] = "",bool:dynamic=false,extra=0,bool:pass_extra=false,bool:func_with_key=false,bool:tradition_func=false,bool:broadcast=false)
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES)
	{
		if(!IsFileHandleInUse(_:filehandle))
		{
			INI_Error(filehandle,"[INI]ParseINI:Invalid File Handle ID (%d)",_:filehandle);
			return INI_ERR_INVALID_HANDLE;
		}
	}
	else
	{
		INI_Error(filehandle,"[INI]ParseINI:Invalid File Handle ID (%d)",_:filehandle);
		return INI_ERR_INVALID_HANDLE;
	}
	#endif

	static File:rfile;
    static line[INI_MAX_LINE_LENGTH],len;
    static index,tmp,func[INI_MAX_FUNCTION_NAME_LENGTH];

    new fmode = INI_File[_:filehandle][E_INI_FILE_mode],bool:keystart = true,bool:wspace = false,KeyID = 0,SectionID = 0,LineID = INI_MAX_LINES*_:filehandle;

	switch(fmode)
	{
	    case INI_WRITE_NEW:	return 0;
	    default:
	    {
	        strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
	        if(!(rfile = fopen(line,io_read)))
			{
			    INI_Error(filehandle,"[INI]ParseINI:Failed to open file(%s) for reading.",line);
				return INI_ERR_FAILED_TO_OPEN;
			}
	    }
	}

	while((len = fread(rfile,line)))
	{
		for(new i = 0;;i++)
		{
		    switch(line[i])
		    {
				case '[':
				{
				    #if !defined INI_ASSUME_FORMATTED_INI
				    do
					{
					    switch(line[++i])
					    {
					        case '\r','\n',0,']':
					        {
					            #if defined INI_LIBERAL_MODE
					            goto comment_line;
					            #else
					            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
							  	INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >> empty section",LineID + 1 - INI_MAX_LINES*_:filehandle,line);
							  	INI::CloseINI(filehandle,false);
							  	fclose(rfile);
							  	return INI_ERR_SYNTAX;
							  	#endif
					        }
					    }
					}while(line[i] == ' ');
					#endif

                    #if !defined INI_ASSUME_FORMATTED_INI
					index = i;
					#else
					index = ++i;
					#endif

					tmp = INI_MAX_SECTIONS*_:filehandle + ++SectionID;

					INI_Line[LineID][E_INI_LINE_type] = INI_LINE_SECTION_TAG;
					INI_Line[LineID][E_INI_LINE_id] = tmp;

					INI_Section[tmp][E_INI_SECTION_lineid] = LineID;
          			INI_Section[tmp][E_INI_SECTION_sectionid] = SectionID;

          			wspace = false;

					for(;;i++)
					{
          			    if(IsValidNameChar(line[i]))
					    {
					        #if defined INI_ENABLE_WHITESPACE
					            switch(line[i])
					            {
					                case ' ':
					                {
					                    if(!wspace)
										{
										 	wspace = true;
											strmid(INI_Section[tmp][E_INI_SECTION_name],line,index,i,INI_MAX_SECTION_NAME_LENGTH);
										}
					                }
					                default: wspace = false;
					            }
							#else
								#if !defined INI_ASSUME_FORMATTED_INI
								if(wspace)
								{
								    #if defined INI_LIBERAL_MODE
	          			            SectionID--;
						            goto comment_line;
						            #else
	          			            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
									INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >> whitespace found in section name",LineID+1 - INI_MAX_LINES*_:filehandle,line);
									INI::CloseINI(filehandle,false);
									fclose(rfile);
									return INI_ERR_SYNTAX;
									#endif
								}
								#endif
					        #endif
							continue;
						}
          			    switch(line[i])
          			    {
          			        case ']':
          			        {
          			            if(wspace) break;
          			            strmid(INI_Section[tmp][E_INI_SECTION_name],line,index,i,INI_MAX_SECTION_NAME_LENGTH);
			       		    	break;
          			        }
          			        #if !defined INI_ASSUME_FORMATTED_INI
          			        case ' ':
          			        {
          			            if(wspace) continue;
          			            wspace = true;
          			            strmid(INI_Section[tmp][E_INI_SECTION_name],line,index,i,INI_MAX_SECTION_NAME_LENGTH);
          			            continue;
          			        }
          			        case '\r','\n',0:
          			        {
          			            #if defined INI_LIBERAL_MODE
          			            if(wspace) break;
          			            strmid(INI_Section[tmp][E_INI_SECTION_name],line,index,i,INI_MAX_SECTION_NAME_LENGTH);
			       		    	break;
					            #else
          			            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
								INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >> non-terminated section tag",LineID+1 - INI_MAX_LINES*_:filehandle,line);
								INI::CloseINI(filehandle,false);
								fclose(rfile);
								return INI_ERR_SYNTAX;
								#endif
          			        }
          			        default:
          			        {
          			            #if defined INI_LIBERAL_MODE
          			            continue;
					            #else
          			            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
								INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >>  invalid character",LineID + 1 - INI_MAX_LINES*_:filehandle,line);
								INI::CloseINI(filehandle,false);
								fclose(rfile);
								return INI_ERR_SYNTAX;
								#endif
          			        }
          			        #endif
          			    }
          			}
          			#if !defined INI_DISABLE_WARNINGS
					    for(new j = 1;j < SectionID;j++)
						{
							if(!strcmp(INI_Section[tmp][E_INI_SECTION_name],INI_Section[tmp-j][E_INI_SECTION_name],_INI_CS))
							{
							    strunpack(func,INI_File[_:filehandle][E_INI_FILE_filename]);
							   	INI_Warning(filehandle,"[INI]Warning:Duplicate Section %s(Will be ignored) in file (%s)",INI_Section[tmp][E_INI_SECTION_name],func);
							   	break;
							}
						}
					#endif
					if(!keystart)
					{
					  	if(KeyID)
							INI_Key[INI_MAX_KEYS*_:filehandle + KeyID - 1][E_INI_KEY_next] = INI_LINKED_LIST_NULL;
						keystart = true;
					}
					else if(SectionID) INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_keystart] = -1;
          			break;
				}
				case ';','#':
		        {
		            comment_line:
		            INI_Line[LineID][E_INI_LINE_type] = INI_LINE_COMMENT;
				    break;
		        }
		        case '\r','\n',0:
				{
				    INI_Line[LineID][E_INI_LINE_type] = INI_LINE_EMPTY;
				    break;
				}
				case ' ': continue;
				default:
				{
				    tmp = INI_MAX_KEYS*_:filehandle + KeyID++;
				    if(SectionID)
				    {
					    INI_Line[LineID][E_INI_LINE_type] = INI_LINE_SECTION_KEY;
					    INI_Key[tmp][E_INI_KEY_sectionid] = SectionID;
					}
					else
					{
					    INI_Line[LineID][E_INI_LINE_type] = INI_LINE_GLOBAL_KEY;
						INI_Key[tmp][E_INI_KEY_sectionid] = 0;
					}

					INI_Key[tmp][E_INI_KEY_lineid] = LineID;

					INI_Line[LineID][E_INI_LINE_id] = tmp;
      				index = i;
      				wspace = false;

      				for(;;i++)
      				{
      				    if(IsValidNameChar(line[i]))
					    {
					        #if defined INI_ENABLE_WHITESPACE
					            switch(line[i])
					            {
					                case ' ':
					                {
					                    if(!wspace)
										{
										 	wspace = true;
											strmid(INI_Key[tmp][E_INI_KEY_name],line,index,i,INI_MAX_KEY_NAME_LENGTH);
										}
					                }
					                default: wspace = false;
					            }
							#else
								#if !defined INI_ASSUME_FORMATTED_INI
								if(wspace)
								{
								    #if defined INI_LIBERAL_MODE
	          			            KeyID--;
						            goto comment_line;
						            #else
	          			            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
									INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >> whitespace found in key name",LineID+1 - INI_MAX_LINES*_:filehandle,line);
									INI::CloseINI(filehandle,false);
									fclose(rfile);
									return INI_ERR_SYNTAX;
									#endif
								}
								#endif
					        #endif
							continue;
						}
						switch(line[i])
						{
						    case INI_NAME_VALUE_DELIMITER:
							{
                                if(wspace) break;
          			            strmid(INI_Key[tmp][E_INI_KEY_name],line,index,i,INI_MAX_KEY_NAME_LENGTH);
			       		    	break;
							}

						    case ' ':
						    {
						        if(wspace) continue;
          			            wspace = true;
          			            strmid(INI_Key[tmp][E_INI_KEY_name],line,index,i,INI_MAX_KEY_NAME_LENGTH);
          			            continue;
						    }
						    #if !defined INI_ASSUME_FORMATTED_INI
						    case '\r','\n',0:
						    {
						        #if defined INI_LIBERAL_MODE
          			            if(wspace) break;
	                            KeyID--;
						        goto comment_line;
			       		    	break;
					            #else
          			            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
								INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >> invalid line",LineID+1 - INI_MAX_LINES*_:filehandle,line);
								INI::CloseINI(filehandle,false);
								fclose(rfile);
								return INI_ERR_SYNTAX;
								#endif
						    }
						    default:
						    {
						        #if defined INI_LIBERAL_MODE
          			            continue;
					            #else
          			            strunpack(line,INI_File[_:filehandle][E_INI_FILE_filename]);
								INI_Error(filehandle,"[INI]Parser:Syntax Error in line %d in %s >>  invalid character in key name",LineID + 1 - INI_MAX_LINES*_:filehandle,line);
								INI::CloseINI(filehandle,false);
								fclose(rfile);
								return INI_ERR_SYNTAX;
								#endif
						    }
						    #endif
						}
      				}

      				if(keystart)
					{
						keystart = false;
					    INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_keystart] = tmp;
					    INI_Key[tmp][E_INI_KEY_previous] = INI_LINKED_LIST_NULL;
					}
					else
					{
					    INI_Key[tmp-1][E_INI_KEY_next] = tmp;
					    INI_Key[tmp][E_INI_KEY_previous] = tmp-1;
					}
      				if(fmode == INI_WRITE) break;
				  	#if !defined INI_ASSUME_FORMATTED_INI
         			do
					{
          				#if !defined INI_DISABLE_WARNINGS
					    switch(line[++i])
					    {
					        case ';','#','\r','\n',0:
					        {
                       	        INI_Key[tmp][E_INI_KEY_value][0] = '\0';
						        strunpack(func,INI_File[_:filehandle][E_INI_FILE_filename]);
								INI_Warning(filehandle,"[INI]Warning:Empty Valued Key  in line %d in %s",LineID+1-INI_MAX_LINES*_:filehandle,func);
                            }
			  	  		}
                    }while(line[i] == ' ');
			  	  		#else
			  	  	}while(line[++i] == ' ');
					    #endif

					#endif

					#if defined INI_ASSUME_FORMATTED_INI
					index = ++i;
					#else
					index = i;
					#endif
          			for(;;)
					{
					    switch(line[++i])
					    {
					      	case INI_ESCAPE_CHARACTER:	i += 2;
					        case ';','#':
					        {
					         	strmid(INI_Key[tmp][E_INI_KEY_value],line,index,i,INI_MAX_KEY_VALUE_LENGTH);
					            break;
							}
							case '\r','\n',0:
							{
							    strmid(INI_Key[tmp][E_INI_KEY_value],line,index,i,INI_MAX_KEY_VALUE_LENGTH);
								break;
							}
						}
					}
					if(dynamic)
					{
					    if(broadcast)
					    {
							if(tradition_func)
							{
       				            if(SectionID)
					            {
	                                if(pass_extra)
										CallRemoteFunction(LoadFunction,"sssi",INI_Key[tmp][E_INI_KEY_name],INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],INI_Key[tmp][E_INI_KEY_value],extra);
								    else
								       	CallRemoteFunction(LoadFunction,"sss",INI_Key[tmp][E_INI_KEY_name],INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],INI_Key[tmp][E_INI_KEY_value]);
								}
								else
								{
	                                if(pass_extra)
										CallRemoteFunction(LoadFunction,"sssi",INI_Key[tmp][E_INI_KEY_name],"\r",INI_Key[tmp][E_INI_KEY_value],extra);
								    else
								       	CallRemoteFunction(LoadFunction,"sss",INI_Key[tmp][E_INI_KEY_name],"\r",INI_Key[tmp][E_INI_KEY_value]);
								}
							}
							else
							{
								if(func_with_key)
								{
        						    if(SectionID)
								    	format(func,sizeof(func),LoadFunction,INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],INI_Key[tmp][E_INI_KEY_name]);
									else
									    format(func,sizeof(func),LoadFunction,"",INI_Key[tmp][E_INI_KEY_name]);


									if(pass_extra)
								   		CallRemoteFunction(func,"si",INI_Key[tmp][E_INI_KEY_value],extra);
							    	else
							        	CallRemoteFunction(func,"s",INI_Key[tmp][E_INI_KEY_value]);
								}
								else
							    {
								    if(SectionID)
								    	format(func,sizeof(func),LoadFunction,INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name]);
									else
									    format(func,sizeof(func),LoadFunction,"");


									if(pass_extra)
									 	CallRemoteFunction(func,"ssi",INI_Key[tmp][E_INI_KEY_name],INI_Key[tmp][E_INI_KEY_value],extra);
							    	else
								       	CallRemoteFunction(func,"ss",INI_Key[tmp][E_INI_KEY_name],INI_Key[tmp][E_INI_KEY_value]);
								}
							}
						}
					    else
						{
							if(tradition_func)
							{
       				            if(SectionID)
					            {
	                                if(pass_extra)
										CallLocalFunction(LoadFunction,"sssi",INI_Key[tmp][E_INI_KEY_name],INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],INI_Key[tmp][E_INI_KEY_value],extra);
								    else
								       	CallLocalFunction(LoadFunction,"sss",INI_Key[tmp][E_INI_KEY_name],INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],INI_Key[tmp][E_INI_KEY_value]);
								}
								else
								{
		                          	if(pass_extra)
										CallLocalFunction(LoadFunction,"sssi",INI_Key[tmp][E_INI_KEY_name]," ",INI_Key[tmp][E_INI_KEY_value],extra);
									else
									  	CallLocalFunction(LoadFunction,"sss",INI_Key[tmp][E_INI_KEY_name]," ",INI_Key[tmp][E_INI_KEY_value]);
								}
							}
	  						else
							{
								if(func_with_key)
								{
        						    if(SectionID)
								    	format(func,sizeof(func),LoadFunction,INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],INI_Key[tmp][E_INI_KEY_name]);
									else
									    format(func,sizeof(func),LoadFunction,"",INI_Key[tmp][E_INI_KEY_name]);


									if(pass_extra)
								   		CallLocalFunction(func,"si",INI_Key[tmp][E_INI_KEY_value],extra);
							    	else
							        	CallLocalFunction(func,"s",INI_Key[tmp][E_INI_KEY_value]);
								}
 								else
								{
								    if(SectionID)
								    	format(func,sizeof(func),LoadFunction,INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name]);
									else
									    format(func,sizeof(func),LoadFunction,"");


									if(pass_extra)
								   		CallLocalFunction(func,"ssi",INI_Key[tmp][E_INI_KEY_name],INI_Key[tmp][E_INI_KEY_value],extra);
							    	else
							        	CallLocalFunction(func,"ss",INI_Key[tmp][E_INI_KEY_name],INI_Key[tmp][E_INI_KEY_value]);
								}
 					        }
					    }
					}
    				#if !defined INI_DISABLE_WARNINGS
					for(new j = INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_keystart];j < tmp;j++)
					{
						if(!strcmp(INI_Key[tmp][E_INI_KEY_name],INI_Key[j][E_INI_KEY_name],_INI_CS))
						{
						    strunpack(func,INI_File[_:filehandle][E_INI_FILE_filename]);
						   	INI_Warning(filehandle,"[INI]Warning:Duplicate Key %s(Will be ignored) in section %s of file (%s)",INI_Key[tmp][E_INI_KEY_name],INI_Section[INI_MAX_SECTIONS*_:filehandle + SectionID][E_INI_SECTION_name],func);
						   	break;
						}
					}
					#endif
					break;
     			}
		    }
		}
		if(line[len-1] != '\n')	strcat(line,"\r\n");
	 	INI_Line[LineID][E_INI_LINE_Content] = line;
		INI_Line[LineID][E_INI_LINE_next] = ++LineID;
		INI_Line[LineID][E_INI_LINE_previous] = LineID-1;
	}
	fclose(rfile);

	if((INI_File[_:filehandle][E_INI_FILE_LoadedKeys] = KeyID))
		INI_Key[INI_MAX_KEYS*_:filehandle + KeyID - 1][E_INI_KEY_next] = INI_LINKED_LIST_NULL;

    INI_Line[LineID][E_INI_LINE_type] = INI_LINE_EOF;
    INI_Line[LineID][E_INI_LINE_next] = INI_LINKED_LIST_NULL;
	INI_Line[INI_MAX_LINES*_:filehandle][E_INI_LINE_previous] = INI_LINKED_LIST_NULL;
	INI_File[_:filehandle][E_INI_FILE_end_lineid] = LineID;
	INI_File[_:filehandle][E_INI_FILE_lines] = LineID - INI_MAX_LINES*_:filehandle;
	INI_File[_:filehandle][E_INI_FILE_LoadedSections] = SectionID;
	INI_File[_:filehandle][E_INI_FILE_LoadedKeys] = KeyID;
	INI_File[_:filehandle][E_INI_FILE_parsed] = true;

 	#if defined INI_ASSUME_FORMATTED_INI || !defined INI_LIBERAL_MODE
        #pragma unused comment_line
    #endif
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************************************************
	<summary>ReadString</summary>
	<para>Gets the value of a key</para>
	<param name="filehandle">INI Handle</param>
	<param name="result">The array to store the value</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="result_size">Size of result paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE
		INI_ERR_PARSING_FAILED
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.
	</remarks>
	<example>
	INI::ReadString(handle,res,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadString(handle,res,"KEY"); //Searches for KEY in the global section
	INI::ReadString(handle,res,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadString(handle,res,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadString(INI:filehandle,result[],const key[],const section[]="",keyid=-1,sectionid=-1,result_size=sizeof(result),section_size=sizeof(section),key_size=sizeof(key))
{
	#if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]ReadString:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]ReadString:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(!INI_File[_:filehandle][E_INI_FILE_parsed])
		if(INI::ParseINI(filehandle))
		{
		    new str[INI_MAX_FILE_NAME_LENGTH];
		    strunpack(str,INI_File[_:filehandle][E_INI_FILE_filename]);
		    INI_Error(filehandle,"[INI]ReadString:Failed to parse file(%s)>>Read Failed",str);
			return INI_ERR_PARSING_FAILED;
		}
	if(--key_size) //removing the null character
	{
	    if(--section_size) //removing the null character
	    {
	        for(new i = INI_MAX_SECTIONS*_:filehandle + 1,j = i + INI_File[_:filehandle][E_INI_FILE_LoadedSections];i <= j;i++)
	        {
	            if(INI_Section[i][E_INI_SECTION_name][0] == section[0])
	            {
	                if(!strcmp(section,INI_Section[i][E_INI_SECTION_name],_INI_CS))
	                {
	                    //SECTION FOUND
	                    if((i = INI_Section[i][E_INI_SECTION_keystart]) != -1)
	                    {
		                    do
		                    {
		                        if(key[0] == INI_Key[i][E_INI_KEY_name][0])
		                        {
		                            if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
		                            {
		                                //KEY FOUND
		                                result[0] = '\0';
		                                strcat(result,INI_Key[i][E_INI_KEY_value],result_size);
		                                return (i - INI_MAX_KEYS*_:filehandle);
		                            }
		                        }
		                    }while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
						}
                     	break;
	                }
	            }
	        }
			INI_Notice(filehandle,"[INI]ReadString:Key %s not found in section %s",key,section);
	   		return INI_KEY_NOT_FOUND;
		}
		else if(sectionid > -1)
		{
		  	if(sectionid <= INI_File[_:filehandle][E_INI_FILE_LoadedSections])
		    {
		        new i = INI_Section[INI_MAX_SECTIONS*_:filehandle + sectionid][E_INI_SECTION_keystart];
		        if(i != -1)
	            {
		        	do
		          	{
		            	if(key[0] == INI_Key[i][E_INI_KEY_name][0])
		              	{
		               		if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
	                		{
		                   		//KEY FOUND
		                   		result[0] = '\0';
		                  		strcat(result,INI_Key[i][E_INI_KEY_value],result_size);
		                    	return (i - INI_MAX_KEYS*_:filehandle);
		         			}
		   				}
		   			}while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
				}
		    }
		    else
		    {
		        INI_Error(filehandle,"[INI]ReadString:Invalid Section ID (%d)",sectionid);
		    	return INI_ERR_INVALID_ID;
			}
            INI_Notice(filehandle,"[INI]ReadString:Key(%s) not found in section ID %d ",key,sectionid);
            return INI_KEY_NOT_FOUND;
		}
		else
		{
		    new i = INI_Section[INI_MAX_SECTIONS*_:filehandle][E_INI_SECTION_keystart];
		    if(i != -1)
	        {
		    	do
		       	{
		        	if(key[0] == INI_Key[i][E_INI_KEY_name][0])
		         	{
		            	if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
		            	{
		              		//KEY FOUND
		              		result[0] = '\0';
		           			strcat(result,INI_Key[i][E_INI_KEY_value],result_size);
              				return (i - INI_MAX_KEYS*_:filehandle);
		 				}
		   			}
				}while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
			}
			INI_Notice(filehandle,"[INI]ReadString:Key(%s) not found in global section",key);
	    	return INI_KEY_NOT_FOUND;
		}
	}
    else if(keyid > -1)
	{
	    if(-1 < keyid < INI_File[_:filehandle][E_INI_FILE_LoadedKeys])
        {
            new tmp = INI_MAX_KEYS*_:filehandle + keyid;
            if(INI_Key[tmp][E_INI_KEY_sectionid] > -1)
		    {
		        result[0] = '\0';
		       	strcat(result,INI_Key[tmp][E_INI_KEY_value],result_size);
				return keyid;
	   		}
        }
        else
        {
	       	INI_Error(filehandle,"[INI]ReadString:Non-existant Key ID (%d)",keyid);
	    	return INI_KEY_NOT_FOUND;
      	}
   	}
    INI_Error(filehandle,"[INI]ReadString:Invalid Parameters",key,sectionid);
	return INI_KEY_NOT_FOUND;
}
/*******************************************************************************************************************************
	<summary>ReadBool</summary>
	<para>Interprets the value of a key and sets variable to the appropriate value</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">The variable in which the value has to be stored</param>
	<param name="key">Key from which the value has to be interpreted</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE
        INI_ERR_INVALID_BOOL
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.

	    Similarly sectionid.

		variable is set to true if the value of the key is equal to 'true' or '1'
		variable is set to false if the value of the key is equal to 'false' or '0'
	</remarks>
	<example>
	INI::ReadBool(handle,res,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadBool(handle,res,"KEY"); //Searches for KEY in the global section
	INI::ReadBool(handle,res,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadBool(handle,res,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadBool(INI:filehandle,&bool:variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	#if INI_WRITE_TRUE_VALUE_SIZE > INI_WRITE_FALSE_VALUE_SIZE
	static result[INI_WRITE_TRUE_VALUE_SIZE];
	#else
	static result[INI_WRITE_FALSE_VALUE_SIZE];
	#endif
	new ret_num = INI::ReadString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
	if(ret_num > -1)
	{
	    if(!strcmp(result,INI_WRITE_TRUE_VALUE,true) || !strcmp(result,"1")) variable = true;
		else if(!strcmp(result,INI_WRITE_FALSE_VALUE,true) && !strcmp(result,"0")) variable = false;
		else return INI_ERR_INVALID_BOOL;
	}
	return ret_num;
}
/*******************************************************************************************************************************
	<summary>ReadInteger</summary>
 	<para>Reads the value of a key and sets variable to the value</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">The value of the key will be saved here</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE

		variable left unchanged if an error occured

		can abuse this by setting variable to a value that this function would not set variable to
		and check if an error had occured
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.

	    Similarly sectionid.
	</remarks>
	<example>
	INI::ReadInteger(handle,res,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadInteger(handle,res,"KEY"); //Searches for KEY in the global section
	INI::ReadInteger(handle,res,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadInteger(handle,res,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadInteger(INI:filehandle,&variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	static result[INI_INTEGER_DIGITS];
	new ret_num = INI::ReadString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
	if(ret_num > -1) variable = strval(result);
	return ret_num;
}
/*******************************************************************************************************************************
	<summary>ReadFloat</summary>
 	<para>Reads the value of a key and sets variable to the value</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">The value of the key will be saved here</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE

		variable left unchanged if an error occured

		can abuse this by setting variable to a value that this function would not set variable to
		and check if an error had occured
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.

	    Similarly sectionid.
	</remarks>
	<example>
	INI::ReadFloat(handle,res,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadFloat(handle,res,"KEY"); //Searches for KEY in the global section
	INI::ReadFloat(handle,res,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadFloat(handle,res,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadFloat(INI:filehandle,&Float:variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	static result[INI_FLOATING_POINT_PRECISION];
	new ret_num = INI::ReadString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
	if(ret_num > -1) variable = floatstr(result);
	return ret_num;
}
/*******************************************************************************************************************************
	<summary>ReadHex</summary>
 	<para>Reads the value of a key and sets variable to the value</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">The value of the key will be saved here</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE

		variable left unchanged if an error occured

		can abuse this by setting variable to a value that this function would not set variable to
		and check if an error had occured
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.

	    Similarly sectionid.
	</remarks>
	<example>
	INI::ReadHex(handle,res,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadHex(handle,res,"KEY"); //Searches for KEY in the global section
	INI::ReadHex(handle,res,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadHex(handle,res,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadHex(INI:filehandle,&variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	static result[INI_HEX_DIGITS];
	new ret_num = INI::ReadString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
	if(ret_num > -1) variable = intrl_EINI_HexadecimalToDecimal(result);
	return ret_num;
}
/*******************************************************************************************************************************
	<summary>ReadBinary</summary>
 	<para>Reads the value of a key and sets variable to the value</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">The value of the key will be saved here</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE

		variable left unchanged if an error occured

		can abuse this by setting variable to a value that this function would not set variable to
		and check if an error had occured
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.

	    Similarly sectionid.
	</remarks>
	<example>
	INI::ReadBinary(handle,res,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadBinary(handle,res,"KEY"); //Searches for KEY in the global section
	INI::ReadBinary(handle,res,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadBinary(handle,res,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadBinary(INI:filehandle,&variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	static result[INI_BIN_DIGITS];
	new ret_num = INI::ReadString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
	if(ret_num > -1) variable = intrl_EINI_BinaryToDecimal(result);
	return ret_num;
}
/*******************************************************************************************************************************
	<summary>ReadArray</summary>
 	<para>Parses a array key and sets up the given array</para>
	<param name="filehandle">INI Handle</param>
	<param name="array">The array where the data is to be saved</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="array_size">Size of array paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.
	</remarks>
	<example>
	INI::ReadArray(handle,arr,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadArray(handle,arr,"KEY"); //Searches for KEY in the global section
	INI::ReadArray(handle,arr,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadArray(handle,arr,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::ReadArray(INI:filehandle,array[],const key[],const section[]="",keyid=-1,sectionid=-1,array_size=sizeof(array),section_size=sizeof(section),key_size=sizeof(key))
{
	static result[INI_MAX_KEY_VALUE_LENGTH];
	new ret_num = INI::ReadString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
	if(ret_num > -1)
	{
	    new val;
	    for(new i = 0,j = 0;j < array_size;)
	    {
	        switch(result[i])
	        {
	            case ',':
	            {
				  	array[j++] = val;
					val = 0;
	 				i++;
	            }
	            default:
	            {
	                switch(result[i++])
					{

					    case ' ':continue;
					    case '0': val = val*10 + 0;
					    case '1': val = val*10 + 1;
					    case '2': val = val*10 + 2;
					    case '3': val = val*10 + 3;
					    case '4': val = val*10 + 4;
					    case '5': val = val*10 + 5;
					    case '6': val = val*10 + 6;
					    case '7': val = val*10 + 7;
					    case '8': val = val*10 + 8;
					    case '9': val = val*10 + 9;
						default:
						{
                            array[j++] = val;
							val = 0;
			 				i++;
							return ret_num;
						}
					}
	            }
		 	}
	    }
	}
	return ret_num;
}
/*******************************************************************************************************************************
	<summary>ReadEnum</summary>
 	<para>Parses a enum key and sets up the given enum array</para>
	<param name="filehandle">INI Handle</param>
	<param name="enum_array">The enum index where the data has to be loaded</param>
	<param name="enum_size">Size of unit enum</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid(relative to filehandle) if the key is found or an error code
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_HANDLE
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.
	</remarks>
	<example>
	INI::ReadArray(handle,arr,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::ReadArray(handle,arr,"KEY"); //Searches for KEY in the global section
	INI::ReadArray(handle,arr,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::ReadArray(handle,arr,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
#define INI_ReadEnum(%0,%1,%2,%3,%4,%5,%6,%7,%8,%9) ReadArray(%0,%1,%3,%4,%5,%6,%7,%2,%8,%9)
/*******************************************************************************************************************************
	<summary>ReadFormat</summary>
 	<para>Reads multiple values and stores in the variables given</para>
	<param name="filehandle">INI Handle</param>
    <param name="sectionid">Section ID relative to the handle(see remarks)</param>
    <param name="format">Type of each data(see example)</param>
	<params>Give the variable arguments in this format:variable1,key1,variable2,key2</params>
	<returns>
		Returns 0 on success or an error code
		INI_ERR_INVALID_HANDLE
	</returns>
	<remarks>
	    The first section of the file is given a section id 0,the next 1 and so on.
	    The sectionid paramter takes these numbers.This is called relative section id.

	    Specifiers:
	    d,i => integer
	    s => string
	    f => float
	    b => binary
	    x,X => hexadecimal number
	    T,F => boolean number

	    Note that keys must always be valid, the only way to check if there was a failure while reading a key
	    is by setting the arguments to a default value.This will remain unchanged in case of an error.

	    The parsing will stop if an invalid character is found or any other exception occurs
	</remarks>
	<example>
	new pInfo[MAX_PLAYERS][e_pInfo];
	INI::ReadEnum(handle,sid,"isf",myint,"KeyInt",mystr,"KeyStr",myfloat,"KeyFloat"); //Searches for KEY in SECTION
	</example>
*******************************************************************************************************************************/
stock INI::ReadFormat(INI:filehandle,sectionid,const format[],{Float,_}:...)
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]ReadFormat:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]ReadFormat:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	
	static j,result[INI_MAX_KEY_VALUE_LENGTH],key[INI_MAX_KEY_NAME_LENGTH],val1,Float:val2,bool:val3;

    #emit LOAD.S.pri  8
	#emit SHR.C.pri   2
	#emit STOR.pri  j //Get number of arguments

	for(new i = 0,k = 0;(4 + i*2) < j;i++)
	{
	    do
        {
            key[k] = getarg(4 + i*2,k);
        }while(key[k++] != '\0');
	    switch(format[i])
	    {
	        case '\0': return 0;
	        case 'd','i':
	        {
                INI::ReadInteger(filehandle,val1,key,"",-1,sectionid,1,k);
                setarg(3 + i*2,0,val1);
	        }
	        case 's':
	        {
	            INI::ReadString(filehandle,result,key,"",-1,sectionid,INI_MAX_KEY_VALUE_LENGTH,1,k);
				k = 0;
				do
		        {
		            setarg(3 + i*2,k,result[k]);
		        }while(result[k++] != '\0');
	        }
	        case 'f':
	        {
	            INI::ReadFloat(filehandle,val2,key,"",-1,sectionid,1,k);
                setarg(3 + i*2,0,_:val2);
	        }
			case 'b':
			{
			    INI::ReadBinary(filehandle,val1,key,"",-1,sectionid,1,k);
                setarg(3 + i*2,0,val1);
			}
			case 'x','X':
			{
			    INI::ReadHex(filehandle,val1,key,"",-1,sectionid,1,k);
                setarg(3 + i*2,0,val1);
			}
   			case 'T','F':
			{
			    INI::ReadBool(filehandle,val3,key,"",-1,sectionid,1,k);
                setarg(3 + i*2,0,val3);
			}
			default:	return 0;
	    }
	}
	return 0;
}
/*******************************************************************************************************************************
	<summary>Replace</summary>
	<para>Replaces escape characters with their real ASCII Value.Also does custom replacements.</para>
	<param name="src">Soruce Text</param>
	<param name="dest">Destination Array</param>
	<param name="ReplacementFunction">Local Function to be called for Custom Replacement</param>
	<param name="extra">Extra Value to be passed to the Replacement Function</param>
    <param name="pass_extra">Set to true if extra is used</param>
	<param name="sz">Size of src</param>
	<returns>
		Returns 0 always
	</returns>
	<remarks>
	    Destination array should be large enough to hold the string after replacement
	</remarks>
	<example>
	    INI::Replace(src,dest); //Does all the standard replacements
	    INI::Replace(src,dest,"MyFunc",0,false);
	    INI::Replace(src,dest,"MyFunc",playerid,true);
	</example>
*******************************************************************************************************************************/
stock INI::Replace(const src[],dest[],const ReplacementFunction[]="",extra=0,bool:pass_extra=false,sz=sizeof(src),sz_dest=sizeof(dest),sz_rf=sizeof(ReplacementFunction))
{
	static pos,rtext[INI_MAX_REPLACEMENT_TAG];
	for(new i = 0,j = 0;i < sz;i++)
	{
	    switch(src[i])
	    {
	        case '\\':
	        {
	            switch(src[++i])
	            {
	                case '\\':	dest[i - ++j] = '\\';
	                case '0':	dest[i - ++j] = '\0';
	                case 't':	dest[i - ++j] = '\t';
	                case 'r':	dest[i - ++j] = '\r';
	                case 'n':	dest[i - ++j] = '\n';
	                case ';':	dest[i - ++j] = ';';
	                case '#':	dest[i - ++j] = '#';
	                case '[':	dest[i - ++j] = '[';
	                case ']':	dest[i - ++j] = ']';
	            }
	        }
	        case '[':
	        {
	            if(sz_rf > 1)
	            {
		        	pos = strfind(src,"]",false,i);
		        	if(pos == -1)
		        	{
						dest[i-j] = '[';
						continue;
		        	}
		        	else
		        	{
						strmid(rtext,src,++i,pos);
			        	if(pass_extra)
						{
							if(CallLocalFunction(ReplacementFunction,"is",extra,rtext))
							{
                                j += pos - i - strcat(dest,INI_ReplacementText,sz_dest) + 2;
								i = pos;
							}
							else
							{
							    dest[i-j] = '[';
								continue;
							}
						}
						else
						{
							if(CallLocalFunction(ReplacementFunction,"s",rtext))
							{
							    j += pos - i - strcat(dest,INI_ReplacementText,sz_dest) + 2;
								i = pos;
							}
							else
							{
							    dest[i-j] = '[';
								continue;
							}
						}
					}
				}
				else dest[i - j] = src[i];
	        }
	        default:
	        {
	            dest[i - j] = src[i];
	        }
	    }
	}
	return 0;
}
stock INI::SetReplacementText(const text[],sz=sizeof(text))
{
 	return memcpy(INI_ReplacementText,text,0,sz*4 + 4);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************************************************
	<summary>WriteString</summary>
	<para>Sets the value of a key.The key and the section will be created if they don't exist.</para>
	<param name="filehandle">INI Handle</param>
	<param name="data">data to be written (a.k.a value)</param>
	<param name="key">The key whose data is to be changed</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Relative Key ID if known</param>
    <param name="sectionid">Relative Section ID if known</param>
	<param name="data_size">Size of data paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
	<remarks>
	    This function will create the key if it doesn't exist
	</remarks>
    <example>
	INI::WriteString(handle,data,"KEY","SECTION"); //Changes the value of KEY in SECTION (will be created if it doesn't exist)
	INI::WriteString(handle,data,"KEY"); //Changes the value of KEY in global section (will be created if it doesn't exist)
	INI::WriteString(handle,data,"KEY","",-1,sectionid); //Changes the value of KEY in the given section id(Error if it doesn't exist)
	INI::WriteString(handle,data,"","",1); //Changes the value of the key having the given keyid
	</example>
*******************************************************************************************************************************/
stock INI::WriteString(INI:filehandle,const data[],const key[],const section[]="",keyid=-1,sectionid=-1,data_size=sizeof(data),section_size=sizeof(section),key_size=sizeof(key))
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]WriteString:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]WriteString:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	
	if(!INI_File[_:filehandle][E_INI_FILE_parsed])
		if(INI::ParseINI(filehandle))
		{
		    new str[INI_MAX_FILE_NAME_LENGTH];
		    strunpack(str,INI_File[_:filehandle][E_INI_FILE_filename]);
		    INI_Error(filehandle,"[INI]ReadString:Failed to parse file(%s)>>Read Failed",str);
			return INI_ERR_PARSING_FAILED;
		}
	if(--key_size) //removing the null character
	{
	    if(--section_size) //removing the null character
	    {
	        new i = INI_MAX_SECTIONS*_:filehandle;
	        for(new j = i + INI_File[_:filehandle][E_INI_FILE_LoadedSections];i++ < j;)
	        {
	           	if(INI_Section[i][E_INI_SECTION_name][0] == section[0])
	            {
	                if(!strcmp(section,INI_Section[i][E_INI_SECTION_name],_INI_CS))
	                {
	                    //SECTION FOUND
	                    if((j = INI_Section[i][E_INI_SECTION_keystart]) != -1)
	                    {
		                    do
		                    {
		                        if(key[0] == INI_Key[j][E_INI_KEY_name][0])
		                        {
		                            if(!strcmp(key,INI_Key[j][E_INI_KEY_name],_INI_CS))
		                            {
		                                //KEY FOUND
		                                memcpy(INI_Key[j][E_INI_KEY_value],data,0,data_size*4 + 4,INI_MAX_KEY_VALUE_LENGTH);
		                                format(INI_Line[INI_Key[j][E_INI_KEY_lineid]][E_INI_LINE_Content],INI_MAX_LINE_LENGTH,"%s=%s\r\n",key,data);
		                                return (j - INI_MAX_KEYS*_:filehandle);
	                            	}
                        		}
                		    }while((j = INI_Key[j][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
                            return ini_internal_CreateKey(filehandle,key,data,i);
 						}
					}
	            }
	        }
	        if((i = ini_internal_CreateSection(filehandle,section)) > -1)
	        	return ini_internal_CreateKey(filehandle,key,data,i);
			else return INI_SECTION_CREATE_FAILED;
		}
		else if(sectionid > -1)
		{
		  	if(-1 < sectionid <= INI_File[_:filehandle][E_INI_FILE_LoadedSections])
		    {
		       	new j = INI_Section[INI_MAX_SECTIONS*_:filehandle + sectionid][E_INI_SECTION_keystart];
				if(j != -1)
	            {
	                do
		            {
		               	if(key[0] == INI_Key[j][E_INI_KEY_name][0])
		                {
		                   	if(!strcmp(key,INI_Key[j][E_INI_KEY_name],_INI_CS))
		                    {
		                       	//KEY FOUND
		                        memcpy(INI_Key[j][E_INI_KEY_value],data,0,data_size*4 + 4,INI_MAX_KEY_VALUE_LENGTH);
		                        format(INI_Line[INI_Key[j][E_INI_KEY_lineid]][E_INI_LINE_Content],INI_MAX_LINE_LENGTH,"%s=%s\r\n",key,data);
		                        return (j - INI_MAX_KEYS*_:filehandle);
		                    }
	                 	}
              		}while((j=INI_Key[j][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
				}
				return ini_internal_CreateKey(filehandle,key,data,sectionid);
	    	}
		    else
		    {
		        INI_Error(filehandle,"[INI]WriteString:Invalid Section ID (%d)",sectionid);
		    	return INI_ERR_INVALID_ID;
			}
		}
		else
		{
		    new i = INI_Section[0][E_INI_SECTION_keystart];
		    if(i != -1)
	        {
		    	do
		       	{
		        	if(key[0] == INI_Key[i][E_INI_KEY_name][0])
		         	{
		            	if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
		            	{
		              		//KEY FOUND
		              		memcpy(INI_Key[i][E_INI_KEY_value],data,0,data_size*4 + 4,INI_MAX_KEY_VALUE_LENGTH);
              				format(INI_Line[INI_Key[i][E_INI_KEY_lineid]][E_INI_LINE_Content],INI_MAX_LINE_LENGTH,"%s=%s\r\n",key,data);
              				return (i - INI_MAX_KEYS*_:filehandle);
		 				}
		   			}
				}while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
			}
			return ini_internal_CreateKey(filehandle,key,data,0);
		}
	}
    else if(keyid > -1)
	{
	    if(-1 < keyid < INI_File[_:filehandle][E_INI_FILE_LoadedKeys])
        {
            new tmp = INI_MAX_KEYS*_:filehandle + keyid;
            if(INI_Key[tmp][E_INI_KEY_sectionid] > -1)
		    {
				memcpy(INI_Key[tmp][E_INI_KEY_value],data,0,data_size*4 + 4,INI_MAX_KEY_VALUE_LENGTH);
		        format(INI_Line[INI_Key[tmp][E_INI_KEY_lineid]][E_INI_LINE_Content],INI_MAX_LINE_LENGTH,"%s=%s\r\n",INI_Key[tmp][E_INI_KEY_name],data);
				return keyid;
	   		}
        }
        else
        {
	       	INI_Error(filehandle,"[INI]WriteString:Non-existant Key ID (%d)",keyid);
	    	return INI_KEY_NOT_FOUND;
      	}
   	}
    INI_Notice(filehandle,"[INI]WriteString:Invalid Parameters");
	return INI_KEY_NOT_FOUND;
}
/*******************************************************************************************************************************
	<summary>WriteBool</summary>
	<para>Sets the value of a key to the given boolean value</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">value to be set</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Relative Key ID if known</param>
    <param name="sectionid">Relative Section ID if known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
    <example>
	INI::WriteBool(handle,var,"KEY","SECTION"); //Changes the value of KEY in SECTION (will be created if it doesn't exist)
	INI::WriteBool(handle,var,"KEY"); //Changes the value of KEY in global section (will be created if it doesn't exist)
	INI::WriteBool(handle,var,"KEY","",-1,sectionid); //Changes the value of KEY in the given section id(Error if it doesn't exist)
	INI::WriteBool(handle,var,"","",1); //Changes the value of the key having the given keyid
	</example>
*******************************************************************************************************************************/
stock INI::WriteBool(INI:filehandle,bool:variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	if(variable)
        return INI::WriteString(filehandle,INI_WRITE_TRUE_VALUE,key,section,keyid,sectionid,INI_WRITE_TRUE_VALUE_SIZE,section_size,key_size);
	else
		return INI::WriteString(filehandle,INI_WRITE_FALSE_VALUE,key,section,keyid,sectionid,INI_WRITE_TRUE_VALUE_SIZE,section_size,key_size);
}
/*******************************************************************************************************************************
	<summary>WriteInteger</summary>
	<para>Sets the value of the key to the given integer</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">value to be set</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Relative Key ID if known</param>
    <param name="sectionid">Relative Section ID if known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
    <example>
	INI::WriteInteger(handle,var,"KEY","SECTION"); //Changes the value of KEY in SECTION (will be created if it doesn't exist)
	INI::WriteInteger(handle,var,"KEY"); //Changes the value of KEY in global section (will be created if it doesn't exist)
	INI::WriteInteger(handle,var,"KEY","",-1,sectionid); //Changes the value of KEY in the given section id(Error if it doesn't exist)
	INI::WriteInteger(handle,var,"","",1); //Changes the value of the key having the given keyid
	</example>
*******************************************************************************************************************************/
stock INI::WriteInteger(INI:filehandle,variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	new result[INI_INTEGER_DIGITS]; //Assuming integers to be of 32bit so it can go up to billion = 10 digits
	valstr(result,variable);
	return INI::WriteString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
}
/*******************************************************************************************************************************
	<summary>WriteFloat</summary>
	<para>Sets the value of a key to the given float</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">value to be set</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Set to -1 if the sectionid is not known</param>
    <param name="sectionid">Set to -1 if the sectionid is not known</param>
	<param name="data_size">Size of result paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
    <example>
	INI::WriteFloat(handle,data,"KEY","SECTION"); //Changes the value of KEY in SECTION (will be created if it doesn't exist)
	INI::WriteFloat(handle,data,"KEY"); //Changes the value of KEY in global section (will be created if it doesn't exist)
	INI::WriteFloat(handle,data,"KEY","",-1,sectionid); //Changes the value of KEY in the given section id(Error if it doesn't exist)
	INI::WriteFloat(handle,data,"","",1); //Changes the value of the key having the given keyid
	</example>
*******************************************************************************************************************************/
stock INI::WriteFloat(INI:filehandle,Float:variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
 	new result[INI_FLOATING_POINT_PRECISION];
	format(result,INI_FLOATING_POINT_PRECISION,"%f",variable);
	return INI::WriteString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
}
/*******************************************************************************************************************************
	<summary>WriteHex</summary>
	<para>Sets the value of a key to the given integer in hexadecimal notation</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">value to be set</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Set to -1 if the sectionid is not known</param>
    <param name="sectionid">Set to -1 if the sectionid is not known</param>
	<param name="data_size">Size of result paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
    <example>
	INI::WriteHex(handle,data,"KEY","SECTION"); //Changes the value of KEY in SECTION (will be created if it doesn't exist)
	INI::WriteHex(handle,data,"KEY"); //Changes the value of KEY in global section (will be created if it doesn't exist)
	INI::WriteHex(handle,data,"KEY","",-1,sectionid); //Changes the value of KEY in the given section id(Error if it doesn't exist)
	INI::WriteHex(handle,data,"","",1); //Changes the value of the key having the given keyid
	</example>
*******************************************************************************************************************************/
stock INI::WriteHex(INI:filehandle,variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	new result[INI_HEX_DIGITS];
	format(result,INI_FLOATING_POINT_PRECISION,"0x%x",variable);
	return INI::WriteString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
}
/*******************************************************************************************************************************
	<summary>WriteBinary</summary>
	<para>Sets the value of a key to the given integer in binary form</para>
	<param name="filehandle">INI Handle</param>
	<param name="variable">value to be set</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Set to -1 if the sectionid is not known</param>
    <param name="sectionid">Set to -1 if the sectionid is not known</param>
	<param name="data_size">Size of result paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
    <example>
	INI::WriteBinary(handle,data,"KEY","SECTION"); //Changes the value of KEY in SECTION (will be created if it doesn't exist)
	INI::WriteBinary(handle,data,"KEY"); //Changes the value of KEY in global section (will be created if it doesn't exist)
	INI::WriteBinary(handle,data,"KEY","",-1,sectionid); //Changes the value of KEY in the given section id(Error if it doesn't exist)
	INI::WriteBinary(handle,data,"","",1); //Changes the value of the key having the given keyid
	</example>
*******************************************************************************************************************************/
stock INI::WriteBinary(INI:filehandle,variable,const key[],const section[]="",keyid=-1,sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	new result[INI_FLOATING_POINT_PRECISION];
	format(result,INI_FLOATING_POINT_PRECISION,"%b",variable);
	return INI::WriteString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
}
/*******************************************************************************************************************************
	<summary>WriteArray</summary>
 	<para>Sets an array key</para>
	<param name="filehandle">File Handle ID of the file to be closed</param>
	<param name="array">The array to be saved</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="array_size">Size of array paramter</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
	<remarks>
	    The first key of the file is given a key id 0,the next 1 and so on.
	    The keyid paramter takes these numbers.

	    Similarly sectionid.
	</remarks>
	<example>
	INI::WriteArray(handle,arr,"KEY","SECTION"); //Searches for KEY in SECTION
	INI::WriteArray(handle,arr,"KEY"); //Searches for KEY in the global section
	INI::WriteArray(handle,arr,"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::WriteArray(handle,arr,"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
stock INI::WriteArray(INI:filehandle,array[],const key[]="",const section[]="",keyid=-1,sectionid=-1,array_size=sizeof(array),section_size=sizeof(section),key_size=sizeof(key))
{
	new result[INI_MAX_KEY_VALUE_LENGTH],sint[INI_INTEGER_DIGITS];
	for(new i = 0; i < array_size;i++)
	{
	    if(i)	strcat(result,",");
	    valstr(sint,array[i]);
		strcat(result,sint);
	}
	return INI::WriteString(filehandle,result,key,section,keyid,sectionid,sizeof(result),section_size,key_size);
}
/*******************************************************************************************************************************
	<summary>WriteEnum</summary>
 	<para>Parses a enum key and sets up the given enum array</para>
	<param name="filehandle">File Handle ID of the file to be closed</param>
	<param name="enum_array">The enum index where the data is present</param>
	<param name="enum_size">Size of unit enum</param>
	<param name="key">Key to search for</param>
	<param name="section">The section where the key resides(leave null if the key is in global section)</param>
	<param name="keyid">Key ID relative to the handle(see remarks).Set to -1 if keyid not known</param>
    <param name="sectionid">Section ID relative to the handle(see remarks).Set to -1 if the sectionid is not known</param>
	<param name="section_size">Size of section parameter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns keyid of the updated/created key or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_PARSING_FAILED
	</returns>
	<example>
	INI::WriteEnum(handle,arr[1],sizeof(arr[]),"KEY","SECTION"); //Searches for KEY in SECTION
	INI::WriteEnum(handle,arr[2],sizeof(arr[]),"KEY"); //Searches for KEY in the global section
	INI::WriteEnum(handle,arr[1],sizeof(arr[]),"KEY","",-1,sectionid); //Searches for KEY in section with id sectionid
	INI::WriteEnum(handle,arr[4],sizeof(arr[]),"","",1); //Gets the value of key with keyid 1
	</example>
*******************************************************************************************************************************/
#define ReadEnum(%0,%1,%2,%3,%4,%5,%6,%7,%8,%9) ReadArray(%0,%1,%3,%4,%5,%6,%7,%2,%8,%9)
/*******************************************************************************************************************************
	<summary>WriteFormat</summary>
 	<para>Reads multiple values and stores in the variables given</para>
	<param name="filehandle">INI Handle</param>
    <param name="sectionid">Section ID relative to the handle(see remarks)</param>
    <param name="format">Type of each data(see example)</param>
	<params>Write variable1,key1,variable2,key2</params>
	<returns>
		Returns 0 on success or an error code
  		INI_ERR_INVALID_HANDLE
	</returns>
	<remarks>
	    Specifiers:
	    d,i => integer
	    s => string
	    f => float
	    b => binary
	    x,X => hexadecimal number
	    T,F => boolean number
	</remarks>
	<example>
	new pInfo[MAX_PLAYERS][e_pInfo];
	INI::ReadEnum(handle,sid,"isf",myint,"KeyInt",mystr,"KeyStr",myfloat,"KeyFloat"); //Searches for KEY in SECTION
	</example>
*******************************************************************************************************************************/
stock INI::WriteFormat(INI:filehandle,sectionid,const format[],{Float,_}:...)
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]ReadFormat:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]ReadFormat:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	
	static j,result[INI_MAX_KEY_VALUE_LENGTH],key[INI_MAX_KEY_NAME_LENGTH];
	
	#emit LOAD.S.pri  8
	#emit SHR.C.pri   2
	#emit STOR.pri  j //Get number of arguments
	
	for(new i = 0,k = 0;(4 + i*2) < j;i++)
	{
	    do
        {
            key[k] = getarg(4 + i*2,k);
        }while(key[k++] != '\0');

	    switch(format[i])
	    {
	        case '\0': return 0;
	        case 'd','i':	INI::WriteInteger(filehandle,getarg(3 + i*2,0),key,"",-1,sectionid,1,k);
	        case 's':
	        {
	            k = 0;
			    do
		        {
		            result[k] = getarg(3 + i*2,k);
		        }while(result[k++] != '\0');
	            INI::WriteString(filehandle,result,key,"",-1,sectionid,INI_MAX_KEY_VALUE_LENGTH,1,k);
	        }
	        case 'f':	INI::WriteFloat(filehandle,Float:getarg(3 + i*2,0),key,"",-1,sectionid,1,k);
			case 'b':	INI::WriteBinary(filehandle,getarg(3 + i*2,0),key,"",-1,sectionid,1,k);
			case 'x','X':	INI::WriteHex(filehandle,getarg(3 + i*2,0),key,"",-1,sectionid,1,k);
   			case 'T','F':  	INI::WriteBool(filehandle,bool:getarg(3 + i*2,0),key,"",-1,sectionid,1,k);
			default:	return 0;
	    }
	}
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************************************************
	<summary>DeleteSection</summary>
	<para>Deletes a section</para>
	<param name="filehandle">INI Handle</param>
	<param name="section">Section to delete (leave null to indicate global section)</param>
	<param name="sectionid">relative section id if known</param>
	<param name="section_size">Size of section parameter</param>
	<returns>
		Returns 0 on success or an error code
		INI_ERR_INVALID_HANDLE
		INI_SECTION_NOT_FOUND
		INI_ERR_INVALID_ID
	</returns>
    <example>
	new id = INI::DeleteSection(handle,"MYSECTION"); //Deletes MYSECTION
	new id = INI::DeleteSection(handle,""); //Deletes Global Section
	new id = INI::DeleteSection(handle,"",1); //Deletes Section with sectionid 1
	</example>
*******************************************************************************************************************************/
stock INI::DeleteSection(INI:filehandle,const section[]="",sectionid=-1,section_size=sizeof(section))
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]DeleteSection:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]DeleteSection:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(--section_size)
	{
		if((sectionid = INI::GetSectionID(filehandle,section,section_size+1)) < 0) return INI_SECTION_NOT_FOUND;
	}
	else if(sectionid > -1)
	{
     	if(sectionid > INI_File[_:filehandle][E_INI_FILE_LoadedSections])
		{
		    INI_Error(filehandle,"[INI]WriteString:Invalid Section ID (%d)",sectionid);
		    return INI_ERR_INVALID_ID;
		}
	}
	else
	    sectionid = 0;

    new i = INI_MAX_SECTIONS*_:filehandle + sectionid;
    new k,n = INI_Section[i][E_INI_SECTION_lineid];
    INI_Section[i][E_INI_SECTION_sectionid] = INI_DEFAULT_FILL;
    new j = INI_Section[i][E_INI_SECTION_keystart];
    if(j == INI_LINKED_LIST_NULL)
	{
	    if(INI_Line[n][E_INI_LINE_previous] == INI_LINKED_LIST_NULL)
		{
		    INI_File[_:filehandle][E_INI_FILE_start_lineid] = INI_Line[n][E_INI_LINE_next];
		    INI_Line[INI_Line[n][E_INI_LINE_next]][E_INI_LINE_previous] = INI_LINKED_LIST_NULL;
		}
		else
		{
		    INI_Line[INI_Line[n][E_INI_LINE_previous]][E_INI_LINE_next] = INI_Line[n][E_INI_LINE_next];
		    INI_Line[INI_Line[n][E_INI_LINE_next]][E_INI_LINE_previous] = INI_Line[n][E_INI_LINE_previous];
		}
	}
	else
	{
		for(;;)
		{
		 	k = INI_Key[j][E_INI_KEY_lineid];
		    INI_Line[k][E_INI_LINE_type] = INI_DEFAULT_FILL;
		    INI_Key[j][E_INI_KEY_sectionid] = INI_DEFAULT_FILL;
		    if((j = INI_Key[j][E_INI_KEY_next]) == INI_LINKED_LIST_NULL)
		    {
				if(INI_Line[n][E_INI_LINE_previous] == INI_LINKED_LIST_NULL)
				{
		         	INI_File[_:filehandle][E_INI_FILE_start_lineid] = INI_Line[k][E_INI_LINE_next];
	                INI_Line[INI_Line[k][E_INI_LINE_next]][E_INI_LINE_previous] = INI_LINKED_LIST_NULL;
				}
				else
				{
				    INI_Line[INI_Line[n][E_INI_LINE_previous]][E_INI_LINE_next] = INI_Line[k][E_INI_LINE_next];
				    INI_Line[INI_Line[k][E_INI_LINE_next]][E_INI_LINE_previous] = INI_Line[n][E_INI_LINE_previous];
				}
				INI_Line[k][E_INI_LINE_previous] = INI_Line[k][E_INI_LINE_next] = INI_LINKED_LIST_NULL;
				break;
		    }
		    else
		    {
		       INI_Line[k][E_INI_LINE_previous] = INI_Line[k][E_INI_LINE_next] = INI_LINKED_LIST_NULL;
		    }
		}
        INI_Line[n][E_INI_LINE_type] = INI_DEFAULT_FILL;
        INI_Line[n][E_INI_LINE_previous] = INI_Line[n][E_INI_LINE_next] = INI_LINKED_LIST_NULL;
	}
    return 0;
}
/*******************************************************************************************************************************
	<summary>DeleteKey</summary>
	<para>Deletes a key</para>
	<param name="filehandle">INI Handle</param>
	<param name="key">key to be deleted</param>
	<param name="section">Section in which the key resides (leave null to indicate global section)</param>
	<param name="keyid">relative key id if known</param>
	<param name="sectionid">relative section id if known</param>
	<param name="key_size">Size of key parameter</param>
	<param name="section_size">Size of section parameter</param>
	<returns>
		Returns 0 on success or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
		INI_ERR_INVALID_ID
	</returns>
    <example>
	new id = INI::DeleteKey(handle,"MYKEY","MYSECTION"); //Deletes MYKEY from MYSECTION
	new id = INI::DeleteKey(handle,"MYKEY"); //Deletes MYKEY from Global Section
	new id = INI::DeleteKey(handle,"","",1); //Deletes the key with key id 1
	new id = INI::DeleteKey(handle,"MYKEY","","-1",1); //Deletes MYKEY from the section with id 1
	</example>
*******************************************************************************************************************************/
stock INI::DeleteKey(INI:filehandle,const key[],const section[]="",keyid=-1,sectionid=-1,key_size=sizeof(key),section_size=sizeof(section))
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]DeleteKey:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]DeleteKey:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(key_size > 1)
	{
		if((keyid = INI::GetKeyID(INI:filehandle,key,section,sectionid,section_size,key_size)) < 0) return INI_KEY_NOT_FOUND;
	}
	else if(keyid > -1)
	{
	    if(keyid > INI_File[_:filehandle][E_INI_FILE_LoadedKeys])
		{
		    INI_Error(filehandle,"[INI]DeleteKey:Invalid Key ID (%d)",keyid);
		    return INI_ERR_INVALID_ID;
		}
	}
	else
	{
	    INI_Notice(filehandle,"[INI]DeleteKey:Invalid Parameters");
		return INI_KEY_NOT_FOUND;
	}
	new i = INI_Key[keyid][E_INI_KEY_lineid];
	INI_Key[keyid][E_INI_KEY_sectionid] = INI_Line[i][E_INI_LINE_type] = INI_DEFAULT_FILL;
	if(INI_Line[i][E_INI_LINE_previous] == INI_LINKED_LIST_NULL)
	{
	    INI_File[_:filehandle][E_INI_FILE_start_lineid] = INI_Line[i][E_INI_LINE_next];
     	INI_Line[INI_Line[i][E_INI_LINE_next]][E_INI_LINE_previous] = INI_LINKED_LIST_NULL;
	}
	else
	{
	    INI_Line[INI_Line[i][E_INI_LINE_next]][E_INI_LINE_previous] = INI_Line[i][E_INI_LINE_previous];
	    INI_Line[INI_Line[i][E_INI_LINE_previous]][E_INI_LINE_next] = INI_Line[i][E_INI_LINE_next];
	}
	INI_Line[i][E_INI_LINE_next] = INI_Line[i][E_INI_LINE_previous] = INI_LINKED_LIST_NULL;
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************************************************
	<summary>GetSectionID</summary>
	<para>Finds the relative section id</para>
	<param name="filehandle">INI Handle</param>
	<param name="section">Section whose relative id is required(leave null to search global section)</param>
	<param name="section_size">Size of section parameter</param>
	<returns>
		Returns the relative section id or an error code
		INI_ERR_INVALID_HANDLE
		INI_SECTION_NOT_FOUND
	</returns>
    <example>
	new id = INI::GetSectionID(handle,"MYSECTION");
	</example>
*******************************************************************************************************************************/
stock INI::GetSectionID(INI:filehandle,const section[],section_size=sizeof(section))
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]GetSectionID:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]GetSectionID:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(!INI_File[_:filehandle][E_INI_FILE_parsed])
		if(INI::ParseINI(filehandle))
		{
		    new str[INI_MAX_FILE_NAME_LENGTH];
		    strunpack(str,INI_File[_:filehandle][E_INI_FILE_filename]);
		    INI_Error(filehandle,"[INI]ReadString:Failed to parse file(%s)>>Read Failed",str);
			return INI_ERR_PARSING_FAILED;
		}
	if(--section_size)
	{
        new i = INI_MAX_SECTIONS*_:filehandle;
		for(new j = i + INI_File[_:filehandle][E_INI_FILE_LoadedSections];++i <= j;)
		{
			if(INI_Section[i][E_INI_SECTION_name][0] == section[0])
		    {
		     	if(!strcmp(section,INI_Section[i][E_INI_SECTION_name],_INI_CS))
		     	    return (i-INI_MAX_SECTIONS*_:filehandle);
		 	}
		}
		return INI_SECTION_NOT_FOUND;
	}
	else	return 0;
}
/*******************************************************************************************************************************
	<summary>GetKeyID</summary>
	<para>Finds the relative key id</para>
	<param name="filehandle">INI Handle</param>
	<param name="key">Key whose relative id is required</param>
	<param name="section">Section where the key resides if sectionid is not known</param>
	<param name="sectionid">Section ID if known</param>
	<param name="section_size">Size of section paramter</param>
	<param name="key_size">Size of key parameter</param>
	<returns>
		Returns the relative section id or an error code
		INI_ERR_INVALID_HANDLE
		INI_KEY_NOT_FOUND
	</returns>
    <example>
	new id = INI::GetKeyID(handle,"MYKEY","MYSECTION"); //Search for MYKEY in MYSECTION
	new id = INI::GetKeyID(handle,"MYKEY"); //Search for MYKEY in global section
	new id = INI::GetKeyID(handle,"MYKEY","",1); //Search for MYKEY in section with id 1
	</example>
*******************************************************************************************************************************/
stock INI::GetKeyID(INI:filehandle,const key[],const section[]="",sectionid=-1,section_size=sizeof(section),key_size=sizeof(key))
{
	#if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]GetSectionID:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]GetSectionID:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(--key_size) //removing the null character
	{
	    if(--section_size) //removing the null character
	    {
			new sid = INI::GetSectionID(filehandle,section,section_size+1);
			if(sid < 0) return INI_SECTION_NOT_FOUND;
			new i = INI_Section[INI_MAX_SECTIONS*_:filehandle + sid][E_INI_SECTION_keystart];
			do
			{
				if(INI_Key[i][E_INI_KEY_name][0] == key[0])
			    {
			     	if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
			     	    return (i-INI_MAX_KEYS*_:filehandle);
			 	}
			}while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
			INI_Notice(filehandle,"[INI]GetKeyID:Key not found (Key:%s Section:%s)",key,section);
	   		return INI_KEY_NOT_FOUND;
		}
		else if(sectionid > -1)
		{
		    if(!INI_File[_:filehandle][E_INI_FILE_parsed])
				if(INI::ParseINI(filehandle))
				{
				    new str[INI_MAX_FILE_NAME_LENGTH];
				    strunpack(str,INI_File[_:filehandle][E_INI_FILE_filename]);
				    INI_Error(filehandle,"[INI]ReadString:Failed to parse file(%s)>>Read Failed",str);
					return INI_ERR_PARSING_FAILED;
				}
		  	if(sectionid >= INI_File[_:filehandle][E_INI_FILE_LoadedSections])
		    {
		        INI_Error(filehandle,"[INI]GetKeyID:Invalid Section ID (%d)",sectionid);
		    	return INI_ERR_INVALID_ID;
	      	}
		    new i = INI_Section[INI_MAX_SECTIONS*_:filehandle + sectionid][E_INI_SECTION_keystart];
			do
			{
				if(INI_Key[i][E_INI_KEY_name][0] == key[0])
			    {
			     	if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
			     	    return (i-INI_MAX_KEYS*_:filehandle);
			 	}
			}while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
			INI_Notice(filehandle,"[INI]GetKeyID:Key not found (Key:%s Section:%s)",key,section);
	   		return INI_KEY_NOT_FOUND;
		}
		else
		{
		    if(!INI_File[_:filehandle][E_INI_FILE_parsed])
				if(INI::ParseINI(filehandle))
				{
				    new str[INI_MAX_FILE_NAME_LENGTH];
				    strunpack(str,INI_File[_:filehandle][E_INI_FILE_filename]);
				    INI_Error(filehandle,"[INI]ReadString:Failed to parse file(%s)>>Read Failed",str);
					return INI_ERR_PARSING_FAILED;
				}
		    new i = INI_Section[INI_MAX_SECTIONS*_:filehandle][E_INI_SECTION_keystart];
			do
			{
				if(INI_Key[i][E_INI_KEY_name][0] == key[0])
			    {
			     	if(!strcmp(key,INI_Key[i][E_INI_KEY_name],_INI_CS))
			     	    return (i-INI_MAX_KEYS*_:filehandle);
			 	}
			}while((i = INI_Key[i][E_INI_KEY_next]) != INI_LINKED_LIST_NULL);
			INI_Notice(filehandle,"[INI]GetKeyID:Key(%s) not found in global section ",key);
	    	return INI_KEY_NOT_FOUND;
		}
	}
    INI_Notice(filehandle,"[INI]GetKeyID:Invalid Parameters",key,sectionid);
	return INI_KEY_NOT_FOUND;
}
/*******************************************************************************************************************************
	<summary>GetKeyName</summary>
	<para>Stores the name of the given key(keyid) in result</para>
	<param name="filehandle">INI Handle</param>
	<param name="result">Array where the name should be stored</param>
	<param name="keyid">Key ID of the key of which the name has to be obtained</param>
	<param name="result_size">Size of result paramter</param>
	<returns>
		Returns INI_ERR_INVALID_ID if the given keyid is invalid
		Returns 0 on sucess
	</returns>
    <example>
	INI::GetKeyName(handle,res,2);
	</example>
*******************************************************************************************************************************/
stock INI::GetKeyName(INI:filehandle,result[],keyid,result_size=sizeof(result))
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]GetKeyName:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]GetKeyName:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(-1 < keyid < INI_File[_:filehandle][E_INI_FILE_LoadedKeys])
	{
	    new i = INI_MAX_KEYS*_:filehandle + keyid;
	    if(INI_Key[i][E_INI_KEY_sectionid] != INI_DEFAULT_FILL)
	    {
	        result[0] = '\0';
		    strcat(result,INI_Key[i][E_INI_KEY_name],result_size);
			return 0;
	    }
	}
	INI_Error(filehandle,"[INI]GetKeyName:Invalid Key ID (%d)",keyid);
	return INI_ERR_INVALID_ID;
}
/*******************************************************************************************************************************
	<summary>GetSectionName</summary>
	<para>Stores the name of the given section(sectionid) in result</para>
	<param name="filehandle">INI Handle</param>
	<param name="result">Array where the name should be stored</param>
	<param name="sectionid">Section ID of the key of which the name has to be obtained</param>
	<param name="result_size">Size of result paramter</param>
	<returns>
		Returns INI_ERR_INVALID_ID if the given sectionid is invalid
		Returns 0 on success
	</returns>
    <example>
	INI::GetSectionName(handle,res,2);
	</example>
*******************************************************************************************************************************/
stock INI::GetSectionName(INI:filehandle,result[],sectionid,result_size=sizeof(result))
{
    #if !defined INI_CAREFUL_MODE
	if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]GetSectionName:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	else { INI_Error(filehandle,"[INI]GetSectionName:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif
	if(-1 < sectionid < INI_File[_:filehandle][E_INI_FILE_LoadedSections])
	{
	    new i = INI_MAX_SECTIONS*_:filehandle + sectionid;
	    if(INI_Section[i][E_INI_SECTION_sectionid] != INI_DEFAULT_FILL)
	    {
	        result[0] = '\0';
		    strcat(result,INI_Section[i][E_INI_SECTION_name],result_size);
			return 0;
	    }
	}
	INI_Error(filehandle,"[INI]GetSectionName:Invalid Key ID (%d)",sectionid);
	return INI_ERR_INVALID_ID;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************************************************
	<summary>DumpINI</summary>
	<para>Dumps all the contents of the INI in the server window</para>
	<param name="filehandle">INI Handle</param>
	<returns>
		Returns error id if an invalid handle is passed
		Returns 0 on success
	</returns>
	<example>
		INI::DumpINI(handle);
	</example>
*******************************************************************************************************************************/
stock INI::DumpINI(INI:filehandle)
{
	#if !defined INI_CAREFUL_MODE
		if(INI:-1 < filehandle < INI:INI_MAX_MULTI_FILES) { if(!IsFileHandleInUse(_:filehandle)){ INI_Error(filehandle,"[INI]DumpINI:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; } }
	    else { INI_Error(filehandle,"[INI]DumpINI:Invalid File Handle ID (%d)",_:filehandle); return INI_ERR_INVALID_HANDLE; }
	#endif

    if(!INI_File[_:filehandle][E_INI_FILE_parsed]) INI::ParseINI(filehandle);
	for(new i = INI_File[_:filehandle][E_INI_FILE_start_lineid];INI_Line[i][E_INI_LINE_type] != INI_LINE_EOF;i = INI_Line[i][E_INI_LINE_next])
	    printf("[DUMP] %s",INI_Line[i][E_INI_LINE_Content]);
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static stock ini_internal_CreateSection(INI:filehandle,const section[])
{
    new sid,j,i;
    if(INI_File[_:filehandle][E_INI_FILE_lines] < (INI_MAX_LINES-1))
	    i = INI_MAX_LINES*_:filehandle + ++INI_File[_:filehandle][E_INI_FILE_lines];
	else
	{
	    for(i = INI_MAX_LINES*_:filehandle,j = INI_MAX_LINES*(1+_:filehandle);;i++)
	        if(i < j) {	if(INI_Line[i][E_INI_LINE_type] == INI_DEFAULT_FILL)	break;  }
			else
			{
			    INI_Notice(filehandle,"[INI]Could not create section %s>>Maximum line limit reached",section);
			    return INI_SECTION_CREATE_FAILED;
			}
	}

	if(INI_File[_:filehandle][E_INI_FILE_LoadedSections] < (INI_MAX_SECTIONS-1))
		sid = INI_MAX_SECTIONS*_:filehandle + ++INI_File[_:filehandle][E_INI_FILE_LoadedSections];
	else
	{
	    for(sid = INI_MAX_SECTIONS*_:filehandle,j = INI_MAX_SECTIONS*(1+_:filehandle);;sid++)
	        if(sid < j) { 	if(INI_Section[sid][E_INI_SECTION_sectionid] == INI_DEFAULT_FILL) break; }
			else
			{
			    INI_Notice(filehandle,"[INI]Could not create section %s>>Maximum sections limit reached",section);
			    return INI_SECTION_CREATE_FAILED;
			}
	}
	INI_Section[sid][E_INI_SECTION_sectionid] = sid - INI_MAX_SECTIONS*_:filehandle;
	INI_Section[sid][E_INI_SECTION_keystart] = INI_LINKED_LIST_NULL;
   	INI_Section[sid][E_INI_SECTION_lineid] = i;

   	format(INI_Section[sid][E_INI_SECTION_name],INI_MAX_SECTION_NAME_LENGTH,"%s",section);

	INI_Line[i][E_INI_LINE_type] = INI_LINE_SECTION_TAG;
	INI_Line[i][E_INI_LINE_id] = sid;
	INI_Line[i][E_INI_LINE_Content][0] = '\0';
	format(INI_Line[i][E_INI_LINE_Content],INI_MAX_LINE_LENGTH,"[%s]\r\n",section);
	j = INI_Line[i][E_INI_LINE_next] = INI_File[_:filehandle][E_INI_FILE_end_lineid];
	if(INI_Line[j][E_INI_LINE_previous] != INI_LINKED_LIST_NULL)
		INI_Line[INI_Line[j][E_INI_LINE_previous]][E_INI_LINE_next] = i;
	else
	    INI_File[_:filehandle][E_INI_FILE_start_lineid] = i;
	INI_Line[i][E_INI_LINE_previous] = INI_Line[j][E_INI_LINE_previous];
	INI_Line[j][E_INI_LINE_previous] = i;
	return sid;
}
static stock ini_internal_CreateKey(INI:filehandle,const key[],const value[],sectionid)
{
    new kid,j,i;

    if(INI_File[_:filehandle][E_INI_FILE_lines] < (INI_MAX_LINES-1))
	    i = INI_MAX_LINES*_:filehandle + ++INI_File[_:filehandle][E_INI_FILE_lines];
	else
	{
	    for(i = INI_MAX_LINES*_:filehandle,j = INI_MAX_LINES*(1+_:filehandle);;i++)
	        if(i < j)	{	if(INI_Line[i][E_INI_LINE_type] == INI_DEFAULT_FILL) break; }
			else
			{
			    INI_Notice(filehandle,"[INI]Could not create key %s>>Maximum line limit reached",key);
			    return INI_KEY_CREATE_FAILED;
			}
	}
	if(INI_File[_:filehandle][E_INI_FILE_LoadedKeys] < (INI_MAX_KEYS-1))
		kid = INI_MAX_KEYS*_:filehandle + INI_File[_:filehandle][E_INI_FILE_LoadedKeys]++;
	else
	{
	    for(kid = INI_MAX_KEYS*_:filehandle,j = INI_MAX_KEYS*(1+_:filehandle);;kid++)
	        if(kid < j) {	if(INI_Key[kid][E_INI_KEY_sectionid] == INI_DEFAULT_FILL) break; }
			else
			{
			    INI_Notice(filehandle,"[INI]Could not create key %s>>Maximum keys limit reached",key);
			    return INI_KEY_CREATE_FAILED;
			}
	}
	INI_Key[kid][E_INI_KEY_sectionid] = sectionid;
	INI_Key[kid][E_INI_KEY_lineid] = i;

	format(INI_Key[kid][E_INI_KEY_name],INI_MAX_KEY_NAME_LENGTH,"%s",key);
	format(INI_Key[kid][E_INI_KEY_value],INI_MAX_KEY_VALUE_LENGTH,"%s",value);

	if(sectionid == 0)
	    INI_Line[i][E_INI_LINE_type] = INI_LINE_GLOBAL_KEY;
	else
		INI_Line[i][E_INI_LINE_type] = INI_LINE_SECTION_KEY;

	INI_Line[i][E_INI_LINE_id] = kid;

	format(INI_Line[i][E_INI_LINE_Content],INI_MAX_LINE_LENGTH,"%s=%s\r\n",key,value);

	if(INI_Section[sectionid][E_INI_SECTION_keystart] == INI_DEFAULT_FILL)
	{
	    INI_Key[kid][E_INI_KEY_next] = INI_LINKED_LIST_NULL;
		INI_Key[kid][E_INI_KEY_previous] = INI_LINKED_LIST_NULL;
		INI_Section[sectionid][E_INI_SECTION_keystart] = kid;
	}
	else
	{
	    new t = INI_Section[sectionid][E_INI_SECTION_keystart];
	    INI_Key[kid][E_INI_KEY_next] = t;
	    INI_Key[t][E_INI_KEY_previous] = kid;
		INI_Key[kid][E_INI_KEY_previous] = INI_LINKED_LIST_NULL;
		INI_Section[sectionid][E_INI_SECTION_keystart] = kid;
	}
	if(sectionid)
	{
	    j = INI_Section[sectionid][E_INI_SECTION_lineid];
	    INI_Line[i][E_INI_LINE_next] = INI_Line[j][E_INI_LINE_next];
	    INI_Line[i][E_INI_LINE_previous] = j;
	    INI_Line[INI_Line[j][E_INI_LINE_next]][E_INI_LINE_previous] = INI_Line[j][E_INI_LINE_next] = i;
	}
	else
	{
	    j = INI_File[_:filehandle][E_INI_FILE_start_lineid];
	    INI_Line[i][E_INI_LINE_next] = j;
	    INI_Line[i][E_INI_LINE_previous] = INI_LINKED_LIST_NULL;
	    INI_File[_:filehandle][E_INI_FILE_start_lineid] = INI_Line[j][E_INI_LINE_previous] = i;
	}
	return kid;
}
