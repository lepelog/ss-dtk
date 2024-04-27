#include <toBeSorted/storyflag_manager.h>

// TODO Move
extern "C" u16 lbl_805A9AD8[];
extern "C" UnkFlagDefinition lbl_80510D90[];

/** 800bf6a0 */
StoryFlagManager::StoryFlagManager(): ItemStoryManagerBase(), storyFlags(lbl_805A9AD8, 0x80) {
}

/** 800bf700 */
void StoryFlagManager::copyFlagsFromSave() {
    ItemStoryManagerBase::setFlagSizes(0x80, 0x100);
    ItemStoryManagerBase::copyFlagsFromSave_Priv();
}

/** 800bf740 */
void StoryFlagManager::setupUnkFlagsStuff() {
    this->setupUnkFlagStuff(lbl_80510D90, 0x4b1);
}

/** 800bf750 */
void StoryFlagManager::onDirty() {
}
