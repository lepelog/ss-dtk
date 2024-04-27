#include <toBeSorted/itemstory_manager_base.h>

class ItemFlagManager: ItemStoryManagerBase {
public:
    FlagSpace itemFlags;

    ItemFlagManager();
    void copyFlagsFromSave() override;
    void setupUnkFlagsStuff() override;
    void onDirty() override;
};
