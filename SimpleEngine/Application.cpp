#include "Application.h"
#include "SceneManager.h"
#include "WindowManager.h"

namespace Application
{
	void Quit()
	{
		SceneManager::GetInstance()->Clear();
		WindowManager::GetInstance()->Clear();

		exit(0);
	}
}