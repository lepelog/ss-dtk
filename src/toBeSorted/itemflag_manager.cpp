#include <toBeSorted/itemflag_manager.h>

// TODO Move
extern "C" u16 lbl_805A9BD8[];
extern "C" UnkFlagDefinition lbl_805116F4[];

/** 800bf7c0 */
ItemFlagManager::ItemFlagManager(): ItemStoryManagerBase(), itemFlags(lbl_805A9BD8, 0x40) {
}

/** 800bf820 */
void ItemFlagManager::copyFlagsFromSave() {
    ItemStoryManagerBase::setFlagSizes(0x40, 0x80);
    ItemStoryManagerBase::copyFlagsFromSave_Priv();
}

/** 800bf860 */
void ItemFlagManager::setupUnkFlagsStuff() {
    this->setupUnkFlagStuff(lbl_805116F4, 0x1fe);
}

/** 800bf870 */
void ItemFlagManager::onDirty() {
}
