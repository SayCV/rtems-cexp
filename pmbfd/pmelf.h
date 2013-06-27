/* $Id: pmelf.h,v 1.22 2013/01/23 15:46:17 strauman Exp $ */

/* 
 * Authorship
 * ----------
 * This software ('pmelf' ELF file reader) was created by
 *     Till Straumann <strauman@slac.stanford.edu>, 2008,
 * 	   Stanford Linear Accelerator Center, Stanford University.
 * 
 * Acknowledgement of sponsorship
 * ------------------------------
 * This software was produced by
 *     the Stanford Linear Accelerator Center, Stanford University,
 * 	   under Contract DE-AC03-76SFO0515 with the Department of Energy.
 * 
 * Government disclaimer of liability
 * ----------------------------------
 * Neither the United States nor the United States Department of Energy,
 * nor any of their employees, makes any warranty, express or implied, or
 * assumes any legal liability or responsibility for the accuracy,
 * completeness, or usefulness of any data, apparatus, product, or process
 * disclosed, or represents that its use would not infringe privately owned
 * rights.
 * 
 * Stanford disclaimer of liability
 * --------------------------------
 * Stanford University makes no representations or warranties, express or
 * implied, nor assumes any liability for the use of this software.
 * 
 * Stanford disclaimer of copyright
 * --------------------------------
 * Stanford University, owner of the copyright, hereby disclaims its
 * copyright and all other rights in this software.  Hence, anyone may
 * freely use it for any purpose without restriction.  
 * 
 * Maintenance of notices
 * ----------------------
 * In the interest of clarity regarding the origin and status of this
 * SLAC software, this and all the preceding Stanford University notices
 * are to remain affixed to any copy or derivative of this software made
 * or distributed by the recipient and are to be affixed to any copy of
 * software made or distributed by the recipient that contains a copy or
 * derivative of this software.
 * 
 * ------------------ SLAC Software Notices, Set 4 OTT.002a, 2004 FEB 03
 */ 
#ifndef _PMELF_H
#define _PMELF_H

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Elementary Types */
typedef uint32_t Elf32_Addr;
typedef uint16_t Elf32_Half;
typedef uint32_t Elf32_Off;
typedef  int32_t Elf32_Sword;
typedef uint32_t Elf32_Word;

typedef uint64_t Elf64_Addr;
typedef uint64_t Elf64_Off;
typedef uint16_t Elf64_Half;
typedef uint32_t Elf64_Word;
typedef  int32_t Elf64_Sword;
typedef uint64_t Elf64_Xword;
typedef  int64_t Elf64_Sxword;

/**************************************************/
/*  ELF HEADER                                    */
/**************************************************/

/* Object file type */
#define ET_NONE		0		/* none               */
#define ET_REL		1		/* relocatable        */
#define ET_EXEC		2		/* executable         */
#define ET_DYN		3		/* shared object      */
#define ET_CORE		4		/* core               */
#define ET_LOPROC	0xff00	/* processor specific */
#define ET_HIPROC	0xffff	/* processor specific */

/* Machine type (supported by us so far)          */
#define EM_SPARC			 2
#define EM_386				 3
#define EM_68K				 4
#define EM_PPC				20
#define EM_X86_64			62

/* Identification indices                          */
#define EI_MAG0				 0
#define EI_MAG1				 1
#define EI_MAG2				 2
#define EI_MAG3				 3
#define EI_CLASS			 4
#define EI_DATA				 5
#define EI_VERSION			 6
#define EI_OSABI			 7
#define EI_PAD				 8

#define ELFMAG0			  0x7f
#define ELFMAG1			   'E'
#define ELFMAG2			   'L'
#define ELFMAG3			   'F'

#define ELFCLASSNONE		 0
#define ELFCLASS32			 1
#define ELFCLASS64			 2

#define ELFDATANONE			 0
#define ELFDATA2LSB			 1
#define ELFDATA2MSB			 2

#define ELFOSABI_NONE		 0
#define ELFOSABI_SYSV		 0 /* yep */

/* Object file version                             */
#define EV_NONE				 0
#define EV_CURRENT			 1

#define EI_NIDENT  16

/* if eh_phnum == PN_XNUM then the number of program headers doesn't fit.
 * it is then stored in the sh_info field of section 0.
 */
#define PN_XNUM     0xffff

typedef struct {
	uint8_t		e_ident[EI_NIDENT];
	Elf32_Half	e_type;
	Elf32_Half	e_machine;
	Elf32_Word	e_version;
	Elf32_Addr	e_entry;
	Elf32_Off	e_phoff;
	Elf32_Off	e_shoff;
	Elf32_Word	e_flags;
	Elf32_Half	e_ehsize;
	Elf32_Half	e_phentsize;
	Elf32_Half	e_phnum;
	Elf32_Half	e_shentsize;
	Elf32_Half	e_shnum;
	Elf32_Half	e_shstrndx;
} Elf32_Ehdr;

typedef struct {
	uint8_t		e_ident[EI_NIDENT];
	Elf64_Half	e_type;
	Elf64_Half	e_machine;
	Elf64_Word	e_version;
	Elf64_Addr	e_entry;
	Elf64_Off	e_phoff;
	Elf64_Off	e_shoff;
	Elf64_Word	e_flags;
	Elf64_Half	e_ehsize;
	Elf64_Half	e_phentsize;
	Elf64_Half	e_phnum;
	Elf64_Half	e_shentsize;
	Elf64_Half	e_shnum;
	Elf64_Half	e_shstrndx;
} Elf64_Ehdr;

typedef union {
	uint8_t    e_ident[EI_NIDENT];
	Elf32_Ehdr e32;
	Elf64_Ehdr e64;
} Elf_Ehdr;

/**************************************************/
/*  SECTION HEADER                                */
/**************************************************/

/* Section indices                                */
#define SHN_UNDEF			 0
#define SHN_LORESERVE		 0xff00
#define SHN_LOPROC			 0xff00
#define SHN_HIPROC			 0xff1f
#define SHN_ABS				 0xfff1
#define SHN_COMMON			 0xfff2
#define SHN_HIRESERVE		 0xffff

#define SHT_NULL			 0
#define SHT_PROGBITS		 1
#define SHT_SYMTAB			 2
#define SHT_STRTAB			 3
#define SHT_RELA			 4
#define SHT_HASH			 5
#define SHT_DYNAMIC			 6
#define SHT_NOTE			 7
#define SHT_NOBITS			 8
#define SHT_REL				 9
#define SHT_SHLIB			10
#define SHT_DYNSYM			11
#define SHT_INIT_ARRAY		14
#define SHT_FINI_ARRAY		15
#define SHT_PREINIT_ARRAY	16
#define SHT_GROUP			17
#define SHT_SYMTAB_SHNDX	18
#define SHT_GNU_ATTRIBUTES  0x6ffffff5
#define SHT_GNU_HASH        0x6ffffff6
#define SHT_GNU_VERSION     0x6fffffff
#define SHT_GNU_VERSION_R   0x6ffffffe
#define SHT_LOPROC			0x70000000
#define SHT_HIPROC			0x7fffffff
#define SHT_LOUSER			0x80000000
#define SHT_HIUSER			0xffffffff
#define SHT_ISSUP(i) ( ((i) <= SHT_SYMTAB_SHNDX) || ((i)>=SHT_GNU_ATTRIBUTES && (i)<=SHT_GNU_VERSION) )

