#include <nw4r/db/db_mapFile.h>

namespace nw4r {
namespace db {

extern "C" void snprintf(u8*, u32, const char*, ...);
extern "C" OSModuleInfo* OSSearchModule(u32 address, u32* moduleIdx, u32* moduleAddr);

int a = 0x200;
u32 b = 0x8063b320;
u32 c = -1;
/* 804371b0 */ bool QuerySymbolToSingleMapFile(MapFile* pMapFile, u32 address, u8* strBuf, u32 strBufSize){
}

/* 804372b0 */ bool MapFile_QuerySymbol(u32 address, u8* strBuf, u32 strBufSize) {
    MapFile* pMap = sMapFileList;
    if (pMap == nullptr) {
        if (address < (u32)_stack_end) {
            snprintf(strBuf, strBufSize, "[%p]", address);
            return true;
        }
        u32 moduleAddr, moduleIdx;
        OSModuleInfo* module = OSSearchModule(address, &moduleIdx, &moduleAddr);
        if (module != nullptr) {
            snprintf(strBuf, strBufSize, "[%d:%d:%06x]", module->id, moduleIdx, moduleAddr);
            return true;
        }
        return false;
    } else {
        while (pMap != nullptr) {
            if ( QuerySymbolToSingleMapFile(pMap, address, strBuf, strBufSize))
                return true;
            pMap = pMap->next;
        }
    }
    return false;
}

} // namespace db
} // namespace nw4r
