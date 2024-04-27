#include <toBeSorted/itemstory_manager_base.h>

/** 800bf270 */
ItemStoryManagerBase::ItemStoryManagerBase(): flagSizeMaybe(0), anotherSizeMaybe(0), storyFlagsPtr(nullptr), unkFlagsPtr(nullptr), dirty(false) {

}

/** 800bf2a0 */
ItemStoryManagerBase::~ItemStoryManagerBase() {
    if (this->unkFlagsPtr) {
        delete this->unkFlagsPtr;
    }
}

/** 800bf310 */
void ItemStoryManagerBase::setFlagSizes(u16 flagSizeMaybe, u16 anotherFlagSizeMaybe) {
    this->flagSizeMaybe = flagSizeMaybe;
    this->anotherSizeMaybe = anotherFlagSizeMaybe;
}

/** 800bf320 */
void ItemStoryManagerBase::setupUnkFlagStuff(UnkFlagDefinition *def, u16 count) {
    UnkFlagStuff *stuff = new UnkFlagStuff(count, def);
    this->unkFlagsPtr = stuff;
}

/** 800bf380 */
void ItemStoryManagerBase::copyFlagsFromSave_Priv() {
    FlagSpace *current = this->storyFlagsPtr;
    u16 *saved = this->getSaveFlagSpace();
    current->copyFromSaveFile(saved, 0, this->flagSizeMaybe);
}

void ItemStoryManagerBase::init() {
    u16 *space = this->getSaveFlagSpace();
    if (space == nullptr || this->unkFlagsPtr == nullptr) {
        this->setFlagszptr();
        this->copyFlagsFromSave();
        this->setupUnkFlagsStuff();
    }
}

/** 800bf470 */
void ItemStoryManagerBase::setFlagszptr() {
    
}

/** 800bf480 */
u32 ItemStoryManagerBase::getCounterOrFlag(u16 flag) {
    u16 *data = this->getSaveFlagSpace();
    return this->unkFlagsPtr->getCounterOrFlag(flag, data, this->flagSizeMaybe);
}

/** 800bf4e0 */
u32 ItemStoryManagerBase::getUncommittedValue_Priv(u16 flag) {
    u16 *data = this->storyFlagsPtr->getFlagPtrUnchecked();
    return this->unkFlagsPtr->getCounterOrFlag(flag, data, this->flagSizeMaybe);
}

/** 800bf530 */
void ItemStoryManagerBase::setOrClearFlag(u16 flag, bool value) {
    FlagSpace *storyFlagsPtr = this->storyFlagsPtr;
    u16 *pData = storyFlagsPtr->getFlagPtrChecked();
    this->unkFlagsPtr->setCounterOrFlag(flag, pData, storyFlagsPtr->mCount, value);
    this->FUN_800bf610(flag);
}

/** 800bf5b0 */
void ItemStoryManagerBase::setFlag(u16 flag) {
    this->setOrClearFlag(flag, true);
}

/** 800bf5c0 */
void ItemStoryManagerBase::unsetFlag(u16 flag) {
    this->setOrClearFlag(flag, false);
}

/** 800bf5d0 */
void ItemStoryManagerBase::thunk_setOrClearFlag(u16 flag, bool value) {
    this->setOrClearFlag(flag, value);
}

/** 800bf5e0 */
u32 ItemStoryManagerBase::FUN_800bf5e0(u16 flag) {
    return ItemStoryManagerBase::getCounterOrFlag(flag);
}

/** 800bf5f0 */
u32 ItemStoryManagerBase::getUncommittedValue(u16 flag) {
    return this->getUncommittedValue_Priv(flag);
}

/** 800bf600 */
u16 ItemStoryManagerBase::FUN_800bf600(u16 flag) {
    return this->FUN_800bf640(flag);
}

/** 800bf610 */
void ItemStoryManagerBase::FUN_800bf610(u16 flag) {
    this->dirty = true;
    this->onDirty();
}

/** 800bf630 */
void ItemStoryManagerBase::onDirty() {

}

/** 800bf640 */
u16 ItemStoryManagerBase::FUN_800bf640(u16 flag) {
    return this->unkFlagsPtr->maskForIdx(flag, this->flagSizeMaybe);
}

/** 800bf650 */
void ItemStoryManagerBase::doCommit_Priv() {
    this->doCommit();
    this->dirty = false;
}

/* 800bf690 */
void FUN_800bf690() {

}