#define SHF_WRITE			0x00000001
#define SHF_ALLOC			0x00000002
#define SHF_EXECINSTR		0x00000004
#define SHF_MERGE			0x00000010
#define SHF_STRINGS			0x00000020
#define SHF_INFO_LINK		0x00000040
#define SHF_LINK_ORDER		0x00000080
#define SHF_OS_NONCONFORMING	0x00000100
#define SHF_GROUP			0x00000200
#define SHF_MSKSUP			 (~0x3f7)
#define SHF_MASKPROC		0xf0000000

#define SHF_PPC_VLE         0x10000000

#define GRP_COMDAT			 1

typedef struct {
	Elf32_Word	sh_name;
	Elf32_Word	sh_type;
	Elf32_Word	sh_flags;
	Elf32_Addr	sh_addr;
	Elf32_Off	sh_offset;
	Elf32_Word	sh_size;
	Elf32_Word	sh_link;
	Elf32_Word	sh_info;
	Elf32_Word	sh_addralign;
	Elf32_Word	sh_entsize;
} Elf32_Shdr;

typedef struct {
	Elf64_Word	sh_name;
	Elf64_Word	sh_type;
	Elf64_Xword	sh_flags;
	Elf64_Addr	sh_addr;
	Elf64_Off	sh_offset;
	Elf64_Xword	sh_size;
	Elf64_Word	sh_link;
	Elf64_Word	sh_info;
	Elf64_Xword	sh_addralign;
	Elf64_Xword	sh_entsize;
} Elf64_Shdr;

typedef union {
	Elf32_Shdr s32;
	Elf64_Shdr s64;
} Elf_Shdr;

/**************************************************/
/*  SYMBOLS                                       */
/**************************************************/

#define ELF32_ST_BIND(x)		(((x)>>4)&0xf)
#define ELF32_ST_TYPE(x)		((x) & 0xf)
#define ELF32_ST_INFO(b,t)		(((b)<<4) | ((t)&0xf))

#define ELF64_ST_BIND(x)		ELF32_ST_BIND(x)
#define ELF64_ST_TYPE(x)		ELF32_ST_TYPE(x)
#define ELF64_ST_INFO(b,t)		ELF32_ST_INFO(b,t)

#define STB_LOCAL		 0
#define STB_GLOBAL		 1
#define STB_WEAK		 2
#define STB_MAXSUP		 2
#define STB_LOPROC		13
#define STB_HIPROC		15

#define STT_NOTYPE		 0
#define STT_OBJECT		 1
#define STT_FUNC		 2
#define STT_SECTION		 3
#define STT_FILE		 4
#define STT_COMMON		 5
#define STT_TLS			 6
#define STT_MAXSUP		 6
#define STT_LOPROC		13
#define STT_HIPROC		15

#define STV_DEFAULT		 0
#define STV_INTERNAL	 1
#define STV_HIDDEN		 2
#define STV_PROTECTED	 3

#define ELF32_ST_VISIBILITY(o) ((o)&3)
#define ELF64_ST_VISIBILITY(o) ELF32_ST_VISIBILITY(o)

typedef struct {
	Elf32_Word	st_name;
	Elf32_Addr	st_value;
	Elf32_Word	st_size;
	uint8_t		st_info;
	uint8_t		st_other;
	Elf32_Half	st_shndx;
} Elf32_Sym;

typedef struct {
	Elf64_Word	st_name;
	uint8_t		st_info;
	uint8_t		st_other;
	Elf64_Half	st_shndx;
	Elf64_Addr	st_value;
	Elf64_Xword	st_size;
} Elf64_Sym;

typedef union {
	Elf32_Sym t32;
	Elf64_Sym t64;
} Elf_Sym;

/**************************************************/
/*  RELOCATION RECORDS                            */
/**************************************************/

/*
 * Sysv relocation types for SPARC.
 */

#define R_SPARC_NONE              0
#define R_SPARC_8                 1
#define R_SPARC_16                2
#define R_SPARC_32                3
#define R_SPARC_DISP8             4
#define R_SPARC_DISP16            5
#define R_SPARC_DISP32            6
#define R_SPARC_WDISP30           7
#define R_SPARC_WDISP22           8
#define R_SPARC_HI22              9
#define R_SPARC_22               10
#define R_SPARC_12               11
#define R_SPARC_LO10             12
#define R_SPARC_GOT10            13	/* unimpl */
#define R_SPARC_GOT13            14	/* unimpl */
#define R_SPARC_GOT22            15	/* unimpl */
#define R_SPARC_PC10             16
#define R_SPARC_PC22             17
#define R_SPARC_WPLT30           18	/* unimpl */
#define R_SPARC_COPY             19	/* unimpl */
#define R_SPARC_GLOB_DAT         20	/* unimpl */
#define R_SPARC_JMP_SLOT         21	/* unimpl */
#define R_SPARC_RELATIVE         22	/* unimpl */
#define R_SPARC_UA32             23
#define R_SPARC_PLT32            24	/* unimpl */
#define R_SPARC_HIPLT22          25	/* unimpl */
#define R_SPARC_LOPLT10          26	/* unimpl */
#define R_SPARC_PCPLT32          27	/* unimpl */
#define R_SPARC_PCPLT22          28	/* unimpl */
#define R_SPARC_PCPLT10          29	/* unimpl */
#define R_SPARC_10               30
#define R_SPARC_11               31
/**/
#define R_SPARC_HH22             34
#define R_SPARC_HM10             35
#define R_SPARC_LM22             36
#define R_SPARC_PC_HH22          37
#define R_SPARC_PC_HM10          38
#define R_SPARC_PC_LM22          39
#define R_SPARC_WDISP16          40
#define R_SPARC_WDISP19          41
/**/
#define R_SPARC_7                43
#define R_SPARC_5                44
#define R_SPARC_6                45
/**/
#define R_SPARC_HIX22            48
#define R_SPARC_LOX10            49
#define R_SPARC_H44              50
#define R_SPARC_M44              51
#define R_SPARC_L44              52
#define R_SPARC_REGISTER         53	/* unimpl */
/**/
#define R_SPARC_UA16             55
/**/
#define R_SPARC_GOTDATA_HIX22    80	/* unimpl */
#define R_SPARC_GOTDATA_LOX10    81	/* unimpl */
#define R_SPARC_GOTDATA_OP_HIX22 82	/* unimpl */
#define R_SPARC_GOTDATA_OP_LOX10 83	/* unimpl */
#define R_SPARC_GOTDATA_OP       84	/* unimpl */


