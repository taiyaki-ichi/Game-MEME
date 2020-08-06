#include"BeeCircleActive.hpp"
#include"BeeParam.hpp"
#include"GameLib/include/Draw/DrawAnimation.hpp"
#include"Stage/Gravity/GravityFunc.hpp"

namespace Stage
{
	namespace BeeState
	{

		CircleActive::CircleActive(GameLib::DrawAnimation* anim, GameLib::Vector2&& center, GameLib::Vector2&& rediusvec, float dir)
			:StateBase<>{}
			, mAnim{anim}
			, mCenter{std::move(center)}
			, mRadiusVec{std::move(rediusvec)}
			, mDir{dir}
			, mCnt{0}
			, mWeakness{ "BeeWeakness" }
			, mStrength{ "BeeStrangth" }
		{
			using namespace BeeParam;

			mWeakness.SetScale(SCALE);
			mWeakness.SetWidthAndHeith(WIDTH, HEIGHT* WEAKNESS_RATE);
			mWeakness.SetColor({ 0,255,0,255 });

			mStrength.SetScale(SCALE);
			mStrength.SetWidthAndHeith(WIDTH, HEIGHT* STRENGTH_RATE);
			mWeakness.SetColor({ 0,0,255,255 });
		}

		StateBase<>* CircleActive::Update()
		{
			float rate = 0.03f;
			auto adjust = GameLib::Vector2::Rotation(mRadiusVec, mCnt * rate * mDir);
			auto pos = mCenter + adjust;

			mAnim->SetPosition(pos);
			using namespace BeeParam;
			mWeakness.SetPosition(pos + GetVector2(Dir4::Up, HEIGHT * WEAKNESS_RATE * SCALE));
			mStrength.SetPosition(pos + GetVector2(Dir4::Down, HEIGHT * STRENGTH_RATE * SCALE));

			float rot = -std::atan2(adjust.x, adjust.y);

			if (mDir < 0.f)
				mAnim->SetRotation(rot + GameLib::PI);
			else
				mAnim->SetRotation(rot);


			mCnt++;

			return this;
		}

		void CircleActive::BeginWorking()
		{
			mWeakness.Active();
			mStrength.Active();
		}

		void CircleActive::BeginToRest()
		{
			mWeakness.Pause();
			mStrength.Pause();
		}

	}
}