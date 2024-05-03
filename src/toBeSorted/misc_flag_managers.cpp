#include <common.h>
#include <libc.h>
#include <toBeSorted/bitwise_flag_helper.h>
#include <toBeSorted/file_manager.h>
#include <toBeSorted/flag_space.h>

class CommittableFlagManager {
public:
    bool mNeedsCommit;

    virtual void doCommit() = 0;
    bool commitIfNecessary();
    void setNeedsCommit(bool commit) {
        mNeedsCommit = commit;
    }
    CommittableFlagManager() {
        mNeedsCommit = false;
    }
    CommittableFlagManager(bool commit) {
        mNeedsCommit = commit;
    }
};

/* 0x800BE7B0 */
bool CommittableFlagManager::commitIfNecessary() {
    if (mNeedsCommit) {
        doCommit();
        mNeedsCommit = false;
        return true;
    } else {
        return false;
    }
}

class TBoxFlagManager : public CommittableFlagManager {
public:
    FlagSpace mFlagSpace;
    u16 mSceneIndex;
    BitwiseFlagHelper mFlagHelper;

    static u16 sTBoxFlags[2];

    static TBoxFlagManager *sInstance;

    virtual void doCommit() override;
    bool checkUncommittedFlag(u16 flag);
    TBoxFlagManager();
    virtual ~TBoxFlagManager() {}
    void init();
    void copyFromSave(s16 sceneIndex);
    bool checkFlag(u16 sceneIndex, u16 flag);
    virtual u16 getFlagCount() const;
    void setFlag(u16 flag);
    bool checkUncommittedFlag(u16 sceneIndex, u16 flag);
    u16 checkUncommittedFlag2(u16 flag) {
        return checkUncommittedFlag(flag);
    }
};

TBoxFlagManager *TBoxFlagManager::sInstance = nullptr;
u16 TBoxFlagManager::sTBoxFlags[2] = {};

/* 0x800BE810 */
void TBoxFlagManager::doCommit() {
    if (mSceneIndex != 0xFFFF) {
        FileManager::getInstance()->setTBoxFlags(mFlagSpace.getFlagPtrUnchecked(), mSceneIndex * 2, 2);
    }
}

/* 0x800BE870 */
bool TBoxFlagManager::checkUncommittedFlag(u16 flag) {
    return mFlagHelper.checkFlag(flag / 16, flag % 16, mFlagSpace.getFlagPtrUnchecked(), mFlagSpace.mCount);
}

/* 0x800BE8E0 */
TBoxFlagManager::TBoxFlagManager() : CommittableFlagManager(false), mFlagSpace(sTBoxFlags, ARRAY_LENGTH(sTBoxFlags)) {
    mSceneIndex = 0xFFFF;
}

/* 0x800BE920 */
void TBoxFlagManager::init() {}

/* 0x800BE930 */
void TBoxFlagManager::copyFromSave(s16 sceneIndex) {
    u16 idx = sceneIndex;
    mSceneIndex = idx;
    u16 *flags = FileManager::getInstance()->getTBoxFlagsConst();
    mFlagSpace.copyFromSaveFile2(flags + (idx * 2), 0, 2);
}

/* 0x800BE990 */
bool TBoxFlagManager::checkFlag(u16 sceneIndex, u16 flag) {
    s32 actualFlag = (flag + sceneIndex * 0x20);
    return mFlagHelper.checkFlag(actualFlag / 16, flag % 16, FileManager::getInstance()->getTBoxFlagsConst(),
            getFlagCount());
}

/* 0x800BEA30 */
u16 TBoxFlagManager::getFlagCount() const {
    return 0x200;
}

/* 0x800BEA40 */
void TBoxFlagManager::setFlag(u16 flag) {
    if (checkUncommittedFlag2(flag) != 1) {
        mFlagHelper.setFlag(flag / 16, flag % 16, mFlagSpace.getFlagPtrChecked(), mFlagSpace.mCount);
        setNeedsCommit(true);
    }
}