/*
 * SysvR4 relocation types for i386. Statically linked objects
 * just use R_386_32 and R_386_PC32 which makes our job really easy...
 */
#define R_386_NONE                0
#define R_386_32                  1
#define R_386_PC32                2
#define R_386_GOT32               3
#define R_386_PLT32               4
#define R_386_COPY                5
#define R_386_GLOB_DAT            6
#define R_386_JMP_SLOT            7
#define R_386_RELATIVE            8
#define R_386_GOTOFF              9
#define R_386_GOTPC              10

/*
 * 68k relocation types
 */
#define R_68K_NONE                0
#define R_68K_32                  1
#define R_68K_16                  2
#define R_68K_8                   3
#define R_68K_PC32                4
#define R_68K_PC16                5
#define R_68K_PC8                 6
#define R_68K_GOT32               7
#define R_68K_GOT16               8
#define R_68K_GOT8                9
#define R_68K_GOT320             10
#define R_68K_GOT160             11
#define R_68K_GOT80              12
#define R_68K_PLT32              13
#define R_68K_PLT16              14
#define R_68K_PLT8               15
#define R_68K_PLT320             16
#define R_68K_PLT160             17
#define R_68K_PLT80              18
#define R_68K_COPY               19
#define R_68K_GLOB_DAT           20
#define R_68K_JMP_SLOT           21
#define R_68K_RELATIVE           22


/* PPC relocation types */
#define R_PPC_NONE                0
#define R_PPC_ADDR32              1
#define R_PPC_ADDR24              2
#define R_PPC_ADDR16              3
#define R_PPC_ADDR16_LO           4
#define R_PPC_ADDR16_HI           5
#define R_PPC_ADDR16_HA           6
#define R_PPC_ADDR14              7
#define R_PPC_ADDR14_BRTAKEN      8
#define R_PPC_ADDR14_BRNTAKEN     9
#define R_PPC_REL24              10
#define R_PPC_REL14              11
#define R_PPC_REL14_BRTAKEN      12
#define R_PPC_REL14_BRNTAKEN     13
#define R_PPC_GOT16              14
#define R_PPC_GOT16_LO           15
#define R_PPC_GOT16_HI           16
#define R_PPC_GOT16_HA           17
#define R_PPC_PLTREL24           18
#define R_PPC_COPY               19
#define R_PPC_GLOB_DAT           20
#define R_PPC_JMP_SLOT           21
#define R_PPC_RELATIVE           22
#define R_PPC_LOCAL24PC          23
#define R_PPC_UADDR32            24
#define R_PPC_UADDR16            25
#define R_PPC_REL32              26
#define R_PPC_PLT32              27
#define R_PPC_PLTREL32           28
#define R_PPC_PLT16_LO           29
#define R_PPC_PLT16_HI           30
#define R_PPC_PLT16_HA           31
#define R_PPC_SDAREL16           32
#define R_PPC_SECTOFF            33
#define R_PPC_SECTOFF_LO         34
#define R_PPC_SECTOFF_HI         35
#define R_PPC_SECTOFF_HA         36
#define R_PPC_ADDR30             37

/*
 * SVR4 relocation types for x86_64
 */
#define R_X86_64_NONE             0
#define R_X86_64_64               1
#define R_X86_64_PC32             2
#define R_X86_64_GOT32            3
#define R_X86_64_PLT32            4
#define R_X86_64_COPY             5
#define R_X86_64_GLOB_DAT         6
#define R_X86_64_JUMP_SLOT        7
#define R_X86_64_RELATIVE         8
#define R_X86_64_GOTPCREL         9
#define R_X86_64_32              10
#define R_X86_64_32S             11
#define R_X86_64_16              12
#define R_X86_64_PC16            13
#define R_X86_64_8               14
#define R_X86_64_PC8             15
#define R_X86_64_DTPMOD64        16
#define R_X86_64_DTPOFF64        17
#define R_X86_64_TPOFF64         18
#define R_X86_64_TLSGD           19
#define R_X86_64_TLSLD           20
#define R_X86_64_DTPOFF32        21
#define R_X86_64_GOTTPOFF        22
#define R_X86_64_TPOFF32         23
#define R_X86_64_PC64            24
#define R_X86_64_GOTOFF64        25
#define R_X86_64_GOTPC32         26
#define R_X86_64_SIZE32          32
#define R_X86_64_SIZE64          33
#define R_X86_64_GOTPC32_TLSDESC 34
#define R_X86_64_TLSDESC_CALL    35
#define R_X86_64_TLSDESC         36

#define ELF32_R_SYM(x)		((x) >> 8)
#define ELF32_R_TYPE(x) 	((uint8_t)((x)&0xff))
#define ELF32_R_INFO(s,t)	(((s)<<8) | ((t)&0xff))

#define ELF64_R_SYM(x)		((x) >> 32)
#define ELF64_R_TYPE(x) 	((uint32_t)((x)&0xffffffffL))
#define ELF64_R_INFO(s,t)	(((s)<<32) | ((t)&0xffffffffL))

typedef struct {
	Elf32_Addr	r_offset;
	Elf32_Word	r_info;
} Elf32_Rel;

typedef struct {
	Elf32_Addr	r_offset;
	Elf32_Word	r_info;
	Elf32_Sword	r_addend;
} Elf32_Rela;

typedef struct {
	Elf64_Addr	r_offset;
	Elf64_Xword	r_info;
} Elf64_Rel;

typedef struct {
	Elf64_Addr		r_offset;
	Elf64_Xword		r_info;
	Elf64_Sxword	r_addend;
} Elf64_Rela;

typedef union {
	Elf32_Rel	r32;
	Elf32_Rela  ra32;
	Elf64_Rel	r64;
	Elf64_Rela  ra64;
} Elf_Reloc;

/**************************************************/
/*  PROGRAM HEADER                                */
/**************************************************/

#define PT_NULL			0
#define PT_LOAD			1
#define PT_DYNAMIC		2
#define PT_INTERP		3
#define PT_NOTE			4
#define PT_SHLIB		5
#define PT_PHDR			6
#define PT_LOOS			0x60000000
#define PT_GNU_EH_FRAME	0x6474e550
#define PT_GNU_STACK	0x6474e551
#define PT_GNU_RELRO	0x6474e552
#define PT_HIOS			0x6fffffff
#define PT_LOPROC		0x70000000
#define PT_HIPROC		0x7fffffff
#define PT_ISSUP(t) ((t) <= PT_PHDR || ((t)>=PT_GNU_EH_FRAME && (t)<=PT_GNU_RELRO))

#define PF_X			0x1  /* Execute */
#define PF_W			0x2  /* Write   */
#define PF_R			0x4  /* Read    */
#define PF_MASCOS		0x0ff00000
#define PF_MASCPROC		0xf0000000
#define PF_MSKSUP       (~(PF_X|PF_W|PF_R))

