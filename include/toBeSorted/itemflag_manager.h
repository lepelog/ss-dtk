#ifndef ITEMFLAG_MANAGER_H
#define ITEMFLAG_MANAGER_H

#include <toBeSorted/itemstory_manager_base.h>

class ItemFlagManager: ItemStoryManagerBase {
public:
    FlagSpace itemFlags;

    ItemFlagManager();
    void copyFlagsFromSave() override;
    void setupUnkFlagsStuff() override;
    void onDirty() override;
    bool doCommit() override;
};

#endif
