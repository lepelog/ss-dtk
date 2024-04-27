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
};

#endif