typedef struct {
	Elf32_Word		p_type;
	Elf32_Off		p_offset;
	Elf32_Addr		p_vaddr;
	Elf32_Addr		p_paddr;
	Elf32_Word		p_filesz;
	Elf32_Word		p_memsz;
	Elf32_Word		p_flags;
	Elf32_Word		p_align;
} Elf32_Phdr;

typedef struct {
	Elf64_Word		p_type;
	Elf64_Word		p_flags;
	Elf64_Off		p_offset;
	Elf64_Addr		p_vaddr;
	Elf64_Addr		p_paddr;
	Elf64_Xword		p_filesz;
	Elf64_Xword		p_memsz;
	Elf64_Xword		p_align;
} Elf64_Phdr;

typedef union {
	Elf32_Phdr p32;
	Elf64_Phdr p64;
} Elf_Phdr;

/**************************************************/
/*  DYNAMIC SECTION                               */
/**************************************************/

typedef struct {
	Elf32_Sword		d_tag;
	union {
		Elf32_Word		d_val;
		Elf32_Addr		d_ptr;
	} 				d_un;
} Elf32_Dyn;

typedef struct {
	Elf64_Sxword	d_tag;
	union {
		Elf64_Xword		d_val;
		Elf64_Addr		d_ptr;
	} 				d_un;
} Elf64_Dyn;

typedef union {
	Elf32_Dyn d32;
	Elf64_Dyn d64;
} Elf_Dyn;

#define DT_NULL				0	/* End of array marker									*/
#define DT_NEEDED			1	/* string table offset of name of needed library		*/
#define DT_PLTRELSZ			2	/* # relocation entries associated with PLT				*/
#define DT_PLTGOT			3	/* address associated with PLT or GOT (proc specific)	*/
#define DT_HASH				4	/* address of symbol hash table							*/
#define DT_STRTAB			5	/* address of string table								*/
#define DT_SYMTAB			6	/* address of symbol table								*/
#define DT_RELA				7	/* address of RELA relocation table						*/
#define DT_RELASZ			8	/* total size (in bytes) of RELA relocation table		*/
#define DT_RELAENT			9	/* size (in bytes) of one RELA entry					*/
#define DT_STRSZ			10	/* size (in bytes) of the string table					*/
#define DT_SYMENT			11	/* size (in bytes) of a symbol table entry				*/
#define DT_INIT				12	/* address of initialization function					*/
#define DT_FINI				13	/* address of termination function						*/
#define DT_SONAME			14	/* strtab index of shared object name					*/
#define DT_RPATH			15	/* strtab index of library search path (deprecated)		*/
#define DT_SYMBOLIC			16	/* start symbol search with this shared object			*/
#define DT_REL				17	/* address of REL relocation table						*/
#define DT_RELSZ			18	/* size (in bytes) of REL table							*/
#define DT_RELENT			19	/* size (in bytes) of a REL entry						*/
#define DT_PLTREL			20	/* type of PLT relocation (rel/rela)					*/
#define DT_DEBUG			21	/* debugging; unspecified								*/
#define DT_TEXTREL			22	/* reloc might modify .text								*/
#define DT_JMPREL			23	/* address of PLT relocation table						*/
#define DT_BIND_NOW			24	/* process relocations when loading program				*/
#define DT_INIT_ARRAY		25	/* address of array of init functions					*/
#define DT_FINI_ARRAY		26	/* address of array of termination functions			*/
#define DT_INIT_ARRAYSZ		27	/* size (in bytes) of INIT_ARRAY						*/
#define DT_FINI_ARRAYSZ		28	/* size (in bytes) of FINI_ARRAY						*/
#define DT_RUNPATH			29	/* library search path									*/
#define DT_FLAGS			30	/* flags for shared object being loaded					*/
#define DT_ENCODING			31	/* start of encoded range								*/
#define DT_PREINIT_ARRAY	32	/* address of array of preinit functions				*/
#define DT_PREINIT_ARRAYSZ	33	/* size (in bytes) of PREINIT_ARRAY						*/
#define DT_LOOS		0x6000000d
#define DT_HIOS		0x6ffff000
#define DT_LOPROC	0x70000000
#define DT_HIPROC	0x7fffffff

/**************************************************/
/* ANYTHING BELOW HERE IS DEFINED BY THIS LIBRARY */
/* AND NOT BY THE ELF FILE FORMAT.                */
/**************************************************/

typedef union {
	Elf32_Ehdr *p_e32;
	Elf64_Ehdr *p_e64;
} Elf_PEhdr;

typedef union {
	uint8_t    *p_raw;
	Elf32_Shdr *p_s32;
	Elf64_Shdr *p_s64;
} Elf_PShdr;

typedef union {
	uint8_t    *p_raw;
	Elf32_Sym  *p_t32;
	Elf64_Sym  *p_t64;
} Elf_PSym;

typedef unsigned long Pmelf_Off;
typedef unsigned long Pmelf_Size;
typedef long          Pmelf_Long;


/* A Section Header Table */
typedef struct {
	Elf_PShdr	shdrs;        /* Array of Shdrs    */
	uint32_t   	nshdrs;       /* number of entries */
	const char 	*strtab;      /* associated strtab */
	Pmelf_Size  strtablen;
	uint32_t	idx;          /* SH idx of strtab  */
	uint8_t     clss;         /* class (64/32-bit) */
} *Pmelf_Shtab;

/* A Symbol Table         */
typedef struct {
	Elf_PSym	syms;         /* Array of symbols  */
	Pmelf_Long  nsyms;        /* number of entries */
	const char  *strtab;      /* associated strtab */
	Pmelf_Size  strtablen;
	uint32_t	idx;          /* SH idx of strtab  */
	uint8_t     clss;         /* class (64/32-bit) */
} *Pmelf_Symtab;

/* Stream (file) where to read from; we hide the
 * details so that other implementations could be
 * provided.
 */
typedef struct _Elf_Stream *Elf_Stream;

static inline const char *
pmelf32_get_section_name(Pmelf_Shtab stab, uint32_t index)
{
	return &stab->strtab[stab->shdrs.p_s32[index].sh_name];
}

static inline const char *
pmelf64_get_section_name(Pmelf_Shtab stab, uint32_t index)
{
	return &stab->strtab[stab->shdrs.p_s64[index].sh_name];
}

static inline const char *
pmelf_get_section_name(Pmelf_Shtab stab, uint32_t index)
{
	if ( ELFCLASS64 == stab->clss )
		return pmelf64_get_section_name(stab, index);
	else
		return pmelf32_get_section_name(stab, index);
}

