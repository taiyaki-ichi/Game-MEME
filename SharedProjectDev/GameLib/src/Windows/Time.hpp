#pragma once

namespace GameLib
{
	//���݂̎��Ԃ̎擾
	unsigned long GetTime();

	//prevTime����waitTime����Sleep
	void Wait(unsigned long preTime, unsigned long waitTime);
}