// NOTE: Not actually Enemy Defeat.
// This is a little more than that, it keeps track of live objects based on their id as a whole
class EnemyDefeatManager : public CommittableFlagManager {
public:
    FlagSpace mFlagSpace;
    BitwiseFlagHelper mFlagHelper;
    u16 mSceneIndex;

    static u16 sEnemyDefeatFlags[4096];

    static EnemyDefeatManager *sInstance;

    void clearSavedFlags();
    bool checkUncommittedFlag(u16 flag);
    u16 checkUncommittedFlag2(u16 flag) {
        return checkUncommittedFlag(flag);
    }
    EnemyDefeatManager();
    void init();
    void copyFromSave(u16 sceneIndex);
    void updateFlagIndex(u16 sceneIndex);
    void clearAll();
    bool checkIsValidFlag(u16 flag);
    bool checkFlag(u16 flag);
    virtual ~EnemyDefeatManager() {}
    virtual u16 getFlagCount() const;
    void setFlag(u16 flag);
};

/** 0x805753F0 */
EnemyDefeatManager *EnemyDefeatManager::sInstance = nullptr;
/** 0x805A7AD8 */
u16 EnemyDefeatManager::sEnemyDefeatFlags[4096] = {};

/* 0x800BEAC0 */
void EnemyDefeatManager::clearSavedFlags() {
    u16 empty[0x1000];
    memset(empty, 0, 0x2000);
    FileManager::getInstance()->setEnemyDefeatFlags(empty, 0, 0x1000);
}

/* 0x800BEB00 */
bool EnemyDefeatManager::checkUncommittedFlag(u16 flag) {
    if (checkIsValidFlag(flag)) {
        return mFlagHelper.checkFlag(flag / 16, flag % 16, mFlagSpace.getFlagPtrUnchecked(), mFlagSpace.mCount);
    } else {
        return false;
    }
}

/* 0x800BEB80 */
EnemyDefeatManager::EnemyDefeatManager()
    : CommittableFlagManager(false), mFlagSpace(sEnemyDefeatFlags, ARRAY_LENGTH(sEnemyDefeatFlags)) {}

/* 0x800BEBC0 */
void EnemyDefeatManager::init() {
    mSceneIndex = 0;
    clearAll();
}

/* 0x800BEBD0 */
void EnemyDefeatManager::copyFromSave(u16 sceneIndex) {
    mSceneIndex = sceneIndex;
    u16 count = mFlagSpace.mCount;
    u16 *flags = FileManager::getInstance()->getEnemyDefeatFlagsConst();
    mFlagSpace.copyFromSaveFile(flags, 0, count);
}

/* 0x800BEC30 */
void EnemyDefeatManager::updateFlagIndex(u16 sceneIndex) {
    if (mSceneIndex == sceneIndex) {
        return;
    }
    mSceneIndex = sceneIndex;
    clearAll();
}

/* 0x800BEC50 */
void EnemyDefeatManager::clearAll() {
    clearSavedFlags();
    mFlagSpace.unsetAll();
}

/* 0x800BEC90 */
bool EnemyDefeatManager::checkIsValidFlag(u16 flag) {
    return flag < 0xFFFF;
}

/* 0x800BECB0 */
bool EnemyDefeatManager::checkFlag(u16 flag) {
    if (!checkIsValidFlag(flag)) {
        return false;
    } else {
        u16 *pData = FileManager::getInstance()->getEnemyDefeatFlagsConst();
        return mFlagHelper.checkFlag(flag / 16, flag % 16, pData, getFlagCount());
    }
}

/* 0x800BED50 */
u16 EnemyDefeatManager::getFlagCount() const {
    return 0x1000;
}

/* 0x800BED60 */
void EnemyDefeatManager::setFlag(u16 flag) {
    if (checkUncommittedFlag2(flag) != 1 && checkIsValidFlag(flag)) {
        mFlagHelper.setFlag(flag / 16, flag % 16, mFlagSpace.getFlagPtrChecked(), mFlagSpace.mCount);
        setNeedsCommit(true);
    }
}
