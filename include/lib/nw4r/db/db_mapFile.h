#pragma once

#include <types.h>
#include <rvl/OS.h>

// OSModuleLink and OSModuleInfo i think would be in OS.h
struct OSSectionInfo {
    u32 offset;
    u32 size;
};
struct OSModuleInfo; // forward decl
struct OSModuleLink {
    /* 0x00 */ OSModuleInfo* next;
    /* 0x04 */ OSModuleInfo* prev;
};
struct OSModuleInfo {
    /* 0x00 */ u32 id;
    /* 0x04 */ OSModuleLink link;
    /* 0x0C */ u32 numSections;
    /* 0x10 */ u32 sectionInfoOffset;
    /* 0x14 */ u32 nameOffset;
    /* 0x18 */ u32 nameSize;
    /* 0x1C */ u32 version;
};

namespace nw4r {
namespace db {

namespace detail { struct ConsoleHead; }

// From nw4r DWARF info
struct MapFile {
    /* 0x00 */ u8* mapBuf;
    /* 0x04 */ const OSModuleInfo* moduleInfo;
    /* 0x08 */ s32 fileEntry;
    /* 0x0C */ MapFile* next;
};
// QuerySymbolToSingleMapFile___Q24nw4r2dbFPQ34nw4r2db7MapFileUlPUcUl // from DWARF // extra underscore removed for objDiff
/* 804371b0 */ bool QuerySymbolToSingleMapFile(MapFile* pMapFile, u32 address, u8* strBuf, u32 strBufSize);
// MapFile_QuerySymbol__Q24nw4r2dbFUlPUcUl
/* 804372b0 */ bool MapFile_QuerySymbol(u32 address, u8* strBuf, u32 strBufSize); // from DWARF
// Assertion_SetConsole__Q24nw4r2dbFPQ44nw4r2db6detail11ConsoleHead
/* 804373c0 */ void Assertion_SetConsole(detail::ConsoleHead*); // idk the correct symbol yet by this is a possibility given context

static MapFile* sMapFileList;

} // namespace db
} // namespace nw4r