/* Create a new stream; if 'name' is given then
 * the named file is opened and used for the stream.
 * Alternatively, an open FILE stream may be passed.
 * The name is unused in this case (except for informative
 * purposes in error messages).
 * 
 * RETURNS: new stream of NULL on error.
 *
 * NOTE:    if an open 'FILE' is passed and creating
 *          the stream fails the FILE is *not* closed.
 */
Elf_Stream
pmelf_newstrm(const char *name, FILE *f);

/*
 * Create a new stream to read from a memory
 * buffer 'buf'.
 */
Elf_Stream
pmelf_memstrm(void *buf, size_t len);


/* Create a new stream 'mmap()'ing the underlying
 * file 'filename'. Alternatively, an open FILE
 * may be passed (see pmelf_newstrm).
 *
 */
Elf_Stream
pmelf_mapstrm(const char *name, FILE *f);

/* Cleanup and delete a stream. Optionally,
 * (pass nonzero 'noclose' argument) the
 * underlying FILE is not closed but left alone.
 */
void
pmelf_delstrm(Elf_Stream s, int noclose);


/* Direct error messages to FILE; a NULL pointer
 * may be passed to silence all messages.
 *
 * NOTE: by default (w/o calling this routine)
 *       the library is silent (as if NULL had
 *       been passed).
 */
void
pmelf_set_errstrm(FILE *f);

/* Position the stream;
 * 
 * RETURNS: 0 on success, nonzero on error.
 *
 * NOTE:    Always use this routine. Do not
 *          fseek the underlying file directly.
 */
int
pmelf_seek(Elf_Stream s, Pmelf_Off where);

/* Obtain current position in stream
 * RETURNS: 0 on success, nonzero on error
 */
int
pmelf_tell(Elf_Stream s, Pmelf_Off *ppos);

/* Read an ELF file header into *pehdr (storage
 * provided by caller).
 *
 * The header is byte-swapped if necessary into
 * host byte order.
 *
 * NOTE:    The stream is rewound to the beginning
 *          by this routine.
 *          After returning successfully from this
 *          routine the stream is positioned after
 *          the datum that was read.
 *
 * RETURNS: 0 on success, nonzero on error.
 */
int
pmelf_getehdr(Elf_Stream s, Elf_Ehdr *pehdr);

/* Read an ELF section header into *pshdr (storage
 * provided by caller).
 *
 * The header is byte-swapped if necessary into
 * host byte order.
 *
 * NOTE:    The stream must have been correctly 
 *          positioned prior to calling this routine.
 *          After returning successfully from this
 *          routine the stream is positioned after
 *          the datum that was read.
 *
 * RETURNS: 0 on success, nonzero on error.
 */
int
pmelf_getshdr32(Elf_Stream s, Elf32_Shdr *pshdr);
int
pmelf_getshdr64(Elf_Stream s, Elf64_Shdr *pshdr);

/* Read an ELF symbol into *psym (storage
 * provided by caller).
 *
 * The symbol is byte-swapped if necessary into
 * host byte order.
 *
 * NOTE:    The stream must have been correctly 
 *          positioned prior to calling this routine.
 *          After returning successfully from this
 *          routine the stream is positioned after
 *          the datum that was read.
 *
 * RETURNS: 0 on success, nonzero on error.
 */
int
pmelf_getsym32(Elf_Stream s, Elf32_Sym *psym);
int
pmelf_getsym64(Elf_Stream s, Elf64_Sym *psym);

/* Read section contents described by *psect
 * from stream 's' into the storage area pointed
 * to by 'data' (provided by caller).
 *
 * No byte-swapping is performed.
 *
 *
 * The stream is positioned to the section
 * offset as indicated by psect->sh_offset.
 *
 * An additional 'offset' may be provided by
 * the caller
 *
 * If the 'len' argument (byte count) is zero
 * then the entire section contents are read.
 *
 * It is legal to pass a NULL 'data' pointer.
 * This instructs the routine to allocate
 * the required amount of memory. It is the
 * responsability of the caller to free such
 * memory.
 *
 * After returning successfully from this
 * routine the stream is positioned after
 * the datum that was read.
 *
 * RETURNS: pointer to 'data' (or allocated area
 *          if a NULL data pointer was passed)
 *          or NULL on failure.
 */
void *
pmelf_getscn(Elf_Stream s, Elf_Shdr *psect, void *data, Pmelf_Off offset, Pmelf_Off len);


/* Read the contents of a SHT_GROUP section identified
 * by the section header 'psect'.
 *
 * The stream is positioned to the start of the section
 * and it's contents are read into the 'data' storage
 * area which may be provided by the caller. If a NULL
 * 'data' pointer is passed then memory is allocated
 * (it is the user's responsability to free it when done).
 *
 * The section contents are byte-swapped as needed.
 *
 * A group section is an array of Elf32_Words listing
 * the section indices of the group members. However,
 * the very first word is a flag word (e.g., containing
 * GRP_COMDAT).
 *
 * RETURNS: 'data' pointer on success, NULL on error.
 *
 * NOTE:    on successful return the stream is positioned
 *          behind the section contents.
 */
Elf32_Word *
pmelf_getgrp(Elf_Stream s, Elf_Shdr *psect, Elf32_Word *data);

/*
 * Allocate memory for a section header table and read
 * the section headers described by file header *pehdr
 * from stream 's'.
 *
 * It is the user's responsibility to destroy the table
 * by calling pmelf_delshtab().
 *
 * RETURNS: pointer to section header table on success,
 *          NULL on error.
 *
 * NOTE:    after successful execution the stream is
 *          positioned behind the section headers.
 */
Pmelf_Shtab
pmelf_getshtab(Elf_Stream s, Elf_Ehdr *pehdr);

/*
 * Destroy section header table and release memory
 */
void
pmelf_delshtab(Pmelf_Shtab sht);

/*
 * Convenience routine: retrieve section name as a
 * string.
 *
 * RETURNS: section name or NULL if parameters are
 *          invalid (e.g., index into strtab found
 *          in shdr is out of bounds).
 */
const char *
pmelf_sec_name(Pmelf_Shtab sht, Elf_Shdr *shdr);

/*
 * Convenience routine: retrieve symbol name as a
 * string.
 *
 * RETURNS: symbol name or NULL if parameters are
 *          invalid (e.g., index into strtab found
 *          in sym is out of bounds).
 */
const char *
pmelf_sym_name(Pmelf_Symtab symt, Elf_Sym *sym);

/*
 * Allocate memory for a symbol table and read the
 * section headers described by section header table
 * 'shtab' from stream 's'.
 *
 * It is the user's responsibility to destroy the table
 * by calling pmelf_delsymtab().
 *
 * RETURNS: pointer to symbol header table on success,
 *          NULL on error.
 *
 * NOTE:    after successful execution the stream is
 *          positioned behind the ELF symbol table.
 */
Pmelf_Symtab
pmelf_getsymtab(Elf_Stream s, Pmelf_Shtab shtab);

Pmelf_Symtab
pmelf_getdsymtab(Elf_Stream s, Pmelf_Shtab shtab);

