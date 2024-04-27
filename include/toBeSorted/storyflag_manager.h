#ifndef STORYFLAG_MANAGER_H
#define STORYFLAG_MANAGER_H

#include <toBeSorted/itemstory_manager_base.h>

class StoryFlagManager: ItemStoryManagerBase {
public:
    FlagSpace storyFlags;

    StoryFlagManager();
    void copyFlagsFromSave() override;
    void setupUnkFlagsStuff() override;
    void onDirty() override;
    void unsetFlag(u16 flag) override;
    bool doCommit() override;
};

#endif
