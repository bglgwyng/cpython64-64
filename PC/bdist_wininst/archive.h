/*
  IMPORTANT NOTE: IF THIS FILE IS CHANGED, WININST-6.EXE MUST BE RECOMPILED
  WITH THE MSVC6 WININST.DSW WORKSPACE FILE MANUALLY, AND WININST-7.1.EXE MUST
  BE RECOMPILED WITH THE MSVC 2003.NET WININST-7.1.VCPROJ FILE MANUALLY.

  IF CHANGES TO THIS FILE ARE CHECKED INTO PYTHON CVS, THE RECOMPILED BINARIES
  MUST BE CHECKED IN AS WELL!
*/

#pragma pack(1)

/* zip-archive headers
 * See: http://www.pkware.com/appnote.html
 */

#ifndef REALLYLONG
typedef long long REALLYLONG;
#endif
#ifndef UREALLYLONG
typedef unsigned long long UREALLYLONG;
#endif
#ifndef NATIVELONG
typedef long NATIVELONG;
#endif
#ifndef UNATIVELONG
typedef unsigned long UNATIVELONG;
#endif

struct eof_cdir {
    NATIVELONG tag;           /* must be 0x06054b50 */
    short disknum;
    short firstdisk;
    short nTotalCDirThis;
    short nTotalCDir;
    NATIVELONG nBytesCDir;
    NATIVELONG ofsCDir;
    short commentlen;
};

struct cdir {
    NATIVELONG tag;           /* must be 0x02014b50 */
    short version_made;
    short version_extract;
    short gp_bitflag;
    short comp_method;
    short last_mod_file_time;
    short last_mod_file_date;
    NATIVELONG crc32;
    NATIVELONG comp_size;
    NATIVELONG uncomp_size;
    short fname_length;
    short extra_length;
    short comment_length;
    short disknum_start;
    short int_file_attr;
    NATIVELONG ext_file_attr;
    NATIVELONG ofs_local_header;
};

struct fhdr {
    NATIVELONG tag;           /* must be 0x04034b50 */
    short version_needed;
    short flags;
    short method;
    short last_mod_file_time;
    short last_mod_file_date;
    NATIVELONG crc32;
    NATIVELONG comp_size;
    NATIVELONG uncomp_size;
    short fname_length;
    short extra_length;
};


struct meta_data_hdr {
    int tag;
    int uncomp_size;
    int bitmap_size;
};

#pragma pack()

/* installation scheme */

typedef struct tagSCHEME {
    char *name;
    char *prefix;
} SCHEME;

typedef int (*NOTIFYPROC)(int code, LPSTR text, ...);

extern BOOL
extract_file(char *dst, char *src, int method, int comp_size,
             int uncomp_size, NOTIFYPROC notify);

extern BOOL
unzip_archive(SCHEME *scheme, char *dirname, char *data,
              DWORD size,  NOTIFYPROC notify);

extern char *
map_new_file(DWORD flags, char *filename, char
             *pathname_part, int size,
             WORD wFatDate, WORD wFatTime,
             NOTIFYPROC callback);

extern BOOL
ensure_directory (char *pathname, char *new_part,
                  NOTIFYPROC callback);

/* codes for NOITIFYPROC */
#define DIR_CREATED 1
#define CAN_OVERWRITE 2
#define FILE_CREATED 3
#define ZLIB_ERROR 4
#define SYSTEM_ERROR 5
#define NUM_FILES 6
#define FILE_OVERWRITTEN 7