/*
 * Destroy symbol table and release memory
 */
void
pmelf_delsymtab(Pmelf_Symtab symtab);

/*
 * Convenience routine for users who want to build their
 * own symbol table (by repeated use of pmelf_getsym()).
 *
 * This routine locates the section headers of the
 * symbol table and it's associated string table,
 * respectively.
 *
 * RETURNS: (positive) number of symbols or a value less
 *          than zero on error.
 *
 *          If successful, pointers to the respective
 *          headers are stored in *psymsh (header of
 *          symbol table section) and *pstrsh (header
 *          of string table used by symbol table).
 */
Pmelf_Long
pmelf_find_symhdrs(Elf_Stream s, Pmelf_Shtab shtab, Elf_Shdr **psymsh, Elf_Shdr **pstrsh);

Pmelf_Long
pmelf_find_dsymhdrs(Elf_Stream s, Pmelf_Shtab shtab, Elf_Shdr **psymsh, Elf_Shdr **pstrsh);

/* Read an ELF program header into *pphdr (storage
 * provided by caller).
 *
 * The header is byte-swapped if necessary into
 * host byte order.
 *
 * NOTE:    The stream must have been correctly 
 *          positioned prior to calling this routine.
 *          After returning successfully from this
 *          routine the stream is positioned after
 *          the datum that was read.
 *
 *          On reading the last PHDR, p_type == PT_NULL.
 *
 * RETURNS: 0 on success, nonzero on error.
 */
int
pmelf_getphdr32(Elf_Stream s, Elf32_Phdr *pphdr);
int
pmelf_getphdr64(Elf_Stream s, Elf64_Phdr *pphdr);


/* Dump contents of file header to FILE in readable form */
void
pmelf_dump_ehdr(FILE *f, Elf_Ehdr *pehdr);

#define FMT_SHORT  0		/* more concise; fits on one line */
#define FMT_LONG   1        /* slightly longer / more info    */
#define FMT_COMPAT 2        /* 'readelf -Ss' compatible       */

/* Dump contents of section header to FILE in readable form
 * using one of the formats defined above.
 *
 * NOTE: the section name is NOT printed by this routine
 *       (essentially because it has no information about
 *       the string table). It is the user's responsability
 *       to print the name if needed.
 */
void 
pmelf_dump_shdr32(FILE *f, Elf32_Shdr *pshdr, int format);

void 
pmelf_dump_shdr64(FILE *f, Elf64_Shdr *pshdr, int format);

/*
 * Dump contents of section header table in readable
 * form to FILE. If format == FMT_COMPAT the listing is
 * identical to the output of 'readelf -S' (except for some
 * header and footer lines).
 */
void
pmelf_dump_shtab(FILE *f, Pmelf_Shtab shtab, int format);

/*
 * Dump symbol information in readable form to FILE.
 * Either of 'shtab' or 'strtab' may be NULL but then
 * instead of the name of the section defining the symbol
 * or the name of the symbol itself their respective
 * index numbers are printed.
 *
 * If format == FMT_COMPAT the listing is identical to the
 * output of 'readelf -s'.
 */
void
pmelf_dump_sym32(FILE *f, Elf32_Sym *sym, Pmelf_Shtab shtab, const char *strtab, unsigned strtablen, int format);
void
pmelf_dump_sym64(FILE *f, Elf64_Sym *sym, Pmelf_Shtab shtab, const char *strtab, unsigned strtablen, int format);

/*
 * Dump contents of symbol table in readable form to FILE.
 * If format == FMT_COMPAT the listing is identical to the
 * output of 'readelf -s' (except for some header and footer
 * lines).
 */
void
pmelf_dump_symtab(FILE *f, Pmelf_Symtab symtab, Pmelf_Shtab shtab, int format);

/*
 * Dump contents of all section groups to FILE in readable
 * form, compatible with 'readelf -g'.
 *
 * RETURNS:  number of section groups on success or a value
 *           less than zero if an error was found.
 */
int
pmelf_dump_groups(FILE *f, Elf_Stream s, Pmelf_Shtab shtab, Pmelf_Symtab symtab);

/*
 * Dump contents of all relocation sections to FILE in
 * readable form, compatible with 'readelf -r'.
 */
void
pmelf_dump_rels(FILE *f, Elf_Stream s, Pmelf_Shtab sht, Pmelf_Symtab symt);

/* Dump contents of program header to FILE in readable form
 * using one of the formats defined above.
 *
 */
void 
pmelf_dump_phdr32(FILE *f, Elf32_Phdr *pphdr, int format);

void 
pmelf_dump_phdr64(FILE *f, Elf64_Phdr *pphdr, int format);

/*
 * Dump all phdrs to FILE
 */
int
pmelf_dump_phdrs(FILE *f, Elf_Stream s, int format);

/*
 * Object file attributes (stored in '.gnu.attributes' sections of type
 * SHT_GNU_ATTRIBUTES). They describe ABI compatibility features of object
 * files.
 */
typedef struct Pmelf_attribute_set_ Pmelf_attribute_set;

typedef struct Pmelf_attribute_vendor_ Pmelf_attribute_vendor;

/*
 * Vendors implemented so far
 */

extern Pmelf_attribute_vendor pmelf_attributes_vendor_gnu_ppc;

/*
 * Provide a compile-time constant if there is an implementation
 */
#if defined(__PPC__) && defined(_CALL_SYSV)
#define PMELF_ATTRIBUTE_VENDOR (&pmelf_attributes_vendor_gnu_ppc)
#endif

/*
 * Try to find a vendor for 'machine/osabi' at run-time.
 * (Using this routine will trigger linkage of all implemented
 * vendors)
 */
Pmelf_attribute_vendor *
pmelf_attributes_vendor_find_gnu(Elf32_Word machine, Elf32_Word osabi);

/* register a vendor (attribute parser + filter)
 *
 * RETURNS: 0 on success, -1 if vendor with new vendor's name
 *          is already registered.
 */
int
pmelf_attributes_vendor_register(Pmelf_attribute_vendor *pv);
	
/* retrieve name of a vendor (pointer to constant string) */
const char * 
pmelf_attributes_vendor_name(Pmelf_attribute_vendor *pv);

/* Create attribute set reading from an ELF stream.
 *
 * 's'       : stream object
 *
 * 'psect'   : section header of type SHT_GNU_ATTRIBUTES (".gnu.attributes")
 * 
 * RETURNS   : attribute set or NULL on error.
 *
 * NOTE      : the stream and section header are not referenced anymore
 *             after this routine returns and may therefore be safely
 *             destroyed.
 */
Pmelf_attribute_set *
pmelf_create_attribute_set(Elf_Stream s, Elf_Shdr *psect);

