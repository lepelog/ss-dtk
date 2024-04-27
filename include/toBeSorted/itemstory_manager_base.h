#include <common.h>
#include <toBeSorted/flag_space.h>
#include <toBeSorted/unk_flag_stuff.h>

class ItemStoryManagerBase {
public:
    // vtables, how do they work???
    /** 0x00 */ ItemStoryManagerBase();
    virtual void unk();
    /** 0x08 */ ~ItemStoryManagerBase();
    /** 0x0C */ virtual void setFlagszptr();
    /** 0x10 */ virtual void onDirty();
    /** 0x14 */ virtual void copyFlagsFromSave() = 0;
    /** 0x18 */ virtual void setupUnkFlagsStuff() = 0;
    /** 0x1C */ virtual void doCommit() = 0;
    /** 0x20 */ virtual void setFlag(u16 flag);
    /** 0x24 */ virtual void unsetFlag(u16 flag);
    /** 0x28 */ virtual void setFlagOrCounterToValue();
    /** 0x2C */ virtual  u32 getCounterOrFlag(u16 flag);
    /** 0x30 */ virtual  u32 getUncommittedValue(u16 flag);
    /** 0x34 */ virtual void unk3();
    /** 0x38 */ virtual  u16 *getSaveFlagSpace() = 0;

    void init();
    void setFlagSizes(u16 flagSizeMaybe, u16 anotherFlagSizeMaybe);
    void copyFlagsFromSave_Priv();
    void setupUnkFlagStuff(UnkFlagDefinition *def, u16 count);
    void doCommit_Priv();
    void thunk_setOrClearFlag(u16 flag, bool value);
    void setOrClearFlag(u16 flag, bool value);
    u32  FUN_800bf5e0(u16 flag);
    u16 FUN_800bf600(u16 flag);
    void FUN_800bf610(u16 flag);
    u16 FUN_800bf640(u16 flag);
    void FUN_800bf690();

    u32 getUncommittedValue_Priv(u16 flag);

    /** 0x04 */ u16 flagSizeMaybe;
    /** 0x06 */ u16 anotherSizeMaybe;
    /** 0x08 */ FlagSpace *storyFlagsPtr;
    /** 0x0C */ UnkFlagStuff *unkFlagsPtr;
    /** 0x10 */ bool dirty;
};
