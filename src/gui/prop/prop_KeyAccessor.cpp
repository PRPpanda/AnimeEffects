#include "core/TimeKeyExpans.h"
#include "ctrl/TimeLineUtil.h"
#include "gui/prop/prop_KeyAccessor.h"

namespace
{

const core::SRTKey::Data& getSRTKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_SRT, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::SRTKey*)key)->data();
}

const core::MoveKey::Data& getMoveKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_Move, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::MoveKey*)key)->data();
}

const core::RotateKey::Data& getRotateKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_Rotate, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::RotateKey*)key)->data();
}

const core::ScaleKey::Data& getScaleKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_Scale, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::ScaleKey*)key)->data();
}

const core::OpaKey::Data& getOpaKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_Opa, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::OpaKey*)key)->data();
}

#if 0
const core::PoseKey::Data& getPoseKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_Pose, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::PoseKey*)key)->data();
}

const core::FFDKey::Data& getFFDKeyData(const core::ObjectNode& aTarget, int aFrame)
{
    auto key = aTarget.timeLine()->timeKey(core::TimeKeyType_FFD, aFrame);
    XC_PTR_ASSERT(key);
    return ((const core::FFDKey*)key)->data();
}
#endif

} // namespace

namespace gui {
namespace prop {

KeyAccessor::KeyAccessor()
    : mProject()
    , mTarget()
{
}

void KeyAccessor::setProject(core::Project* aProject)
{
    mProject = aProject;
}

void KeyAccessor::setTarget(core::ObjectNode* aTarget)
{
    mTarget = aTarget;
}

//-------------------------------------------------------------------------------------------------
#define ASSERT_AND_RETURN_INVALID_TARGET() \
    XC_ASSERT(isValid());                  \
    if (!isValid()) return;                \

//-------------------------------------------------------------------------------------------------
void KeyAccessor::assignSRTEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    const int frame = getFrame();
    auto newData = getSRTKeyData(*mTarget, frame);
    newData.easing = aNext;

    ctrl::TimeLineUtil::assignSRTKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignSRTSpline(int aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(0 <= aNext && aNext < core::SRTKey::SplineType_TERM);
    const int frame = getFrame();
    auto newData = getSRTKeyData(*mTarget, frame);
    newData.spline = (core::SRTKey::SplineType)aNext;

    ctrl::TimeLineUtil::assignSRTKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignSRTTrans(const QVector2D& aNewPos)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getSRTKeyData(*mTarget, frame);
    newData.pos.setX(aNewPos.x());
    newData.pos.setY(aNewPos.y());

    ctrl::TimeLineUtil::assignSRTKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignSRTRotate(float aRotate)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getSRTKeyData(*mTarget, frame);
    newData.rotate = aRotate;

    ctrl::TimeLineUtil::assignSRTKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignSRTScale(const QVector2D& aNewScale)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getSRTKeyData(*mTarget, frame);
    newData.scale = aNewScale;

    ctrl::TimeLineUtil::assignSRTKeyData(*mProject, *mTarget, frame, newData);
}

//-------------------------------------------------------------------------------------------------
void KeyAccessor::assignMoveEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    const int frame = getFrame();
    auto newData = getMoveKeyData(*mTarget, frame);
    newData.easing = aNext;

    ctrl::TimeLineUtil::assignMoveKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignMoveSpline(int aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(0 <= aNext && aNext < core::MoveKey::SplineType_TERM);
    const int frame = getFrame();
    auto newData = getMoveKeyData(*mTarget, frame);
    newData.spline = (core::MoveKey::SplineType)aNext;

    ctrl::TimeLineUtil::assignMoveKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignMovePosition(const QVector2D& aNewPos)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getMoveKeyData(*mTarget, frame);
    newData.pos = aNewPos;

    ctrl::TimeLineUtil::assignMoveKeyData(*mProject, *mTarget, frame, newData);
}

//-------------------------------------------------------------------------------------------------
void KeyAccessor::assignRotateEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    const int frame = getFrame();
    auto newData = getRotateKeyData(*mTarget, frame);
    newData.easing = aNext;

    ctrl::TimeLineUtil::assignRotateKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignRotateAngle(float aAngle)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getRotateKeyData(*mTarget, frame);
    newData.rotate = aAngle;