/* Create attribute set from a static memory buffer.
 *
 * 'b'       : pointer to buffer
 *
 * 'bsize'   : size of data/buffer in bytes
 * 
 * 'needswap': if nonzero, assume that endian-ness of the data does not match the
 *             endian-ness of the executing CPU and hence data need to be swapped
 *
 * 'obj_name': a name to associate with this buffer (mainly used in error messages)
 *
 * RETURNS   : attribute set or NULL on error.
 *
 * NOTE      : It is the responsibility of the caller to manage this buffer and
 *             make sure it 'lives' as long as the attribute set since the
 *             latter uses pointers into the buffer.
 *             Data layout in the buffer is expected to be in ARM aeabi format
 *             (which is used by the GNU toolchain).
 */
Pmelf_attribute_set *
pmelf_read_attribute_set(const uint8_t *b, unsigned bsize, int needswap, const char *obj_name);

/*
 * Destroy attribute set and release all associated resources
 */
void
pmelf_destroy_attribute_set(Pmelf_attribute_set *pa);

/*
 * Dump information contained in an attribute set to FILE 'f'
 * (may be NULL resulting in stdout being used).
 */
void
pmelf_print_attribute_set(Pmelf_attribute_set *pa, FILE *f);

/*
 * Compare two attribute sets.
 *
 * RETURNS: zero if the sets describe compatible objects, negative
 *          if an incompatibility is found indicating that they
 *          may not be linked.
 *
 * NOTE:    positive return values are reserved for future use.
 */
int
pmelf_match_attribute_set(Pmelf_attribute_set *pa, Pmelf_attribute_set *pb);

/* Write headers to a stream */
int
pmelf_putehdr32(Elf_Stream s, Elf32_Ehdr *pehdr);
int
pmelf_putehdr64(Elf_Stream s, Elf64_Ehdr *pehdr);

int
pmelf_putshdr32(Elf_Stream s, Elf32_Shdr *pshdr);
int
pmelf_putshdr64(Elf_Stream s, Elf64_Shdr *pshdr);

int
pmelf_putsym32(Elf_Stream s, Elf32_Sym *psym);
int
pmelf_putsym64(Elf_Stream s, Elf64_Sym *psym);

int
pmelf_write(Elf_Stream s, void *data, Pmelf_Long len);

/* Read the contents of a SHT_REL/SHT_RELA section
 * identified by the section header 'psect'.
 *
 * The stream is positioned to the start of the section
 * and it's contents are read into the 'data' storage
 * area which may be provided by the caller. If a NULL
 * 'data' pointer is passed then memory is allocated
 * (it is the user's responsability to free it when done).
 *
 * The section contents are byte-swapped as needed.
 *
 * RETURNS: 'data' pointer on success, NULL on error.
 *
 * NOTE:    on successful return the stream is positioned
 *          behind the section contents.
 *
 */

void *
pmelf_getrel(Elf_Stream s, Elf_Shdr *psect, void *data);

/* 
 * Names of relocation types
 */
#define pmelf_namecase(rel)	case rel: return #rel;

static __inline__ const char *
pmelf_sparc_rel_name(Elf32_Rela *r)
{
	switch ( ELF32_R_TYPE(r->r_info) ) {
		pmelf_namecase( R_SPARC_NONE             )
		pmelf_namecase( R_SPARC_8                )
		pmelf_namecase( R_SPARC_16               )
		pmelf_namecase( R_SPARC_32               )
		pmelf_namecase( R_SPARC_DISP8            )
		pmelf_namecase( R_SPARC_DISP16           )
		pmelf_namecase( R_SPARC_DISP32           )
		pmelf_namecase( R_SPARC_WDISP30          )
		pmelf_namecase( R_SPARC_WDISP22          )
		pmelf_namecase( R_SPARC_HI22             )
		pmelf_namecase( R_SPARC_22               )
		pmelf_namecase( R_SPARC_12               )
		pmelf_namecase( R_SPARC_LO10             )
		pmelf_namecase( R_SPARC_GOT10            )
		pmelf_namecase( R_SPARC_GOT13            )
		pmelf_namecase( R_SPARC_GOT22            )
		pmelf_namecase( R_SPARC_PC10             )
		pmelf_namecase( R_SPARC_PC22             )
		pmelf_namecase( R_SPARC_WPLT30           )
		pmelf_namecase( R_SPARC_COPY             )
		pmelf_namecase( R_SPARC_GLOB_DAT         )
		pmelf_namecase( R_SPARC_JMP_SLOT         )
		pmelf_namecase( R_SPARC_RELATIVE         )
		pmelf_namecase( R_SPARC_UA32             )
		pmelf_namecase( R_SPARC_PLT32            )
		pmelf_namecase( R_SPARC_HIPLT22          )
		pmelf_namecase( R_SPARC_LOPLT10          )
		pmelf_namecase( R_SPARC_PCPLT32          )
		pmelf_namecase( R_SPARC_PCPLT22          )
		pmelf_namecase( R_SPARC_PCPLT10          )
		pmelf_namecase( R_SPARC_10               )
		pmelf_namecase( R_SPARC_11               )
/**/
		pmelf_namecase( R_SPARC_HH22             )
		pmelf_namecase( R_SPARC_HM10             )
		pmelf_namecase( R_SPARC_LM22             )
		pmelf_namecase( R_SPARC_PC_HH22          )
		pmelf_namecase( R_SPARC_PC_HM10          )
		pmelf_namecase( R_SPARC_PC_LM22          )
		pmelf_namecase( R_SPARC_WDISP16          )
		pmelf_namecase( R_SPARC_WDISP19          )
/**/
		pmelf_namecase( R_SPARC_7                )
		pmelf_namecase( R_SPARC_5                )
		pmelf_namecase( R_SPARC_6                )
/**/
		pmelf_namecase( R_SPARC_HIX22            )
		pmelf_namecase( R_SPARC_LOX10            )
		pmelf_namecase( R_SPARC_H44              )
		pmelf_namecase( R_SPARC_M44              )
		pmelf_namecase( R_SPARC_L44              )
		pmelf_namecase( R_SPARC_REGISTER         )
/**/
		pmelf_namecase( R_SPARC_UA16             )
/**/
		pmelf_namecase( R_SPARC_GOTDATA_HIX22    )
		pmelf_namecase( R_SPARC_GOTDATA_LOX10    )
		pmelf_namecase( R_SPARC_GOTDATA_OP_HIX22 )
		pmelf_namecase( R_SPARC_GOTDATA_OP_LOX10 )
		pmelf_namecase( R_SPARC_GOTDATA_OP       )

		default:
			break;
	}
	return "UNKNOWN";
}