    ctrl::TimeLineUtil::assignRotateKeyData(*mProject, *mTarget, frame, newData);
}

//-------------------------------------------------------------------------------------------------
void KeyAccessor::assignScaleEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    const int frame = getFrame();
    auto newData = getScaleKeyData(*mTarget, frame);
    newData.easing = aNext;

    ctrl::TimeLineUtil::assignScaleKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignScaleRate(const QVector2D& aNewScale)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getScaleKeyData(*mTarget, frame);
    newData.scale = aNewScale;

    ctrl::TimeLineUtil::assignScaleKeyData(*mProject, *mTarget, frame, newData);
}

//-------------------------------------------------------------------------------------------------
void KeyAccessor::assignOpacity(float aOpacity)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    const int frame = getFrame();
    auto newData = getOpaKeyData(*mTarget, frame);
    newData.opacity = aOpacity;

    ctrl::TimeLineUtil::assignOpaKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignOpaEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    const int frame = getFrame();
    auto newData = getOpaKeyData(*mTarget, frame);
    newData.easing = aNext;

    ctrl::TimeLineUtil::assignOpaKeyData(*mProject, *mTarget, frame, newData);
}

void KeyAccessor::assignPoseEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    ctrl::TimeLineUtil::assignPoseKeyEasing(*mProject, *mTarget, getFrame(), aNext);
}

void KeyAccessor::assignFFDEasing(util::Easing::Param aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    XC_ASSERT(aNext.isValidParam());
    ctrl::TimeLineUtil::assignFFDKeyEasing(*mProject, *mTarget, getFrame(), aNext);
}

void KeyAccessor::assignImageResource(img::ResourceNode& aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    ctrl::TimeLineUtil::assignImageKeyResource(*mProject, *mTarget, getFrame(), aNext);
}

void KeyAccessor::assignImageOffset(const QVector2D& aNext)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    ctrl::TimeLineUtil::assignImageKeyOffset(*mProject, *mTarget, getFrame(), aNext);
}

//-------------------------------------------------------------------------------------------------
void KeyAccessor::knockNewSRT()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::SRTKey();
    newKey->data() = mTarget->timeLine()->current().srt().data();

    ctrl::TimeLineUtil::pushNewSRTKey(*mProject, *mTarget, getFrame(), newKey);
}

void KeyAccessor::knockNewMove()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::MoveKey();
    newKey->data().pos = mTarget->timeLine()->current().srt().pos();

    ctrl::TimeLineUtil::pushNewMoveKey(*mProject, *mTarget, getFrame(), newKey);
}
void KeyAccessor::knockNewRotate()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::RotateKey();
    newKey->data().rotate = mTarget->timeLine()->current().srt().rotate();

    ctrl::TimeLineUtil::pushNewRotateKey(*mProject, *mTarget, getFrame(), newKey);
}
void KeyAccessor::knockNewScale()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::ScaleKey();
    newKey->data().scale = mTarget->timeLine()->current().srt().scale();

    ctrl::TimeLineUtil::pushNewScaleKey(*mProject, *mTarget, getFrame(), newKey);
}

void KeyAccessor::knockNewOpacity()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::OpaKey();
    newKey->data() = mTarget->timeLine()->current().opa();

    ctrl::TimeLineUtil::pushNewOpaKey(*mProject, *mTarget, getFrame(), newKey);
}

void KeyAccessor::knockNewPose()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::PoseKey();
    newKey->data() = mTarget->timeLine()->current().pose();
    core::BoneKey* parentKey = mTarget->timeLine()->current().bone().areaKey();
    XC_PTR_ASSERT(parentKey);
    newKey->data().createBonesBy(*parentKey);

    ctrl::TimeLineUtil::pushNewPoseKey(*mProject, *mTarget, getFrame(), newKey, parentKey);
}

void KeyAccessor::knockNewFFD()
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::FFDKey();
    newKey->data() = mTarget->timeLine()->current().ffd();
    core::TimeKey* parentKey = mTarget->timeLine()->current().ffdMeshParent();

    ctrl::TimeLineUtil::pushNewFFDKey(*mProject, *mTarget, getFrame(), newKey, parentKey);
}

void KeyAccessor::knockNewImage(const img::ResourceHandle& aHandle)
{
    ASSERT_AND_RETURN_INVALID_TARGET();
    auto newKey = new core::ImageKey();
    newKey->setImage(aHandle);

    ctrl::TimeLineUtil::pushNewImageKey(*mProject, *mTarget, getFrame(), newKey);
}

} // namespace prop
} // namespace gui