static __inline__ const char *
pmelf_i386_rel_name(Elf32_Rel *r)
{
	switch ( ELF32_R_TYPE(r->r_info) ) {
		pmelf_namecase( R_386_NONE     )
		pmelf_namecase( R_386_32       )
		pmelf_namecase( R_386_PC32     )
		pmelf_namecase( R_386_GOT32    )
		pmelf_namecase( R_386_PLT32    )
		pmelf_namecase( R_386_COPY     )
		pmelf_namecase( R_386_GLOB_DAT )
		pmelf_namecase( R_386_JMP_SLOT )
		pmelf_namecase( R_386_RELATIVE )
		pmelf_namecase( R_386_GOTOFF   )
		pmelf_namecase( R_386_GOTPC    )

		default:
		break;
	}
	return "UNKNOWN";
}

static __inline__ const char *
pmelf_m68k_rel_name(Elf32_Rela *r)
{
	switch ( ELF32_R_TYPE(r->r_info) ) {
		pmelf_namecase( R_68K_NONE )
		pmelf_namecase( R_68K_32 )
		pmelf_namecase( R_68K_16 )
		pmelf_namecase( R_68K_8 )
		pmelf_namecase( R_68K_PC32 )
		pmelf_namecase( R_68K_PC16 )
		pmelf_namecase( R_68K_PC8 )
		pmelf_namecase( R_68K_GOT32 )
		pmelf_namecase( R_68K_GOT16 )
		pmelf_namecase( R_68K_GOT8 )
		pmelf_namecase( R_68K_GOT320 )
		pmelf_namecase( R_68K_GOT160 )
		pmelf_namecase( R_68K_GOT80 )
		pmelf_namecase( R_68K_PLT32 )
		pmelf_namecase( R_68K_PLT16 )
		pmelf_namecase( R_68K_PLT8 )
		pmelf_namecase( R_68K_PLT320 )
		pmelf_namecase( R_68K_PLT160 )
		pmelf_namecase( R_68K_PLT80 )
		pmelf_namecase( R_68K_COPY )
		pmelf_namecase( R_68K_GLOB_DAT )
		pmelf_namecase( R_68K_JMP_SLOT )
		pmelf_namecase( R_68K_RELATIVE )

		default:
		break;
	}
	return "UNKNOWN";
}

static __inline__ const char *
pmelf_ppc_rel_name(Elf32_Rela *r)
{
	switch ( ELF32_R_TYPE(r->r_info) ) {
		pmelf_namecase( R_PPC_NONE                )
		pmelf_namecase( R_PPC_ADDR32              )
		pmelf_namecase( R_PPC_ADDR24              )
		pmelf_namecase( R_PPC_ADDR16              )
		pmelf_namecase( R_PPC_ADDR16_LO           )
		pmelf_namecase( R_PPC_ADDR16_HI           )
		pmelf_namecase( R_PPC_ADDR16_HA           )
		pmelf_namecase( R_PPC_ADDR14              )
		pmelf_namecase( R_PPC_ADDR14_BRTAKEN      )
		pmelf_namecase( R_PPC_ADDR14_BRNTAKEN     )
		pmelf_namecase( R_PPC_REL24               )
		pmelf_namecase( R_PPC_REL14               )
		pmelf_namecase( R_PPC_REL14_BRTAKEN       )
		pmelf_namecase( R_PPC_REL14_BRNTAKEN      )
		pmelf_namecase( R_PPC_GOT16               )
		pmelf_namecase( R_PPC_GOT16_LO            )
		pmelf_namecase( R_PPC_GOT16_HI            )
		pmelf_namecase( R_PPC_GOT16_HA            )
		pmelf_namecase( R_PPC_PLTREL24            )
		pmelf_namecase( R_PPC_COPY                )
		pmelf_namecase( R_PPC_GLOB_DAT            )
		pmelf_namecase( R_PPC_JMP_SLOT            )
		pmelf_namecase( R_PPC_RELATIVE            )
		pmelf_namecase( R_PPC_LOCAL24PC           )
		pmelf_namecase( R_PPC_UADDR32             )
		pmelf_namecase( R_PPC_UADDR16             )
		pmelf_namecase( R_PPC_REL32               )
		pmelf_namecase( R_PPC_PLT32               )
		pmelf_namecase( R_PPC_PLTREL32            )
		pmelf_namecase( R_PPC_PLT16_LO            )
		pmelf_namecase( R_PPC_PLT16_HI            )
		pmelf_namecase( R_PPC_PLT16_HA            )
		pmelf_namecase( R_PPC_SDAREL16            )
		pmelf_namecase( R_PPC_SECTOFF             )
		pmelf_namecase( R_PPC_SECTOFF_LO          )
		pmelf_namecase( R_PPC_SECTOFF_HI          )
		pmelf_namecase( R_PPC_SECTOFF_HA          )
		pmelf_namecase( R_PPC_ADDR30              )

		default:
			break;
	}
	return "UNKNOWN";
}

static __inline__ const char *
pmelf_x86_64_rel_name(Elf64_Rela *r)
{
	switch ( ELF64_R_TYPE(r->r_info) ) {
		pmelf_namecase( R_X86_64_NONE             )
		pmelf_namecase( R_X86_64_64               )
		pmelf_namecase( R_X86_64_PC32             )
		pmelf_namecase( R_X86_64_GOT32            )
		pmelf_namecase( R_X86_64_PLT32            )
		pmelf_namecase( R_X86_64_COPY             )
		pmelf_namecase( R_X86_64_GLOB_DAT         )
		pmelf_namecase( R_X86_64_JUMP_SLOT        )
		pmelf_namecase( R_X86_64_RELATIVE         )
		pmelf_namecase( R_X86_64_GOTPCREL         )
		pmelf_namecase( R_X86_64_32               )
		pmelf_namecase( R_X86_64_32S              )
		pmelf_namecase( R_X86_64_16               )
		pmelf_namecase( R_X86_64_PC16             )
		pmelf_namecase( R_X86_64_8                )
		pmelf_namecase( R_X86_64_PC8              )
		pmelf_namecase( R_X86_64_DTPMOD64         )
		pmelf_namecase( R_X86_64_DTPOFF64         )
		pmelf_namecase( R_X86_64_TPOFF64          )
		pmelf_namecase( R_X86_64_TLSGD            )
		pmelf_namecase( R_X86_64_TLSLD            )
		pmelf_namecase( R_X86_64_DTPOFF32         )
		pmelf_namecase( R_X86_64_GOTTPOFF         )
		pmelf_namecase( R_X86_64_TPOFF32          )
		pmelf_namecase( R_X86_64_PC64             )
		pmelf_namecase( R_X86_64_GOTOFF64         )
		pmelf_namecase( R_X86_64_GOTPC32          )
		pmelf_namecase( R_X86_64_SIZE32           )
		pmelf_namecase( R_X86_64_SIZE64           )
		pmelf_namecase( R_X86_64_GOTPC32_TLSDESC  )
		pmelf_namecase( R_X86_64_TLSDESC_CALL     )
		pmelf_namecase( R_X86_64_TLSDESC          )

		default:
		break;
	}
	return "UNKNOWN";
}

#undef pmelf_namecase

#ifdef __cplusplus
}
#endif


#endif
